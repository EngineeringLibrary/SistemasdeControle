#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include "lsim.h"


class Optimization
{
private:
    Matrix A, B, P, Theta; //Error;
    Lsim Model;
    float lambda;
    int size, nu, ny;
    long unsigned int p0;

    void initRLS(int nu, int ny, unsigned long int  p0);
    void setData(Matrix in, Matrix out);

public:
    Optimization();

    void RLS(int nu, int ny, unsigned long int p0, Matrix in, Matrix out);
};

#endif // OPTIMIZATION_H
