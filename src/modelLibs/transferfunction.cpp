#include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/modelLibs/conversions.h"

//template <class UsedType>
//void TransferFunction<UsedType>::initTfNumber()
//{
//    this->TF = new PolynomOperations::Polynom<UsedType> *[nRowsTF];
//    for (unsigned i = 0; i < nRowsTF; i++)
//        this->TF[i] = new PolynomOperations::Polynom<UsedType> [nColsTF];
//}

template <class UsedType>
void TransferFunction<UsedType>::c2dConversion()
{
    StateSpace<UsedType> SS = Conversions::tf2ss(*this);
    SS.c2d(this->sampleTime);
    *this = Conversions::ss2tf(SS);
}

template <class UsedType>
void TransferFunction<UsedType>::c2d(UsedType sampleTime)
{
    this->sampleTime = sampleTime;
    this->c2dConversion();
    this->isContinuous = false;
}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction()
{
    sampleTime = 0.1;
}

//template <class UsedType>
//TransferFunction<UsedType>::TransferFunction(LinAlg::Matrix<UsedType> numerators,
//                                             LinAlg::Matrix<UsedType> denominators)
//{
//    nRowsTF = 1;
//    nColsTF = 1;
//    this->initTfNumber();
//    sampleTime = 0.1;

//    unsigned cont = 1;
//    for(unsigned i = 0; i < nRowsTF; i++)
//        for (unsigned j = 0; j < nColsTF; j++)
//        {
////            this->TF[i][j].init(numerators.GetRow(cont), denominators.GetRow(cont));
//            cont++;
//        }
//}

//template <class UsedType>
//TransferFunction<UsedType>::TransferFunction(std::string num, std::string den,
//                                             unsigned rows  , unsigned cols)
//{
//    LinAlg::Matrix<UsedType> Num(num), Den(den);
//    nRowsTF = rows;
//    nColsTF = cols;
//    this->initTfNumber();
//    sampleTime = 0.1;

//    unsigned cont = 1;
//    for(unsigned i = 0; i < nRowsTF; i++)
//        for (unsigned j = 0; j < nColsTF; j++)
//        {
////            this->TF[i][j].init(Num.GetRow(cont), Den.GetColumn(cont));
//            cont++;
//        }
//}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(unsigned rows, unsigned cols)
{
    this->TF = LinAlg::Matrix< PolynomOperations::Polynom<UsedType> > (rows, cols);
    sampleTime = 0.1;
}

template <class UsedType>
PolynomOperations::Polynom<UsedType>& TransferFunction<UsedType>::operator ()(unsigned row, unsigned col)
{
    return this->TF(row, col);
}

template <class UsedType>
PolynomOperations::Polynom<UsedType> TransferFunction<UsedType>::operator ()(unsigned row, unsigned col) const
{
    return (*this)(row,col);
}

template <class UsedType>
void TransferFunction<UsedType>::operator = (TransferFunction TF)
{
    this->sampleTime = TF.sampleTime;
    this->timeSimulation = TF.timeSimulation;
//    this->nRowsTF = TF.nRowsTF;
//    this->initTfNumber();

//    for(unsigned i = 0; i < this->nRowsTF; i++)
//        for(unsigned j = 0; j < this->nRowsTF; j++)
//            this->TF[i][j] = TF.TF[i][j];
}

template <class UsedType>
void TransferFunction<UsedType>::print()
{
//    for(unsigned i = 0; i < nRowsTF; i++)
//        for(unsigned j = 0; j < nColsTF; j++)
//        {
//            if(isContinuous)
//                this->TF[i][j].setVar('s');
//            else
//                this->TF[i][j].setVar('z');
//            this->TF[i][j].print();
//        }
}

template <class UsedType>
void TransferFunction<UsedType>::setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)
{

}

template <class UsedType>
void TransferFunction<UsedType>::setLinearVectorPhi()
{

}

template <class UsedType>
void TransferFunction<UsedType>::setLinearVectorPhiEstimation()
{

}


//template <class UsedType>
//void TransferFunction<UsedType>::setTF(Polynom<UsedType> **TF,
//                                       unsigned rows, unsigned cols)
//{
//    this->TF = PolynomMatrix<UsedType> (rows,cols);
//    nRowsTF = rows;
//    nColsTF = cols;

//    for(unsigned i = 0; i < nRowsTF; i++)
//        for(unsigned j = 0; j < nColsTF; j++)
//        {
//            this->TF[i][j] = TF[i][j];
//        }

//}

//template <class UsedType>
//Polynom<UsedType>** TransferFunction<UsedType>::getTF()
//{
//    Polynom<UsedType> GerPol;
//    Polynom<UsedType> **Ret = PolynomMatrix<UsedType>(nRowsTF,nColsTF);

//    for(unsigned i = 0; i < nRowsTF; i++)
//        for(unsigned j = 0; j < nColsTF; j++)
//        {
//            Ret[i][j] = TF[i][j];
//        }
//    return Ret;
//}

template <class UsedType>
unsigned TransferFunction<UsedType>::getNRowsTF()
{
//    return nRowsTF;
}

template <class UsedType>
unsigned TransferFunction<UsedType>::getNColsTF()
{
//    return nColsTF;
}

template <class UsedType>
UsedType TransferFunction<UsedType>::sim(UsedType x)
{
    return x;
}

template <class UsedType>
UsedType TransferFunction<UsedType>::sim(UsedType x, UsedType y)
{
    return x;
}

template <class UsedType>
LinAlg::Matrix<UsedType> TransferFunction<UsedType>::sim(LinAlg::Matrix<UsedType> x)
{
    return x;
}

template <class UsedType>
LinAlg::Matrix<UsedType> TransferFunction<UsedType>::sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y)
{
    return x;
}

template <class UsedType>
LinAlg::Matrix<UsedType> TransferFunction<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{
}

//template class TransferFunction<int>;
template class TransferFunction<float>;
template class TransferFunction<double>;
