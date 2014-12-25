#include "fir.h"

template <class UsedType>
FIR<UsedType>::FIR(unsigned nUpar, unsigned delay, unsigned qdtVar)
{
    this->nUpar  = nUpar;
    this->delay  = delay;
    this->qdtVar = qdtVar;
    this->cont   = nUpar+delay;
    this->U.zeros(qdtVar,1000);
}

template <class UsedType>
void FIR<UsedType>::setSysPar(Matrix<UsedType> SysPar)
{
    this->SysPar = SysPar;
}

template <class UsedType>
void FIR<UsedType>::setOneStepLinSys(UsedType input)
{
    U(1,cont,input);
    unsigned cont2 = 1;

    for(unsigned j = cont - delay - 1; j >= cont-nUpar; j--)
    {
        OneStepLinSys(1,cont2,U(1, j));
    }
}


template <class UsedType>
UsedType FIR<UsedType>::sim(UsedType input)
{
    return (this->OneStepLinSys*this->SysPar)(1,1);
}

//template class TransferFunction<int>;
template class FIR<float>;
template class FIR<double>;
