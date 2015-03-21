#ifndef __OPTIMIZATION_H_INCLUDED
#define __OPTIMIZATION_H_INCLUDED

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/arx.h"

//Biblioteca incompleta, ainda nao funcional.

template <class UsedType>
class Optimization
{
protected:
    LinAlg::Matrix<UsedType> OptimizatedVariable; //Error;
    Model<UsedType> *model;

//    void initRLS(int nu, int ny, unsigned long int  p0);
//    void setData(Matrix<UsedType> in, Matrix<UsedType> out);

public:
    Optimization();

    LinAlg::Matrix<UsedType> getOptimizatedVariable();
    virtual void Optimize()=0;
//    void RLS(int nu, int ny, unsigned long int p0, Matrix<UsedType> in, Matrix<UsedType> out);
};

#endif // OPTIMIZATION_H
