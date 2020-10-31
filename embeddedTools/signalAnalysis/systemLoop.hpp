#include "systemLoop.h"

Devices::fes4channels::fes4channels(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint16_t &freq){
    
    // this->fes = new ElectroStimulation::bioSignalController[channelQuantity];
    this->channelQuantity = channelQuantity;
    for(uint8_t i = 0; i < channelQuantity; ++i){
        this->fes[i].boostInit((gpio_num_t) levelPin[i], freq,(ledc_channel_t) i);
        this->fes[i].setOutputHandlerDirectPin((gpio_num_t) modPin[i]);
    }
    counter = 0; activeChannel = 0;
    time_on = 200;//microsseconds
    period = 20000;//microssenconds
    counterMax = period/time_on;
    fesDivisionCounter[0] =   counterMax/5 + 2;
    fesDivisionCounter[1] =   counterMax/5 + 3;
    fesDivisionCounter[2] = 2*counterMax/5 + 2;
    fesDivisionCounter[3] = 2*counterMax/5 + 3;
    fesDivisionCounter[4] = 3*counterMax/5 + 2;
    fesDivisionCounter[5] = 3*counterMax/5 + 3;
}

static void Devices::fes4ChannelLoop(void *para){// timer group 0, ISR
    Devices::fes4channels *dispositivo = ((Devices::fes4channels*) para);
    
    dispositivo->counter++;
    for(uint8_t i = 0; i < dispositivo->channelQuantity; ++i)
        dispositivo->fes[i].resetOutputDirectPin();
    if(dispositivo->counter == 2)
        dispositivo->fes[0].setOutputDirectPin();
    else if(dispositivo->counter == 3)
        dispositivo->fes[0].resetOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[0])
        dispositivo->fes[1].setOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[1])
        dispositivo->fes[1].resetOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[2])
        dispositivo->fes[2].setOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[3])
        dispositivo->fes[2].resetOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[4])
        dispositivo->fes[3].setOutputDirectPin();
    else if(dispositivo->counter == dispositivo->fesDivisionCounter[5])
        dispositivo->fes[3].resetOutputDirectPin();
    else if(dispositivo->counter == dispositivo->counterMax)
        dispositivo->counter = 0;
}

void Devices::fes4channels::startLoop(/*void (*loopFunction2Call)(void*)*/){
    periodic_timer_args.callback = &fes4ChannelLoop;
    periodic_timer_args.arg = (void*) this;
    periodic_timer_args.name = "periodic";
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, time_on));
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