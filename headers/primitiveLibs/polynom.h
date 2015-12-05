#ifndef __POLYNOM_H_INCLUDED
#define __POLYNOM_H_INCLUDED

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace PolynomHandler {
    template <class Type>
    class Polynom
    {
        public:

            Polynom(Type Num);//testada
            Polynom(LinAlg::Matrix<Type> Num); //testada
            Polynom(const Polynom<Type> &CopyPolynom); //testada
            Polynom(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);//testada
            Polynom(): x('x'), sizeDen(0), sizeNum(0), num(NULL), den(NULL){} //testada
            virtual ~Polynom(); //testada

            void changeVar(char var);
            LinAlg::Matrix<Type> getNum();
            unsigned            getNumSize();
            LinAlg::Matrix<Type> getDen();
            unsigned            getDenSize();
            char                getVar();

            void setNum(Type *Num, unsigned sizenum);
            void setNum(LinAlg::Matrix<Type> Num);
            void setDen(Type *Den, unsigned sizeden);
            void setDen(LinAlg::Matrix<Type> Den);

            Polynom<Type> operator+(Polynom<Type> P);
            Polynom<Type> operator+(Type scalar);
            friend Polynom<Type> operator+(Type scalar, Polynom<Type> P){return P+scalar;}

            Polynom<Type> operator-(Polynom<Type> P);
            Polynom<Type> operator-(Type scalar);
            friend Polynom<Type> operator-(Type scalar, Polynom<Type> P){return (-1)*P+scalar;}

            Polynom<Type> operator*(Type scalar);
            Polynom<Type> operator*(Polynom<Type> P);
            friend Polynom<Type> operator*(Type scalar, Polynom<Type> P){return P*scalar;}

            Polynom<Type> operator/(Polynom<Type> P);
            Polynom<Type> operator/(Type scalar);
            friend Polynom<Type> operator/(Type scalar, Polynom<Type> P){return (P^-1)*scalar;}
            void operator=(Polynom<Type> P);


            Polynom<Type> operator^(unsigned scalar);



            void print();
        private:
            unsigned sizeNum, sizeDen;
            Type *num, *den;
            char x;

            void init(Type Num); //ok
            void init(LinAlg::Matrix<Type> Num);
            void init(unsigned NumSize, unsigned DenSize);
            void init(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den);

            Type* initPointer(unsigned Size);

            bool VefDen(Type *den1, Type *den2, unsigned sizeden1, unsigned sizeden2);

    };

    template<typename Type>
    std::ostream& operator<< (std::ostream& output, PolynomHandler::Polynom<Type>& pol);

    template<typename Type>
    std::string& operator<< (std::string& output, PolynomHandler::Polynom<Type>& pol);


//    template <class Type>
//    Type *SumPoly(Type *value1, Type *value2,
//                         unsigned SizeValue1, unsigned SizeValue2)
//    {
//        Type *ret;

//        unsigned min = SizeValue1, max = SizeValue2;

//        if(min < SizeValue2)
//        {
//            min = SizeValue2;
//            max = SizeValue1;
//        }

//        ret = initPointer<Type> (max);
//        for (unsigned i = 1; i <= min; i++)
//            ret[max - i] =  value1[SizeValue1 - i] + value2[SizeValue2 - i];

//        return ret;
//    }

//    template <class Type>
//    Type *SubPoly(Type *value1, Type *value2,
//                         unsigned SizeValue1, unsigned SizeValue2)
//    {
//        Type *ret;

//        unsigned min = SizeValue1, max = SizeValue2;

//        if(min < SizeValue2)
//        {
//            min = SizeValue2;
//            max = SizeValue1;
//        }

//        ret = initPointer<Type> (max);
//        for (unsigned i = 1; i <= min; i++)
//            ret[max - i] =  value1[SizeValue1 - i] - value2[SizeValue2 - i];

//        return ret;
//    }

//    template <class Type>
//    Type *MultPoly(Type *value1, Type *value2,
//                          unsigned SizeValue1, unsigned SizeValue2)
//    {
//        Type *ret;

//        ret = initPointer<Type> (SizeValue1+SizeValue2);
//        for(unsigned i = 0; i < SizeValue1; i++)
//            for(unsigned j = 0; j < SizeValue2; j++)
//                ret[i+j] = ret[i+j] +  value1[i]*value2[j];

//        return ret;
//    }

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
