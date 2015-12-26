#include "SistemasdeControle/headers/modelLibs/fir.h"

template <class UsedType>
FIR<UsedType>::FIR(unsigned nUpar, unsigned delay, unsigned qdtVar)
{
    this->nUpar  = nUpar;
    this->delay  = delay;
    this->qdtVar = qdtVar;
    this->cont   = nUpar+delay;
    this->Input  = LinAlg::Zeros<UsedType>(qdtVar,1000);
}

//template <class UsedType>
//void FIR<UsedType>::setOneStepLinSys(UsedType input)
//{
//    this->Input(1,cont) = input;
//    unsigned cont2 = 1;

//    for(unsigned j = cont - delay - 1; j >= cont-nUpar; j--)
//    {
//        this->LinearVectorA(1,cont2) = this->Input(1, j);
//    }
//}

template <class UsedType>
void FIR<UsedType>::setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{

}

template <class UsedType>
void FIR<UsedType>::setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{

}

template <class UsedType>
void FIR<UsedType>::print()
{

}

template <class UsedType>
UsedType FIR<UsedType>::sim(UsedType input)
{
    return (this->LinearVectorA*this->ModelCoef)(1,1);
}

template <class UsedType>
UsedType FIR<UsedType>::sim(UsedType x, UsedType y)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> FIR<UsedType>::sim(LinAlg::Matrix<UsedType> x)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> FIR<UsedType>::sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> FIR<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{

}

//template class TransferFunction<int>;
template class FIR<float>;
template class FIR<double>;
