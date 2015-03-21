#ifndef RECURSIVELEASTSQUARE_H
#define RECURSIVELEASTSQUARE_H
#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

template <class UsedType>
class RecursiveLeastSquare: public Optimization<UsedType>
{
    unsigned nIteration;
    UsedType p0, lambda, e;
    LinAlg::Matrix<UsedType> P, K, phi;
public:
    RecursiveLeastSquare(Model<UsedType> *model,
                         UsedType p0,
                         unsigned nIteration,
                         UsedType lambda);

    void Iteration();
    void Optimize();
};

#endif // RECURSIVELEASTSQUARE_H
