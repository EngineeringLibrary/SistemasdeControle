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

/*
void simFunction::GenerateDataFunction()
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

double simFunction::normalize(double input, double xUp,
                              double xDown, double yUp, double yDown)
{
    return ((input - xDown)/(xUp - xDown))*(yUp - yDown) + yDown;
}

void simFunction::SetDataStep(double step)
{
    this->step = step;
}

void simFunction::SetDataLimits(double lMin, double lMax)
{
    this->lMax = lMax;
    this->lMin = lMin;
}

void simFunction::SetInputData(Matrix<double> input)
{
    this->input = input;
}

void simFunction::SetOutputData(Matrix<double> output)
{
    this->output = output;
}

void simFunction::SetFunctionCall(double (*FunctionToCall)(double))
{
    this->FunctionToCall = FunctionToCall;
}

Matrix<double> simFunction::GetInputData()
{
    return this->input;
}

Matrix<double> simFunction::GetOutputData()
{
    return this->output;
}

double simFunction::GetDataStep()
{
    return this->step;
}

double simFunction::GetDataMinLimit()
{
    return this->lMin;
}

double simFunction::GetDataMaxLimit()
{
    return this->lMax;
}

typedef double(*FunctionCall)(double);
FunctionCall simFunction::GetFunctionCall()
{
    return this->FunctionToCall;
}
*/

template class simFunction<float>;
template class simFunction<double>;
