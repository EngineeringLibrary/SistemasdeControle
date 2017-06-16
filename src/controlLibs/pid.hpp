#ifdef testControl
    #include "../../../headers/controlLibs/pid.h"
#else
    #include "SistemasdeControle/headers/controlLibs/pid.h"
#endif

template<typename Type>
ControlHandler::PID<Type>::PID()
{
    this->kd = 0;
    this->ki = 0;
    this->kp = 0;

    this->Error = 0;
    this->derivativeError = 0;
    this->pastError = 0;
    this->integralError = 0;

    this->Step = 0.1;
    this->upperLimit = 200;
    this->lowerLimit = -200;
}

template<typename Type>
ControlHandler::PID<Type>::PID(const LinAlg::Matrix<Type> &PIDsParameters)
{
    this->kp = PIDsParameters(1,1);
    this->ki = PIDsParameters(1,2);
    this->kd = PIDsParameters(1,3);

    this->Error = 0;
    this->derivativeError = 0;
    this->pastError = 0;
    this->integralError = 0;

    this->Step = 0.1;
    this->upperLimit = 200;
    this->lowerLimit = -200;
}

template<typename Type>
void ControlHandler::PID<Type>::errorLimitation()
{
    if(this->PIDout >= this->upperLimit)
    {
        this->checkUpLim = true;
        this->PIDout = this->upperLimit;
    }
    else
        this->checkUpLim = false;

    if(this->PIDout <= this->lowerLimit)
    {
        this->checkLowLim = true;
        this->PIDout = this->lowerLimit;
    }
    else
        this->checkLowLim = false;
}

template<typename Type>
void ControlHandler::PID<Type>::intError()
{
    this->errorLimitation();

    if(!this->checkUpLim && !this->checkLowLim)
        this->integralError += this->Error*this->Step;
}

template<typename Type>
void ControlHandler::PID<Type>::difError()
{
    this->derivativeError = ((this->Error - this->pastError)/this->Step);
    this->pastError = this->Error;
}

template<typename Type>
void ControlHandler::PID<Type>::setLimits(Type lowerLimit, Type upperLimit)
{
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
}

template<typename Type>
void ControlHandler::PID<Type>::setSampleTime(Type Time)
{
    this->Step = Time;
}

template<typename Type>
void ControlHandler::PID<Type>::setParams(Type kp, Type ki, Type kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

template<typename Type>
void ControlHandler::PID<Type>::setParams(const LinAlg::Matrix<Type> &PIDsParameters)
{
    this->kp = PIDsParameters(1,1);
    this->ki = PIDsParameters(1,2);
    this->kd = PIDsParameters(1,3);
}

template<typename Type>
Type ControlHandler::PID<Type>::OutputControl(Type Reference, Type SignalInput)
{
    this->Error = Reference - SignalInput;

    difError();
    intError();
    this->PIDout = (this->kp*this->Error + this->ki*this->integralError + this->kd*this->derivativeError);
    errorLimitation();
    
    return this->PIDout;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::PID<Type>::getLimits()
{
    LinAlg::Matrix<Type> limits(1,2);

    limits(1,1) = this->lowerLimit;
    limits(1,2) = this->upperLimit;

    return limits;
}

template<typename Type>
LinAlg::Matrix<Type> ControlHandler::PID<Type>::getParams()
{
    LinAlg::Matrix<Type> params(1,3);

    params(1,1) = this->kp;
    params(1,2) = this->ki;
    params(1,3) = this->kd;

    return params;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::ZieglerNicholsTunning(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.9*tau/(K*theta);
        controller.setParams(Kp,Kp/(3.33*theta),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/(2*theta),Kp*0.5*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::CHRTunningServo0OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.3*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.35*tau/(K*theta);
        controller.setParams(Kp,Kp/(1.16*tau),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/tau,Kp*0.5*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::CHRTunningServo20OV(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.7*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.6*tau/(K*theta);
        controller.setParams(Kp,Kp/(tau),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 0.95*tau/(K*theta);
        controller.setParams(Kp,Kp/(1.357*tau),Kp*0.473*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::CHRTunningRegulatorio(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = 0.3*tau/(K*theta);
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = 0.6*tau/(K*theta);
        controller.setParams(Kp,Kp/(4*theta),0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = 1.2*tau/(K*theta);
        controller.setParams(Kp,Kp/(2.375*theta),Kp*0.421*theta);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
}

template <typename Type>
ControlHandler::PID<Type> ControlHandler::CohenCoonTunning(const ModelHandler::TransferFunction<Type> &FOPDT, const std::string &controllerType)
{
    LinAlg::Matrix<Type> num = FOPDT(1,1).getNum();
    LinAlg::Matrix<Type> den = FOPDT(1,1).getDen();
    num /= den(1,2);
    den /= den(1,2);
    Type tau = den(1,1), K = num(1,1), theta = FOPDT.getTransportDelay();

    ControlHandler::PID<Type> controller;
    controller.setSampleTime(FOPDT.getSampleTime());
    if(controllerType == "P")
    {
        Type Kp = (1.03+0.35*tau/theta)*(tau/(K*theta));
        controller.setParams(Kp,0.0,0.0);
    }
    else if(controllerType == "PI")
    {
        Type Kp = (0.9+0.083*tau/theta)*(tau/(K*theta));
        Type Ti = ((0.9+0.083*tau/theta)/(1.27+0.6*(tau/theta)))*theta;
        controller.setParams(Kp,Kp/Ti,0.0);
    }
    else if(controllerType == "PID")
    {
        Type Kp = (1.35+0.25*tau/theta)*(tau/(K*theta));
        Type Ti = ((1.35+0.25*tau/theta)/(0.54+0.6*(tau/theta)))*theta;
        Type Td = ((0.5*theta)/(1.35+0.25*(theta/tau)));
        controller.setParams(Kp,Kp/Ti,Kp*Td);
    }
    else
        std::cout << "Controlador nao encontrado" << std::endl;
}
