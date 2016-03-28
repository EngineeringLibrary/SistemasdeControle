#include "SistemasdeControle/headers/modelLibs/arx.h"

template <class Type>
ModelHandler::ARX<Type>::ARX(unsigned nInputpar , unsigned nOutputpar,
                             unsigned delay,
                             unsigned qdtInputVar, unsigned qdtOutputVar,
                             double sampleTime)
{
    this->maxnInOut    = nInputpar;
    if( nOutputpar > nInputpar)
        this->maxnInOut    = nOutputpar;

    this->nInputpar    = nInputpar;
    this->qdtInputVar  = qdtInputVar;
    this->nOutputpar   = nOutputpar;
    this->qdtOutputVar = qdtOutputVar;
    this->delay        = delay;
    this->sampleTime   = sampleTime;

    this->ModelCoef = LinAlg::Zeros<Type>(nInputpar*qdtInputVar + nOutputpar*qdtOutputVar, 1);
    this->Input = LinAlg::Zeros<Type>(qdtInputVar, nInputpar);
    this->Output = LinAlg::Zeros<Type>(qdtOutputVar, nOutputpar);
    this->EstOutput = this->Output;
    this->nSample = delay + maxnInOut + 1;
    this->OutputLinearVector = LinAlg::Zeros<Type>(this->qdtOutputVar, this->delay + this->nOutputpar);
    this->InputLinearVector  = LinAlg::Zeros<Type>(this->qdtInputVar, this->nInputpar);
}

template <class Type>
ModelHandler::ARX<Type>::ARX(const ModelHandler::ARX<Type>& OtherArxModel){
    this->delay                 = OtherArxModel.delay;
    this->EstOutput             = OtherArxModel.EstOutput;
    this->Input                 = OtherArxModel.Input;
    this->input                 = OtherArxModel.input;
    this->InputLinearVector     = OtherArxModel.InputLinearVector;
    this->instance              = OtherArxModel.instance;
    this->LinearEqualityB       = OtherArxModel.LinearEqualityB;
    this->LinearEqualityVectorB = OtherArxModel.LinearEqualityVectorB;
    this->LinearMatrixA         = OtherArxModel.LinearMatrixA;
    this->LinearVectorA         = OtherArxModel.LinearVectorA;
    this->lmax                  = OtherArxModel.lmax;
    this->lmin                  = OtherArxModel.lmin;
    this->maxnInOut             = OtherArxModel.maxnInOut;

}

// Nesta função será avaliada a quantidade de saídas pelo número de linhas das matrizes
// Neste caso Input e Output se forem escalares corresponderão ao próximo valor
// a ser colocado no vetor de saídas ou entradas e sor uma matriz corresponderá
// a um conjunto de variáveis no instante de tempo pedido
template <class Type>
void ModelHandler::ARX<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> PastOutput)
{
    this->InputLinearVector  =  Input     |this->InputLinearVector (from(1)-->this->qdtInputVar, from(1)-->this->nInputpar -1);
    this->OutputLinearVector =  PastOutput|this->OutputLinearVector(from(1)-->this->qdtOutputVar,from(1)-->this->nOutputpar-1);

    LinAlg::Matrix<Type> TempLinearVector;//, TotalLinearVector;

    for(unsigned i = 1; i <= PastOutput.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | -this->OutputLinearVector(i, from(1 + this->delay) --> this->delay + this->nOutputpar);

    for(unsigned i = 1; i <= Input.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | this->InputLinearVector(i, from(1) --> this->nInputpar);

//    for(unsigned i = 1; i <= PastOutput.getNumberOfRows(); ++i)
//        TotalLinearVector = TotalLinearVector||TempLinearVector;

    this->LinearVectorA = TempLinearVector;
}

template <class Type>
void ModelHandler::ARX<Type>::setLinearModel(LinAlg::Matrix<Type> Input,
                                   LinAlg::Matrix<Type> Output)
{
    this->Input = Input;
    this->Output = Output;

    for(nSample = 1; nSample < this->Output.getNumberOfColumns(); ++nSample)
    {
        this->setLinearVector(Input(from(1) --> this->qdtInputVar, nSample), Output(from(1) --> this->qdtOutputVar, nSample));
        this->LinearMatrixA = this->LinearMatrixA || this->LinearVectorA;
        this->LinearEqualityB = this->LinearEqualityB || ~Output(from(1) --> this->qdtOutputVar, nSample+1);
    }
}

template <class Type>
Type ModelHandler::ARX<Type>::sim(Type input)
{
    this->setLinearVector(input, this->output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <class Type>
Type ModelHandler::ARX<Type>::sim(Type input, Type output)
{
    this->setLinearVector(input, output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <class Type>
std::string ModelHandler::ARX<Type>::print()
{

}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(LinAlg::Matrix<Type> Input)
{
    this->Input  = Input;
    LinAlg::Matrix<Type> TempOutput = LinAlg::Zeros<Type>(this->qdtOutputVar,1);

    for(unsigned i = 1; i < Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input.GetColumn(i),TempOutput);
        TempOutput = ~(this->LinearVectorA*this->ModelCoef);
        this->Output = this->Output | TempOutput;
    }
    return this->Output;
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    this->Input  = Input;
    this->Output = LinAlg::Zeros<Type>(1, this->qdtOutputVar);

    for(unsigned i = 1; i < Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input(from(1) --> Input.getNumberOfRows(), i), Output(from(1) --> Output.getNumberOfRows(), i));
        this->Output = this->Output | this->LinearVectorA*this->ModelCoef;
    }
    return this->Output;
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(Type lsim, Type lmax, Type step)
{
    return 0.0;
}

template <class Type>
unsigned ModelHandler::ARX<Type>::getNumberOfInputDelays() const{
    return this->nInputpar;
}

template <class Type>
unsigned ModelHandler::ARX<Type>::getNumberOfInputs()const {
    return this->qdtInputVar;
}

template <class Type>
unsigned ModelHandler::ARX<Type>::getNumberOfOutputDelays() const {
    return this->nOutputpar;
}

template <class Type>
unsigned ModelHandler::ARX<Type>::getNumberOfOutputs() const {
    return this->qdtOutputVar;
}

template <class Type>
double ModelHandler::ARX<Type>::getSampleTime() const {
    return this->sampleTime;
}

template <class Type>
unsigned ModelHandler::ARX<Type>::getNumberOfVariables(){
    return this->qdtInputVar*this->nInputpar + this->qdtOutputVar*this->nOutputpar;
}
