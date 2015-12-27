#include "SistemasdeControle/headers/modelLibs/model.h"

template <typename Type>
ModelHandler::Model<Type>::Model(ModelHandler::Model<Type>* InheritedModel)
{
    this->step     = 1;
    this->input    = 0;
    this->output   = 0;

    this->InheritedModel = InheritedModel;
}

template<typename Type>
ModelHandler::Model<Type>::~Model()
{
    delete this->InheritedModel;
    this->InheritedModel = NULL;
}

template <typename Type>
Type ModelHandler::Model<Type>::diff(Type x)
{
    return (InheritedModel->sim(x+step)-InheritedModel->sim(x))/step;
}

template <typename Type>
void ModelHandler::Model<Type>::setStep(Type step)
{
    this->step = step;
}

template <typename Type>
void ModelHandler::Model<Type>::setModelCoef(LinAlg::Matrix<Type> coef)
{
    this->ModelCoef = coef;
}

template <typename Type>
void ModelHandler::Model<Type>::setIO(LinAlg::Matrix<Type> in, LinAlg::Matrix<Type> out)
{
    this->Input  = in;
    this->Output = out;
}

template <typename Type>
Type ModelHandler::Model<Type>::getOutput()
{
    return this->output;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getModelCoef()
{
    return this->ModelCoef;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getInputMatrix()
{
    return this->Input;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getOutputMatrix()
{
    return this->Output;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getLinearVectorA()
{
    return this->LinearVectorA;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getLinearMatrixA()
{
    return this->LinearMatrixA;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getLinearEqualityB()
{
    return this->LinearEqualityB;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::Model<Type>::getLinearEqualityVectorB()
{
    return this->LinearEqualityVectorB;
}

template <typename Type>
void ModelHandler::Model<Type>::operator= (ModelHandler::Model<Type>* InheritedModel)
{
    this->InheritedModel = InheritedModel;
}

template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::Model<Type> *model)
{
    output << model->print();
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::Model<Type> *model)
{
    return model->print();
}
