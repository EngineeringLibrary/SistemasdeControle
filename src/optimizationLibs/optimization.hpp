#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

template <class UsedType>
OptimizationHandler::Optimization<UsedType>::Optimization()
{
}

template <class UsedType>
LinAlg::Matrix<UsedType> OptimizationHandler::Optimization<UsedType>::getOptimizatedVariable() const
{
    return this->OptimizatedVariable;
}

