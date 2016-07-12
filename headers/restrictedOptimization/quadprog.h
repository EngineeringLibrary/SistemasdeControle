#ifndef QUADPROG_H
#define QUADPROG_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrixrestriction.h"

namespace restrictedOptimizationHandler{

    template <typename Type>
    class QuadProg
    {
    public:
        QuadProg();
        virtual void optimize() = 0;
        void operator= (const MatrixRestrictionHandler::MatrixEquality<Type> &E);
        void operator= (const MatrixRestrictionHandler::MatrixNegativeInequality<Type> &E);
        void operator= (const MatrixRestrictionHandler::MatrixPositiveInequality<Type> &E);

    private:
        MatrixRestrictionHandler::MatrixEquality<Type> E;
        MatrixRestrictionHandler::MatrixNegativeInequality<Type> N;
        MatrixRestrictionHandler::MatrixPositiveInequality<Type> P;
    };
}

#include "SistemasdeControle/src/restrictedOptimization/quadprog.hpp"
#endif // QUADPROG_H
