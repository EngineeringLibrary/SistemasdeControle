#include "optimization.h"

Optimization::Optimization()
{
}

void Optimization::initRLS(int nu, int ny, unsigned long int p0)
{
    this->nu = nu;
    this->ny = ny;
    this->p0 = p0;

    this->P.eye(this->ny + this->nu);
    this->Theta.ones(this->ny + this->nu, this->B.getCols());
    this->lambda = 1;
    this->size = min(this->Model.getInput().getCols(), this->Model.getOutput().getCols());
    this->P = this->P*(this->p0);
    this->Theta = this->Theta/(float)this->p0;
}

void Optimization::RLS(int nu, int ny, unsigned long int p0, Matrix in, Matrix out)
{
    Matrix K;
    double e;


    this->Model.addIO(in, out);
    initRLS(nu, ny, p0);

    for(int i = (this->nu + this->ny + 1); i < this->size; i++)
    {
        this->A = Model.getPhi(ny, nu, i);
        K = this->P*this->A/(this->lambda + ((~this->A * this->P)*this->A));
        this->P = (this->P - (K*(~this->A)*this->P))/this->lambda;
        //this->Error.add(i,1, Model.getOutput()(i,1) - this->A*this->Theta);
        e = (Model.getOutput()(i,1) - this->A*this->Theta)(1,1);
        this->Theta = this->Theta + K*e;
    }
    this->Theta.print();
}
