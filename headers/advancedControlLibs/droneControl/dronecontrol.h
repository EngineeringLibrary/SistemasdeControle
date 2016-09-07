#ifndef __DRONECONTROL_H_INCLUDED
#define __DRONECONTROL_H_INCLUDED

#include "SistemasdeControle/headers/modelLibs/arx.h"
#include "SistemasdeControle/headers/controlLibs/pid.h"
#include "SistemasdeControle/headers/graphicLibs/plot.h"
#include "SistemasdeControle/headers/controlLibs/modelpredictivecontrol.h"
#include "SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h"
#include "SistemasdeControle/headers/advancedModelLibs/droneModel/dronemodel.h"

namespace ControlHandler {

    template<typename Type>
    class DroneControl{

    };
}

#include "SistemasdeControle/src/controlLibs/pid.hpp"
#endif // DRONECONTROL_H
