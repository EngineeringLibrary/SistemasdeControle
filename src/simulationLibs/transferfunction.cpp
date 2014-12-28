#include "transferfunction.h"
#include "src/simulationLibs/statespace.h"
#include "src/simulationLibs/conversions.h"

template <class UsedType>
void TransferFunction<UsedType>::initTfNumber()
{
    this->TF = new Polynom<UsedType> *[nRowsTF];
    for (unsigned i = 0; i < nRowsTF; i++)
        this->TF[i] = new Polynom<UsedType> [nColsTF];
}

template <class UsedType>
void TransferFunction<UsedType>::c2dConversion()
{
    StateSpace<UsedType> SS = conversions::tf2ss(*this);
    SS.c2d(this->sampleTime);
    *this = conversions::ss2tf(SS);
}

template <class UsedType>
void TransferFunction<UsedType>::c2d(UsedType sampleTime)
{
    this->sampleTime = sampleTime;
    this->c2dConversion();
    this->isContinuous = false;
}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(std::string num, std::string den,
                                             unsigned rows  , unsigned cols)
{
    Matrix<UsedType> Num(num), Den(den);
    nRowsTF = rows;
    nColsTF = cols;
    this->initTfNumber();
    sampleTime = 0.1;

    unsigned cont = 1;
    for(unsigned i = 0; i < nRowsTF; i++)
        for (unsigned j = 0; j < nColsTF; j++)
        {
            this->TF[i][j].init(Num.getLine(cont), Den.getLine(cont));
            cont++;
        }
}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(unsigned rows, unsigned cols)
{
    nRowsTF = rows;
    nColsTF = cols;
    this->initTfNumber();
    sampleTime = 0.1;
}

template <class UsedType>
Polynom<UsedType> TransferFunction<UsedType>::operator ()(unsigned row, unsigned col)
{
    Polynom<UsedType> Ret(this->TF[row-1][col-1].getNum(),
                          this->TF[row-1][col-1].getDen());

    return Ret;
}

template <class UsedType>
void TransferFunction<UsedType>::operator ()(unsigned row, unsigned col, Polynom<UsedType> P)
{
    this->TF[row-1][col-1] = P;
}

template <class UsedType>
void TransferFunction<UsedType>::operator =(TransferFunction TF)
{
    this->sampleTime = TF.sampleTime;
    this->timeSimulation = TF.timeSimulation;
    this->nRowsTF = TF.nRowsTF;
    this->initTfNumber();

    for(unsigned i = 0; i < this->nRowsTF; i++)
        for(unsigned j = 0; j < this->nRowsTF; j++)
            this->TF[i][j] = TF.TF[i][j];
}

template <class UsedType>
void TransferFunction<UsedType>::print()
{
    for(unsigned i = 0; i < nRowsTF; i++)
        for(unsigned j = 0; j < nColsTF; j++)
        {
            if(isContinuous)
                this->TF[i][j].setVar('s');
            else
                this->TF[i][j].setVar('z');
            this->TF[i][j].print();
        }
}


template <class UsedType>
void TransferFunction<UsedType>::setTF(Polynom<UsedType> **TF,
                                       unsigned rows, unsigned cols)
{
    this->TF = PolynomMatrix<UsedType> (rows,cols);
    nRowsTF = rows;
    nColsTF = cols;

    for(unsigned i = 0; i < nRowsTF; i++)
        for(unsigned j = 0; j < nColsTF; j++)
        {
            this->TF[i][j] = TF[i][j];
        }

}

template <class UsedType>
Polynom<UsedType>** TransferFunction<UsedType>::getTF()
{
    Polynom<UsedType> GerPol;
    Polynom<UsedType> **Ret = PolynomMatrix<UsedType>(nRowsTF,nColsTF);

    for(unsigned i = 0; i < nRowsTF; i++)
        for(unsigned j = 0; j < nColsTF; j++)
        {
            Ret[i][j] = TF[i][j];
        }
    return Ret;
}

template <class UsedType>
unsigned TransferFunction<UsedType>::getNRowsTF()
{
    return nRowsTF;
}

template <class UsedType>
unsigned TransferFunction<UsedType>::getNColsTF()
{
    return nColsTF;
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
Matrix<UsedType> TransferFunction<UsedType>::sim(Matrix<UsedType> x)
{
    return x;
}

template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(Matrix<UsedType> x, Matrix<UsedType> y)
{
    return x;
}

template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{
}

//template class TransferFunction<int>;
template class TransferFunction<float>;
template class TransferFunction<double>;
