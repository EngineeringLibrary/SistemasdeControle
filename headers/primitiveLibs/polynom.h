#ifndef __POLYNOM_H_INCLUDED
#define __POLYNOM_H_INCLUDED

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace PolynomHandler {
    template <typename Type>
    class Polynom
    {
        public:

            Polynom(Type Num);//testada
            Polynom(LinAlg::Matrix<Type> Num); //testada
            Polynom(const PolynomHandler::Polynom<Type> &CopyPolynom); //testada
            Polynom(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);//testada
            Polynom(): x('x'), sizeDen(0), sizeNum(0), num(NULL), den(NULL){} //testada
            virtual ~Polynom(); //testada

            char                 getVar(); // testada
            void                 changeVar(char var); //testada

            unsigned             getNumSize(); // testada
            unsigned             getDenSize(); // testada

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
            template<typename RightType> // com defeito
            PolynomHandler::Polynom<Type>& operator+= (const PolynomHandler::Polynom<RightType>& rhs);
//            friend Polynom<Type> operator+(Type scalar, Polynom<Type> P){return P+scalar;}

//            Polynom<Type> operator-(Polynom<Type> P);
//            Polynom<Type> operator-(Type scalar);
//            friend Polynom<Type> operator-(Type scalar, Polynom<Type> P){return (-1)*P+scalar;}

//            Polynom<Type> operator*(Type scalar);
//            Polynom<Type> operator*(Polynom<Type> P);
//            friend Polynom<Type> operator*(Type scalar, Polynom<Type> P){return P*scalar;}

//            Polynom<Type> operator/(Polynom<Type> P);
//            Polynom<Type> operator/(Type scalar);
//            friend Polynom<Type> operator/(Type scalar, Polynom<Type> P){return (P^-1)*scalar;}


//            Polynom<Type> operator^(unsigned scalar);



            void print();
        private:
            unsigned sizeNum, sizeDen;
            Type *num, *den;
            char x;

            void init(Type Num); //ok
            void init(LinAlg::Matrix<Type> Num);
            void init(unsigned NumSize, unsigned DenSize);
            void init(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);
    };

    template<typename Type> // testado
    std::ostream& operator<< (std::ostream& output, PolynomHandler::Polynom<Type>& pol);

    template<typename Type> // testada
    std::string& operator<< (std::string& output, PolynomHandler::Polynom<Type>& pol);

    template<typename Type> // testada
    bool VefDen(const Type *den1, const Type *den2, const unsigned sizeden1, const unsigned sizeden2);

    template <class Type>
    bool isDivisible(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template<typename Type> // testada
    Type* initPointer(const unsigned &Size);

    template<typename Type> // testado
    Type *SumPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template <class Type> // com defeito
    Type *MultPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

    template <typename Type>
    Type *polydiv(const Type *num,const Type *den,const unsigned &numSize,const unsigned &denSize);//sincronizado

    template <typename Type>
    LinAlg::Matrix<Type> Roots(const Type *num,const unsigned &numSize);//sincronizado


//    template <class Type>
//    LinAlg::Matrix<Type> MultPoly(LinAlg::Matrix<Type> value1,
//                                         LinAlg::Matrix<Type> value2)
//    {
//        LinAlg::Matrix<Type> ret;
//        ret.zeros(1,value1.getCols()+value2.getCols() -1);

//        for(unsigned i = 1; i <= value1.getCols(); i++)
//            for(unsigned j = 1; j <= value2.getCols(); j++)
//                ret(1,i+j-1, ret(1,i+j-1) +  value1(1,i)*value2(1,j));

//        return ret;
//    }

//    template <class Type>
//    Polynom<Type>** PolynomMatrix(unsigned rows, unsigned cols)
//    {
//        Polynom<Type> **Ret = new Polynom<Type> *[rows];
//        for (unsigned i = 0; i < rows; i++)
//            Ret[i] = new Polynom<Type> [cols];

//        return Ret;
//    }

//    template <class Type>
//    Polynom<Type>** MMC(Polynom<Type> **P,
//                             unsigned rows, unsigned cols)
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

//    template <class Type>
//    void zeroPoleGain(Polynom<Type> P,
//                      LinAlg::Matrix <Type> Zero,
//                      LinAlg::Matrix <Type> Pole,
//                              Type  gain)
//    {

//    }
}

#include "SistemasdeControle/src/primitiveLibs/polynom.hpp"

#endif // POLYNOM_H
