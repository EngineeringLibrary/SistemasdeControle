#include "SistemasdeControle/headers/modelLibs/conversions.h"

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::ss2tf(const ModelHandler::StateSpace<Type> &SS)
{

}

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::ss2tfSISO(const ModelHandler::StateSpace<Type> &SS)
{
    using namespace LinAlg;
    using namespace ModelHandler;
    using namespace PolynomHandler;

    Matrix<Type> A = SS.getA();
    Matrix<Type> B = SS.getB();
    Matrix<Type> C = SS.getC();
    Matrix<Type> D = SS.getD();

    TransferFunction<Type> TF = Polynom<Type>(CaracteristicPolynom(A - B*C) - CaracteristicPolynom(A), CaracteristicPolynom(A));
    if(!SS.isContinuous())
    {
        TF.setContinuous(SS.isContinuous());
        TF.setSampleTime(SS.getSampleTime());
    }
    return TF;
}

template <typename Type>
ModelHandler::TransferFunction<Type> ModelHandler::arx2tf(const ARX<Type> &Arx, double sampleTime)
{
    unsigned nuPar  = Arx.getNumberOfInputs();
    unsigned nyPar  = Arx.getNumberOfOutputs();
    unsigned nu     = Arx.getNumberOfInputDelays();
    unsigned ny     = Arx.getNumberOfOutputDelays();

    LinAlg::Matrix<Type> ArxParameters = Arx.getModelCoef();
    ModelHandler::TransferFunction<Type> TF(nyPar, nuPar);

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        for(unsigned j = 1; j <= nuPar; ++j)
        {
            TF(i,j) = PolynomHandler::Polynom<Type>
            ( ~ArxParameters(from( nyPar*ny + (j-1)*nu + 1) --> nyPar*ny + j*nu, i), LinAlg::Matrix<Type>(1)|
              ~ArxParameters(from((j-1)*ny + 1)             --> j*ny,i            ) );
        }
    }
    TF.setContinuous(false);
    TF.setSampleTime(sampleTime);
    return TF;
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::arx2SS(const ARX<Type> &Arx)
{
    LinAlg::Matrix<Type> Temp;
    LinAlg::Matrix<Type> ArxParameters = Arx.getModelCoef();

    double sampleTime = Arx.getSampleTime();
    unsigned nuPar    = Arx.getNumberOfInputs();
    unsigned nyPar    = Arx.getNumberOfOutputs();
//    unsigned nArxPar  = Arx.getNumberOfVariables();
    unsigned nu       = Arx.getNumberOfInputDelays();
    unsigned ny       = Arx.getNumberOfOutputDelays();

    LinAlg::Matrix<Type> A;//(nyPar*ny, nyPar*ny);
    LinAlg::Matrix<Type> B;//(nyPar*ny, nuPar);
    LinAlg::Matrix<Type> C(nyPar, nyPar*ny);
    LinAlg::Matrix<Type> D(nyPar, nuPar);

//    std::cout << ArxParameters;//dispensável

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        Temp = LinAlg::Zeros<Type>(nyPar*ny, 1);
        unsigned row = 1;
        for(unsigned j = 1; j <= nyPar; ++j)
            for(unsigned k = 1; k <= ny; ++k){
                Temp(row,1) = -ArxParameters((i-1)*ny + k, j);
                ++row;
            }
//        std::cout << Temp;
        A = A|Temp|(LinAlg::Zeros<Type>((i - 1)*ny, ny - 1)                        ||
                    LinAlg::Eye<Type>(ny-1)                                        ||
                    LinAlg::Zeros<Type>(nyPar*ny - (i - 1)*ny - (ny - 1), ny - 1));
//        std::cout << A;
    }

    for(unsigned i = 1; i <= nuPar; ++i)
    {
        Temp = LinAlg::Zeros<Type>(nyPar*ny, 1);
        unsigned row = 1;
        for(unsigned j = 1; j <= nyPar; ++j)
            for(unsigned k = 1; k <= nu; ++k){
                Temp(row,1) = ArxParameters((i-1)*nu + k + nyPar*ny, j);
                ++row;
            }
//        std::cout << Temp;
        B = B|Temp;
//        std::cout << B;
    }

    for(unsigned i = 1; i <= nyPar; ++i)
    {
        for(unsigned j = 1; j <= nyPar*ny; ++j)
        {
            if(j == (i-1)*ny + 1)
                C(i,j) = 1;
        }
    }
//    std::cout << C;

    return StateSpace<Type>(A,B,C,D,sampleTime);
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::tf2ss(const ModelHandler::TransferFunction<Type> &TF)
{
    ModelHandler::TransferFunction<Type> TFtemp = TF(1,1);
    ModelHandler::StateSpace<Type> SS = ModelHandler::tf2ssSISO(TFtemp);
    LinAlg::Matrix<Type> ZeroDireita, ZeroAbaixo;

    for(unsigned i = 1; i <= TF.getNumberOfRows(); ++i)
    {
        LinAlg::Matrix<Type> Btemp;
        LinAlg::Matrix<Type> Ctemp;
        LinAlg::Matrix<Type> Dtemp;

        for(unsigned j = 1; j <= TF.getNumberOfColumns(); ++j)
        {
            TFtemp = TF(i,j);
            ModelHandler::StateSpace<Type> SStemp = ModelHandler::tf2ssSISO(TFtemp);
            if(i != 1 || j != 1)//monta A
            {
                ZeroDireita = LinAlg::Zeros<Type> (SS.getA().getNumberOfRows(),SStemp.getA().getNumberOfColumns());
                ZeroAbaixo  = LinAlg::Zeros<Type> (SStemp.getA().getNumberOfRows(),SS.getA().getNumberOfColumns());
                SS.setA((SS.getA()|ZeroDireita) || (ZeroAbaixo|SStemp.getA()));
            }

            if(j == 1) // Monta B, C e D
            {
                Btemp = SStemp.getB();
                Ctemp = SStemp.getC();
                Dtemp = SStemp.getD();
            }
            else
            {
                ZeroDireita = LinAlg::Zeros<Type> (Btemp.getNumberOfRows(),SStemp.getB().getNumberOfColumns());
                ZeroAbaixo  = LinAlg::Zeros<Type> (SStemp.getB().getNumberOfRows(),Btemp.getNumberOfColumns());
                Btemp = (Btemp|ZeroDireita) || (ZeroAbaixo|SStemp.getB());

                Ctemp = (Ctemp) | (SStemp.getC());
                Dtemp = (Dtemp) | (SStemp.getD());
            }
        }
        if(i == 1) // Monta B, C e D
        {
            SS.setB(Btemp);
            SS.setC(Ctemp);
            SS.setD(Dtemp);
        }
        else
        {
            SS.setB(SS.getB()||Btemp);

            ZeroDireita = LinAlg::Zeros<Type> (Ctemp.getNumberOfRows(),SS.getC().getNumberOfColumns());
            ZeroAbaixo  = LinAlg::Zeros<Type> (SS.getC().getNumberOfRows(),Ctemp.getNumberOfColumns());
            SS.setC((Ctemp|ZeroDireita) || (ZeroAbaixo|SS.getC()));

            ZeroDireita = LinAlg::Zeros<Type> (Dtemp.getNumberOfRows(),SS.getD().getNumberOfColumns());
            ZeroAbaixo  = LinAlg::Zeros<Type> (SS.getD().getNumberOfRows(),Dtemp.getNumberOfColumns());
            SS.setD((Dtemp|ZeroDireita) || (ZeroAbaixo|SS.getD()));
        }
    }
    return SS;
}

template <typename Type>
ModelHandler::StateSpace<Type> ModelHandler::tf2ssSISO(const ModelHandler::TransferFunction<Type> &TF)
{
    unsigned TFdenCols = TF(1,1).getDenSize() - 1;
    LinAlg::Matrix<Type> I = LinAlg::Eye<Type> (TFdenCols - 1);
    LinAlg::Matrix<Type> den(1, TFdenCols);
    LinAlg::Matrix<Type> ZeroVector = LinAlg::Zeros<Type> (TFdenCols - 1, 1);

    for (unsigned i = 1; i <= TFdenCols; ++i)
    {
        den(1, i) = -(TF(1,1).getDen()(1, TFdenCols + 2 - i));
    }

    LinAlg::Matrix<Type> A = (ZeroVector|I)||den;
    LinAlg::Matrix<Type> B = LinAlg::Zeros<Type>(A.getNumberOfRows() - 1, 1)||LinAlg::Matrix<Type>(1);

    LinAlg::Matrix<Type> D(1,1);
    if(TF(1,1).getNumSize() == TF(1,1).getDenSize())
        D(1,1) = TF(1,1).getNum()(1,1);

    LinAlg::Matrix<Type> C = LinAlg::Zeros<Type>(1, A.getNumberOfColumns());
    for(unsigned i = 1; i <= TF(1,1).getNumSize(); ++i)
        C(1,i) = TF(1,1).getNum()(1, TF(1,1).getNumSize() - i + 1);

    for (unsigned i = 1; i <= A.getNumberOfColumns(); ++i)
        C(1,i) = C(1,i) - (TF(1,1).getDen()(1, TFdenCols + 2 - i))* D(1,1);


    if(!TF.isContinuous())
    {
        return ModelHandler::StateSpace<Type>(A,B,C,D,TF.getSampleTime());
    }

    return ModelHandler::StateSpace<Type>(A,B,C,D);
}
