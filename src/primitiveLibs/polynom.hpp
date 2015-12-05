#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

template <class Type> // testada
PolynomHandler::Polynom<Type>::Polynom(Type Num)
{
    init(Num);
}

template <class Type> //testada
PolynomHandler::Polynom<Type>::Polynom(LinAlg::Matrix<Type> Num)
{
    init(Num);
}

template <class Type> //testada
PolynomHandler::Polynom<Type>::Polynom(const PolynomHandler::Polynom<Type> &CopyPolynom)
{
    this->num = initPointer(CopyPolynom.sizeNum);
    this->den = initPointer(CopyPolynom.sizeDen);
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = CopyPolynom.num[i];

    for(unsigned i = 0; i < this->sizeDen; ++i)
        this->den[i] = CopyPolynom.den[i];
}

template <class Type> // testada
PolynomHandler::Polynom<Type>::Polynom(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den)
{
    init(Num,Den);
}

template <class Type> // testada
PolynomHandler::Polynom<Type>::~Polynom()
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

template <typename Type> // testada
Type* PolynomHandler::Polynom<Type>::initPointer(unsigned Size)
{
    Type *ret;
    //ret = new Type[Size];

    ret = (Type*)calloc((Size+1),(Size+1)*sizeof(Type*));

    return ret;
}


template <class Type>
void PolynomHandler::Polynom<Type>::init(Type Num)
{
    this->num = initPointer(1);
    this->den = initPointer(0);
    this->sizeNum = 1;
    this->sizeDen = 1;
    this->num[0] = Num;
    this->den[0] = 1;
    this->x = 'x';
}

template <class Type>
void PolynomHandler::Polynom<Type>::init(unsigned NumSize, unsigned DenSize)
{
    this->num = initPointer(NumSize);
    this->den = initPointer(DenSize);
    this->sizeNum = NumSize;
    this->sizeDen = DenSize;
    this->x = 'x';
}

template <class Type>
void PolynomHandler::Polynom<Type>::init(LinAlg::Matrix<Type> Num)
{
    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer(Num.getNumberOfColumns());
    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (Type) Num(1, i+1);

    this->sizeDen = 1;
    this->den = initPointer(1);
    this->den[0] = 1;
    this->x = 'x';

}

template <class Type>
void PolynomHandler::Polynom<Type>::init(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den)
{
    using namespace std;

    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer(Num.getNumberOfColumns());
    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (Type) Num(1, i+1);

    this->sizeDen = Den.getNumberOfColumns();
    this->den = initPointer(Den.getNumberOfColumns());
    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = (Type) Den(1 , i+1);
    this->x = 'x';
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator +(PolynomHandler::Polynom<Type> P)
{
    PolynomHandler::Polynom<Type> ret;
    unsigned max;

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

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator -(PolynomHandler::Polynom<Type> P)
{
    PolynomHandler::Polynom<Type> ret;

    P = (-1)*P;

    ret = *this+P;

    return ret;
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator *(Type scalar)
{
    PolynomHandler::Polynom<Type> ret;

    for (unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = scalar*this->num[i];

    ret = *this;

    return ret;
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator /(PolynomHandler::Polynom<Type> P)
{
    PolynomHandler::Polynom<Type> ret;

    ret.setDen(P.num, P.sizeNum);
    ret.setNum(P.den, P.sizeDen);

    return *this*ret;

}

template <class Type>
void PolynomHandler::Polynom<Type>::operator =(PolynomHandler::Polynom<Type> P)
{
    this->setDen(P.den, P.sizeDen);
    this->setNum(P.num, P.sizeNum);
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator *(PolynomHandler::Polynom<Type> P)
{
    PolynomHandler::Polynom<Type> ret;

    ret.num = MultPoly(this->num, P.num, this->sizeNum, P.sizeNum);
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeDen);
    ret.sizeNum = (this->sizeNum + P.sizeNum - 1);
    ret.sizeDen = (this->sizeDen + P.sizeDen - 1);
    ret.x = P.x;

    return ret;

}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator^(unsigned scalar)
{
    PolynomHandler::Polynom<Type> ret;

    if(scalar < 0)
    {
        ret.setNum(this->den, this->sizeDen);
        ret.setDen(this->num, this->sizeNum);
        scalar *= -1;
    }
    else if(scalar > 0)
    {
        ret = *this;
        for (unsigned i = 1; i < scalar; ++i)
            ret = ret*ret;
    }
    else
    {
        ret.num = initPointer(1);
        ret.num[0] = 1;
        ret.den = initPointer(1);
        ret.den[0] = 1;
        ret.sizeNum = 1;
        ret.sizeDen = 1;
    }

    return ret;
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator+(Type scalar)
{
    PolynomHandler::Polynom<Type> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);
    ret = *this + (scalar*ret);

    return ret;
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator-(Type scalar)
{
    PolynomHandler::Polynom<Type> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);

    return *this - (scalar*ret);
}

template <class Type>
PolynomHandler::Polynom<Type> PolynomHandler::Polynom<Type>::operator/(Type scalar)
{
    return *this*(1/scalar);
}

template <class Type>
bool PolynomHandler::Polynom<Type>::VefDen(Type *den1, Type *den2, unsigned sizeden1, unsigned sizeden2)
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

template <class Type>
void PolynomHandler::Polynom<Type>::setNum(Type *Num, unsigned sizenum)
{
    this->num = initPointer(sizenum);
    this->sizeNum = sizenum;

    for (unsigned i = 0; i < sizenum; ++i)
        this->num[i] = Num[i];
}

template <class Type>
void PolynomHandler::Polynom<Type>::setNum(LinAlg::Matrix<Type> Num)
{
    this->num = initPointer(Num.getNumberOfColumns());
    this->sizeNum = Num.getNumberOfColumns();

    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = Num(1,i+1);
}

template <class Type>
void PolynomHandler::Polynom<Type>::setDen(Type *Den, unsigned sizeden)
{
    this->den = initPointer(sizeden);
    this->sizeDen = sizeden;

    for (unsigned i = 0; i < sizeden; ++i)
        this->den[i] = Den[i];
}

template <class Type>
void PolynomHandler::Polynom<Type>::setDen(LinAlg::Matrix<Type> Den)
{
    this->den = initPointer(Den.getNumberOfColumns());
    this->sizeDen = Den.getNumberOfColumns();

    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = Den(1,i+1);
}

template <class Type>
void PolynomHandler::Polynom<Type>::changeVar(char var)
{
    this->x = var;
}

template <class Type>
char PolynomHandler::Polynom<Type>::getVar()
{
    return this->x;
}

template <class Type>
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getNum()
{
    LinAlg::Matrix<Type> ret(1, this->sizeNum);

    for(unsigned i = 0; i < this->sizeNum; ++i)
        ret(1,i+1) = this->num[i];

    return ret;
}

template <class Type>
unsigned PolynomHandler::Polynom<Type>::getNumSize()
{
    return sizeNum;
}

template <class Type>
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getDen()
{
    LinAlg::Matrix<Type> ret(1, this->sizeDen);

    for(unsigned i = 0; i < this->sizeDen; ++i)
        ret(1,i+1) = this->den[i];

    return ret;
}

template <class Type>
unsigned PolynomHandler::Polynom<Type>::getDenSize()
{
    return sizeDen;
}

template <class Type>
void PolynomHandler::Polynom<Type>::print()
{
    if((this->sizeDen != 0)&&(this->sizeNum != 0))
    {
        unsigned maxSize;

        if(this->sizeNum > this->sizeDen)
            maxSize = this->sizeNum;
        else
            maxSize = this->sizeDen;

        if(this->sizeDen == 0) {
            if(this->sizeNum >= 2) {
                for(unsigned i = 0; i < this->sizeNum - 2; ++i) {
                    if(this->num[i] != 0) {
                        if(this->num[i] != 1)
                            std::cout << this->num[i];
                        std::cout << this->x << '^' << this->sizeNum - i - 1 << ' ';
                        if(i != this->sizeNum - 3)
                            std::cout << '+' << ' ';
                    }
                }
                if(this->num[this->sizeNum - 2]  != 0) {
                    if(this->num[this->sizeNum - 2] != 1)
                            std::cout << '+' << ' ' << this->num[this->sizeNum - 2];
                    std::cout << this->x << ' ';
                }
            }
            if(this->num[this->sizeNum - 1] != 0)
                std::cout << '+' << ' ' << this->num[this->sizeNum - 1] << '\n';

        }
        else {
            if(this->sizeNum >= 2) {
                for(unsigned i = 0; i < this->sizeNum - 2; ++i) {
                    if(this->num[i] != 0) {
                        if(this->num[i] != 1)
                            std::cout << this->num[i];
                        std::cout << this->x << '^' << this->sizeNum - i - 1 << ' ';
                        if( i != this->sizeNum - 3)
                           std::cout << '+' << ' ';
                    }
                }
                if(this->num[this->sizeNum - 2] != 0) {
                    if(this->num[this->sizeNum - 2] != 1)
                        std::cout << this->num[this->sizeNum - 2];
                    std::cout << this->x << ' ';
                }
            }
            if(this->num[this->sizeNum - 1] != 0)
                std::cout << '+' << ' ' << this->num[this->sizeNum - 1] << '\n';

            for(unsigned i = 0; i < maxSize; ++i)
                std::cout << '-' << '-' << '-' << '-' << '-';
            std::cout << '\n';

            if(this->sizeDen >= 2) {
                for(unsigned i = 0; i < this->sizeDen - 2; ++i) {
                    if(this->den[i] != 0) {
                        if(this->den[i] != 1)
                            std::cout << this->den[i];
                        std::cout << this->x << '^' << this->sizeDen - i - 1 << ' ';
                        if(i != this->sizeDen - 3)
                           std::cout << '+' << ' ';
                    }
                }
                if(this->den[this->sizeDen - 2] != 0) {
                    if(this->den[this->sizeDen - 2] != 1)
                       std::cout << '+' << ' ' << this->den[this->sizeDen - 2];
                    std::cout << this->x << ' ';
                }
            }
           if(this->den[this->sizeDen - 1] != 0)
               std::cout << '+' << ' ' << this->den[this->sizeDen - 1];
        }
        std::cout << '\n';
    }
}

template <typename Type>
std::ostream& PolynomHandler::operator<< (std::ostream& output, PolynomHandler::Polynom<Type>& pol)
{

    if((pol.getDenSize() != 0)&&(pol.getNumSize() != 0))
    {
        unsigned maxSize;

        if(pol.getNumSize() > pol.getDenSize())
            maxSize = pol.getNumSize();
        else
            maxSize = pol.getDenSize();

        if(pol.getDenSize() == 0) {
            if(pol.getNumSize() >= 2) {
                for(unsigned i = 0; i < pol.getNumSize() - 2; ++i) {
                    if(pol.getNum()(1,i+1) != 0) {
                        if(pol.getNum()(1,i+1) != 1)
                            output << pol.getNum()(1,i+1);
                        output << pol.getVar() << '^' << pol.getNumSize() - i - 1 << ' ';
                        if(i != pol.getNumSize() - 3)
                            output << '+' << ' ';
                    }
                }
                if(pol.getNum()(1, pol.getNumSize() - 1)  != 0) {
                    if(pol.getNum()(1, pol.getNumSize() - 1) != 1)
                            output << '+' << ' ' << pol.getNum()(1,pol.getNumSize() - 1);
                    output << pol.getVar() << ' ';
                }
            }
            if(pol.getNum()(1,pol.getNumSize()) != 0)
                output << '+' << ' ' << pol.getNum()(1,pol.getNumSize()) << '\n';

        }
        else {
            if(pol.getNumSize() >= 2) {
                for(unsigned i = 0; i < pol.getNumSize() - 2; ++i) {
                    if(pol.getNum()(1,i+1) != 0) {
                        if(pol.getNum()(1,i+1) != 1)
                            output << pol.getNum()(1,i+1);
                        output << pol.getVar() << '^' << pol.getNumSize() - i - 1 << ' ';
                        if( i != pol.getNumSize() - 3)
                           output << '+' << ' ';
                    }
                }
                if(pol.getNum()(1,pol.getNumSize() - 1) != 0) {
                    if(pol.getNum()(1,pol.getNumSize() - 1) != 1)
                        output << pol.getNum()(1,pol.getNumSize() - 1);
                    output << pol.getVar() << ' ';
                }
            }
            if(pol.getNum()(1,pol.getNumSize()) != 0)
                output << '+' << ' ' << pol.getNum()(1,pol.getNumSize()) << '\n';

            for(unsigned i = 0; i < maxSize; ++i)
                output << '-' << '-' << '-' << '-' << '-';
            output << '\n';

            if(pol.getDenSize() >= 2) {
                for(unsigned i = 0; i < pol.getDenSize() - 2; ++i) {
                    if(pol.getDen()(1,i+1) != 0) {
                        if(pol.getDen()(1,i+1) != 1)
                            output << pol.getDen()(1,i+1);
                        output << pol.getVar() << '^' << pol.getDenSize() - i - 1 << ' ';
                        if(i != pol.getDenSize() - 3)
                           output << '+' << ' ';
                    }
                }
                if(pol.getDen()(1,pol.getDenSize() - 1) != 0) {
                    if(pol.getDen()(1,pol.getDenSize() - 1) != 1)
                       output << '+' << ' ' << pol.getDen()(1,pol.getDenSize() - 1);
                    output << pol.getVar() << ' ';
                }
            }
           if(pol.getDen()(1,pol.getDenSize()) != 0)
               output << '+' << ' ' << pol.getDen()(1,pol.getDenSize());
        }
        output << '\n';
    }
    return output;
}

template<typename Type>
std::string& PolynomHandler::operator<< (std::string& output, PolynomHandler::Polynom<Type>& pol)
{
    std::stringstream ss;
    ss << pol;
    output = ss.str();
    return output;
}
