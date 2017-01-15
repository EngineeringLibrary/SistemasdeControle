#ifdef testModel
    #include "../../../headers/modelLibs/arx.h"
#else
    #include "SistemasdeControle/headers/modelLibs/arx.h"
#endif

template <typename Type>
ModelHandler::ARX<Type>::ARX(unsigned nOutputpar,unsigned nInputpar,
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
    this->step         = sampleTime;

    this->ModelCoef = LinAlg::Zeros<Type>(nInputpar*qdtInputVar + nOutputpar*qdtOutputVar, qdtOutputVar);
    this->Input = LinAlg::Zeros<Type>(qdtInputVar, nInputpar);
    this->Output = LinAlg::Zeros<Type>(qdtOutputVar, nOutputpar);
    this->output = 0;
    this->EstOutput = this->Output;
    this->nSample = delay + maxnInOut + 1;
    this->OutputLinearVector = LinAlg::Zeros<Type>(this->qdtOutputVar, this->delay + this->nOutputpar);
    this->InputLinearVector  = LinAlg::Zeros<Type>(this->qdtInputVar, this->nInputpar);
//    this->InputLinearVector  = LinAlg::Zeros<Type>(this->qdtInputVar, this->nInputpar+1);
    this->LinearVectorA = LinAlg::Zeros<Type>(this->qdtOutputVar, this->nInputpar+this->delay + this->nOutputpar);
}

template <typename Type>
ModelHandler::ARX<Type>::ARX(const ModelHandler::ARX<Type>& OtherArxModel){
    this->delay                 = OtherArxModel.delay;
    this->nInputpar             = OtherArxModel.nInputpar;
    this->qdtInputVar           = OtherArxModel.qdtInputVar;
    this->nOutputpar            = OtherArxModel.nOutputpar;
    this->qdtOutputVar          = OtherArxModel.qdtOutputVar;
    this->step                  = OtherArxModel.step;
    this->EstOutput             = OtherArxModel.EstOutput;
    this->Input                 = OtherArxModel.Input;
    this->input                 = OtherArxModel.input;
    this->InputLinearVector     = OtherArxModel.InputLinearVector;
//    this->instance              = OtherArxModel.instance;
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
template <typename Type>
void ModelHandler::ARX<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> PastOutput)
{
    this->InputLinearVector  =  Input|this->InputLinearVector;
    this->OutputLinearVector =  PastOutput|this->OutputLinearVector;
    this->InputLinearVector.removeColumn(this->InputLinearVector.getNumberOfColumns());
    this->OutputLinearVector.removeColumn(this->OutputLinearVector.getNumberOfColumns());
    LinAlg::Matrix<Type> TempLinearVector;


    for(unsigned i = 1; i <= this->OutputLinearVector.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | -this->OutputLinearVector.getRow(i);

    for(unsigned i = 1; i <= this->InputLinearVector.getNumberOfRows(); ++i)
        TempLinearVector = TempLinearVector | this->InputLinearVector.getRow(i);

    this->LinearVectorA = TempLinearVector;
//    std::cout << TempLinearVector;
}

template <typename Type>
void ModelHandler::ARX<Type>::setLinearModel(LinAlg::Matrix<Type> Input,
                                   LinAlg::Matrix<Type> Output)
{
    this->Input = Input;
    this->Output = Output;

    for(nSample = 1; nSample < this->Output.getNumberOfColumns()-1; ++nSample)
    {
        this->setLinearVector( Input.getColumn(nSample), Output.getColumn(nSample+1));
        this->LinearMatrixA = this->LinearMatrixA || this->LinearVectorA;
        this->LinearEqualityB = this->LinearEqualityB || ~Output.getColumn(nSample+2);
    }
}

template <typename Type>
Type ModelHandler::ARX<Type>::sim(Type input)
{
    this->setLinearVector(input, this->output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <typename Type>
Type ModelHandler::ARX<Type>::sim(Type input, Type output)
{
    this->setLinearVector(input, output);
    this->output = (this->LinearVectorA*this->ModelCoef)(1,1);
    return this->output;
}

template <typename Type>
std::string ModelHandler::ARX<Type>::print()
{
    return "função não implementada";
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(LinAlg::Matrix<Type> Input)
{
    this->Input  = Input;
    LinAlg::Matrix<Type> TempOutput;// = LinAlg::Zeros<Type>(this->qdtOutputVar,1);

    for(unsigned i = 1; i <= Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input.getColumn(i),this->Output.getColumn(i));
        TempOutput = TempOutput | ~(this->LinearVectorA*this->ModelCoef);
    }
    this->Output = TempOutput;
    return this->Output;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    this->Input  = Input;
    LinAlg::Matrix<Type> TempOutput = LinAlg::Zeros<Type>(this->qdtOutputVar,1);

    for(unsigned i = 1; i <= Input.getNumberOfColumns(); ++i){
        this->setLinearVector(Input.getColumn(i),Output.getColumn(i));
        TempOutput = TempOutput | ~(this->LinearVectorA*this->ModelCoef);
    }
    this->Output = TempOutput;
    return this->Output;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::ARX<Type>::sim(Type lsim, Type lmax, Type step)
{
    return LinAlg::Matrix<Type>(lsim+lmax+step);
}

template <typename Type>
unsigned ModelHandler::ARX<Type>::getNumberOfInputDelays() const{
    return this->nInputpar;
}

template <typename Type>
unsigned ModelHandler::ARX<Type>::getNumberOfInputs()const {
    return this->qdtInputVar;
}

template <typename Type>
unsigned ModelHandler::ARX<Type>::getNumberOfOutputDelays() const {
    return this->nOutputpar;
}

template <typename Type>
unsigned ModelHandler::ARX<Type>::getNumberOfOutputs() const {
    return this->qdtOutputVar;
}


template <typename Type>
unsigned ModelHandler::ARX<Type>::getNumberOfVariables() const {
    return this->qdtInputVar*this->nInputpar + this->qdtOutputVar*this->nOutputpar;
}
