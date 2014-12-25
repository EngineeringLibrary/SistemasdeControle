#include "ma.h"

template <class UsedType>
MA<UsedType>::MA()
{
}

//template <class UsedType>
//void Sim<UsedType>::SetArmaxOneStep()
//{
//    this->LinSysOneStep.zeros(1, this->nInPut*this->InPut.getCols() + this->nOutPut*this->OutPut.getCols() + this->nError);

//    for(int j = 1; j <= this->nError; j++)
//    {
//        this->LinSysOneStep.add(1, cont, this->Error(this->nSample - j, 1));
//        cont++;
//    }
//}

//template class TransferFunction<int>;
template class MA<float>;
template class MA<double>;
