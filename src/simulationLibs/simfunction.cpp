#include "simfunction.h"

template<class UsedType>
simFunction<UsedType>::simFunction(UsedType (*FunctionToCall)(UsedType))
{
    this->FunctionToCall = FunctionToCall;
}

template <class UsedType>
UsedType simFunction<UsedType>::sim(UsedType input)
{
    input = ((*this->FunctionToCall)(input));
    return (input);
}

template<class UsedType>
Matrix<UsedType> simFunction<UsedType>::sim(Matrix<UsedType> X)
{
    Matrix<UsedType> Y;

    for(int i = 1; i < X.getRows(); i++)
        for(int j = 1; j < X.getRows(); j++)
            Y(i,j, sim(X(i,j)));

    return Y;
}

template<class UsedType>
Matrix<UsedType> simFunction<UsedType>::sim(UsedType lmim, UsedType lmax, UsedType step)
{
    unsigned i = 1;
    Matrix<UsedType> Y;

    for(UsedType x = lmim; x <= lmax; x+= step)
    {
        Y(i,1, sim(x));
        i++;
    }

    return Y;
}

template <class UsedType>
void simFunction<UsedType>::GenerateDataFunction()
{
    int tam  = (int)((this->lMax - this->lMin)/this->step);
    int cont = 1;
    this->input.init(1,tam);

    for (double i = this->lMin; i < this->lMax; i += this->step)
    {
        this->input(1,cont,i);
        this->output(1,cont,this->FunctionCalculation(i));
        cont++;
    }
}
template <class UsedType>
double simFunction<UsedType>::normalize(double input, double xUp,
                              double xDown, double yUp, double yDown)
{
    return ((input - xDown)/(xUp - xDown))*(yUp - yDown) + yDown;
}

template <class UsedType>
void simFunction<UsedType>::SetDataStep(double step)
{
    this->step = step;
}

template <class UsedType>
void simFunction<UsedType>::SetDataLimits(double lMin, double lMax)
{
    this->lMax = lMax;
    this->lMin = lMin;
}

template <class UsedType>
void simFunction<UsedType>::SetInputData(Matrix<double> input)
{
    this->input = input;
}

template <class UsedType>
void simFunction<UsedType>::SetOutputData(Matrix<double> output)
{
    this->output = output;
}

template <class UsedType>
void simFunction<UsedType>::SetFunctionCall(double (*FunctionToCall)(double))
{
    this->FunctionToCall = FunctionToCall;
}

template <class UsedType>
Matrix<double> simFunction<UsedType>::GetInputData()
{
    return this->input;
}

template <class UsedType>
Matrix<double> simFunction<UsedType>::GetOutputData()
{
    return this->output;
}

template <class UsedType>
double simFunction<UsedType>::GetDataStep()
{
    return this->step;
}

template <class UsedType>
double simFunction<UsedType>::GetDataMinLimit()
{
    return this->lMin;
}

template <class UsedType>
double simFunction<UsedType>::GetDataMaxLimit()
{
    return this->lMax;
}


typedef double(*FunctionCall)(double);
template <class UsedType>
FunctionCall simFunction<UsedType>::GetFunctionCall()
{
    return this->FunctionToCall;
}


template class simFunction<float>;
template class simFunction<double>;
