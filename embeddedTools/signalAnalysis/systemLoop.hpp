#include "systemLoop.h"

Devices::fes4channels::fes4channels(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint16_t &freq){
    
    // this->fes = new ElectroStimulation::bioSignalController[channelQuantity];
    this->channelQuantity = channelQuantity;
    for(uint8_t i = 0; i < channelQuantity; ++i){
        this->fes[i].boostInit((gpio_num_t) levelPin[i], freq,(ledc_channel_t) i);
        this->fes[i].setOutputHandlerDirectPin((gpio_num_t) modPin[i]);
    }
    counter = 0; activeChannel = 0;
}

static void Devices::fes4ChannelLoop(void *para){// timer group 0, ISR
    Devices::fes4channels *dispositivo = ((Devices::fes4channels*) para);
    
    dispositivo->counter++;
    for(uint8_t i = 0; i < dispositivo->channelQuantity; ++i)
        dispositivo->fes[i].setOutputDirectPin();
    switch (dispositivo->counter)
    {
        case 1:
            dispositivo->fes[0].resetOutputDirectPin();
            break;
        case 4:
            dispositivo->fes[1].resetOutputDirectPin();
            break;
        case 8:
            dispositivo->fes[2].resetOutputDirectPin();
            break;
        case 12:
            dispositivo->fes[3].resetOutputDirectPin();
            break;
        case 16:
            dispositivo->counter = 0;
            break;
    }
}

void Devices::fes4channels::startLoop(/*void (*loopFunction2Call)(void*)*/){
    periodic_timer_args.callback = &fes4ChannelLoop;
    periodic_timer_args.arg = (void*) this;
    periodic_timer_args.name = "periodic";
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 500));
}

void Devices::fes4channels::stopLoop(){
    ESP_ERROR_CHECK(esp_timer_stop(periodic_timer));
}

void Devices::fes4channels::pauseLoop(){
     //ESP_ERROR_CHECK(esp_timer_(periodic_timer));
}

// void Devices::fes4channels::resumeLoop(){
//     // timer_start(timer_group, timer_idx);
//     startIterator = true;
// }