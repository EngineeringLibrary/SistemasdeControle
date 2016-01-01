#include "SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h"

template <class Type>
OptimizationHandler::RecursiveLeastSquare<Type>::RecursiveLeastSquare(ModelHandler::Model<Type> *model,
                                                     Type p0,
                                                     Type lambda)
{
    this->p0     = p0;
    this->model  = model;
    this->lambda = lambda;    
    this->firstTimeFlag = false;    
    this->model->setModelCoef(LinAlg::Ones<Type>(this->model->getNumberOfVariables(), 1)/this->p0);
    this->P = LinAlg::Eye<Type>(this->model->getNumberOfVariables())*(this->p0);
}

template <class Type>
void OptimizationHandler::RecursiveLeastSquare<Type>::Optimize()
{
}

template <class Type>
void OptimizationHandler::RecursiveLeastSquare<Type>::Optimize(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{
    this->model->setLinearVector(Input, Output(from(1)-->Output.getNumberOfRows(),1));

    LinAlg::Matrix<Type> phi = this->model->getLinearVectorA();
    E = Output(from(1)-->Output.getNumberOfRows(),2) - phi*this->model->getModelCoef();
    K = (P*~phi)/(((phi*P)*~phi) + lambda);
    this->model->setModelCoef(this->model->getModelCoef() + K*E);
    P = (P - (K*(phi*P)))/lambda;
}
