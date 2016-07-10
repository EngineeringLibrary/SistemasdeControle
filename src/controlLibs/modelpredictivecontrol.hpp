#include "SistemasdeControle/headers/controlLibs/modelpredictivecontrol.h"

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::
       ModelPredictiveControl(const ModelHandler::StateSpace<Type> &SS,
                              unsigned N1, unsigned N2, unsigned NU,
                              Type Q, Type R, Type W)
{
    this->N1 = N1;
    this->N2 = N2;
    this->NU = NU;
    LinAlg::Matrix<double> X  = LinAlg::Zeros<double>(SSd.getA().getNumberOfRows(),2);
    LinAlg::Matrix<double> Y  = LinAlg::Zeros<double>((SSd.getC()*X).getNumberOfRows(),(SSd.getC()*X).getNumberOfColumns());

    if(SS.isContinuous())
        this->SSd = ModelHandler::c2d(SS,0.1);
    else
        this->SSd = SS;
    this->SSdStateStimated = this->SSd;

    this->SSI = new ModelHandler::IntegrativeModel<double>(SSd);
    this->SSP = new ModelHandler::PredictionModel<double>(SSd,N1,N2,NU);
    this->Q = Q*LinAlg::Eye<double>((SSP->getC()*SSP->getB()).getNumberOfRows());
    this->R = R*LinAlg::Eye<double>(NU*SSd.getB().getNumberOfColumns());
    this->W = W*LinAlg::Ones<double>((SSP->getC()*SSP->getA()*(X||Y)).getNumberOfRows(),1);
    this->U  = LinAlg::Zeros<Type>(SSI.getB().getNumberOfColumns(),1);
    this->K = (((~SSP.getB())*(~SSP.getC())*this->Q*SSP.getC()*SSP.getB()+this->R )^-1)*(~SSP.getB())*(~SSP.getC())*(~this->Q);
    this->lMax = 50;
    this->lMin = -this->lMax;
}

template<typename Type>
ControlHandler::ModelPredictiveControl<Type>::
       ModelPredictiveControl(const ModelHandler::ARX<Type> &gz,
                              unsigned N1, unsigned N2, unsigned NU,
                              Type Q, Type R, Type W)
{
    this->N1 = N1;
    this->N2 = N2;
    this->NU = NU;

    this->SSd = ModelHandler::arx2SS<double>(gz);
    LinAlg::Matrix<double> X  = LinAlg::Zeros<double>(SSd.getA().getNumberOfRows(),2);
    LinAlg::Matrix<double> Y  = LinAlg::Zeros<double>((SSd.getC()*X).getNumberOfRows(),(SSd.getC()*X).getNumberOfColumns());
    this->SSdStateStimated = this->SSd;

    this->SSI = ModelHandler::IntegrativeModel<double>(this->SSd);
    this->SSP = ModelHandler::PredictionModel<double>(this->SSd,N1,N2,NU);
    this->Q = Q*LinAlg::Eye<double>((SSP.getC()*SSP.getB()).getNumberOfRows());
    this->R = R*LinAlg::Eye<double>(NU*SSd.getB().getNumberOfColumns());
    this->W = W*LinAlg::Ones<double>((SSP.getC()*SSP.getA()*(X||Y)).getNumberOfRows(),1);
    this->U  = LinAlg::Zeros<Type>(SSI.getB().getNumberOfColumns(),1);
    this->K = (((~SSP.getB())*(~SSP.getC())*this->Q*SSP.getC()*SSP.getB()+this->R )^-1)*(~SSP.getB())*(~SSP.getC())*(~this->Q);
    this->lMax = 50;
    this->lMin = -this->lMax;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setLimits(Type max, Type min)
{
    this->lMax = max; this->lMin = min;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setReference(LinAlg::Matrix<Type> W)
{
    for(unsigned i = 1; i <= this->W.getNumberOfRows(); i += this->SSd.getC().getNumberOfRows())
            for(unsigned j = 0; j < this->SSd.getC().getNumberOfRows(); ++j)
                this->W(i+j,  1)  = W(j+1,1);
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
void ControlHandler::ModelPredictiveControl<Type>::setNewModel(const ModelHandler::ARX<Type> &gz)
{
    LinAlg::Matrix<Type> X = this->SSd.getActualState()/*, Xss = SSdStateStimated.getActualState()*/;
    this->SSdStateStimated = ModelHandler::arx2SS(gz);
    LinAlg::Matrix<Type> gzState = gz.getLinearVectorA();
    unsigned j = 1;
    for(unsigned i = 1; i <= X.getNumberOfRows(); i += gz.getNumberOfOutputDelays())
    {
        X(i, 1) = -gzState(1,j);
        ++j;
    }
//    std::cout << X << gzState;
    SSdStateStimated.setInitialState(X);
    SSdStateStimated.sim(this->U);
    this->SSI = ModelHandler::IntegrativeModel<double>(SSdStateStimated);
    this->SSP = ModelHandler::PredictionModel<double>(SSdStateStimated,N1,N2,NU);

    this->K = (((~SSP.getB())*(~SSP.getC())*this->Q*SSP.getC()*SSP.getB()+this->R )^-1)*(~SSP.getB())*(~SSP.getC())*(~this->Q);
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::setNewModel(ModelHandler::StateSpace<Type> SS)
{
////    SS.setInitialState(this->SSd.getActualState());
//    if(SS.isContinuous())
//        this->SSdStateStimated = ModelHandler::c2d(SS,0.1);
//    else
//        this->SSdStateStimated = SS;
////    this->SSd.setInitialState(SS.getActualState());
//    this->SSI = new ModelHandler::IntegrativeModel<double>(SSd);
//    this->SSP = new ModelHandler::PredictionModel<double>(SSd,N1,N2,NU);

//    this->K = (((~SSP.getB())*(~SSP.getC())*Q*SSP.getC()*SSP.getB()+R )^-1)*(~SSP.getB())*(~SSP.getC())*(~Q);
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
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::getControlerGain() const
{
    return K;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(const ModelHandler::ARX<Type>& gz)
{
    this->setNewModel(gz);
    LinAlg::Matrix<Type> X_state = SSd.getActualState();
    LinAlg::Matrix<Type> X_input = SSdStateStimated.getActualState();
    LinAlg::Matrix<Type> X = ((X_input - X_state)|| this->SSd.getC()*X_input);

    SSd.setInitialState(X_input);

    LinAlg::Matrix<Type> du = this->K*(this->W - SSP.getC()*SSP.getA()*X);
    this->U = this->U + ((du.GetRow(1)));
    LimitControlOutput();

    return this->U;
}


template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input)
{
    LinAlg::Matrix<Type> X_input = SSd.getActualState();
    LinAlg::Matrix<Type> X = ((X_input - X_state)|| this->SSd.getC()*X_input);

    SSd.setInitialState(X_input);

    LinAlg::Matrix<Type> du = this->K*(this->W - SSP.getC()*SSP.getA()*X);
    this->U = this->U + ((du.GetRow(1)));
    LimitControlOutput();

    return this->U;
}

template<typename Type>
void ControlHandler::ModelPredictiveControl<Type>::LimitControlOutput()
{
    for(unsigned i = 1; i <= this->U.getNumberOfRows(); ++i)
        if(this->U(i,1) > lMax)
            this->U(i,1) = lMax;
        else if(this->U(i,1) < lMin)
            this->U(i,1) = lMin;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> W)
{

}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::ModelPredictiveControl<Type>::OutputControlCalc(LinAlg::Matrix<Type> X_input, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{

}

