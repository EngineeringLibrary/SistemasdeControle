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

public:
    Optimization();

    LinAlg::Matrix<UsedType> getOptimizatedVariable();
    virtual void Optimize(LinAlg::Matrix<UsedType> Input,
                          LinAlg::Matrix<UsedType> Output)=0;
};

#endif // OPTIMIZATION_H
