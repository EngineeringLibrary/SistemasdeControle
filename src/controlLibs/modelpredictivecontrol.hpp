#include "SistemasdeControle/headers/controlLibs/modelpredictivecontrol.h"

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::
       ModelPredictiveControl(const ModelHandler::StateSpace<Type>       &SS,
             const ModelHandler::IntegrativeModel<Type> &SSI,
             const ModelHandler::PredictionModel <Type> &SSP,
             const LinAlg::Matrix<Type> &Q, const LinAlg::Matrix<Type> &R,
             const LinAlg::Matrix<Type> &W)
{
    this->W  = W;
    this->Q = Q;
    this->R = R;

    if(SS.isContinuous())
        this->SSd = ModelHandler::c2d(SS,0.1);
    else
        this->SSd = SS;

    this->SSI = SSI;
    this->SSP = SSP;
    this->K = (((~SSP.getB())*(~SSP.getC())*Q*SSP.getC()*SSP.getB()+R )^-1)*(~SSP.getB())*(~SSP.getC())*(~Q);
    this->U  = LinAlg::Zeros<Type>(SSI.getB().getNumberOfColumns(),1);
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
void ControlHandler::ModelPredictiveControl<Type>::setNewModel(ModelHandler::StateSpace<Type> SS, ModelHandler::IntegrativeModel<Type> SSI, ModelHandler::PredictionModel<Type> SSP, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{
    this->W  = W;
    this->Q = Q;
    this->R = R;

    SS.setInitialState(this->SSd.getActualState());
    if(SS.isContinuous())
        this->SSd = ModelHandler::c2d(SS,0.1);
    else
        this->SSd = SS;
    this->SSd.setInitialState(SS.getActualState());

    this->SSI = SSI;
    this->SSP = SSP;

    this->K = (((~SSP.getB())*(~SSP.getC())*Q*SSP.getC()*SSP.getB()+R )^-1)*(~SSP.getB())*(~SSP.getC())*(~Q);
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
    return SSd.getActualState();
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getControlWeight() const
{
    return R;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input)
{
    LinAlg::Matrix<Type> X = ((X_input - SSd.getActualState()) || this->SSd.getC()*X_input);
    SSd.setInitialState(X_input);

//    std::cout << SSP.getC()*SSP.getA()*X;
    LinAlg::Matrix<Type> du = this->K*(this->W - SSP.getC()*SSP.getA()*X);
    this->U = this->U + du(from(1)-->SSd.getB().getNumberOfColumns(),1);

    return this->U;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> W)
{

}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{

}

