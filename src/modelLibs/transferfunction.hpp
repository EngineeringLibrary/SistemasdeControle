#include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/modelLibs/conversions.h"

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(ARX<Type> gz)
{
//    LinAlg::Matrix<Type> gzParmeters = gz.getModelCoef();
//    this->nColsTF = gz.getNumberOfInputs();
//    this->nRowsTF = gz.getNumberOfOutputs();
//    this->initTfNumber();
//    this->sampleTime = gz.getSampleTime();

//    for(unsigned i = 0; i < this->nRowsTF; i++)
//        for (unsigned j = 0; j < this->nColsTF; j++)
//        {
//            unsigned posTemp = 1 + i*(gz.getNumberOfInputDelays() + gz.getNumberOfOutputDelays());
//            this->TF[i][j].init(gzParmeters(from(posTemp) --> posTemp + gz.getNumberOfOutputDelays() - 1,i+1), gzParmeters(from(posTemp + gz.getNumberOfOutputDelays()) --> posTemp + gz.getNumberOfOutputDelays() + gz.getNumberOfInputDelays(),i+1));
//        }
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(unsigned rows, unsigned cols)
{
    this->sampleTime     = 0.1;
    this->isContinuous   = 1;
    this->timeSimulation = 10;

    this->TF = LinAlg::Matrix< PolynomHandler::Polynom<Type> >(rows, cols);
}

template <typename Type>
ModelHandler::TransferFunction<Type>::TransferFunction(LinAlg::Matrix< PolynomHandler::Polynom<Type> > TF)
{
    this->TF = TF;
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
std::ostream& ModelHandler::TransferFunction<Type>::print()
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
    ModelHandler::StateSpace<Type> SS = Conversions::tf2ss(*this);
    SS.c2d(this->sampleTime);
    *this = Conversions::ss2tf(SS);
}
