#include "transferfunction.h"

template <class UsedType>
void TransferFunction<UsedType>::initTfNumber()
{
    this->TF = new Polynom<UsedType> *[nRowsTF];
    for (unsigned i = 0; i < nRowsTF; i++)
        this->TF[i] = new Polynom<UsedType> [nRowsTF];
}

template <class UsedType>
void TransferFunction<UsedType>::c2dConversion()
{

}

template <class UsedType>
TransferFunction<UsedType>::TransferFunction(std::string num, std::string den)
{
    Matrix<UsedType> Num(num), Den(den);
    nRowsTF = (unsigned)sqrt(Num.getRows());
    this->initTfNumber();
    sampleTime = 0.1;

    unsigned cont = 1;
    for(unsigned i = 0; i < nRowsTF; i++)
        for (unsigned j = 0; j < nRowsTF; j++)
        {
            this->TF[i][j].init(Num.getLine(cont), Den.getLine(cont));
            cont++;
        }
}

template <class UsedType>
void TransferFunction<UsedType>::printTF()
{
    for(unsigned i = 0; i < nRowsTF; i++)
        for(unsigned j = 0; j < nRowsTF; j++)
        {
            this->TF[i][j].setVar('s');
            this->TF[i][j].print();
        }
}


template <class UsedType>
UsedType TransferFunction<UsedType>::sim(UsedType x)
{

}


template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(Matrix<UsedType> x)
{

}

template <class UsedType>
Matrix<UsedType> TransferFunction<UsedType>::sim(UsedType lsim, UsedType lmax, UsedType step)
{

}

template class TransferFunction<float>;
template class TransferFunction<double>;
