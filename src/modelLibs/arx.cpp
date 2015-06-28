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
    this->OutputLinearVector = LinAlg::Zeros<UsedType>(this->qdtOutputVar, this->delay + this->nOutputpar + 1);
    this->InputLinearVector  = LinAlg::Zeros<UsedType>(this->qdtInputVar, this->nInputpar);
}
// Nesta função será avaliada a quantidade de saídas pelo número de linhas das matrizes
// Neste caso Input e Output se forem escalares corresponderão ao próximo valor
// a ser colocado no vetor de saídas ou entradas e sor uma matriz corresponderá
// a um conjunto de variáveis no instante de tempo pedido
template <class UsedType>
void ARX<UsedType>::setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{
    if(1 < this->nInputpar)
        this->InputLinearVector =  Input | this->InputLinearVector(from(1) --> this->qdtInputVar, from(1) --> this->nInputpar - 1);
    else
        this->InputLinearVector =  Input;

    this->OutputLinearVector =  Output | this->OutputLinearVector(from(1) --> this->qdtOutputVar, from(1) --> this->nOutputpar + this->delay);

    LinAlg::Matrix<UsedType> TempLinearVector;

    for(unsigned i = 1; i <= Output.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | -this->OutputLinearVector(i, from(2 + this->delay) --> this->delay + this->nOutputpar + 1);

    for(unsigned i = 1; i <= Input.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | this->InputLinearVector(i, from(1) --> this->nInputpar);

    this->LinearVectorA = TempLinearVector;
    this->LinearEqualityVectorB = ~Output;
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
        this->LinearEqualityB = this->LinearEqualityB || this->LinearEqualityVectorB;
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
    this->Output = LinAlg::Zeros<UsedType>(1, this->qdtOutputVar);

    for(unsigned i = 1; i <= Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input(from(1) --> Input.getNumberOfRows(), i), this->Output(from(1) --> this->Output.getNumberOfRows(), i));
        this->Output = this->Output | this->LinearVectorA*this->ModelCoef;
    }
    return this->Output;
}

template <class UsedType>
LinAlg::Matrix<UsedType> ARX<UsedType>::sim(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{
    this->Input  = Input;
    this->Output = LinAlg::Zeros<UsedType>(1, this->qdtOutputVar);

    for(unsigned i = 1; i <= Input.getNumberOfColumns(); ++i){
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
