#ifndef RECURSIVELEASTSQUARE_H
#define RECURSIVELEASTSQUARE_H
#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

template <class UsedType>
class RecursiveLeastSquare: public Optimization<UsedType>
{
    bool firstTimeFlag;
    UsedType p0, lambda;
    LinAlg::Matrix<UsedType> P, K, E;
public:
    RecursiveLeastSquare(Model<UsedType> *model,
                         UsedType p0 = 1e3,
                         UsedType lambda = 1);

    void Iteration();
    void Optimize(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);
};

#endif // RECURSIVELEASTSQUARE_H
