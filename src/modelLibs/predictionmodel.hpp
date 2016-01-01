#include "SistemasdeControle/headers/modelLibs/predictionmodel.h"

template <typename Type>
ModelHandler::PredictionModel<Type>::PredictionModel(
              ModelHandler::IntegrativeModel<Type> IM,
              unsigned HorizontePredicaoMin, unsigned HorizontePredicaoMax,
              unsigned HorizonteControle)
{
    this->HorizonteControle = HorizonteControle;
    this->HorizontePredicaoMax = HorizontePredicaoMax;
    this->HorizontePredicaoMin = HorizontePredicaoMin;
    this->Continuous = IM.isContinuous();

    if(Continuous)
    {

    }else{

        for(unsigned i = this->HorizontePredicaoMin; i <= this->HorizontePredicaoMax; ++i)
            this->Ad = (this->Ad || IM.getA()^i);

        for(unsigned j = 0; j <= this->HorizontePredicaoMin - 1; ++j)
        {
            LinAlg::Matrix<Type> Btemp = LinAlg::Zeros<Type>(j*IM.getB().getNumberOfRows(),
                                                               IM.getB().getNumberOfColumns());

            for(unsigned i = this->HorizontePredicaoMin - 1 + j;  i <= this->HorizontePredicaoMax - 1; ++i)
            {
                Btemp = (Btemp || (IM.getA()^i)*IM.getB());
            }
            this->B = (this->B | Btemp);
        }

        LinAlg::Matrix<Type> zerosC = LinAlg::Zeros<Type>(IM.getC().getNumberOfRows(), IM.getC().getNumberOfColumns());

        for(unsigned i = this->HorizontePredicaoMin; i <= this->HorizontePredicaoMax; ++i)
        {
            LinAlg::Matrix<Type> Ctemp;
            for(unsigned j = this->HorizontePredicaoMin; j <= this->HorizontePredicaoMax; ++j)
            {
                if(i == j)
                {
                    Ctemp = (Ctemp || IM.getC());
                }else
                {
                    Ctemp = (Ctemp || zerosC);
                }
            }
            this->C = (this->C | Ctemp);
        }
    }

    this->D = IM.getD();
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::getA() const
{
    if(this->Continuous)
        return this->A;
    else
        return this->Ad;
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::getB() const
{
    if(this->Continuous)
        return this->B;
    else
        return this->Bd;
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::getC() const
{
    return this->C;
}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::getD() const
{
    return this->D;
}

template <class Type>
void ModelHandler::PredictionModel<Type>::setContinuous(bool Continuous)
{
    this->Continuous = Continuous;
}

template <class Type>
void ModelHandler::PredictionModel<Type>::setSampleTime(double SampleTime)
{
    this->SampleTime = SampleTime;
}

template <class Type>
void ModelHandler::PredictionModel<Type>::setInitialState(LinAlg::Matrix<Type> X0)
{
    this->initialState = X0;
}

template <class Type>
void ModelHandler::PredictionModel<Type>::SetObserverParameter(LinAlg::Matrix<Type> L)
{
    this->L = L;
}

template <class Type>
bool ModelHandler::PredictionModel<Type>::isContinuous()  const
{
    return Continuous;
}

template <class Type>
bool ModelHandler::PredictionModel<Type>::isObservable()  const
{

}

template <class Type>
bool ModelHandler::PredictionModel<Type>::isControlable() const
{

}

template <class Type>
Type ModelHandler::PredictionModel<Type>::sim(Type u)
{

}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::sim(LinAlg::Matrix<Type> u)
{

}

template <class Type>
LinAlg::Matrix<Type> ModelHandler::PredictionModel<Type>::sim(Type lmin, Type lmax, Type step)
{

}

template <class Type>
std::string ModelHandler::PredictionModel<Type>::print()
{
    std::string output;

    if(this->Continuous == true){
        output += "The Continuous Predictive Model is: \n\nA = \n";
        output << this->A; output += "\n\nB = \n";
        output << this->B; output += "\n\nC = \n";

    }else{
        output += "The Discrete Predictive Model is: \n\nA = \n";
        output << this->Ad; output += "\n\nB = \n";
        output << this->Bd; output += "\n\nC = \n";
    }

    output << this->C; output += "\n\nD = \n";
    output << this->D; output += '\n';

    return output;
}

template<typename Type>
std::ostream& ModelHandler::operator<< (std::ostream& output, ModelHandler::PredictionModel<Type> IM)
{
    output << IM.print();
    return output;
}

template<typename Type>
std::string& ModelHandler::operator<< (std::string& output, ModelHandler::PredictionModel<Type> IM)
{
    output += IM.print();
    return output;
}

