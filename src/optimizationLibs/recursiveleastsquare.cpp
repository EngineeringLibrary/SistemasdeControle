#include "recursiveleastsquare.h"

template <class UsedType>
RecursiveLeastSquare<UsedType>::RecursiveLeastSquare(Model<UsedType> *model,
                                                     UsedType p0,
                                                     unsigned nIteration,
                                                     UsedType lambda)
{
    this->p0     = p0;
    this->model  = model;
    this->lambda = lambda;
    this->OptimizatedVariable.ones(1,this->model->getLinearVectorPhi().getCols());
    this->OptimizatedVariable = this->OptimizatedVariable/this->p0;
    this->P.eye(this->model->getLinearVectorPhi().getCols());
    this->P = this->P*(this->p0);
}

template <class UsedType>
void RecursiveLeastSquare<UsedType>::Iteration()
{
//    this->B = in;
//    this->Model.addIO(in, out);
//    initRLS(nu, ny, p0);

//    for(int i = (this->nu + this->ny + 1); i <= this->size; i++)
//    {
        this->phi = this->model->getLinearVectorPhi();
        K = (P*~phi)/(((phi*P)*~phi) + (lambda));
        P = (P - (K*(phi*P)))/lambda;
        //this->Error.add(i,1, Model.getOutput()(i,1) - this->A*this->Theta);

        e = (this->model->sim(this->model->getLinearEqualityB()(nIteration,1)) - (phi*this->OptimizatedVariable)(1,1));
        this->OptimizatedVariable = this->OptimizatedVariable + K*e;
//    }
//    this->Theta.print();
}

template <class UsedType>
void RecursiveLeastSquare<UsedType>::Optimize()
{

}

template class RecursiveLeastSquare<float>;
template class RecursiveLeastSquare<double>;
