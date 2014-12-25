#include "arx.h"

template <class UsedType>
ARX<UsedType>::ARX()
{
}

//template <class UsedType>
//void Sim<UsedType>::SetArmaxOneStep()
//{
//    this->LinSysOneStep.zeros(1, this->nInPut*this->InPut.getCols() + this->nOutPut*this->OutPut.getCols() + this->nError);

//    int cont = 1;
//    for(int i = 1; i <= this->OutPut.getCols(); i++)
//    {
//        for(int j = 1; j <= this->nOutPut; j++)
//        {
//            this->LinSysOneStep.add(1, cont, -this->EstOutPut(this->nSample - j, i));
//            cont++;
//        }
//    }
//    for(int i = 1; i <= this->InPut.getCols(); i++)
//    {
//        for(int j = 1; j <= this->nInPut; j++)
//        {
//            this->LinSysOneStep.add(1, cont, this->InPut(this->nSample - j, i));
//            cont++;
//        }
//    }
//}

//template class TransferFunction<int>;
template class ARX<float>;
template class ARX<double>;
