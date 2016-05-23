#include "SistemasdeControle/headers/optimizationLibs/pid.h"

template<typename UsedType>
PID<UsedType>::PID()
{
    this->kd = 0;
    this->ki = 0;
    this->kp = 0;

    this->Error = 0;
    this->derivativeError = 0;
    this->pastError = 0;
    this->integralError = 0;

    this->Step = 0;
    this->upperLimit = 2000;
    this->lowerLimit = -2000;
}

template<typename UsedType>
void PID<UsedType>::antReset()
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

template<typename UsedType>
void PID<UsedType>::intError()
{
    antReset();

    if(!this->checkUpLim && !this->checkLowLim)
        this->integralError += this->Error*this->Step;
}

template<typename UsedType>
void PID<UsedType>::difError()
{
    this->derivativeError = ((this->Error - this->pastError)/this->Step);
    this->pastError = this->Error;
}

template<typename UsedType>
void PID<UsedType>::setLimits(UsedType upperLimit, UsedType lowerLimit)
{
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
}

template<typename UsedType>
void PID<UsedType>::setSampleTime(UsedType Time)
{
    this->Step = Time;
}

template<typename UsedType>
void PID<UsedType>::setParams(UsedType kp, UsedType ki, UsedType kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

template<typename UsedType>
UsedType PID<UsedType>::OutputControl(UsedType Reference, UsedType SignalInput)
{
    this->Error = Reference - SignalInput;

    difError();
    intError();
    this->PIDout = (this->kp*this->Error + this->ki*this->integralError + this->kd*this->derivativeError);
    antReset();
    
    return this->PIDout;
}
