#include "polynom.h"

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom()
{
    this->x = 's';
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(int Num, int Den)
{
    init(Num, Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(std::string Num, std::string Den)
{
    init(Num, Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(Matrix<TypeOfClass> Num, Matrix<TypeOfClass> Den)
{
    init(Num,Den);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(std::string Num)
{
    init(Num);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(int Num)
{
    init(Num);
}

template <class TypeOfClass>
Polynom<TypeOfClass>::Polynom(const Polynom<TypeOfClass> &CopyPolynom)
{
    this->num = initPointer(CopyPolynom.sizeNum);
    this->den = initPointer(CopyPolynom.sizeDen);
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(int i = 0; i < this->sizeNum; i++)
        this->num[i] = CopyPolynom.num[i];

    for(int i = 0; i < this->sizeDen; i++)
        this->den[i] = CopyPolynom.den[i];
}

template <class TypeOfClass>
Polynom<TypeOfClass>::~Polynom()
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

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::initPointer(int Size)
{
    TypeOfClass *ret;
    //ret = new TypeOfClass[Size];

    ret = (TypeOfClass*)calloc((Size+1),(Size+1)*sizeof(TypeOfClass*));

    return ret;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(int NumSize)
{
    this->num = initPointer(NumSize);
    this->den = initPointer(0);
    this->sizeNum = NumSize;
    this->sizeDen = 1;
    this->den[0] = 1;
    this->x = 's';
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(int NumSize, int DenSize)
{
    this->num = initPointer(NumSize);
    this->den = initPointer(DenSize);
    this->sizeNum = NumSize;
    this->sizeDen = DenSize;
    this->x = 's';
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(std::string Num)
{
    using namespace std;

    Matrix<TypeOfClass> tempNum;

    tempNum = Num;
    this->sizeNum = tempNum.getCols();
    this->num = initPointer(tempNum.getCols());
    for (int i = 0; i < tempNum.getCols(); i++)
        this->num[i] = (TypeOfClass) tempNum(1, i+1);

    this->sizeDen = 1;
    this->den = initPointer(1);
    this->den[0] = 1;
    this->x = 's';

}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(std::string Num, std::string Den)
{
    using namespace std;

    Matrix<TypeOfClass> tempNum, tempDen;

    tempNum = Num;
    this->sizeNum = tempNum.getCols();
    this->num = initPointer(tempNum.getCols());
    for (int i = 0; i < tempNum.getCols(); i++)
        this->num[i] = (TypeOfClass) tempNum(1, i+1);

    tempDen = Den;
    this->sizeDen = tempDen.getCols();
    this->den = initPointer(tempDen.getCols());
    for (int i = 0; i < tempDen.getCols(); i++)
        this->den[i] = (TypeOfClass) tempDen(1 , i+1);
    this->x = 's';
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::init(Matrix<TypeOfClass> Num, Matrix<TypeOfClass> Den)
{
    using namespace std;

    this->sizeNum = Num.getCols();
    this->num = initPointer(Num.getCols());
    for (int i = 0; i < Num.getCols(); i++)
        this->num[i] = (TypeOfClass) Num(1, i+1);

    this->sizeDen = Den.getCols();
    this->den = initPointer(Den.getCols());
    for (int i = 0; i < Den.getCols(); i++)
        this->den[i] = (TypeOfClass) Den(1 , i+1);
    this->x = 's';
}



template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator +(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;
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
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator -(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    P = (-1)*P;

    ret = *this+P;

    return ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator *(TypeOfClass scalar)
{
    Polynom<TypeOfClass> ret;

    for (int i = 0; i < this->sizeNum; i++)
        this->num[i] = scalar*this->num[i];

    ret = *this;

    return ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator /(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    ret.setDen(P.num, P.sizeNum);
    ret.setNum(P.den, P.sizeDen);

    return *this*ret;

}

template <class TypeOfClass>
void Polynom<TypeOfClass>::operator =(Polynom<TypeOfClass> P)
{
    this->setDen(P.den, P.sizeDen);
    this->setNum(P.num, P.sizeNum);
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator *(Polynom<TypeOfClass> P)
{
    Polynom<TypeOfClass> ret;

    ret.num = MultPoly(this->num, P.num, this->sizeNum, P.sizeNum);
    ret.den = MultPoly(this->den, P.den, this->sizeDen, P.sizeDen);
    ret.sizeNum = (this->sizeNum + P.sizeNum - 1);
    ret.sizeDen = (this->sizeDen + P.sizeDen - 1);
    ret.x = P.x;

    return ret;

}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator^(int scalar)
{
    Polynom<TypeOfClass> ret;

    if(scalar < 0)
    {
        ret.setNum(this->den, this->sizeDen);
        ret.setDen(this->num, this->sizeNum);
        scalar *= -1;
    }
    else if(scalar > 0)
    {
        ret = *this;
        for (int i = 1; i < scalar; i++)
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

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator+(TypeOfClass scalar)
{
    Polynom<TypeOfClass> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);
    ret = *this + (scalar*ret);

    return ret;
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator-(TypeOfClass scalar)
{
    Polynom<TypeOfClass> ret;

    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);

    return *this - (scalar*ret);
}

template <class TypeOfClass>
Polynom<TypeOfClass> Polynom<TypeOfClass>::operator/(TypeOfClass scalar)
{
    return *this*(1/scalar);
}

template <class TypeOfClass>
bool Polynom<TypeOfClass>::VefDen(TypeOfClass *den1, TypeOfClass *den2, int sizeden1, int sizeden2)
{
    bool vef = true;

    if (sizeden1 != sizeden2)
        vef = false;
    else
    {
        for (int i = 0; i < sizeden1; i++)
            if (den1[i] != den2[2])
            {
                break;
                vef = false;
            }
    }

    return vef;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::setNum(TypeOfClass *Num, int sizenum)
{
    this->num = initPointer(sizenum);
    this->sizeNum = sizenum;

    for (int i = 0; i < sizenum; i++)
        this->num[i] = Num[i];
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::setDen(TypeOfClass *Den, int sizeden)
{
    this->den = initPointer(sizeden);
    this->sizeDen = sizeden;

    for (int i = 0; i < sizeden; i++)
        this->den[i] = Den[i];
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::setVar(char var)
{
    this->x = var;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::SumPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
   TypeOfClass *ret;

   int min = SizeValue1, max = SizeValue2;

   if(min < SizeValue2)
   {
       min = SizeValue2;
       max = SizeValue1;
   }

   ret = initPointer(max);
   for (int i = 1; i <= min; i++)
       ret[max - i] =  value1[SizeValue1 - i] + value2[SizeValue2 - i];

   return ret;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::SubPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
    TypeOfClass *ret;

    int min = SizeValue1, max = SizeValue2;

    if(min < SizeValue2)
    {
        min = SizeValue2;
        max = SizeValue1;
    }

    ret = initPointer(max);
    for (int i = 1; i <= min; i++)
        ret[max - i] =  value1[SizeValue1 - i] - value2[SizeValue2 - i];

    return ret;
}

template <class TypeOfClass>
TypeOfClass *Polynom<TypeOfClass>::MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2)
{
    TypeOfClass *ret;

    ret = initPointer(SizeValue1+SizeValue2);
    for(int i = 0; i < SizeValue1; i++)
        for(int j = 0; j < SizeValue2; j++)
            ret[i+j] = ret[i+j] +  value1[i]*value2[j];

    return ret;
}

template <class TypeOfClass>
Matrix<TypeOfClass> Polynom<TypeOfClass>::getNum()
{
    Matrix<TypeOfClass> ret(1, this->sizeNum);

    for(int i = 0; i < this->sizeNum; i++)
        ret(1,i+1, this->num[i]);

    return ret;
}

template <class TypeOfClass>
Matrix<TypeOfClass> Polynom<TypeOfClass>::getDen()
{
    Matrix<TypeOfClass> ret(1, this->sizeDen);

    for(int i = 0; i < this->sizeDen; i++)
        ret(1,i+1, this->den[i]);

    return ret;
}

template <class TypeOfClass>
void Polynom<TypeOfClass>::print()
{
    unsigned int maxSize;

        if(this->sizeNum > this->sizeDen)
            maxSize = this->sizeNum;
        else
            maxSize = this->sizeDen;

        if(this->sizeDen == 0) {
            if(this->sizeNum >= 2) {
                for(unsigned i = 0; i < this->sizeNum - 2; i++) {
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
                for(unsigned i = 0; i < this->sizeNum - 2; i++) {
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

            for(unsigned i = 0; i < maxSize; i++)
                std::cout << '-' << '-' << '-' << '-' << '-';
            std::cout << '\n';

            if(this->sizeDen >= 2) {
                for(unsigned i = 0; i < this->sizeDen - 2; i++) {
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

template class Polynom <int>;
template class Polynom <float>;
template class Polynom <double>;


