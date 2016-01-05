#include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/modelLibs/conversions.h"

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols)
{
    this->var            = 's';
    this->sampleTime     = 0.1;
    this->Continuous   = 1;
    this->timeSimulation = 10;

    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(const PolynomHandler::Polynom<Type> &TFSISO)
{
    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(1,1);

    this->TF(1,1)        = TFSISO;
    this->var            = 's';
    this->sampleTime     = 0.1;
    this->Continuous   = 1;
    this->timeSimulation = 10;
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF)
{
    this->TF = TF;
}

template <typename Type>
bool ModelHandler::TransferFunction<Type>::isContinuous() const
{
    return this->Continuous;
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfRows() const
{
    return this->TF.getNumberOfRows();
}

template <typename Type>
unsigned ModelHandler::TransferFunction<Type>::getNumberOfColumns() const
{
    return this->TF.getNumberOfColumns();
}

template <typename Type>
double ModelHandler::TransferFunction<Type>::getSampleTime() const
{
    return this->sampleTime;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setContinuous(const bool &continuous)
{
    this->Continuous = continuous;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setSampleTime(const double &sampleTime)
{
    this->sampleTime = sampleTime;
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

template <typename Type>
void ModelHandler::TransferFunction<Type>::setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output)
{

}

template <typename Type>
void ModelHandler::TransferFunction<Type>::c2d(Type sampleTime)
{
    this->sampleTime = sampleTime;
    this->c2dConversion();
    this->isContinuous = false;
}


template <typename Type>
PolynomHandler::Polynom<Type>& ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column)
{
    return this->TF(row, column);
}

template <typename Type>
PolynomHandler::Polynom<Type> ModelHandler::TransferFunction<Type>::operator ()(unsigned row, unsigned column) const
{
    return this->TF(row, column);
}


template <typename Type>
void ModelHandler::TransferFunction<Type>::operator= (const PolynomHandler::Polynom<Type> &rhs)
{
    this->TF(1,1) = rhs;
}

template <typename Type>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<Type>& otherTransferFunction)
{
    this->TF = otherTransferFunction.TF;

    this->sampleTime     = otherTransferFunction.sampleTime;
    this->isContinuous   = otherTransferFunction.isContinuous;
    this->timeSimulation = otherTransferFunction.timeSimulation;

    return *this;
}

template <typename Type> template<typename OtherTransferFunctionType>
ModelHandler::TransferFunction<Type>& ModelHandler::TransferFunction<Type>::operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction)
{
    this->TF = otherTransferFunction.TF;

    this->sampleTime     = otherTransferFunction.sampleTime;
    this->isContinuous   = otherTransferFunction.isContinuous;
    this->timeSimulation = otherTransferFunction.timeSimulation;

    return *this;
}

template <typename Type>
std::string ModelHandler::TransferFunction<Type>::print()
{    
    unsigned rows = this->TF.getNumberOfRows(), columns = this->TF.getNumberOfColumns();
    std::string polyNum[rows][columns];
    std::string polyDen[rows][columns];
    std::string numSpace[rows][columns], denSpace[rows][columns], midLine[rows][columns];
    unsigned maxSize[rows][columns];
    std::string output;
    for(unsigned i = 1; i <= rows; ++i)
    {
        for(unsigned j = 1; j <= columns; ++j)
            polyNum[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getNum(),this->var);

        for(unsigned j = 1; j <= columns; ++j)
            polyDen[i-1][j-1] = PolynomHandler::printSmallPolynom(this->TF(i,j).getDen(),this->var);

        for(unsigned j = 0; j < columns; ++j)
        {
            maxSize[i-1][j] = polyNum[i-1][j].length();
            if(maxSize[i-1][j] < polyDen[i-1][j].length())
                maxSize[i-1][j] = polyDen[i-1][j].length();
            maxSize[i-1][j] += 6;

            for(unsigned k = 0; k < unsigned(abs((maxSize[i-1][j] - polyNum[i-1][j].length())/2)); ++k)
                numSpace[i-1][j] += ' ';
            for(unsigned k = 0; k < maxSize[i-1][j]; ++k)
                midLine[i-1][j] += '-';
            for(unsigned k = 0; k < unsigned(abs((maxSize[i-1][j] - polyDen[i-1][j].length())/2)); ++k)
                denSpace[i-1][j] += ' ';
        }

        for(unsigned j = 0; j < columns; ++j)
            output += numSpace[i-1][j] + polyNum[i-1][j] + numSpace[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += midLine[i-1][j] + "      ";
        output += '\n';

        for(unsigned j = 0; j < columns; ++j)
            output += denSpace[i-1][j] + polyDen[i-1][j] + denSpace[i-1][j] + "      ";
        output += '\n'; output += '\n';
    }

    return output;
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x)
{
    return x;
}

template <typename Type>
Type ModelHandler::TransferFunction<Type>::sim(Type x, Type y)
{
    return x;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x)
{
    return x;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y)
{
    return x;
}

template <typename Type>
LinAlg::Matrix<Type> ModelHandler::TransferFunction<Type>::sim(Type lsim, Type lmax, Type step)
{
}

template <typename Type>
void ModelHandler::TransferFunction<Type>::c2dConversion()
{
//    ModelHandler::StateSpace<Type> SS = Conversions::tf2ss(*this);
//    SS.c2d(this->sampleTime);
    this->var = 'z';
//    *this = Conversions::ss2tf(SS);
}

template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF)
{
    if(TF.isContinuous())
    {
        output << "The continuous transfer function is:\n\n";
        output << TF.print();
    }
    else
    {
        output << "The discrete transfer function is:\n\n";
        output << TF.print() << "\n";
        output << "The sample time is: " << TF.getSampleTime();
    }
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::TransferFunction<Type> TF)
{
    std::stringstream ss;
    ss << TF;
    output += ss.str();
    return output;
}
