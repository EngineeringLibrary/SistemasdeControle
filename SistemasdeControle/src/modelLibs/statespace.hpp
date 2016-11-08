#include "SistemasdeControle/headers/modelLibs/statespace.h"

template <typename Type>
ModelHandler::StateSpace<Type>::StateSpace(LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> B,
                                 LinAlg::Matrix<Type> C, LinAlg::Matrix<Type> D)
{
    this->A                  =    A;
    this->B                  =    B;
    this->C                  =    C;
    this->D                  =    D;
    this->Continuous         = true;
    this->SampleTime         =  0.1;
    this->TimeSimulation     =   10;
    this->nDiscretization    =    6;
    this->firstTimeKalmanObserver = 0;

    this->initialState = LinAlg::Zeros<Type> (A.getNumberOfRows(),1);
    this->X = this->initialState;
}

template <typename Type>
ModelHandler::StateSpace<Type>::StateSpace(LinAlg::Matrix<Type> Ad, LinAlg::Matrix<Type> Bd,
                                 LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D ,
                                 Type SampleTime)
{
    this->Ad                 =    Ad;
    this->Bd                 =    Bd;
    this->C                  =    C;
    this->D                  =    D;
    this->Continuous         = false;
    this->SampleTime         = SampleTime;
    this->TimeSimulation     =   10;
    this->firstTimeKalmanObserver = 0;
    this->nDiscretization    =    6;

    this->initialState = LinAlg::Zeros<Type>(Ad.getNumberOfRows(),1);
    this->X = this->initialState;
}
template <typename Type>
ModelHandler::StateSpace<Type>& ModelHandler::StateSpace<Type>::operator= (const ModelHandler::StateSpace<Type>& otherStateSpaceFunction)
{
    this->A  = otherStateSpaceFunction.A;
    this->B  = otherStateSpaceFunction.B;
    this->C  = otherStateSpaceFunction.C;
    this->D  = otherStateSpaceFunction.D;
    this->X  = otherStateSpaceFunction.X;
    this->L  = otherStateSpaceFunction.L;
    this->Ad = otherStateSpaceFunction.Ad;
    this->Bd = otherStateSpaceFunction.Bd;
    this->P = otherStateSpaceFunction.P;
    this->firstTimeKalmanObserver = 0;

    this->Continuous   = otherStateSpaceFunction.Continuous;
    this->SampleTime   = otherStateSpaceFunction.SampleTime;
    this->initialState = otherStateSpaceFunction.initialState;

    this->TimeSimulation  = otherStateSpaceFunction.TimeSimulation;
    this->nDiscretization = otherStateSpaceFunction.nDiscretization;

    return *this;
}

template <typename Type>
bool ModelHandler::StateSpace<Type>::isContinuous() const
{
    return this->Continuous;
}

template <typename Type>
double ModelHandler::StateSpace<Type>::getSampleTime() const
{
    return this->SampleTime;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::getA() const
{
    if(this->Continuous)
        return this->A;
    else
        return this->Ad;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::getB() const
{
    if(this->Continuous)
        return this->B;
    else
        return this->Bd;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::getC() const
{
    return this->C;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::getD() const
{
    return this->D;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::getActualState() const
{
    return X;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setA(LinAlg::Matrix<Type> A)
{
    this->A = A;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setB(LinAlg::Matrix<Type> B)
{
    this->B = B;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setC(LinAlg::Matrix<Type> C)
{
    this->C = C;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setD(LinAlg::Matrix<Type> D)
{
    this->D = D;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setSampleTime(double SampleTime)
{
    this->SampleTime = SampleTime;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setContinuous(bool Continuous)
{
    this->Continuous = Continuous;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setInitialState(LinAlg::Matrix<Type> X0)
{
    this->initialState = X0;
    this->X = X0;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

template <typename Type>
void ModelHandler::StateSpace<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

template <typename Type>
void ModelHandler::StateSpace<Type>::SetObserverParameter(LinAlg::Matrix<Type> L)
{
    this->L = L;
}

template <typename Type>
bool ModelHandler::StateSpace<Type>::isObservable() const
{
    LinAlg::Matrix<Type> Qo;
    if(this->Continuous)
        for (unsigned i = 0; i < A.getNumberOfColumns(); ++i)
            Qo = Qo||(C*(A^i));
    else
        for (unsigned i = 0; i < Ad.getNumberOfColumns(); ++i)
            Qo = Qo||(C*(Ad^i));

//    std::cout << Qo;
    return (LinAlg::Determinant(Qo) != 0);
}

template <typename Type>
bool ModelHandler::StateSpace<Type>::isControlable() const
{
    LinAlg::Matrix<Type> Qc;
    if(this->Continuous)
        for (unsigned i = 0; i < A.getNumberOfColumns(); ++i)
            Qc = Qc|((A^i)*B);
    else
        for (unsigned i = 0; i < Ad.getNumberOfColumns(); ++i)
            Qc = Qc|((Ad^i)*Bd);

//    std::cout << (B) << ((A)*B) << Qc;
    return (LinAlg::Determinant(Qc) != 0);
}

template <typename Type>
Type ModelHandler::StateSpace<Type>::sim(Type u)
{
    if(this->Continuous)
        this->c2dConversion();

//    X = initialState;
    LinAlg::Matrix<Type> Xi1 = Ad*X+Bd*u;
    LinAlg::Matrix<Type> y  = C*X+D*u;
    X = Xi1;

    return y(1,1);
}

template <typename Type>
Type ModelHandler::StateSpace<Type>::sim(Type u, Type y)
{
    y = u;
    u = y;
    return 0;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::sim(LinAlg::Matrix<Type> u)
{
    if(this->Continuous)
        this->c2dConversion();

    LinAlg::Matrix<Type> y;
//    if()
//    X = initialState;
    for(unsigned i = 0; i < u.getNumberOfColumns(); ++i)
    {
        LinAlg::Matrix<Type> Xi1 = Ad*X+Bd*u.GetColumn(i+1);
        y = y|(C*X + D*u.GetColumn(i+1));
        X = Xi1;
//        std::cout << X << std::endl;
    }

    return y;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::sim(LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y)
{
    u = y;
    return LinAlg::Matrix<Type>(0.0);
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::sim(Type lmin, Type lmax, Type step)
{
    if(this->Continuous)
        this->c2dConversion();

    LinAlg::Matrix<Type> y;
    X = initialState;
    unsigned cont = 1;
    for(Type i = lmin; i <= lmax; i+= step)
    {
        LinAlg::Matrix<Type> Xi1 = Ad*X+Bd*i;
        y = y|(C*X+D*i);
        X = Xi1;
        cont++;
    }

    return y;
}

template <typename Type>
std::string ModelHandler::StateSpace<Type>::print()
{
    std::string output;

    if(this->Continuous == true){
        output += "The Continuous State Space Model is: \n\nA = \n";
        output << this->A; output += "\n\nB = \n";
        output << this->B; output += "\n\nC = \n";

    }else{
        output += "The Discrete State Space Model is: \n\nA = \n";
        output << this->Ad; output += "\n\nB = \n";
        output << this->Bd; output += "\n\nC = \n";
    }

    output << this->C; output += "\n\nD = \n";
    output << this->D; output += '\n';

    return output;
}

template <typename Type>
Type ModelHandler::StateSpace<Type>::factorial(unsigned n)
{
    Type retval = 1;

    for (int i = n; i > 1; --i)
        retval *= i;

    return retval;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::c2dConversion()
{
//Pade
//    unsigned Nsize = nDiscretization, Dsize = nDiscretization;
//    LinAlg::Matrix<Type> Npq = LinAlg::Zeros<Type>(this->A.getNumberOfRows(), this->A.getNumberOfColumns());
//    LinAlg::Matrix<Type> Dpq = LinAlg::Zeros<Type>(this->A.getNumberOfRows(), this->A.getNumberOfColumns());
//
//    unsigned factor =  (unsigned)(LinAlg::max(LinAlg::abs(LinAlg::EigenValues(A))));
//
//    for(unsigned n = 0; n < Nsize; ++n)
//        Npq += ((factorial(Nsize + Dsize - n)*factorial(Nsize)/(factorial(Nsize + Dsize)*factorial(n)*(Nsize - n))))*((A*SampleTime/factor)^n);

//    for(unsigned n = 0; n < Dsize; ++n)
//        Dpq += ((factorial(Nsize + Dsize - n)*factorial(Dsize)/(factorial(Nsize + Dsize)*factorial(n)*(Dsize - n))))*((-A*SampleTime/factor)^n);

//    Ad = ((Dpq^-1)*Npq)^factor;

//Taylor
    this->Ad = LinAlg::Zeros<Type>(this->A.getNumberOfRows(), this->A.getNumberOfColumns());

    unsigned factor =  (unsigned)(LinAlg::max(LinAlg::abs(A)));

    //taylor
    for(unsigned i = 0; i < nDiscretization; ++i){
        Ad += (1/factorial(i))*((A*SampleTime/factor)^i);
//        std::cout << A <<"\n"<< Ad;
    }
    Ad ^= factor;
    Bd = (A^-1)*(Ad - (Ad^0))*B;
}

template <typename Type>
void ModelHandler::StateSpace<Type>::d2cConversion()
{
    LinAlg::Matrix<Type> I = LinAlg::Eye<Type> (Ad.getNumberOfRows());

    A = (Ad - I)/SampleTime;
    B = (((A^-1)*(Ad - I))^-1)*Bd;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::Observer(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y)
{
    if(this->Continuous)
        this->c2dConversion();
    LinAlg::Matrix<Type> Qo;
    for (unsigned i = 0; i < Ad.getNumberOfColumns(); ++i)
        Qo = Qo||(C*(Ad^i));
    this->L = 0.2*LinAlg::Ones<Type>(this->X.getNumberOfRows(),1);

    X = Ad*X + Bd*U + L*(Y - C*X);
    return X;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::StateSpace<Type>::KalmanFilterObserver(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y)
{
    if(this->Continuous)
        this->c2dConversion();
//    if(!firstTimeKalmanObserver)
//    P = LinAlg::Zeros<Type>(Ad.getNumberOfRows(),Ad.getNumberOfColumns());
    P = LinAlg::Eye<Type>(Ad.getNumberOfRows());
    LinAlg::Matrix<Type> Q = 10*LinAlg::Eye<Type>(Ad.getNumberOfRows());
    Type R = 1;

//    std::cout << Ad*P*(~Ad)<< std::endl
//              << Ad*P*(~C) << std::endl
//              << C*P*(~C) << std::endl
//              << ((R + C*P*(~C))^-1) << std::endl
//              << C*P*Ad <<  std::endl
//              << P << std::endl;

    for(unsigned i = 0; i < P.getNumberOfColumns(); ++i)
        P = Q + Ad*P*(~Ad) - Ad*P*(~C)*((R + C*P*(~C))^-1)*C*P*Ad;

//    std::cout << Ad*P*(~C) << std::endl
//              << C*P*(~C) << std::endl
//              << ((R + C*P*(~C))^-1) << std::endl;
    L = Ad*P*(~C)*((R + C*P*(~C))^-1);

//              std::cout << L <<  std::endl
//              << P << std::endl;

    X = ( Ad - L*C )*X + Bd*U(1,1) + L*Y(1,1);
    return X;
}

template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::StateSpace<Type> SS)
{
    output << SS.print();
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::StateSpace<Type> SS)
{
    output += SS.print();
    return output;
}

template<typename Type>
Type ModelHandler::sim(ModelHandler::StateSpace<Type> &SS, Type u)
{
    return SS.sim(u);
}

template<typename Type>
Type ModelHandler::sim(ModelHandler::StateSpace<Type> &SS, Type u, Type y)
{
    return SS.sim(u,y);
}

template<typename Type>
LinAlg::Matrix<Type> ModelHandler::sim(ModelHandler::StateSpace<Type> &SS, LinAlg::Matrix<Type> u)
{
    return SS.sim(u);
}

template<typename Type>
LinAlg::Matrix<Type> ModelHandler::sim(ModelHandler::StateSpace<Type> &SS, Type lmin, Type lmax, Type step)
{
    return SS.sim(lmin, lmax, step);
}

template<typename Type>
LinAlg::Matrix<Type> ModelHandler::sim(ModelHandler::StateSpace<Type> &SS, LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y)
{
    return SS.sim(u,y);
}
