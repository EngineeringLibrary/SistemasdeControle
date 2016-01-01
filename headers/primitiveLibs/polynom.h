#ifndef __POLYNOM_H_INCLUDED
#define __POLYNOM_H_INCLUDED

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include <complex>

namespace PolynomHandler {
    template <typename Type>
    class Polynom
    {
        public:

            Polynom(Type Num);//testada
            Polynom(LinAlg::Matrix<Type> Num); //testada
            Polynom(const PolynomHandler::Polynom<Type> &CopyPolynom); //testada
            Polynom(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);//testada
            Polynom(): x('x'), num(NULL), den(NULL), sizeNum(0), sizeDen(0){} //testada
            virtual ~Polynom(); //testada

            char                 getVar() const; // testada
            void                 changeVar(char var); //testada

            unsigned             getNumSize() const; // testada
            unsigned             getDenSize() const; // testada

            LinAlg::Matrix<Type> getNum(); //testada
            LinAlg::Matrix<Type> getDen(); //testada

            void setNum(Type *Num, unsigned sizenum);//testada
            void setNum(LinAlg::Matrix<Type> Num); // testada

            void setDen(Type *Den, unsigned sizeden); //testada
            void setDen(LinAlg::Matrix<Type> Den); // testada


            PolynomHandler::Polynom<Type>& operator=  (const PolynomHandler::Polynom<Type>& OtherPolynom);//testada
            template<typename OtherPolynomType>//testada
            PolynomHandler::Polynom<Type>& operator=  (const PolynomHandler::Polynom<OtherPolynomType>& OtherPolynom);

            PolynomHandler::Polynom<Type>& operator+= (const Type& rhs /*scalar*/); //testada
            template<typename RightType> //testada
            PolynomHandler::Polynom<Type>& operator+= (const PolynomHandler::Polynom<RightType>& rhs);

            PolynomHandler::Polynom<Type>& operator-= (const Type& rhs /*scalar*/); // testada
            template<typename RightType>
            PolynomHandler::Polynom<Type>& operator-= (const PolynomHandler::Polynom<RightType>& rhs);

            PolynomHandler::Polynom<Type>& operator*= (const Type& rhs /*scalar*/); // testada
            template<typename RightType>
            PolynomHandler::Polynom<Type>& operator*= (const PolynomHandler::Polynom<RightType>& rhs);

            PolynomHandler::Polynom<Type>& operator/= (const Type& rhs /*scalar*/);
            template<typename RightType>
            PolynomHandler::Polynom<Type>& operator/= (const PolynomHandler::Polynom<RightType>& rhs);

            Polynom<Type>& operator^= (const int &scalar);

        private:
            char x;
            Type *num, *den;
            unsigned sizeNum, sizeDen;

            void init(Type Num); //ok
            void init(LinAlg::Matrix<Type> Num);
            void init(unsigned NumSize, unsigned DenSize);
            void init(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);

            bool isZero();
    };

    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType> operator+ (PolynomHandler::Polynom<PolynomType> lhs, const ScalarType& rhs) {return lhs += rhs;}
    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType> operator+ (const ScalarType& lhs, PolynomHandler::Polynom<PolynomType> rhs) {return rhs += lhs;}
    template<typename LeftType, typename RightType>
    PolynomHandler::Polynom<LeftType> operator+ (PolynomHandler::Polynom<LeftType> lhs, const PolynomHandler::Polynom<RightType>& rhs) {return lhs += rhs;}

    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType> operator- (PolynomHandler::Polynom<PolynomType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType> operator- (const ScalarType& lhs, PolynomHandler::Polynom<PolynomType> rhs) {return -rhs -= -lhs;}
    template<typename LeftType, typename RightType>
    PolynomHandler::Polynom<LeftType> operator- (PolynomHandler::Polynom<LeftType> lhs, const PolynomHandler::Polynom<RightType>& rhs) {return lhs -= rhs;}

    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType>  operator* (PolynomHandler::Polynom<PolynomType>  lhs, const ScalarType& rhs) {return lhs *= rhs;}
    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType>  operator* (const ScalarType& lhs, PolynomHandler::Polynom<PolynomType>  rhs) {return rhs *= lhs;}
    template<typename LeftType, typename RightType>
    PolynomHandler::Polynom<LeftType> operator* (PolynomHandler::Polynom<LeftType> lhs, const PolynomHandler::Polynom<RightType>& rhs) {return lhs *= rhs;}

    template<typename PolynomType, typename ScalarType>
    PolynomHandler::Polynom<PolynomType> operator/ (PolynomHandler::Polynom<PolynomType> lhs, const ScalarType& rhs) {return lhs /= rhs;}
    template<typename LeftType, typename RightType>
    PolynomHandler::Polynom<LeftType> operator/ (PolynomHandler::Polynom<LeftType> lhs, const PolynomHandler::Polynom<RightType>& rhs) {return lhs /= rhs;}

    template<typename PolynomType>
    PolynomHandler::Polynom<PolynomType> operator^ (PolynomHandler::Polynom<PolynomType> lhs, int exp) {return lhs ^= exp;}

    template<typename Type> // testado
    std::ostream& operator<< (std::ostream& output, PolynomHandler::Polynom<Type> rhs);

    template<typename Type> // testada
    std::string& operator<< (std::string& output, PolynomHandler::Polynom<Type> rhs);

    template<typename Type>
    std::string printSmallPolynom(const LinAlg::Matrix<Type> &rhs, const char &variable = 'x');

    template<typename Type> // testada
    bool VefDen(const Type *den1, const Type *den2, const unsigned &sizeden1, const unsigned &sizeden2);

//    template <class Type>
//    bool isDivisible(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template<typename Type> // testada
    Type* initPointer(const unsigned &Size);

    template<typename Type> // testado
    Type *SumPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template <class Type> // com defeito
    Type *MultPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template <class Type> // com defeito
    LinAlg::Matrix<Type> MultPoly(const LinAlg::Matrix<Type> &lhs, const LinAlg::Matrix<Type> &rhs);


    template <typename Type>
    Polynom<Type> simplify(const Type *num,const Type *den,const unsigned &numSize,const unsigned &denSize);//sincronizado

    template <typename Type>
    LinAlg::Matrix<Type> Roots(const Type *num,const unsigned &numSize);//sincronizado

    template <typename Type>
    LinAlg::Matrix<Type> Root2Poly(const LinAlg::Matrix<Type> &root);

    template <typename Type>
    bool rootsContainRoot(const Type &root, const LinAlg::Matrix<Type> &roots);

    template <class Type>
    LinAlg::Matrix<Type> MMC(LinAlg::Matrix< PolynomHandler::Polynom<Type> > &polynomToGetMMC);
//    {
//        Polynom<Type> **Ret = PolynomMatrix<Type> (rows,cols);


//        for(unsigned k = 0; k < rows; k++)
//        {
//            for(unsigned l = 0; l < cols; l++)
//            {
//               LinAlg::Matrix<Type> den = P[k][l].getDen();
//               LinAlg::Matrix<Type> num = P[k][l].getNum();

//                for(unsigned i = 0; i < rows; i++)
//                    for(unsigned j = 0; j < cols; j++)
//                    {
//                        if((i == k) && (j == l))
//                        {}
//                        else
//                        {
//                            den = MultPoly(den, P[i][j].getDen());
//    //                        sizeDen = sizeDen + P[i][j].getDenSize() - 1;

//                            num = MultPoly(num, P[i][j].getDen());
//    //                        sizeNum = sizeNum + P[i][j].getDenSize() - 1;
//                        }
//                    }

//                Ret[k][l].setNum(num);
//                Ret[k][l].setDen(den);
//    //            Ret[k][l].print();
//            }
//        }
//        return Ret;
//    }

}

#include "SistemasdeControle/src/primitiveLibs/polynom.hpp"

#endif // POLYNOM_H
