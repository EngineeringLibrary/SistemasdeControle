#include "SistemasdeControle/headers/modelLibs/arx.h"

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

    this->Input = LinAlg::Zeros<UsedType>(nInputpar, qdtInputVar);
    this->Output = LinAlg::Zeros<UsedType>(nOutputpar,qdtOutputVar);
    this->EstOutput = this->Output;
    this->nSample = delay + maxnInOut + 1;
}

template <class UsedType>
void ARX<UsedType>::setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{
    LinAlg::Matrix<UsedType> Temp;
    this->LinearVectorA = Temp;
    from a = 2, b = 1;
    for(unsigned i = 1; i <= Output.getNumberOfRows(); ++i)
        this->LinearVectorA = this->LinearVectorA|-Output(1,a-->this->nOutputpar+1);

    for(unsigned i = 1; i <= Input.getNumberOfRows(); ++i)
            this->LinearVectorA = this->LinearVectorA|Input;

    this->LinearEqualityVectorB = ~Output(b-->Output.getNumberOfRows(),1);
}

template <class UsedType>
void ARX<UsedType>::setLinearModel(LinAlg::Matrix<UsedType> Input,
                                   LinAlg::Matrix<UsedType> Output)
{
    this->Input  = this->Input||Input;
    this->Output = this->Output||Output;
    for(nSample = delay + maxnInOut + 1; nSample <= this->Output.getNumberOfRows(); nSample++)
    {
        from sample = nSample, var = 1;
        this->setLinearVector(this->Input(var --> this->qdtInputVar, sample --> (sample - this->nInputpar)), this->Output(nSample, var-->this->nOutputpar ));
        this->LinearMatrixA = this->LinearMatrixA || this->LinearVectorA;
        this->LinearEqualityB = this->LinearEqualityB || this->LinearEqualityVectorB;
    }
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType input)
{
    if(nSample == delay + maxnInOut + 1)
    {
        //this->LinearVectorPhi = LinAlg::Zeros<UsedType>(1, nInputpar*this->Input.getNumberOfColumns() + nOutputpar*this->Output.getNumberOfColumns());
//        this->Input.ones(nInputpar,this->qdtInputVar);
//        this->Input = this->Input*input;
    }

    this->Input(nSample-1,1) = input;
    //this->setLinearVectorPhiEstimation();

    //this->EstOutput(nSample,1) = (this->LinearVectorPhi*this->ModelCoef)(1,1);
    nSample++;

    return this->EstOutput(nSample-1,1);
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType input, UsedType output)
{
    if(nSample == delay + maxnInOut + 1)
    {
        //this->LinearVectorPhi = LinAlg::Zeros<UsedType>(1, nInputpar*this->Input.getNumberOfColumns() + nOutputpar*this->Output.getNumberOfColumns());
    }

    this->input = input;
    this->Input(nSample-1,1) = input;
    this->Output(nSample-1,1) = output;
    //this->setLinearVectorPhi();
    nSample++;

    //return (this->LinearVectorPhi*this->ModelCoef)(1,1);
}

template <class UsedType>
void ARX<UsedType>::print()
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(LinAlg::Matrix<UsedType> Input)
{
    LinAlg:: Matrix<UsedType> y;
    this->Input = LinAlg::Zeros<UsedType>(nInputpar, qdtInputVar);
    this->Input = this->Input||Input;
    this->nSample = this->delay + this->maxnInOut + 1;
    //this->LinearVectorPhi = LinAlg::Zeros<UsedType>(1, nInputpar*this->Input.getNumberOfColumns() + nOutputpar*this->Output.getNumberOfColumns());

    while(nSample <= this->Input.getNumberOfRows())
    {
        //this->setLinearVectorPhiEstimation();
//        this->EstOutput.setLine(this->nSample,(this->LinearVectorPhi*this->ModelCoef));
        //y = y||(this->LinearVectorPhi*this->ModelCoef);
        this->nSample++;

    }
    this->Input = Input;
    return y;
}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y)
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{

}

//template <class UsedType>
//void Sim<UsedType>::SetArmaxOneStep()
//{
//    this->LinSysOneStep.zeros(1, this->nInPut*this->InPut.getNumberOfColumns() + this->nOutPut*this->OutPut.getNumberOfColumns() + this->nError);

//    int cont = 1;
//    for(int i = 1; i <= this->OutPut.getNumberOfColumns(); i++)
//    {
//        for(int j = 1; j <= this->nOutPut; j++)
//        {
//            this->LinSysOneStep.add(1, cont, -this->EstOutPut(this->nSample - j, i));
//            cont++;
//        }
//    }
//    for(int i = 1; i <= this->InPut.getNumberOfColumns(); i++)
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
