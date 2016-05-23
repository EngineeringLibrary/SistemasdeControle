#ifndef __PID_H_INCLUDED
#define __PID_H_INCLUDED

#include <cmath>


template <typename UsedType>
class PID
{
private:

    bool checkUpLim, checkLowLim;
    UsedType Error, pastError, integralError, derivativeError, Step, kp, ki, kd, upperLimit, lowerLimit, PIDout;

    void antReset();

    void intError();
    void difError();



public:
    PID();

    void setSampleTime(UsedType Time);
    void setLimits(UsedType upperLimit, UsedType lowerLimit);
    void setParams(UsedType kp, UsedType ki, UsedType kd);

    UsedType OutputControl(UsedType Reference, UsedType SignalInput);

};

#include <SistemasdeControle/src/controlLibs/pid.hpp>
#endif // PID_H
