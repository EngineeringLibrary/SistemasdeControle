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
    this->OutputLinearVector = LinAlg::Zeros<UsedType>(this->qdtOutputVar, this->delay + this->nOutputpar);
    this->InputLinearVector  = LinAlg::Zeros<UsedType>(this->qdtInputVar, this->nInputpar);
}
// Nesta função será avaliada a quantidade de saídas pelo número de linhas das matrizes
// Neste caso Input e Output se forem escalares corresponderão ao próximo valor
// a ser colocado no vetor de saídas ou entradas e sor uma matriz corresponderá
// a um conjunto de variáveis no instante de tempo pedido
template <class UsedType>
void ARX<UsedType>::setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> PastOutput)
{
    if(1 < this->nInputpar)
        this->InputLinearVector =  Input | this->InputLinearVector(from(1) --> this->qdtInputVar, from(1) --> this->nInputpar - 1);
    else
        this->InputLinearVector =  Input;

    if(1 < this->nOutputpar)
        this->OutputLinearVector =  PastOutput | this->OutputLinearVector(from(1) --> this->qdtOutputVar, from(1) --> this->nOutputpar + this->delay - 1);
    else
        this->OutputLinearVector =  PastOutput;

    LinAlg::Matrix<UsedType> TempLinearVector;

    for(unsigned i = 1; i <= PastOutput.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | -this->OutputLinearVector(i, from(1 + this->delay) --> this->delay + this->nOutputpar);

    for(unsigned i = 1; i <= Input.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | this->InputLinearVector(i, from(1) --> this->nInputpar);

    this->LinearVectorA = TempLinearVector;
}

template <class UsedType>
void ARX<UsedType>::setLinearModel(LinAlg::Matrix<UsedType> Input,
                                   LinAlg::Matrix<UsedType> Output)
{
    this->Input = Input;
    this->Output = Output;

    for(nSample = 1; nSample <= this->Output.getNumberOfColumns(); ++nSample)
    {
        this->setLinearVector(Input(from(1) --> this->qdtInputVar, nSample), Output(from(1) --> this->qdtOutputVar, nSample));
        this->LinearMatrixA = this->LinearMatrixA || this->LinearVectorA;
        this->LinearEqualityB = this->LinearEqualityB || Output(from(1) --> this->qdtOutputVar, nSample+1);
    }
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType input)
{
    this->setLinearVector(input, this->output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <class UsedType>
UsedType ARX<UsedType>::sim(UsedType input, UsedType output)
{
    this->setLinearVector(input, output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <class UsedType>
void ARX<UsedType>::print()
{

}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(LinAlg::Matrix<UsedType> Input)
{
    this->Input  = Input;
    LinAlg::Matrix<UsedType> TempOutput = LinAlg::Zeros<UsedType>(1, this->qdtOutputVar);

    for(unsigned i = 1; i < Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input(from(1) --> Input.getNumberOfRows(), i),TempOutput);
        TempOutput = this->LinearVectorA*this->ModelCoef;
        this->Output = this->Output | TempOutput;
    }
    return this->Output;
}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{
    this->Input  = Input;
    this->Output = LinAlg::Zeros<UsedType>(1, this->qdtOutputVar);

    for(unsigned i = 1; i < Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input(from(1) --> Input.getNumberOfRows(), i), Output(from(1) --> Output.getNumberOfRows(), i));
        this->Output = this->Output | this->LinearVectorA*this->ModelCoef;
    }
    return this->Output;
}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{
    return 0.0;
}

//template class TransferFunction<int>;
template class ARX<float>;
template class ARX<double>;
