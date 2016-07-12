#ifndef SIMPLEX_H
#define SIMPLEX_H
#include "SistemasdeControle/headers/restrictedOptimization/linprog.h"

namespace restrictedOptimizationHandler{

    template <typename Type>
    class simplex : public linProg
    {
    public:
        simplex();
        void optimize();
    private:
        Type cost;
        LinAlg::Matrix<Type> set;
        void simplexOptimization(const LinAlg::Matrix<Type> &c,
                                 const LinAlg::Matrix<Type> &A,
                                 const LinAlg::Matrix<Type> &b,
                                 const LinAlg::Matrix<Type> &B,
                                 const LinAlg::Matrix<Type> &N);
        LinAlg::Matrix<Type> EscalSimplex(LinAlg::Matrix<Type> A, unsigned index);

    };
}

#include "SistemasdeControle/headers/restrictedOptimization/simplex.hpp"
#endif // SIMPLEX_H
