#include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/modelLibs/conversions.h"

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols)
{
    this->var            = 's';
    this->sampleTime     = 0.1;
    this->Continuous     = 1;
    this->timeSimulation = 10;

    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);

    this->TF(1,1)        = PolynomHandler::Polynom<Type>(numPol,denPol);
    this->var            = 's';
    this->Continuous     = 1;
    this->sampleTime     = 0.1;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);

    this->TF(1,1)        = TFSISO;
    this->var            = 's';
    this->sampleTime     = 0.1;
    this->Continuous   = 1;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF)
{
    this->TF = TF;
    this->var            = 's';
    this->sampleTime     = 0.1;
    this->Continuous   = 1;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols, double sampleTime)
{
    this->var            = 'z';
    this->sampleTime     = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;

    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const LinAlg::Matrix<Type> &numPol, const LinAlg::Matrix<Type> &denPol, double sampleTime)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);

    this->TF(1,1)        = PolynomHandler::Polynom<Type>(numPol,denPol);
    this->var            = 'z';
    this->Continuous     = 0;
    this->sampleTime     = sampleTime;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO, double sampleTime)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);

    this->TF(1,1)        = TFSISO;
    this->var            = 'z';
    this->sampleTime     = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF, double sampleTime)
{
    this->TF = TF;
    this->var            = 'z';
    this->sampleTime     = sampleTime;
    this->Continuous     = 0;
    this->timeSimulation = 10;
}

template <typename Type>
bool ModelHandler::TransferFunction<Type>::isContinuous() const
{
    return this->Continuous;
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfRows() const
{
    return this->TF.getNumberOfRows();
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfColumns() const
{
    return this->TF.getNumberOfColumns();
}

template <typename Type>
double ModelHandler::TransferFunction<Type>::getSampleTime() const
{
    return this->sampleTime;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setContinuous(const bool &continuous)
{
    if(continuous)
        this->var = 's';
    else
        this->var = 'z';

    this->Continuous = continuous;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setSampleTime(const double &sampleTime)
{
    this->sampleTime = sampleTime;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

//template <typename Type>
//void ModelHandler::TransferFunction<Type>::c2d(Type sampleTime)
//{
//    this->sampleTime = sampleTime;
//    this->c2dConversion();
//    this->isContinuous = false;
//}


template <typename Type>
PolynomHandler::Polynom<Type>& ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column)
{
    return this->TF(row, column);
}

template <typename Type>
PolynomHandler::Polynom<Type> ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column) const
{
    return this->TF(row, column);
}


template <typename Type>
void ModelHandler::TransferFunction<Type>::operator= (const PolynomHandler::Polynom<Type> &rhs)
{
    this->TF(1,1) = rhs;
}

template <typename Type>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<Type>& otherTransferFunction)
{
    this->TF = otherTransferFunction.TF;

    this->sampleTime     = otherTransferFunction.sampleTime;
    this->Continuous   = otherTransferFunction.Continuous;
    this->timeSimulation = otherTransferFunction.timeSimulation;
    this->var = otherTransferFunction.var;

    return *this;
}

template <typename Type> template<typename OtherTransferFunctionType>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction)
{
    this->TF = otherTransferFunction.TF;

    this->sampleTime     = otherTransferFunction.sampleTime;
    this->isContinuous   = otherTransferFunction.isContinuous;
    this->timeSimulation = otherTransferFunction.timeSimulation;
    this->var = otherTransferFunction.var;

    return *this;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::print()
{    
    unsigned rows = this->TF.getNumberOfRows(), columns = this->TF.getNumberOfColumns();
    std::string polyNum[rows][columns];
    std::string polyDen[rows][columns];
    std::string numSpace[rows][columns], denSpace[rows][columns], midLine[rows][columns];
    unsigned maxSize[rows][columns];
    std::string output;
    for(unsigned i = 1; i <= rows; ++i)
    {
        for(unsigned j = 1; j <= columns; ++j)
            polyNum[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getNum(),this->var);

        for(unsigned j = 1; j <= columns; ++j)
            polyDen[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getDen(),this->var);

        for(unsigned j = 0; j < columns; ++j)
        {
            maxSize[i-1][j] = polyNum[i-1][j].length();
            if(maxSize[i-1][j] < polyDen[i-1][j].length())
                maxSize[i-1][j] = polyDen[i-1][j].length();
            maxSize[i-1][j] += 6;

            for(unsigned k = 0; k < unsigned(abs((maxSize[i-1][j] - polyNum[i-1][j].length())/2)); ++k)
                numSpace[i-1][j] += ' ';
            for(unsigned k = 0; k < maxSize[i-1][j]; ++k)
                midLine[i-1][j] += '-';
            for(unsigned k = 0; k < unsigned(abs((maxSize[i-1][j] - polyDen[i-1][j].length())/2)); ++k)
                denSpace[i-1][j] += ' ';
        }

        for(unsigned j = 0; j < columns; ++j)
            output += numSpace[i-1][j] + polyNum[i-1][j] + numSpace[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += midLine[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += denSpace[i-1][j] + polyDen[i-1][j] + denSpace[i-1][j] + "      ";
        output += '\n'; output += '\n';
    }

    return output;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::ContinuosFirstOrderCaracteristics()
{
    std::ostringstream str;
    Type tau;
    if(this->TF.getNumberOfRows() == 1 && this->TF.getNumberOfColumns() == 1 && this->Continuous){
       PolynomHandler::Polynom<Type> poly = this->TF(1,1);
       if(poly.getNumSize() == 1 && poly.getDenSize() == 2){
            str << "O ganho estatico e: " << poly.getNum()(1,poly.getNumSize()) / poly.getDen()(1,poly.getDenSize()) << std::endl;
            tau = poly.getDen()(1,poly.getDenSize()-1) / poly.getDen()(1,poly.getDenSize());
            str << "A constante de tempo e: " << tau << std::endl;
            str << "Tempo de subida e: " << 2.2*tau << std::endl;
            str << "Tempo de estabilizacao e: " << 3.9*tau << std::endl;
       }
    }
    std::string ret = str.str();
    return ret;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::ContinuosSecondOrderCaracteristics()
{
    std::ostringstream str;
    Type k, wn, qsi;
    if(this->TF.getNumberOfRows() == 1 && this->TF.getNumberOfColumns() == 1 && this->Continuous){
       PolynomHandler::Polynom<Type> poly = this->TF(1,1);
       if(poly.getNumSize() == 1 && poly.getDenSize() == 3){

            wn = sqrt(fabs(poly.getDen()(1,poly.getDenSize())));
            qsi = poly.getDen()(1,poly.getDenSize()-1) / (wn * 2);
            k = poly.getNum()(1,poly.getNumSize()) / (wn * wn);

            str << "O ganho estatico e: " << k << std::endl;
//            str << "A constante de tempo e: " << tau << std::endl;
            str << "Tempo de subida e: " << 2.1/wn << std::endl;
            str << "Tempo de estabilizacao a 2% e: " << 4/(qsi*wn) << std::endl;
            str << "Tempo de estabilizacao a 5% e: " << 3/(qsi*wn) << std::endl;
            str << "Sobressinal Maximo: " << exp(-qsi * M_PI / sqrt(1 - qsi * qsi)) << std::endl;
            if(qsi > 0 && qsi < 1)
                str << "Tempo de Pico e: " << M_PI / (wn * sqrt(1 - qsi * qsi)) << std::endl;
       }
    }
    std::string ret = str.str();
    return ret;
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x)
{
//    ModelHandler::StateSpace<Type> SS = ModelHandler::tf2ss(*this);
//    SS.setInitialState(state);
//    x = SS.sim(x);
//    state = SS.getActualState();

    return x;
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x, Type y)
{
    return x + y;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x)
{
//    ModelHandler::StateSpace<Type> SS = ModelHandler::tf2ss(*this);

//    return SS.sim(x);
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y)
{
    return x + y;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(Type lsim, Type lmax, Type step)
{
    return lsim+lmax+step;
}

//template <typename Type>// Passou a fazer parte de Conversions
//void ModelHandler::TransferFunction<Type>::c2dConversion()
//{
//    ModelHandler::StateSpace<Type> SS = ModelHandler::tf2ss(*this);
//    SS.c2d(this->sampleTime);
//    this->var = 'z';
//    *this = ModelHandler::ss2tf(SS);
//}


template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF)
{
    if(TF.isContinuous())
    {
        output << "The continuous transfer function is:\n\n";
        output << TF.print();
    }
    else
    {
        output << "The discrete transfer function is:\n\n";
        output << TF.print() << "\n";
        output << "The sample time is: " << TF.getSampleTime();
    }
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::TransferFunction<Type> TF)
{
    std::stringstream ss;
    ss << TF;
    output += ss.str();
    return output;
}
