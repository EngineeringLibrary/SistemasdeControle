#include "SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h"

template <class UsedType>
RecursiveLeastSquare<UsedType>::RecursiveLeastSquare(Model<UsedType> *model,
                                                     UsedType p0,
                                                     UsedType lambda)
{
    this->p0     = p0;
    this->model  = model;
    this->lambda = lambda;    
    this->firstTimeFlag = false;
}

template <class UsedType>
void RecursiveLeastSquare<UsedType>::Optimize(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{
    LinAlg::Matrix<UsedType> PastOutput = Output.GetColumn(1);
    Output = Output.GetColumn(2);

    this->model->setLinearVector(Input, PastOutput);
    if(!this->firstTimeFlag)
    {
        this->firstTimeFlag = true;
        this->OptimizatedVariable = LinAlg::Ones<UsedType>(this->model->getLinearVectorA().getNumberOfColumns(), Output.getNumberOfRows())/this->p0;
        this->P = LinAlg::Eye<UsedType>(this->model->getLinearVectorA().getNumberOfColumns())*(this->p0);
    }

    LinAlg::Matrix<UsedType> phi = this->model->getLinearVectorA();
    E = Output - phi*this->OptimizatedVariable;
    K = (P*~phi)/(((phi*P)*~phi) + lambda);
    this->OptimizatedVariable = this->OptimizatedVariable + K*E;
    P = (P - (K*(phi*P)))/lambda;
}

template class RecursiveLeastSquare<float>;
template class RecursiveLeastSquare<double>;
