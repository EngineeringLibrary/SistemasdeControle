#include "arx.h"

template <class UsedType>
ARX<UsedType>::ARX(unsigned nInputpar , unsigned nOutputpar,
                   unsigned delay,
                   unsigned qdtInputVar, unsigned qdtOutputVar)
{
    this->maxnInOut    = nInputpar;
    if( nOutputpar > nInputpar)
        this->maxnInOut    = nOutputpar;

    this->nInputpar    = nInputpar;
    this->qdtInputVar  = qdtInputVar;
    this->nOutputpar   = nOutputpar;
    this->qdtOutputVar = qdtOutputVar;
    this->delay        = delay;

    this->Input.zeros (nInputpar, qdtInputVar);
    this->EstOutput = this->Input;
    this->Output.zeros(nOutputpar,qdtOutputVar);
    this->nSample = delay + maxnInOut + 1;
}

template <class UsedType>
void ARX<UsedType>::setLinearVectorPhiEstimation()
{
    unsigned cont = 1;
    for(unsigned i = 1; i <= this->Output.getCols(); i++)
    {
        for(unsigned j = 1; j <= this->nOutputpar; j++)
        {
            this->LinearVectorPhi(1, cont, -this->EstOutput(this->nSample - j, i));
            cont++;
        }
    }
    for(unsigned i = 1; i <= this->Input.getCols(); i++)
    {
        for(unsigned j = 1; j <= this->nInputpar; j++)
        {
            this->LinearVectorPhi(1, cont, this->Input(this->nSample - j - delay, i));
            cont++;
        }
    }
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType input)
{
    if(nSample == delay + maxnInOut + 1)
    {
        this->LinearVectorPhi.zeros(1, nInputpar*this->Input.getCols() + nOutputpar*this->Output.getCols());
//        this->Input.ones(nInputpar,this->qdtInputVar);
//        this->Input = this->Input*input;
    }

    this->Input(nSample-1,1,input);
    this->setLinearVectorPhiEstimation();

    this->EstOutput(nSample,1,(this->LinearVectorPhi*this->ModelCoef)(1,1));
    nSample++;

    return this->EstOutput(nSample-1,1);
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType x, UsedType y)
{

}

template <class UsedType>
Matrix<UsedType> ARX<UsedType>::sim(Matrix<UsedType> x)
{

}

template <class UsedType>
Matrix<UsedType> ARX<UsedType>::sim(Matrix<UsedType> x, Matrix<UsedType> y)
{

}

template <class UsedType>
Matrix<UsedType> ARX<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
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
