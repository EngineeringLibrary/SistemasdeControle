#ifndef __OPTIMIZATION_H_INCLUDED
#define __OPTIMIZATION_H_INCLUDED

#include "..\simulation libs\lsim.h"

//Biblioteca incompleta, ainda não funcional.

template <class UsedType>
class Optimization
{
private:
    Matrix<UsedType> A, B, P, Theta; //Error;
    Lsim<UsedType> Model;
    float lambda;
    int size, nu, ny;
    long unsigned int p0;

    void initRLS(int nu, int ny, unsigned long int  p0);
    void setData(Matrix<UsedType> in, Matrix<UsedType> out);

public:
    Optimization();

    void RLS(int nu, int ny, unsigned long int p0, Matrix<UsedType> in, Matrix<UsedType> out);
};

#endif // OPTIMIZATION_H
