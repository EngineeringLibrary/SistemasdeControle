#ifndef LINALG_H
#define LINALG_H

#define SWAP

#include "matrix.h"
#include <complex>//numeros complexos
#include <cfloat>

namespace LinAlg {
    //Not a linear algebra method. This is a computer to method to guarantee a matrix precision.
    template <typename  Type>
    void Balance (LinAlg::Matrix<Type>& matrix_to_balance);

    template<typename Type>
    Type Trace (const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    LinAlg::Matrix<Type> CaracteristicPolynom (const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    void QR_Factorization (const LinAlg::Matrix<Type>& input_matrix,
                           LinAlg::Matrix<Type>& output_Q_matrix,
                           LinAlg::Matrix<Type>& output_R_matrix);

    //Simplified away to call QR_Factorization.
    template<typename Type>
    void QR (const LinAlg::Matrix<Type>& input_matrix,
             LinAlg::Matrix<Type>& output_Q_matrix,
             LinAlg::Matrix<Type>& output_R_matrix);

    template<typename Type>
    LinAlg::Matrix<Type> Hessemberg_Form (const LinAlg::Matrix<Type>& matrix_to_reduce);

    //Simplified away to call Hessemberg_Form.
    template<typename Type>
    LinAlg::Matrix<Type> Hess (const LinAlg::Matrix<Type>& matrix_to_reduce);

    template <typename Type>
    LinAlg::Matrix<Type> EigenValues(const LinAlg::Matrix<Type>& matrix_to_get_eigenvalues, unsigned iterations = 100);
    
    template <typename Type>
    Type *MultPoly(const Type *lhs, const Type  *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template <typename Type>
    Type max(const LinAlg::Matrix<Type> &mat);

    template <typename Type>
    Type min(const LinAlg::Matrix<Type> &mat);

    template <typename Type>
    LinAlg::Matrix<Type> abs(const LinAlg::Matrix<Type> &mat);
}

#include "SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp"

#endif // LINALG_H




