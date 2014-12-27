#ifndef __OPTIMIZATION_H_INCLUDED
#define __OPTIMIZATION_H_INCLUDED

#include "src/simulationLibs/model.h"
#include "src/simulationLibs/arx.h"

//Biblioteca incompleta, ainda nao funcional.

template <class UsedType>
class Optimization
{
protected:
    Matrix<UsedType> OptimizatedVariable; //Error;
    Model<UsedType> *model;

//    void initRLS(int nu, int ny, unsigned long int  p0);
//    void setData(Matrix<UsedType> in, Matrix<UsedType> out);

public:
    Optimization();

    Matrix<UsedType> getOptimizatedVariable();
    virtual void Optimize()=0;
//    void RLS(int nu, int ny, unsigned long int p0, Matrix<UsedType> in, Matrix<UsedType> out);
};

#endif // OPTIMIZATION_H
