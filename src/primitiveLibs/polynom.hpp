#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

template <typename Type> // testada
PolynomHandler::Polynom<Type>::Polynom(const Type &Num)
{
    init(LinAlg::Matrix<Type>(Num),LinAlg::Matrix<Type>(1.0));
}

template <typename Type> //testada
PolynomHandler::Polynom<Type>::Polynom(const LinAlg::Matrix<Type> &Num)
{
    init(Num,LinAlg::Matrix<Type>(1.0));
}

template <typename Type> //testada
PolynomHandler::Polynom<Type>::Polynom(const PolynomHandler::Polynom<Type> &CopyPolynom)
{
    this->num = new Type[CopyPolynom.sizeNum]();
    this->den = new Type[CopyPolynom.sizeDen]();
    this->sizeNum = CopyPolynom.sizeNum;
    this->sizeDen = CopyPolynom.sizeDen;
    this->x = CopyPolynom.x;

    for(unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = CopyPolynom.num[i];

    for(unsigned i = 0; i < this->sizeDen; ++i)
        this->den[i] = CopyPolynom.den[i];
}

template <typename Type> // testada
PolynomHandler::Polynom<Type>::Polynom(const LinAlg::Matrix<Type> &Num, const LinAlg::Matrix<Type> &Den)
{
    init(Num,Den);
}

template <typename Type> // testada
PolynomHandler::Polynom<Type>::~Polynom()
{
    if(this->sizeNum != 0)
        delete this->num;

    if(this->sizeDen != 0)
        delete this->den;

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
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getNum() const
{
    LinAlg::Matrix<Type> ret(1, this->sizeNum);

    for(unsigned i = 0; i < this->sizeNum; ++i)
        ret(1,i+1) = this->num[i];

    return ret;
}

template <typename Type> // testada
LinAlg::Matrix<Type> PolynomHandler::Polynom<Type>::getDen() const
{
    LinAlg::Matrix<Type> ret(1, this->sizeDen);

    for(unsigned i = 0; i < this->sizeDen; ++i)
        ret(1,i+1) = this->den[i];

    return ret;
}

template <typename Type> // testada
void PolynomHandler::Polynom<Type>::setNum(const Type *Num, const unsigned sizenum)
{
    this->num = new Type[sizenum]();
    this->sizeNum = sizenum;

    for (unsigned i = 0; i < sizenum; ++i)
        this->num[i] = Num[i];
}

template <typename Type> //testada
void PolynomHandler::Polynom<Type>::setNum(const LinAlg::Matrix<Type> &Num)
{
    this->num = new Type[Num.getNumberOfColumns()]();
    this->sizeNum = Num.getNumberOfColumns();

    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = Num(1,i+1);
}

template <typename Type> //testada
void PolynomHandler::Polynom<Type>::setDen(const Type *Den, const unsigned sizeden)
{
    this->den = new Type[sizeden]();
    this->sizeDen = sizeden;

    for (unsigned i = 0; i < sizeden; ++i)
        this->den[i] = Den[i];
}

template <typename Type> // testada
void PolynomHandler::Polynom<Type>::setDen(const LinAlg::Matrix<Type> &Den)
{
    this->den = new Type[Den.getNumberOfColumns()]();
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

//    if(isZero())
//    {
//        delete(this->den);
//        this->den = NULL;
//        this->sizeDen = 0;
//    }
    *this = PolynomHandler::simplify(*this);
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
//       std::cout << rhs << (*this);
       ret.num = SumPoly(MultPoly(rhs.den, this->num, rhs.sizeDen, this->sizeNum),MultPoly(rhs.num, this->den, rhs.sizeNum, this->sizeDen), (rhs.sizeDen + this->sizeNum - 1),(rhs.sizeNum + this->sizeDen - 1));
       ret.den = MultPoly(this->den, rhs.den, this->sizeDen, rhs.sizeDen);

       max = (rhs.sizeDen + this->sizeNum - 1);

       if(max < (rhs.sizeNum + this->sizeDen - 1))
           max = (rhs.sizeNum + this->sizeDen - 1);

       ret.sizeNum = max;
       ret.sizeDen = this->sizeDen + rhs.sizeDen - 1;
   }

   *this = ret;
//   if(isZero())
//   {
//       delete(this->den);
//       this->den = NULL;
//       this->sizeDen = 0;
//   }
   *this = PolynomHandler::simplify(*this);
   return *this;
}

template <typename Type> //Testada
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator-= (const Type& rhs)
{
    *this *= -1;
    *this += rhs;
    *this *= -1;
//    if(isZero())
//    {
//        delete(this->den);
//        this->den = NULL;
//        this->sizeDen = 0;
//    }
    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator-= (const PolynomHandler::Polynom<RightType>& rhs)
{
    *this *= -1;
//    std::cout << (*this);
    *this += rhs;
//    std::cout << (*this);
    *this *= -1;
//    std::cout << (*this);
//    if(isZero())
//    {
//        delete(this->den);
//        this->den = NULL;
//        this->sizeDen = 0;
//    }
    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator*= (const Type& rhs /*scalar*/)
{
    for (unsigned i = 0; i < this->sizeNum; ++i)
        this->num[i] = rhs*this->num[i];

    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator*= (const PolynomHandler::Polynom<RightType>& rhs)
{
    this->num = MultPoly(this->num, rhs.num, this->sizeNum, rhs.sizeNum);
    this->den = MultPoly(this->den, rhs.den, this->sizeDen, rhs.sizeDen);
    this->sizeNum = this->sizeNum + rhs.sizeNum - 1;
    this->sizeDen = this->sizeDen + rhs.sizeDen - 1;
    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator/= (const Type& rhs /*scalar*/)
{
    *this *= (1/rhs);
    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type> template<typename RightType>
PolynomHandler::Polynom<Type>& PolynomHandler::Polynom<Type>::operator/= (const PolynomHandler::Polynom<RightType>& rhs)
{
    PolynomHandler::Polynom<Type> ret;

    ret.setDen(rhs.num, rhs.sizeNum);
    ret.setNum(rhs.den, rhs.sizeDen);
    *this *= ret;
    *this = PolynomHandler::simplify(*this);
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
//        std::cout << ret*ret;
        for (int i = 1; i < exp; ++i){
            ret *= ret;
            std::cout << ret;
        }
    }
    else
    {
        ret.num = new Type[1]();
        ret.num[0] = 1;
        ret.den = new Type[1]();
        ret.den[0] = 1;
        ret.sizeNum = 1;
        ret.sizeDen = 1;
    }
    *this = ret;
    *this = PolynomHandler::simplify(*this);
    return *this;
}

template <typename Type>
void PolynomHandler::Polynom<Type>::init(const LinAlg::Matrix<Type> &Num, const LinAlg::Matrix<Type> &Den)
{
    using namespace std;

    this->sizeNum = Num.getNumberOfColumns();
    //this->num = initPointer<Type>(Num.getNumberOfColumns());
    this->num = new Type[Num.getNumberOfColumns()]();
    for (unsigned i = 0; i < Num.getNumberOfColumns(); ++i)
        this->num[i] = (Type) Num(1, i+1);

    this->sizeDen = Den.getNumberOfColumns();
    this->den = new Type[Den.getNumberOfColumns()]();
    for (unsigned i = 0; i < Den.getNumberOfColumns(); ++i)
        this->den[i] = (Type) Den(1 , i+1);
    this->x = 'x';
}

template <typename Type>
bool PolynomHandler::Polynom<Type>::isZero()
{
    unsigned counter = 0;
    for(unsigned i = 0; i < this->sizeNum; ++i)
        if(this->num[i] != 0)
            counter++;

    if(counter == this->sizeNum)
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
std::string PolynomHandler::printSmallPolynom(LinAlg::Matrix<Type> rhs, const char &variable)
{
    std::ostringstream ret;
    for(unsigned i = 1; i < rhs.getNumberOfColumns(); ++i){
        if(rhs(1,i) == 0)
            rhs.removeColumn(1);
        else
            break;
    }
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
            ret << std::setw(2*3+1) << std::setprecision(3) << std::fixed << rhs(1,i);
        else if((rhs(1,i) != -1 && rhs(1,i) < 0)|| ((i == Size) && (rhs(1,i) < 0)))
            ret << std::setw(2*3+1) << std::setprecision(3) << std::fixed << -rhs(1,i);

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
            if (den1[i] != den2[i])
            {
                vef = false;
                break;
            }
    }

    return vef;
}

//template <typename Type>
//bool PolynomHandler::isDivisible(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize)
//{

//}

template <typename Type> //testada
Type* PolynomHandler::SumPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize)
{
    unsigned min = lhsSize, max = rhsSize; Type *ret = new Type[max+1]();
    for(unsigned i = 0; i <= rhsSize; ++i)
        ret[i] = rhs[i];

    if(min > rhsSize)
    {
        min = rhsSize; max = lhsSize; ret = new Type[max+1]();
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
    Type *ret = new Type [lhsSize+rhsSize-1]();

    for(unsigned i = 0; i < lhsSize; ++i)
        for(unsigned j = 0; j < rhsSize; ++j)
        {
            ret[i+j] += lhs[i]*rhs[j];
        }

    return ret;
}

template <class Type> // com defeito
LinAlg::Matrix<Type> PolynomHandler::MultPoly(const LinAlg::Matrix<Type> &lhs, const LinAlg::Matrix<Type> &rhs)
{
    unsigned lhsSize = lhs.getNumberOfColumns();
    unsigned rhsSize = rhs.getNumberOfColumns();
    LinAlg::Matrix<Type>ret(1,lhsSize+rhsSize-1);

    for(unsigned i = 0; i < lhsSize; ++i)
        for(unsigned j = 0; j < rhsSize; ++j)
        {
            ret(1,i+j+1) += lhs(1,i+1)*rhs(1,j+1);
        }

    return ret;
}

template <class Type>//falta testar
PolynomHandler::Polynom<Type> PolynomHandler::simplify(const PolynomHandler::Polynom<Type> &P)
{
    LinAlg::Matrix<Type> num = P.getNum();
    LinAlg::Matrix<Type> den = P.getDen();

    LinAlg::Matrix<Type> numRoots = Roots<Type>(num);
//    std::cout << num << numRoots;
    LinAlg::Matrix<Type> denRoots = Roots<Type>(den);
//    std::cout << den << denRoots;
    unsigned counter = 0;
    for(unsigned i = 1; i <= numRoots.getNumberOfRows(); ++i){
        for(unsigned j = 1; j <= denRoots.getNumberOfRows(); ++j)
            if(fabs(denRoots(j,1) - numRoots(i-counter,1)) < 0.05 && fabs(denRoots(j,2) - numRoots(i-counter,2)) < 0.05)
            {
                numRoots.removeRow(i - counter);
                denRoots.removeRow(j);
                ++counter;
                break;
            }
        if(i == numRoots.getNumberOfRows() && counter == 0)
            return Polynom<Type>(num,den);

    }

    LinAlg::Matrix<Type> numPol = Root2Poly(numRoots);
    if(numPol.getNumberOfColumns() == 0)
        numPol = LinAlg::Matrix<Type>(num(1,1));
    else
        numPol *= num(1,1);
    LinAlg::Matrix<Type> denPol = Root2Poly(denRoots);
//    std::cout << denRoots;
    if(denPol.getNumberOfColumns() == 0)
        denPol = LinAlg::Matrix<Type>(den(1,1));
    else
        denPol *= den(1,1);
    return Polynom<Type>(numPol,denPol);
}

template<class Type>
LinAlg::Matrix<Type> PolynomHandler::Roots(LinAlg::Matrix<Type> smallPoly)
{   
    unsigned zeroRoots;
    for(zeroRoots = 0; zeroRoots < smallPoly.getNumberOfColumns(); ++zeroRoots){
        if(smallPoly(1,smallPoly.getNumberOfColumns() - zeroRoots) == 0){
            smallPoly.removeColumn(smallPoly.getNumberOfColumns() - zeroRoots);
        }
        else
            break;
    }
    for(unsigned i = 1; i < smallPoly.getNumberOfColumns(); ++i){
        if(smallPoly(1,i) == 0)
            smallPoly.removeColumn(1);
        else
            break;
    }

    //const Type *num;
    if(smallPoly.getNumberOfColumns() <= 1)
        return LinAlg::Matrix<Type>();
    else if(smallPoly.getNumberOfColumns() == 2){
        LinAlg::Matrix<Type> root(1,2);
        root(1,1) = -smallPoly(1,2)/smallPoly(1,1);
        return root;
    }
    else if(smallPoly.getNumberOfColumns() == 3){
        LinAlg::Matrix<Type> mat(2,2);
        double a = smallPoly(1,1),b = smallPoly(1,2),c = smallPoly(1,3);
        double delt = (b*b) - 4 * c * a;

        if(delt < 0){
            mat(1,1) = -b / 2 * a;
            mat(1,2) = sqrt(-delt) / 2 * a;
            mat(2,1) = -b / 2 * a;
            mat(2,2) = -sqrt(-delt) / 2 * a;
        }else{
           mat(1,1) = (-b + sqrt(delt)) / 2 * a;
           mat(2,1) = (-b - sqrt(delt)) / 2 * a;
        }

        return LinAlg::Zeros<Type>(zeroRoots,2)||mat;
    }
    else
    {
        LinAlg::Matrix<Type>root;
        unsigned numSize = smallPoly.getNumberOfColumns();
        LinAlg::Matrix<Type> poly_Monic(1,numSize-1);
        for(unsigned j = 2; j <= numSize; ++j)
        {
            poly_Monic(1,j-1) = -smallPoly(1,j)/smallPoly(1,1);
        }

        root = poly_Monic||(LinAlg::Eye<Type> (numSize-2) | LinAlg::Zeros<Type> (numSize-2,1));
//        std::cout << "roots" << LinAlg::EigenValues(root);
        return LinAlg::Zeros<Type>(zeroRoots,2)||LinAlg::EigenValues(root);
    }
}

template <typename Type>
LinAlg::Matrix<Type> PolynomHandler::Root2Poly(const LinAlg::Matrix<Type> &root)
{
    if(root.getNumberOfColumns() == 0)
        return LinAlg::Matrix<Type>();

    unsigned n = root.getNumberOfRows();
    LinAlg::Matrix<Type> ret(1,n+1);
    std::complex<Type> *tempPoly = new std::complex<Type> [2]();
    tempPoly[0] = 1;
    tempPoly[1] = std::complex<Type>(-root(1,1),-root(1,2));
    std::complex<Type> * tempRoot = new std::complex<Type>[2]();

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
