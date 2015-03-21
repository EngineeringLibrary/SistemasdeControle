#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>

#include "identifiers.h"

using namespace Identifiers;

namespace LinAlg {
    template<typename Type>
    class Matrix
    {
        public:
            Matrix (std::string Mat);
            Matrix (unsigned row, unsigned column);
            Matrix (): rows(0), columns(0), mat(NULL){};
            Matrix (const LinAlg::Matrix<Type>& otherMatrix);
            virtual ~Matrix ();

            unsigned getNumberOfRows () const;
            unsigned getNumberOfColumns () const;

            LinAlg::Matrix<Type> GetRow (unsigned number_of_the_row);
            LinAlg::Matrix<Type> GetColumn (unsigned number_of_the_column);

            void SwapRows (unsigned row_to_be_swapped, unsigned  row_to_take_place);
            void SwapColumns (unsigned column_to_be_swapped, unsigned column_to_take_place);

            unsigned Size ();

            bool isNull ();
            bool isSquare ();

            Type& operator() (unsigned row, unsigned column);
            Type  operator() (unsigned  row, unsigned column) const;

            LinAlg::Matrix<Type> operator() (unsigned* row_interval, unsigned column) const;
            LinAlg::Matrix<Type> operator() (unsigned  row, unsigned* column_interval) const;
            LinAlg::Matrix<Type> operator() (unsigned* row_interval, unsigned* column_interval) const;

            void operator= (std::string rhs);
            LinAlg::Matrix<Type>& operator= (const LinAlg::Matrix<Type>& otherMatrix);
            template<typename OtherMatrixType>
            LinAlg::Matrix<Type>& operator= (const LinAlg::Matrix<OtherMatrixType>& otherMatrix);

            LinAlg::Matrix<Type>& operator+= (const Type& rhs /*scalar*/);
            template<typename RightType>
            LinAlg::Matrix<Type>& operator+= (const LinAlg::Matrix<RightType>& rhs);

            LinAlg::Matrix<Type>& operator-= (const Type& rhs /*scalar*/);
            template<typename RightType>
            LinAlg::Matrix<Type>& operator-= (const LinAlg::Matrix<RightType>& rhs);


            LinAlg::Matrix<Type>& operator*= (const Type& rhs /*scalar*/);
            template<typename RightType>
            LinAlg::Matrix<Type>& operator*= (const LinAlg::Matrix<RightType>& rhs);


            LinAlg::Matrix<Type>& operator/= (const Type& rhs /*scalar*/);
            template<typename RightType>
            LinAlg::Matrix<Type>& operator/= (const LinAlg::Matrix<RightType>& rhs);

            LinAlg::Matrix<Type>& operator^= (double exp);

            template<typename RightType>
            LinAlg::Matrix<Type> operator| (LinAlg::Matrix<RightType> rhs);
            template<typename RightType>
            LinAlg::Matrix<Type> operator|| (LinAlg::Matrix<RightType> rhs);

            template<typename OtherMatrixType>
            void swap (const LinAlg::Matrix<OtherMatrixType>& otherMatrix);

            //Should be declared as friend.
            template<typename OtherMatrixType>
            friend void swap (LinAlg::Matrix<Type>& lhs, LinAlg::Matrix<OtherMatrixType>& rhs) {lhs.swap(rhs);};            

        private:
            void Init (std::string Mat);
            void Init (unsigned row, unsigned column);

            void ReInit (unsigned row, unsigned column);

            void Add (unsigned& row, unsigned& column, Type& number);

            template<typename OtherMatrixType>
            bool CheckDimensions(const LinAlg::Matrix<OtherMatrixType>& rhs, unsigned operation);

            unsigned rows, columns;
            Type** mat;
    };

    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator+ (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs += rhs;}
    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator+ (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return rhs += lhs;}
    template<typename LeftType, typename RightType>
    LinAlg::Matrix<LeftType> operator+ (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs += rhs;}

    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator- (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator- (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return -rhs -= -lhs;}
    template<typename LeftType, typename RightType>
    LinAlg::Matrix<LeftType> operator- (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs -= rhs;}

    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator* (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs *= rhs;}
    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator* (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs) {return rhs *= lhs;}
    template<typename LeftType, typename RightType>
    LinAlg::Matrix<LeftType> operator* (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs *= rhs;}

    template<typename MatrixType, typename ScalarType>
    LinAlg::Matrix<MatrixType> operator/ (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs) {return lhs /= rhs;}
    template<typename LeftType, typename RightType>
    LinAlg::Matrix<LeftType> operator/ (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs) {return lhs /= rhs;}

    template<typename Type>
    LinAlg::Matrix<Type> operator- (const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    LinAlg::Matrix<Type> operator~ (LinAlg::Matrix<Type> mat);

    template<typename Type>
    LinAlg::Matrix<Type> operator^ (LinAlg::Matrix<Type> lhs, double exp) {return lhs ^= exp;}

    template<typename Type>
    std::ostream& operator<< (std::ostream& output, const LinAlg::Matrix<Type>& mat);
    template<typename Type>
    std::istream& operator>> (std::istream& input, LinAlg::Matrix<Type>& mat);

    template<typename Type>
    bool operator== (const LinAlg::Matrix<Type>& lhs, const LinAlg::Matrix<Type>& rhs);
    template<typename Type>
    bool operator!= (const LinAlg::Matrix<Type>& lhs, const LinAlg::Matrix<Type>& rhs) {return !(lhs == rhs);}

    template<typename Type>
    void Zeros (LinAlg::Matrix<Type>& Mat);

    template<typename Type>
    LinAlg::Matrix<Type> Zeros (unsigned rows, unsigned columns);

    template<typename Type>
    LinAlg::Matrix<Type> Eye (unsigned dimension);

    template<typename Type>
    void Ones (LinAlg::Matrix<Type> & mat);

    template<typename Type>
    LinAlg::Matrix<Type> Ones (unsigned rows, unsigned columns);

    template<typename Type>
    Type Determinant (const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    LinAlg::Matrix<Type> Cofactor(const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    LinAlg::Matrix<Type> Inverse(const LinAlg::Matrix<Type>& mat);

    template<typename Type>
    void Print (const LinAlg::Matrix<Type>& mat);
}

#include "SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp"

#endif // MATRIX_H
