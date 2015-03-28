#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::init(unsigned NumSize)
{
    this->num = initPointer<TypeOfClass>(NumSize);
    this->den = initPointer<TypeOfClass>(0);
    this->sizeNum = NumSize;
    this->sizeDen = 1;
    this->den[0] = 1;
    this->x = 's';
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::init(unsigned NumSize, unsigned DenSize)
{
    this->num = initPointer<TypeOfClass>(NumSize);
    this->den = initPointer<TypeOfClass>(DenSize);
    this->sizeNum = NumSize;
    this->sizeDen = DenSize;
    this->x = 's';
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::init(LinAlg::Matrix<TypeOfClass> Num)
{
    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer<TypeOfClass>(Num.getNumberOfColumns());
    for (int i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (TypeOfClass) Num(1, i+1);

    this->sizeDen = 1;
    this->den = initPointer<TypeOfClass>(1);
    this->den[0] = 1;
    this->x = 's';

}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::init(LinAlg::Matrix<TypeOfClass> Num, LinAlg::Matrix<TypeOfClass> Den)
{
    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer<TypeOfClass>(Num.getNumberOfColumns());
    for (int i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (TypeOfClass) Num(1, i+1);

    this->sizeDen = Den.getNumberOfColumns();
    this->den = initPointer<TypeOfClass>(Den.getNumberOfColumns());
    for (int i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = (TypeOfClass) Den(1 , i+1);
    this->x = 's';
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom()
{
    this->sizeNum = 0;
    this->sizeDen = 0;
    this->x = 's';
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom(unsigned Num)
{
    init(Num);
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom(unsigned Num, unsigned Den)
{
    init(Num, Den);
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom(LinAlg::Matrix<TypeOfClass> Num)
{
    init(Num);
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom(LinAlg::Matrix<TypeOfClass> Num, LinAlg::Matrix<TypeOfClass> Den)
{
    init(Num,Den);
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::Polynom(const PolynomOperations::Polynom<TypeOfClass> &CopyPolynom)
{
    this->num = initPointer<TypeOfClass>(CopyPolynom.sizeNum);
    this->den = initPointer<TypeOfClass>(CopyPolynom.sizeDen);
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = CopyPolynom.num[i];

    for(unsigned i = 0; i < this->sizeDen; ++i)
        this->den[i] = CopyPolynom.den[i];
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>::~Polynom()
{
    if(this->sizeNum != 0 && this->sizeDen != 0)
    {
        delete (this->num);
        delete (this->den);
    }

    this->num = NULL;
    this->den = NULL;

    this->sizeNum = 0;
    this->sizeDen = 0;
}


template<typename TypeOfClass>
PolynomOperations::Polynom<TypeOfClass>& PolynomOperations::Polynom<TypeOfClass>::operator= (const PolynomOperations::Polynom<TypeOfClass>& OtherPolynom)
{
    this->setNum(OtherPolynom.num, OtherPolynom.sizeNum);
    this->setDen(OtherPolynom.den, OtherPolynom.sizeDen);

    return *this;
}

template<typename TypeOfClass> template<typename OtherPolynomType>
PolynomOperations::Polynom<TypeOfClass>& PolynomOperations::Polynom<TypeOfClass>::operator= (const PolynomOperations::Polynom<OtherPolynomType>& OtherPolynom)
{
    this->setNum(OtherPolynom.num, OtherPolynom.sizeNum);
    this->setDen(OtherPolynom.den, OtherPolynom.sizeDen);

    return *this;
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator +(PolynomOperations::Polynom<TypeOfClass> P)
{
    PolynomOperations::Polynom<TypeOfClass> ret;
    int max;

   if(VefDen(this->den, P.den, this->sizeDen, P.sizeDen))
   {
       ret.num = SumPoly(this->num, P.num, this->sizeNum, P.sizeNum);
       ret.setDen(P.den, P.sizeDen);

       max = this->sizeNum;

       if (max < P.sizeNum)
           max = P.sizeNum;

       ret.sizeNum = max;
   }
   else
   {
       ret.num = SumPoly(MultPoly(P.den, this->num, P.sizeDen, this->sizeNum),MultPoly(P.num, this->den, P.sizeNum, this->sizeDen), (P.sizeDen + this->sizeNum - 1),(P.sizeNum + this->sizeDen - 1));
       ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeNum);

       max = (P.sizeDen + this->sizeNum - 1);

       if(max < (P.sizeNum + this->sizeDen - 1))
           max = (P.sizeNum + this->sizeDen - 1);

       ret.sizeNum = max;
       ret.sizeDen = this->sizeDen + P.sizeDen - 1;
   }

   return ret;

}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator -(PolynomOperations::Polynom<TypeOfClass> P)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    P = (-1)*P;

    ret = *this+P;

    return ret;
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator *(TypeOfClass scalar)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    for (int i = 0; i < this->sizeNum; ++i)
        this->num[i] = scalar*this->num[i];

    ret = *this;

    return ret;
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator /(PolynomOperations::Polynom<TypeOfClass> P)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    ret.setDen(P.num, P.sizeNum);
    ret.setNum(P.den, P.sizeDen);

    return *this*ret;

}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator *(PolynomOperations::Polynom<TypeOfClass> P)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    ret.num = MultPoly(this->num, P.num, this->sizeNum, P.sizeNum);
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeDen);
    ret.sizeNum = (this->sizeNum + P.sizeNum - 1);
    ret.sizeDen = (this->sizeDen + P.sizeDen - 1);
    ret.x = P.x;

    return ret;

}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator^(unsigned scalar)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    if(scalar < 0)
    {
        ret.setNum(this->den, this->sizeDen);
        ret.setDen(this->num, this->sizeNum);
        scalar *= -1;
    }
    else if(scalar > 0)
    {
        ret = *this;
        for (int i = 1; i < scalar; ++i)
            ret = ret*ret;
    }
    else
    {
        ret.num = initPointer<TypeOfClass>(1);
        ret.num[0] = 1;
        ret.den = initPointer<TypeOfClass>(1);
        ret.den[0] = 1;
        ret.sizeNum = 1;
        ret.sizeDen = 1;
    }

    return ret;
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator+(TypeOfClass scalar)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);
    ret = *this + (scalar*ret);

    return ret;
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator-(TypeOfClass scalar)
{
    PolynomOperations::Polynom<TypeOfClass> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);

    return *this - (scalar*ret);
}

template <class TypeOfClass>
PolynomOperations::Polynom<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::operator/(TypeOfClass scalar)
{
    return *this*(1/scalar);
}

template <class TypeOfClass>
bool PolynomOperations::Polynom<TypeOfClass>::VefDen(TypeOfClass *den1, TypeOfClass *den2, unsigned sizeden1, unsigned sizeden2)
{
    bool vef = true;

    if (sizeden1 != sizeden2)
        vef = false;
    else
    {
        for (unsigned i = 0; i < sizeden1; ++i)
            if (den1[i] != den2[2])
            {
                break;
                vef = false;
            }
    }

    return vef;
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::setNum(TypeOfClass *Num, unsigned sizenum)
{
    this->num = initPointer<TypeOfClass>(sizenum);
    this->sizeNum = sizenum;

    for (unsigned i = 0; i < sizenum; ++i)
        this->num[i] = Num[i];
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::setNum(LinAlg::Matrix<TypeOfClass> Num)
{
    this->num = initPointer<TypeOfClass>(Num.getNumberOfColumns());
    this->sizeNum = Num.getNumberOfColumns();

    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = Num(1,i+1);
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::setDen(TypeOfClass *Den, unsigned sizeden)
{
    this->den = initPointer<TypeOfClass>(sizeden);
    this->sizeDen = sizeden;

    for (unsigned i = 0; i < sizeden; ++i)
        this->den[i] = Den[i];
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::setDen(LinAlg::Matrix<TypeOfClass> Den)
{
    this->den = initPointer<TypeOfClass>(Den.getNumberOfColumns());
    this->sizeDen = Den.getNumberOfColumns();

    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = Den(1,i+1);
}

template <class TypeOfClass>
void PolynomOperations::Polynom<TypeOfClass>::setVar(char var)
{
    this->x = var;
}

template <class TypeOfClass>
LinAlg::Matrix<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::getNum() const
{
    LinAlg::Matrix<TypeOfClass> ret(1, this->sizeNum);

    for(unsigned i = 0; i < this->sizeNum; ++i)
        ret(1,i+1) = this->num[i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass* PolynomOperations::Polynom<TypeOfClass>::getNumPointer() const
{
    return num;
}

template <class TypeOfClass>
unsigned PolynomOperations::Polynom<TypeOfClass>::getNumSize() const
{
    return sizeNum;
}

template <class TypeOfClass>
LinAlg::Matrix<TypeOfClass> PolynomOperations::Polynom<TypeOfClass>::getDen() const
{
    LinAlg::Matrix<TypeOfClass> ret(1, this->sizeDen);

    for(unsigned i = 0; i < this->sizeDen; ++i)
        ret(1,i+1) = this->den[i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass* PolynomOperations::Polynom<TypeOfClass>::getDenPointer() const
{
    return den;
}

template <class TypeOfClass>
unsigned PolynomOperations::Polynom<TypeOfClass>::getDenSize() const
{
    return sizeDen;
}

template<typename Type>
void PolynomOperations::printPol(std::string& output, const Type *num, unsigned numSize, char x)
{
    if(numSize > 1){
        if(num[0] > 1)
            output += static_cast<std::ostringstream*>(&(std::ostringstream() << num[0]))->str() + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize-1))->str() + ' ';
        else if(num[0] == 1)
            output += " " + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize-1))->str() + ' ';
        else if(num[0] < 0)
            output += "- " + static_cast<std::ostringstream*>(&(std::ostringstream() << -num[0]))->str() + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize-1))->str();

        for(unsigned i = 1; i < numSize - 1; ++i)
        {
            if(num[i] > 0 || num[i] >1)
                output += " + " + static_cast<std::ostringstream*>(&(std::ostringstream() << num[i]))->str() + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize - i - 1))->str() + ' ';
            else if(num[i] == 1)
                output += " + " + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize-i-1))->str() + ' ';
            else if(num[i] < 0)
                output += " - " + static_cast<std::ostringstream*>(&(std::ostringstream() << -num[i]))->str() + x + '^' + static_cast<std::ostringstream*>(&(std::ostringstream() << numSize - i - 1))->str() + ' ';
        }

        if(num[numSize - 1] > 0)
            output + " + " + static_cast<std::ostringstream*>(&(std::ostringstream() << num[numSize - 1]))->str();
        else if(num[numSize - 1] < 0)
            output += " - " + static_cast<std::ostringstream*>(&(std::ostringstream() << -num[numSize - 1]))->str();
    }

    else
        output += static_cast<std::ostringstream*>(&(std::ostringstream() << num[0]))->str();
}

//template<typename Type>
//void PolynomOperations::linePrint(std::string& linesStr, unsigned amount)
//{
//    for(unsigned i = 0; i < amount; ++i)
//        linesStr += '-';
//}

template<typename TypeOfClass>
std::ostream& PolynomOperations::operator<< (std::ostream& output, const PolynomOperations::Polynom<TypeOfClass>& Pol)
{
    std::string numStr, linesStr, denStr;
    printPol(numStr, Pol.getNumPointer(),Pol.getNumSize(), Pol.getVar());
    printPol(denStr, Pol.getDenPointer(),Pol.getDenSize(), Pol.getVar());

    unsigned amount = numStr.length() > denStr.length() ? numStr.length() : denStr.length();

    for(unsigned i = 0; i < amount; ++i)
        linesStr += '-';
//    PolynomOperations::linePrint(linesStr, amount);

    output << (numStr + "\n" + linesStr + "\n" + denStr);

    return output;
}
