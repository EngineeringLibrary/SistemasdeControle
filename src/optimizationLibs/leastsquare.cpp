#include "SistemasdeControle/headers/optimizationLibs/leastsquare.h"

template <class UsedType>
LeastSquare<UsedType>::LeastSquare(Model<UsedType> *model)
{
    this->model = model;
}

template <class UsedType>
void LeastSquare<UsedType>::Optimize()
{
    LinAlg::Matrix<UsedType> A = this->model->getLinearMatrixA(),
                             B = this->model->getLinearEqualityB();
    this->OptimizatedVariable = (((~A)*A)^-1)*(~A)*B;
}

template class LeastSquare<float>;
template class LeastSquare<double>;
