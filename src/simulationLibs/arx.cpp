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
    this->Output.zeros(nOutputpar,qdtOutputVar);
    this->EstOutput = this->Output;
    this->nSample = delay + maxnInOut + 1;
}

template <class UsedType>
void ARX<UsedType>::setLinearVectorPhiEstimation()
{
    unsigned cont = 1;
    for(unsigned i = 1; i <= this->qdtOutputVar; i++)
    {
        for(unsigned j = 1; j <= this->nOutputpar; j++)
        {
            this->LinearVectorPhi(1, cont, -this->EstOutput(this->nSample - j, i));
            cont++;
        }
    }
    for(unsigned i = 1; i <= this->qdtInputVar; i++)
    {
        for(unsigned j = 1; j <= this->nInputpar; j++)
        {
            this->LinearVectorPhi(1, cont, this->Input(this->nSample - j - delay, i));
            cont++;
        }
    }
}

template <class UsedType>
void ARX<UsedType>::setLinearVectorPhi()
{
    unsigned cont = 1;
    for(unsigned i = 1; i <= this->qdtOutputVar; i++)
    {
        for(unsigned j = 1; j <= this->nOutputpar; j++)
        {
            this->LinearVectorPhi(1, cont, -this->Output(this->nSample - j, i));
            cont++;
        }
    }
    for(unsigned i = 1; i <= this->qdtInputVar; i++)
    {
        for(unsigned j = 1; j <= this->nInputpar; j++)
        {
            this->LinearVectorPhi(1, cont, this->Input(this->nSample - j - delay, i));
            cont++;
        }
    }
}

template <class UsedType>
void ARX<UsedType>::setLinearModel(Matrix<UsedType> Input,
                                   Matrix<UsedType> Output)
{
    this->Input  = this->Input||Input;
    this->Output = this->Output||Output;
    for(nSample = delay + maxnInOut + 1; nSample <= this->Output.getRows(); nSample++)
    {
//        if(nSample == delay + maxnInOut + 1)
//        {
//            this->LinearVectorPhi.zeros(1, nInputpar*this->Input.getCols() + nOutputpar*this->Output.getCols());
//            this->LinearMatrixA   = this->LinearVectorPhi;
//            this->LinearEqualityB = this->Output.getLine(nSample);
//        }
//        else
//        {
            this->setLinearVectorPhi();
            this->LinearMatrixA = this->LinearMatrixA || this->LinearVectorPhi;
            this->LinearEqualityB = this->LinearEqualityB || this->Output.getLine(nSample);
//        }
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
UsedType ARX<UsedType>::sim(UsedType input, UsedType output)
{
    if(nSample == delay + maxnInOut + 1)
    {
        this->LinearVectorPhi.zeros(1, nInputpar*this->Input.getCols() + nOutputpar*this->Output.getCols());
    }

    this->input = input;
    this->Input(nSample-1,1,input);
    this->Output(nSample-1,1,output);
    this->setLinearVectorPhi();
    nSample++;

    return (this->LinearVectorPhi*this->ModelCoef)(1,1);
}

template <class UsedType>
void ARX<UsedType>::print()
{

}

template <class UsedType>
Matrix<UsedType> ARX<UsedType>::sim(Matrix<UsedType> Input)
{
    Matrix<UsedType> y;
    this->Input.zeros (nInputpar, qdtInputVar);
    this->Input = this->Input||Input;
    this->nSample = this->delay + this->maxnInOut + 1;
    this->LinearVectorPhi.zeros(1, nInputpar*this->Input.getCols() + nOutputpar*this->Output.getCols());

    while(nSample <= this->Input.getRows())
    {
        this->setLinearVectorPhiEstimation();
        this->EstOutput.setLine(this->nSample,(this->LinearVectorPhi*this->ModelCoef));
        y = y||(this->LinearVectorPhi*this->ModelCoef);
        this->nSample++;

    }
    this->Input = Input;
    return y;
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
