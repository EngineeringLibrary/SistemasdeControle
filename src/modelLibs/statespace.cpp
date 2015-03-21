#include "SistemasdeControle/headers/modelLibs/statespace.h"

template <class UsedType>
void StateSpace<UsedType>::c2dConversion()
{
    this->Ad = LinAlg::Zeros<UsedType>(this->A.getNumberOfRows(), this->A.getNumberOfColumns());
    for(int i = 0; i < nDiscretization; i++)
        Ad = Ad + (1/factorial(i))*(A^i)*(pow(SampleTime, i));
    Bd = (A^-1)*(Ad - (Ad^0))*B;
}

template <class UsedType>
void StateSpace<UsedType>::d2cConversion()
{
    LinAlg::Matrix<UsedType> Mat, E, Temp, Root, I, ZeroVector, IAd;

    Mat = LinAlg::EigenValues(Ad);
    IAd = LinAlg::Eye<UsedType> (Ad.getNumberOfRows());
    for(int j = 1; j < nDiscretization; j++)
        E( 1, j + 1) = pow(this->SampleTime, j)/factorial(j);

    I = LinAlg::Eye<UsedType> (E.getNumberOfColumns()-2);
    ZeroVector = LinAlg::Zeros<UsedType> ( E.getNumberOfColumns()-2, 1);

    for (unsigned i = 0; i < Mat.getNumberOfRows(); i++)
    {
        E( 1, 1) = 1 - Mat(1, i+1);
        Temp = E||(I|ZeroVector);
        Root = LinAlg::EigenValues(Temp);
//        UsedType autovalor = max(abs(Root));
//        A( i+1, i+1) = autovalor;
    }
    B = (((A^-1)*(Ad - IAd))^-1)*Bd;
}

template <class UsedType>
StateSpace<UsedType>::StateSpace(LinAlg::Matrix<UsedType> A, LinAlg::Matrix<UsedType> B,
                                 LinAlg::Matrix<UsedType> C, LinAlg::Matrix<UsedType> D)
{
    this->A                  =    A;
    this->B                  =    B;
    this->C                  =    C;
    this->D                  =    D;
    this->Continuous         = true;
    this->SampleTime         =  0.1;
    this->TimeSimulation     =   10;
    this->nDiscretization    =    4;

    this->initialState = LinAlg::Zeros<UsedType> (A.getNumberOfRows(),B.getNumberOfColumns());
    this->X = this->initialState;
}

template <class UsedType>
StateSpace<UsedType>::StateSpace(LinAlg::Matrix<UsedType> Ad, LinAlg::Matrix<UsedType> Bd,
                                 LinAlg::Matrix<UsedType> C , LinAlg::Matrix<UsedType> D ,
                                 UsedType SampleTime)
{
    this->Ad                 =    Ad;
    this->Bd                 =    Bd;
    this->C                  =    C;
    this->D                  =    D;
    this->Continuous         = false;
    this->SampleTime         = SampleTime;
    this->TimeSimulation     =   10;
    this->nDiscretization    =    4;

    this->initialState = LinAlg::Zeros<UsedType>(Ad.getNumberOfRows(),Bd.getNumberOfColumns());
    this->X = this->initialState;
}

template <class UsedType>
void StateSpace<UsedType>::c2d(UsedType SampleTime)
{
    this->SampleTime = SampleTime;
    this->c2dConversion();
    this->Continuous = false;
}

template <class UsedType>
void StateSpace<UsedType>::print()
{
    if(this->Continuous == true){
        std::cout << "The Continuous Model is: " << std::endl;
        std::cout << std::endl << "A = " << std::endl << A << std::endl;
        std::cout << std::endl << "B = " << std::endl << B << std::endl;

    }else{
        std::cout << "The Discrete Model is: " << std::endl;
        std::cout << std::endl << "A = " << std::endl << Ad << std::endl;
        std::cout << std::endl << "B = " << std::endl << Bd << std::endl;
    }

    std::cout << std::endl << "C = "<< std::endl << C << std::endl;
    std::cout << std::endl << "D = "<< std::endl << D << std::endl;
}

template <class UsedType>
void StateSpace<UsedType>::setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{

}

template <class UsedType>
void StateSpace<UsedType>::setLinearVectorPhi()
{

}

template <class UsedType>
void StateSpace<UsedType>::setLinearVectorPhiEstimation()
{

}


template <class UsedType>
void StateSpace<UsedType>::setInitialState(LinAlg::Matrix<UsedType> X0)
{
    this->initialState = X0;
    this->X = X0;
}

template <class UsedType>
UsedType StateSpace<UsedType>::sim(UsedType u)
{
    if(this->Continuous)
        this->c2dConversion();

    X = initialState;
    LinAlg::Matrix<UsedType> Xi1 = Ad*X+Bd*u;
    LinAlg::Matrix<UsedType> y  = C*X+D*u;
    X = Xi1;

    return y(1,1);
}

template <class UsedType>
UsedType StateSpace<UsedType>::sim(UsedType u, UsedType y)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::sim(LinAlg::Matrix<UsedType> u)
{
    if(this->Continuous)
        this->c2dConversion();

    LinAlg::Matrix<UsedType> y;
    X = initialState;
    for(unsigned i = 0; i < u.getNumberOfColumns(); i++)
    {
        LinAlg::Matrix<UsedType> Xi1 = Ad*X+Bd*u.GetColumn(i+1);
        y = y|(C*X + D*u.GetColumn(i+1));
        X = Xi1;
    }

    return y;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::sim(LinAlg::Matrix<UsedType> u, LinAlg::Matrix<UsedType> y)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::sim(UsedType lmim, UsedType lmax, UsedType step)
{
    if(this->Continuous)
        this->c2dConversion();

    LinAlg::Matrix<UsedType> y;
    X = initialState;
    unsigned cont = 1;
    for(UsedType i = lmim; i <= lmax; i+= step)
    {
        LinAlg::Matrix<UsedType> Xi1 = Ad*X+Bd*i;
        y = y|(C*X+D*i);
        X = Xi1;
        cont++;
    }

    return y;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::getA()
{
    if(this->Continuous)
        return this->A;
    else
        return this->Ad;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::getB()
{
    if(this->Continuous)
        return this->B;
    else
        return this->Bd;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::getC()
{
    return this->C;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::getD()
{
    return this->D;
}

template <class UsedType>
LinAlg::Matrix<UsedType> StateSpace<UsedType>::getActualState()
{
    return X;
}

template <class UsedType>
UsedType StateSpace<UsedType>::factorial(unsigned n)
{
    UsedType retval = 1;

    for (int i = n; i > 1; --i)
        retval *= i;

    return retval;
}

template class StateSpace<float>;
template class StateSpace<double>;
