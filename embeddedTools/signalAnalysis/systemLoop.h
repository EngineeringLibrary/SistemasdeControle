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

namespace Devices{
    struct fes4channels{
        fes4channels(){};
        ~fes4channels(){ESP_ERROR_CHECK(esp_timer_stop(periodic_timer)); ESP_ERROR_CHECK(esp_timer_delete(periodic_timer));};
        fes4channels(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint16_t &freq = 5000);
        
        void startLoop(/*void (*loopFunction2Call)(void*)*/);
        void stopLoop();
        void pauseLoop();
        // void resumeLoop();
        bool startIterator;
        volatile timer_group_t timer_group;
        volatile timer_idx_t timer_idx;
        timer_config_t config;
        volatile float TIMER_SCALE, TIMER_FINE_ADJ, TIMER_INTERVAL0_SEC;
        uint_fast8_t counter; 
        uint_fast8_t activeChannel, channelQuantity;
        ElectroStimulation::bioSignalController fes[4];
        esp_timer_handle_t periodic_timer;
        esp_timer_create_args_t periodic_timer_args;
    };

    static void fes4ChannelLoop(void *para);
}

#include "systemLoop.hpp"
#endif // SYSTEMLOOP_H