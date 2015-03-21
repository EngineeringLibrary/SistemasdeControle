#ifndef __POLYNOM_H_INCLUDED
#define __POLYNOM_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"


template <class TypeOfClass>
class Polynom
{
private:
    unsigned sizeNum, sizeDen;
    TypeOfClass *num, *den;
    char x;

    void init(unsigned NumSize);
    void init(unsigned NumSize, unsigned DenSize);

    void init(std::string Num);
    void init(std::string Num, std::string Den);


    bool VefDen(TypeOfClass *den1, TypeOfClass *den2, unsigned sizeden1, unsigned sizeden2);

public:

    Polynom();
    Polynom(unsigned Num);
    Polynom(unsigned Num, unsigned Den);

    Polynom(std::string Num);
    Polynom(std::string Num, std::string Den);

    Polynom(LinAlg::Matrix<TypeOfClass> Num, LinAlg::Matrix<TypeOfClass> Den);

    Polynom(const Polynom<TypeOfClass> &CopyPolynom);

    ~Polynom();

    void init(LinAlg::Matrix<TypeOfClass> Num, LinAlg::Matrix<TypeOfClass> Den);

    Polynom<TypeOfClass> operator+(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator+(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator+(TypeOfClass scalar, Polynom<TypeOfClass> P){return P+scalar;}

    Polynom<TypeOfClass> operator-(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator-(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator-(TypeOfClass scalar, Polynom<TypeOfClass> P){return (-1)*P+scalar;}

    Polynom<TypeOfClass> operator*(TypeOfClass scalar);
    Polynom<TypeOfClass> operator*(Polynom<TypeOfClass> P);
    friend Polynom<TypeOfClass> operator*(TypeOfClass scalar, Polynom<TypeOfClass> P){return P*scalar;}

    Polynom<TypeOfClass> operator/(Polynom<TypeOfClass> P);
    Polynom<TypeOfClass> operator/(TypeOfClass scalar);
    friend Polynom<TypeOfClass> operator/(TypeOfClass scalar, Polynom<TypeOfClass> P){return (P^-1)*scalar;}
    void operator=(Polynom<TypeOfClass> P);


    Polynom<TypeOfClass> operator^(unsigned scalar);

    void setNum(TypeOfClass *Num, unsigned sizenum);
    void setNum(LinAlg::Matrix<TypeOfClass> Num);
    void setDen(TypeOfClass *Den, unsigned sizeden);
    void setDen(LinAlg::Matrix<TypeOfClass> Den);

    void setVar(char var);

    LinAlg::Matrix<TypeOfClass> getNum();
    unsigned            getNumSize();
    LinAlg::Matrix<TypeOfClass> getDen();
    unsigned            getDenSize();

    void print();
};

template <typename TypeOfClass>
TypeOfClass* initPointer(unsigned Size)
{
    TypeOfClass *ret;
    //ret = new TypeOfClass[Size];

    ret = (TypeOfClass*)calloc((Size+1),(Size+1)*sizeof(TypeOfClass*));

    return ret;
}

template <class TypeOfClass>
TypeOfClass *SumPoly(TypeOfClass *value1, TypeOfClass *value2,
                     unsigned SizeValue1, unsigned SizeValue2)
{
    TypeOfClass *ret;

    unsigned min = SizeValue1, max = SizeValue2;

    if(min < SizeValue2)
    {
        min = SizeValue2;
        max = SizeValue1;
    }

    ret = initPointer<TypeOfClass> (max);
    for (unsigned i = 1; i <= min; i++)
        ret[max - i] =  value1[SizeValue1 - i] + value2[SizeValue2 - i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass *SubPoly(TypeOfClass *value1, TypeOfClass *value2,
                     unsigned SizeValue1, unsigned SizeValue2)
{
    TypeOfClass *ret;

    unsigned min = SizeValue1, max = SizeValue2;

    if(min < SizeValue2)
    {
        min = SizeValue2;
        max = SizeValue1;
    }

    ret = initPointer<TypeOfClass> (max);
    for (unsigned i = 1; i <= min; i++)
        ret[max - i] =  value1[SizeValue1 - i] - value2[SizeValue2 - i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass *MultPoly(TypeOfClass *value1, TypeOfClass *value2,
                      unsigned SizeValue1, unsigned SizeValue2)
{
    TypeOfClass *ret;

    ret = initPointer<TypeOfClass> (SizeValue1+SizeValue2);
    for(unsigned i = 0; i < SizeValue1; i++)
        for(unsigned j = 0; j < SizeValue2; j++)
            ret[i+j] = ret[i+j] +  value1[i]*value2[j];

    return ret;
}

template <class TypeOfClass>
LinAlg::Matrix<TypeOfClass> MultPoly(LinAlg::Matrix<TypeOfClass> value1,
                                     LinAlg::Matrix<TypeOfClass> value2)
{
    LinAlg::Matrix<TypeOfClass> ret;
    ret.zeros(1,value1.getCols()+value2.getCols() -1);

    for(unsigned i = 1; i <= value1.getCols(); i++)
        for(unsigned j = 1; j <= value2.getCols(); j++)
            ret(1,i+j-1, ret(1,i+j-1) +  value1(1,i)*value2(1,j));

    return ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass>** PolynomMatrix(unsigned rows, unsigned cols)
{
    Polynom<TypeOfClass> **Ret = new Polynom<TypeOfClass> *[rows];
    for (unsigned i = 0; i < rows; i++)
        Ret[i] = new Polynom<TypeOfClass> [cols];

    return Ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass>** MMC(Polynom<TypeOfClass> **P,
                         unsigned rows, unsigned cols)
{
    Polynom<TypeOfClass> **Ret = PolynomMatrix<TypeOfClass> (rows,cols);


    for(unsigned k = 0; k < rows; k++)
    {
        for(unsigned l = 0; l < cols; l++)
        {
           LinAlg::Matrix<TypeOfClass> den = P[k][l].getDen();
           LinAlg::Matrix<TypeOfClass> num = P[k][l].getNum();

            for(unsigned i = 0; i < rows; i++)
                for(unsigned j = 0; j < cols; j++)
                {
                    if((i == k) && (j == l))
                    {}
                    else
                    {
                        den = MultPoly(den, P[i][j].getDen());
//                        sizeDen = sizeDen + P[i][j].getDenSize() - 1;

                        num = MultPoly(num, P[i][j].getDen());
//                        sizeNum = sizeNum + P[i][j].getDenSize() - 1;
                    }
                }

            Ret[k][l].setNum(num);
            Ret[k][l].setDen(den);
//            Ret[k][l].print();
        }
    }
    return Ret;
}

template <class TypeOfClass>
void zeroPoleGain(Polynom<TypeOfClass> P,
                  LinAlg::Matrix <TypeOfClass> Zero,
                  LinAlg::Matrix <TypeOfClass> Pole,
                          TypeOfClass  gain)
{

}


#endif // POLYNOM_H
