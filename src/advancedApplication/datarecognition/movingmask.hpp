#include "SistemasdeControle/headers/advancedApplication/datarecognition/movingmask.h"

template <typename Type>
AdvancedApplication::movingMask<Type>::movingMask(const unsigned &quantidadeVariaveis, const unsigned &tamanho, ModelHandler::Model<Type> *model)
{
    this->quantidadeVariaveis =  quantidadeVariaveis;
    this->tamanho = tamanho;
    this->data2Register = LinAlg::Matrix<unsigned>(quantidadeVariaveis*tamanho,1);

    if(model){
        this->model = model;
        this->RLS = new OptimizationHandler::RecursiveLeastSquare<Type>(this->model);
    }else{
        this->model = NULL;
    }
}

template <typename Type>
void AdvancedApplication::movingMask<Type>::dataRecognitionStart(const unsigned &quantidadeVariaveis, const unsigned &tamanho)
{
    this->quantidadeVariaveis =  quantidadeVariaveis;
    this->tamanho = tamanho;
    this->data2Register = LinAlg::Matrix<unsigned>(quantidadeVariaveis*tamanho,1);
}

template <typename Type>
void AdvancedApplication::movingMask<Type>::operator <<(const LinAlg::Matrix<Type> &inputData)
{
    for(unsigned i = inputData.getNumberOfRows()+1; i <= this->data2Register.getNumberOfRows(); ++i )
        this->data2Register(i-inputData.getNumberOfRows(),1) = this->data2Register(i,1);
    unsigned j = 1;
    for(unsigned i = data2Register.getNumberOfRows()-inputData.getNumberOfRows()+1; i <= this->data2Register.getNumberOfRows(); ++i)
    {
        this->data2Register(i,1) = inputData(j,1);
        ++j;
    }
}

template <typename Type>
Type AdvancedApplication::movingMask<Type>::dataRecognition(const LinAlg::Matrix<Type> &defaultData, Type tolerance)
{
    LinAlg::Matrix<Type> TempRegister = defaultData;
    unsigned j = 1;
    for(unsigned i = data2Register.getNumberOfRows()-defaultData.getNumberOfRows()+1; i <= this->data2Register.getNumberOfRows(); ++i)
    {
        TempRegister(j,1) = this->data2Register(i,1);
        ++j;
    }
    if(counter > unsigned(defaultData.getNumberOfRows()/quantidadeVariaveis))
    {
        counter = 0;
        this->data2Register = LinAlg::Matrix<unsigned>(quantidadeVariaveis*tamanho,1);
    }
    counter++;

//    std::cout << (TempRegister|defaultData|(TempRegister-defaultData)) << "\n\n";
//    std::cout << (((~(TempRegister-defaultData))*(TempRegister-defaultData))(1,1)) << "\n\n";
    unsigned match = 0;
    TempRegister = LinAlg::powMatrix(TempRegister-defaultData,2.0);
    for(unsigned i = 1; i <= TempRegister.getNumberOfRows(); ++i)
        if(TempRegister(i,1) <= tolerance)
            match++;

    return(Type(match))/Type(j);
}
template <typename Type>
void AdvancedApplication::movingMask<Type>::filterOptimization(LinAlg::Matrix<Type> data2beFiltered)
{
    if(this->filterMatrix.isNull()){
        this->filterMatrix = LinAlg::Zeros<Type>(data2beFiltered.getNumberOfRows(),1);
        this->filterCounter = 0;
    }

    this->filterCounter++;
    this->filterMatrix = this->filterMatrix + data2beFiltered;
    this->RLS->Optimize(data2beFiltered, this->filterMatrix/filterCounter);

}

template <typename Type>
LinAlg::Matrix<Type> AdvancedApplication::movingMask<Type>::getFilterParameters() const
{
    return model->getModelCoef();
}

template <typename Type>
LinAlg::Matrix<Type> AdvancedApplication::movingMask<Type>::getFilteredData(LinAlg::Matrix<Type> data2beFiltered) const
{
    if(!this->wasDataOptimized)
        return this->model->sim(data2beFiltered);

    return this->model->getLinearVectorA()*model->getModelCoef();
}
