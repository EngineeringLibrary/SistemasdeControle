#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

template <typename Type> // testada
PolynomHandler::Polynom<Type>::Polynom(Type Num)
{
    init(Num,1);
}

template <typename Type> //testada
PolynomHandler::Polynom<Type>::Polynom(LinAlg::Matrix<Type> Num)
{
    init(Num,LinAlg::Matrix<Type>(1.0));
}

template <typename Type> //testada
PolynomHandler::Polynom<Type>::Polynom(const PolynomHandler::Polynom<Type> &CopyPolynom)
{
    this->num = PolynomHandler::initPointer<Type>(CopyPolynom.sizeNum);
    this->den = PolynomHandler::initPointer<Type>(CopyPolynom.sizeDen);
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = CopyPolynom.num[i];

    for(unsigned i = 0; i < this->sizeDen; ++i)
        this->den[i] = CopyPolynom.den[i];
}

template <typename Type> // testada
PolynomHandler::Polynom<Type>::Polynom(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den)
{
    init(Num,Den);
}

template <typename Type> // testada
PolynomHandler::Polynom<Type>::~Polynom()
{
    if(this->sizeNum != 0)
        free (this->num);

    if(this->sizeDen != 0)
        free (this->den);

    this->num = NULL;
    this->den = NULL;

    this->sizeNum = 0;
    this->sizeDen = 0;
}

template <typename Type> //testada
char PolynomHandler::Polynom<Type>::getVar() const
{
    return this->x;
}

template <typename Type> // testada
void PolynomHandler::Polynom<Type>::changeVar(char var)
{
    this->x = var;
}

template <typename Type> //testada
unsigned PolynomHandler::Polynom<Type>::getNumSize() const
{
    return this->sizeNum;
}

template <typename Type> //testada
unsigned PolynomHandler::Polynom<Type>::getDenSize() const
{
    return this->sizeDen;
}

template <typename Type> //testada
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getNum()
{
    LinAlg::Matrix<Type> ret(1, this->sizeNum);

    for(unsigned i = 0; i < this->sizeNum; ++i)
        ret(1,i+1) = this->num[i];

    return ret;
}

template <typename Type> // testada
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getDen()
{
    LinAlg::Matrix<Type> ret(1, this->sizeDen);

    for(unsigned i = 0; i < this->sizeDen; ++i)
        ret(1,i+1) = this->den[i];

    return ret;
}

template <typename Type> // testada
void PolynomHandler::Polynom<Type>::setNum(Type *Num, unsigned sizenum)
{
    this->num = initPointer<Type>(sizenum);
    this->sizeNum = sizenum;

    for (unsigned i = 0; i < sizenum; ++i)
        this->num[i] = Num[i];
}

template <typename Type> //testada
void PolynomHandler::Polynom<Type>::setNum(LinAlg::Matrix<Type> Num)
{
    this->num = initPointer<Type>(Num.getNumberOfColumns());
    this->sizeNum = Num.getNumberOfColumns();

    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = Num(1,i+1);
}

template <typename Type> //testada
void PolynomHandler::Polynom<Type>::setDen(Type *Den, unsigned sizeden)
{
    this->den = initPointer<Type>(sizeden);
    this->sizeDen = sizeden;

    for (unsigned i = 0; i < sizeden; ++i)
        this->den[i] = Den[i];
}

template <typename Type> // testada
void PolynomHandler::Polynom<Type>::setDen(LinAlg::Matrix<Type> Den)
{
    this->den = initPointer<Type>(Den.getNumberOfColumns());
    this->sizeDen = Den.getNumberOfColumns();

    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = Den(1,i+1);
}

template <typename Type> // testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator= (const PolynomHandler::Polynom<Type>& OtherPolynom)
{
    this->setDen(OtherPolynom.den, OtherPolynom.sizeDen);
    this->setNum(OtherPolynom.num, OtherPolynom.sizeNum);

    return *this;
}

template <typename Type> template<typename OtherPolynomType> // testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator= (const PolynomHandler::Polynom<OtherPolynomType>& OtherPolynom)
{
    this->setDen(OtherPolynom.den, OtherPolynom.sizeDen);
    this->setNum(OtherPolynom.num, OtherPolynom.sizeNum);

    return *this;
}

template <typename Type> //Testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator+= (const Type& scalar)
{
    PolynomHandler::Polynom<Type> ret(scalar);
    ret.setNum(this->den, this->sizeDen);
    ret.setDen(this->den, this->sizeDen);
    for(unsigned i = 0; i < ret.sizeNum; ++i)
        ret.num[i] = ret.num[i]*scalar;

    this->num = PolynomHandler::SumPoly<Type>(this->num, ret.num, this->sizeNum, ret.sizeNum);

    unsigned max = this->sizeNum, min = this->sizeDen;
    if(min > max)
    {
        max = this->sizeDen; min = this->sizeNum;
    }
    this->sizeNum = max;

    if(isZero())
    {
        free(this->den);
        this->den = NULL;
        this->sizeDen = 0;
    }
    return *this;
}

template <typename Type> template<typename RightType>//testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator+= (const PolynomHandler::Polynom<RightType>& rhs)
{
    PolynomHandler::Polynom<Type> ret;
    unsigned max;

   if(VefDen(this->den, rhs.den, this->sizeDen, rhs.sizeDen))
   {
       ret.num = SumPoly(this->num, rhs.num, this->sizeNum, rhs.sizeNum);
       ret.setDen(rhs.den, rhs.sizeDen);

       max = this->sizeNum;

       if (max < rhs.sizeNum)
           max = rhs.sizeNum;

       ret.sizeNum = max;
   }
   else
   {
       ret.num = SumPoly(MultPoly(rhs.den, this->num, rhs.sizeDen, this->sizeNum),MultPoly(rhs.num, this->den, rhs.sizeNum, this->sizeDen), (rhs.sizeDen + this->sizeNum - 1),(rhs.sizeNum + this->sizeDen - 1));
       ret.den = MultPoly(this->den, rhs.den, this->sizeDen, rhs.sizeDen);

       max = (rhs.sizeDen + this->sizeNum - 1);

       if(max < (rhs.sizeNum + this->sizeDen - 1))
           max = (rhs.sizeNum + this->sizeDen - 1);

       ret.sizeNum = max;
       ret.sizeDen = this->sizeDen + rhs.sizeDen - 1;
   }
   *this = ret;
   if(isZero())
   {
       free(this->den);
       this->den = NULL;
       this->sizeDen = 0;
   }
   return *this;
}

template <typename Type> //Testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator-= (const Type& rhs)
{
    *this *= -1;
    *this += rhs;
    *this *= -1;
    if(isZero())
    {
        free(this->den);
        this->den = NULL;
        this->sizeDen = 0;
    }
    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator-= (const PolynomHandler::Polynom<RightType>& rhs)
{
    *this *= -1;
    *this += rhs;
    *this *= -1;
    if(isZero())
    {
        free(this->den);
        this->den = NULL;
        this->sizeDen = 0;
    }
    return *this;
}

template <typename Type>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator*= (const Type& rhs /*scalar*/)
{
    for (unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = rhs*this->num[i];

    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator*= (const PolynomHandler::Polynom<RightType>& rhs)
{
    this->num = MultPoly(this->num, rhs.num, this->sizeNum, rhs.sizeNum);
    this->den = MultPoly(this->den, rhs.den, this->sizeDen, rhs.sizeDen);
    this->sizeNum = this->sizeNum + rhs.sizeNum - 1;
    this->sizeDen = this->sizeDen + rhs.sizeDen - 1;
    return *this;
}

template <typename Type>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator/= (const Type& rhs /*scalar*/)
{
    *this *= (1/rhs);
    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator/= (const PolynomHandler::Polynom<RightType>& rhs)
{
    PolynomHandler::Polynom<Type> ret;

    ret.setDen(rhs.num, rhs.sizeNum);
    ret.setNum(rhs.den, rhs.sizeDen);
    *this *= ret;
    return *this;
}

template <typename Type>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator^= (const int &exp)
{
    PolynomHandler::Polynom<Type> ret;

    if(exp != 0)
    {
        if(exp < 0)
        {
            ret.setNum(this->den, this->sizeDen);
            ret.setDen(this->num, this->sizeNum);
        }
        else
        {
            ret = *this;
        }

        for (int i = 1; i < exp; ++i)
            ret *= ret;
    }
    else
    {
        ret.num = initPointer<Type>(1);
        ret.num[0] = 1;
        ret.den = initPointer<Type>(1);
        ret.den[0] = 1;
        ret.sizeNum = 1;
        ret.sizeDen = 1;
    }
    *this = ret;

    return *this;
}

template <typename Type>
void PolynomHandler::Polynom<Type>::init(Type Num)
{
    this->num = initPointer<Type>(1);
    this->den = initPointer<Type>(0);
    this->sizeNum = 1;
    this->sizeDen = 1;
    this->num[0] = Num;
    this->den[0] = 1;
    this->x = 'x';
}

template <typename Type>
void PolynomHandler::Polynom<Type>::init(unsigned NumSize, unsigned DenSize)
{
    this->num = initPointer<Type>(NumSize);
    this->den = initPointer<Type>(DenSize);
    this->sizeNum = NumSize;
    this->sizeDen = DenSize;
    this->x = 'x';
}

template <typename Type>
void PolynomHandler::Polynom<Type>::init(LinAlg::Matrix<Type> Num)
{
    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer(Num.getNumberOfColumns());
    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (Type) Num(1, i+1);

    this->sizeDen = 1;
    this->den = initPointer<Type>(1);
    this->den[0] = 1;
    this->x = 'x';

}

template <typename Type>
void PolynomHandler::Polynom<Type>::init(LinAlg::Matrix<Type> Num, LinAlg::Matrix<Type> Den)

{
    using namespace std;

    this->sizeNum = Num.getNumberOfColumns();
    this->num = initPointer<Type>(Num.getNumberOfColumns());
    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (Type) Num(1, i+1);

    this->sizeDen = Den.getNumberOfColumns();
    this->den = initPointer<Type>(Den.getNumberOfColumns());
    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = (Type) Den(1 , i+1);
    this->x = 'x';
}

template <typename Type>
bool PolynomHandler::Polynom<Type>::isZero()
{
    for(unsigned i = 0; i < this->sizeNum; ++i)
        if(this->num[i] != 0)
            return 0;

    return 1;
}

template <typename PolynomType>
std::ostream& PolynomHandler::operator<< (std::ostream& output, PolynomHandler::Polynom<PolynomType> rhs)
{
    std::string polyNum = PolynomHandler::printSmallPolynom<PolynomType>(rhs.getNum(), rhs.getVar());
    std::string polyDen = PolynomHandler::printSmallPolynom<PolynomType>(rhs.getDen(), rhs.getVar());
    std::string numSpace, denSpace, midLine;

    unsigned maxSize = polyNum.length();
    if(maxSize < polyDen.length())
        maxSize = polyDen.length();

    maxSize += 6;

    for(unsigned i = 0; i < unsigned(abs((maxSize - polyNum.length())/2)); ++i)
        numSpace += ' ';
    for(unsigned i = 0; i < maxSize; ++i)
        midLine += '-';
    for(unsigned i = 0; i < unsigned(abs((maxSize - polyDen.length())/2)); ++i)
        denSpace += ' ';

    output << numSpace << polyNum << numSpace << '\n';
    output << midLine << '\n';
    output << denSpace << polyDen << denSpace << '\n';

    return output;
}

template<typename Type>
std::string& PolynomHandler::operator<< (std::string& output, PolynomHandler::Polynom<Type> rhs)
{
    std::stringstream ss;
    ss << rhs;
    output = ss.str();
    return output;
}

template<typename Type>
std::string PolynomHandler::printSmallPolynom(const LinAlg::Matrix<Type> &rhs, const char &variable)
{
    std::ostringstream ret;
    const char plusSignal  = '+';
    const char minusSignal = '-';
    unsigned Size = rhs.getNumberOfColumns();

    if(Size == 0)
        return ret.str();

    for(unsigned i = 1; i <= Size; ++i)
    {
        if(i != 1 && rhs(1,i) > 0)
        {
            ret << plusSignal << ' ';
        }
        else if(rhs(1,i) < 0)
        {
            ret << minusSignal << ' ';
        }

        if(((rhs(1,i) != 1) && (rhs(1,i) > 0)) || ((i == Size) && (rhs(1,i) > 0)))
            ret << rhs(1,i);
        else if((rhs(1,i) != -1 && rhs(1,i) < 0)|| ((i == Size) && (rhs(1,i) < 0)))
            ret << -rhs(1,i);

        if(Size-i > 0 && rhs(1,i) != 0)
        {
            ret << variable;
            if(i != Size-1)
            {
                ret << '^';
                ret << Size-i;
            }
        }

        ret << ' ';
    }

    return ret.str();
}

template <typename Type>
bool PolynomHandler::VefDen(const Type *den1, const Type *den2, const unsigned &sizeden1, const unsigned &sizeden2)
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

//template <typename Type>
//bool PolynomHandler::isDivisible(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize)
//{

//}

template <typename Type>
Type* PolynomHandler::initPointer(const unsigned &Size)
{
    return (Type*)calloc((Size+1),(Size+1)*sizeof(Type*));
}

template <typename Type> //testada
Type* PolynomHandler::SumPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize)
{
    Type *ret;
    unsigned min = lhsSize, max = rhsSize; ret = new Type[max];
    for(unsigned i = 0; i <= rhsSize; ++i)
        ret[i] = rhs[i];

    if(min > rhsSize)
    {
        min = rhsSize; max = lhsSize; ret = new Type[max];
        for(unsigned i = 0; i <= rhsSize; ++i)
            ret[i] = lhs[i];
    }

    for (unsigned i = 1; i <= min; ++i)
        ret[max - i] =  lhs[lhsSize - i] + rhs[rhsSize - i];

    return ret;
}

template <class Type> // verificar
Type *PolynomHandler::MultPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize)
{
    Type *ret;

    ret = (Type*)calloc((lhsSize+rhsSize+1),(lhsSize+rhsSize+1)*sizeof(Type*));
    for(unsigned i = 0; i < lhsSize; ++i)
        for(unsigned j = 0; j < rhsSize; ++j)
        {
            ret[i+j] = ret[i+j] +  lhs[i]*rhs[j];
        }

    return ret;
}

template <class Type> // com defeito
LinAlg::Matrix<Type> PolynomHandler::MultPoly(const LinAlg::Matrix<Type> &lhs, const LinAlg::Matrix<Type> &rhs)
{
    unsigned lhsSize = lhs.getNumberOfColumns();
    unsigned rhsSize = rhs.getNumberOfColumns();
    LinAlg::Matrix<Type>ret(1,lhsSize+rhsSize+1);

    for(unsigned i = 0; i < lhsSize; ++i)
        for(unsigned j = 0; j < rhsSize; ++j)
        {
            ret(1,i+j+1) = ret(1,i+j+1) +  lhs(1,i+1)*rhs(1,j+1);
        }

    return ret;
}

template <class Type>//falta testar
PolynomHandler::Polynom<Type> PolynomHandler::simplify(const Type *num,const Type *den,const unsigned &numSize,const unsigned &denSize)
{
    LinAlg::Matrix<Type> numRoots = Roots<Type>(num, numSize);
    LinAlg::Matrix<Type> denRoots = Roots<Type>(den, denSize);
    unsigned equalRootsCount = 0;

    for(unsigned i = 1; i <= numRoots.getNumberOfRows(); ++i)
          if(PolynomHandler::rootsContainRoot(numRoots(i,1),denRoots))
              ++equalRootsCount;

    LinAlg::Matrix<Type>  newNumRoots(numSize - equalRootsCount,2);
    LinAlg::Matrix<Type>  newDenRoots(denSize - equalRootsCount,2);

    unsigned cont = 1;
    for(unsigned i = 1; i <= numRoots.getNumberOfRows(); ++i)
        if(!PolynomHandler::rootsContainRoot(numRoots(i,1),denRoots))
        {
            newNumRoots(cont,1) = numRoots(i,1);
            newNumRoots(cont,2) = numRoots(i,2);
            cont++;
        }

    cont = 1;
    for(unsigned i = 1; i <= denRoots.getNumberOfRows(); ++i)
        if(!PolynomHandler::rootsContainRoot(denRoots(1,i),numRoots))
        {
            newDenRoots(cont,1) = denRoots(i,1);
            newDenRoots(cont,2) = denRoots(i,2);
            cont++;
        }

    return Polynom<Type>(Root2Poly(newNumRoots),Root2Poly(newDenRoots));

//   return ret;
}

template<class Type>
LinAlg::Matrix<Type> PolynomHandler::Roots(const Type *num,const unsigned &numSize)
{
    LinAlg::Matrix<Type> poly_num(1,numSize-1);
    for(unsigned j = 1; j < numSize; ++j)
    {
        poly_num(1,j) = -num[j]/num[0];
    }
    LinAlg::Matrix<Type>rootNum = poly_num||(LinAlg::Eye<Type> (numSize-2) | LinAlg::Zeros<Type> (numSize-2,1));

    return rootNum;
}

template <typename Type>
LinAlg::Matrix<Type> PolynomHandler::Root2Poly(const LinAlg::Matrix<Type> &root)
{
    unsigned n = root.getNumberOfRows();
    LinAlg::Matrix<Type> ret(1,n+1);
    std::complex<Type> *tempPoly = new std::complex<Type> [2];
    tempPoly[0] = 1;
    tempPoly[1] = std::complex<Type>(-root(1,1),-root(1,2));
    std::complex<Type> * tempRoot = new std::complex<Type>[2];

    unsigned sizeTempPoly = 2;
    tempRoot[0] = 1;
    for(unsigned i = 2; i <= n ; ++i)
    {
        tempRoot[1] = std::complex<Type>(-root(i,1),-root(i,2));//apos o templade entre (real,imaginario) atribuição
        tempPoly = PolynomHandler::MultPoly(tempPoly,tempRoot,sizeTempPoly,2);
        sizeTempPoly++;
    }
    for(unsigned i = 0; i < sizeTempPoly; ++i)
    {
        ret(1,i+1) = tempPoly[i].real();
    }
    return ret;
}

template <typename Type>
bool PolynomHandler::rootsContainRoot(const Type &root, const LinAlg::Matrix<Type> &roots)
{
    for(unsigned i = 1; i <= roots.getNumberOfRows(); ++i)
    {
        if(root == roots(1,i))
            return 1;
    }
    return 0;
}
