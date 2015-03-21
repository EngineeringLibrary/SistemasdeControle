#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

template <class UsedType>
Optimization<UsedType>::Optimization()
{
}

template <class UsedType>
LinAlg::Matrix<UsedType> Optimization<UsedType>::getOptimizatedVariable()
{
    return this->OptimizatedVariable;
}


//template <class UsedType>
//void Optimization<UsedType>::initRLS(int nu, int ny, unsigned long int p0)
//{
//    this->nu = nu;
//    this->ny = ny;
//    this->p0 = p0;

//    this->P.eye(this->ny + this->nu);
//    this->Theta.ones(this->ny + this->nu, this->B.getCols());
//    this->lambda = 1;
//    this->size = min(this->Model.getInput().getRows(), this->Model.getOutput().getRows());
//    this->P = this->P*(this->p0);
//    this->Theta = this->Theta/(UsedType)this->p0;
//}

//template <class UsedType>
//void Optimization<UsedType>::RLS(int nu, int ny, unsigned long int p0, Matrix<UsedType> in, Matrix<UsedType> out)
//{
//    Matrix<UsedType> K;
//    UsedType e;

//    this->B = in;
//    this->Model.addIO(in, out);
//    initRLS(nu, ny, p0);

//    for(int i = (this->nu + this->ny + 1); i <= this->size; i++)
//    {
//        this->A = Model.getArxPhi(ny, nu, i);
//        K = (this->P*~this->A)/(((this->A * this->P)*~this->A) + ((UsedType)this->lambda));
//        this->P = (this->P - (K*(this->A*this->P)))/this->lambda;
//        //this->Error.add(i,1, Model.getOutput()(i,1) - this->A*this->Theta);

//        e = -((this->A*this->Theta - Model.getOutput()(i,1))(1,1));
//        this->Theta = this->Theta + K*e;
//    }
//    this->Theta.print();

//}

template class Optimization<float>;
template class Optimization<double>;
