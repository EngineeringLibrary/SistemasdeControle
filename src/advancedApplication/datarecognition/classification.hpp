#include "classification.h"

template <typename Type>
AdvancedApplication::Classification<Type>::Classification(ModelHandler::Model<Type> *model, Type tolerance)
{
    this->model = model;
    this->data2Register = LinAlg::Zeros<Type>(this->model->getNumberOfOutputs(),2);
    this->error = LinAlg::Ones<Type>(this->model->getNumberOfOutputs(),2);
    this->tolerance = tolerance;
}

template <typename Type>
void AdvancedApplication::Classification<Type>::dataRegistration(const LinAlg::Matrix<Type> &data2Register)
{
    this->RLS = new OptimizationHandler::RecursiveLeastSquare<double>(this->model);
    for(unsigned i = 1; i <= data2Register.getNumberOfColumns()-1; ++i)
        this->RLS->Optimize(data2Register.GetColumn(i), data2Register.GetColumn(i+1));
}

template <typename Type>
bool AdvancedApplication::Classification<Type>::dataRecognition(const LinAlg::Matrix<Type> &data2beRecognized)
{
    this->data2Register.removeColumn(2);
    this->data2Register = data2beRecognized|this->data2Register;
    this->Output = this->model->sim(this->data2Register.GetColumn(2));
    this->error  = this->data2Register.GetColumn(1) - Output + 0.5*this->error;

    if(((~this->error)*this->error)(1,1) > this->tolerance)
        return 0;
    else
        return 1;
}


