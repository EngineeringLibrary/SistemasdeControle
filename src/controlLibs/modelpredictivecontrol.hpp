#include "SistemasdeControle/headers/controlLibs/modelpredictivecontrol.h"

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::ModelPredictiveControl(ModelHandler::PredictionModel<Type> PM)
{

}

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::ModelPredictiveControl(ModelHandler::PredictionModel<Type> PM, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R)
{

}

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::ModelPredictiveControl(ModelHandler::PredictionModel<Type> PM, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{
    this->K = (((~PM.getB())*(~PM.getC())*Q*PM.getC()*PM.getB()+R )^-1)*(~PM.getB())*(~PM.getC())*(~Q);
    this->W = W;
    this->PM = PM;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setReference(LinAlg::Matrix<Type> W)
{
    this->W = W;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setErrorWeight(LinAlg::Matrix<Type> Q)
{
    this->Q = Q;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setInitialState(LinAlg::Matrix<Type> X0)
{
    this->X0 = X0;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setControlWeight(LinAlg::Matrix<Type> R)
{
    this->R = R;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getReference() const
{
    return W;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getErrorWeight() const
{
    return Q;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getInitialState() const
{
    return X0;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getControlWeight() const
{
    return R;
}

template<typename Type>
LinAlg::Matrix<Type> Preditivo<Type>::OutputControlCalc()
{
  //  X0 = (X(:,k)-X(:,k-1)); //Cd*X(:,k);

}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> W)
{

}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{

}

