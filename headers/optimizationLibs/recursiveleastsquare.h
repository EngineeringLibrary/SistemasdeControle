#ifndef RECURSIVELEASTSQUARE_H
#define RECURSIVELEASTSQUARE_H
#include "SistemasdeControle/headers/optimizationLibs/optimization.h"

namespace OptimizationHandler {
    template <class Type>
    class RecursiveLeastSquare: public Optimization<Type>
    {
        bool firstTimeFlag;
        Type p0, lambda;
        LinAlg::Matrix<Type> P, K, E;
    public:
        RecursiveLeastSquare(ModelHandler::Model<Type> *model,
                             Type p0 = 1e12,
                             Type lambda = 1);

        void Iteration();
        void Optimize();
        void Optimize(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
    };
}

#include "SistemasdeControle/src/optimizationLibs/recursiveleastsquare.hpp"
#endif // RECURSIVELEASTSQUARE_H
