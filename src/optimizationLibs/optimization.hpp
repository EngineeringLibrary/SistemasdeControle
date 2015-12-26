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

template class Optimization<float>;
template class Optimization<double>;
