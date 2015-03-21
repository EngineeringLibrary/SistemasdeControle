#ifndef LEASTSQUARE_H
#define LEASTSQUARE_H
#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

template <class UsedType>
class LeastSquare: public Optimization<UsedType>
{
public:
    LeastSquare(Model<UsedType> *model);

    void Optimize();
};

#endif // LEASTSQUARE_H
