#ifndef SYSTEMLOOP_H
#define SYSTEMLOOP_H

#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/periph_ctrl.h"
#include "driver/timer.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "esp_timer.h"
#include "esp_log.h"
#include "esp_sleep.h"
#include "sdkconfig.h"

#include "bioSignalGenerator.h"
#include "SistemasdeControle/embeddedTools/controlLibs/pid.h"

namespace Devices{
    struct fes4channels{
        fes4channels(){periodic_timer = nullptr;};
        ~fes4channels(){stopLoop();};
        fes4channels(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq = 5000, const uint32_t &time_on = 200, const uint32_t &period = 20000,  bool isCA = false); 
        void initCC(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq = 5000); 
        void initCA(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq = 5000); 
        
        void startLoop(/*void (*loopFunction2Call)(void*)*/);
        void stopLoop();
        void timeOnAndPeriodUpdate(const uint32_t &time_on, const uint32_t &period);
        LinAlg::Matrix<double> TwoDOFLimbControl(double ref1, double ref2, LinAlg::Matrix<double> sensorData);
        ControlHandler::PID<long double> &getPID(const unsigned &indice) {return this->pid[indice];}
        // void resumeLoop();

        timer_config_t config;
        uint32_t counter, counterMax; 
        uint_fast8_t activeChannel, channelQuantity;
        ElectroStimulation::bioSignalController fes[4];
        ControlHandler::PID<long double> pid[2];
        esp_timer_handle_t periodic_timer;
        esp_timer_create_args_t periodic_timer_args;
        uint32_t time_on, fesDivisionCounter[16];
        uint32_t period;
        bool isCA, stopLoopFlag;
    };

    static void fes4ChannelLoop(void *para);
}

#include "systemLoop.hpp"
#endif // SYSTEMLOOP_H