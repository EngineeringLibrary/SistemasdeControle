#include "bioSignalGenerator.h"

void ElectroStimulation::bioSignalController::boostInit(const gpio_num_t &pin, const uint32_t &freq, const ledc_channel_t channel)
{
    gpio_pad_select_gpio((gpio_num_t)pin);
    gpio_set_direction((gpio_num_t)pin, GPIO_MODE_OUTPUT); 

    ledc_timer_boost.duty_resolution = LEDC_TIMER_12_BIT;
    ledc_timer_boost.freq_hz = freq;
    ledc_timer_boost.speed_mode = LEDC_HIGH_SPEED_MODE;
    ledc_timer_boost.timer_num = LEDC_TIMER_0;
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer_boost);

    ledc_channel_boost.hpoint     = 0;
	ledc_channel_boost.duty       = 0; 
	ledc_channel_boost.channel    = channel;
	ledc_channel_boost.gpio_num   = pin;
	ledc_channel_boost.timer_sel  = LEDC_TIMER_0;
	ledc_channel_boost.speed_mode = LEDC_HIGH_SPEED_MODE;
    ledc_channel_config(&ledc_channel_boost);
    
    ledc_fade_func_install(0);
    this->fadeTime = 0;
}

void ElectroStimulation::bioSignalController::setOutputHandlerPin(const gpio_num_t &pin){
    gpio_pad_select_gpio((gpio_num_t)pin);
    gpio_set_direction((gpio_num_t)pin, GPIO_MODE_OUTPUT); 
    directPin = pin;
    this->CC_AC = false;
}

void ElectroStimulation::bioSignalController::setOutputHandlerPins(const gpio_num_t &directPin, const gpio_num_t &reversePin){
    gpio_pad_select_gpio((gpio_num_t)directPin);
    gpio_set_direction((gpio_num_t)directPin, GPIO_MODE_OUTPUT); 
    this->directPin = directPin;

    gpio_pad_select_gpio((gpio_num_t)reversePin);
    gpio_set_direction((gpio_num_t)reversePin, GPIO_MODE_OUTPUT); 
    this->reversePin = reversePin;
    this->CC_AC = true;
}

void ElectroStimulation::bioSignalController::setPowerLevel(const double &powerLevel){
    ledc_channel_boost.duty       = (uint16_t)((powerLevel)*8192/200); 
    if(this->fadeTime == 0){
        ledc_set_duty(ledc_channel_boost.speed_mode, ledc_channel_boost.channel, ledc_channel_boost.duty);
        ledc_update_duty(ledc_channel_boost.speed_mode, ledc_channel_boost.channel);
    }
    else{
        ledc_set_fade_time_and_start( ledc_channel_boost.speed_mode , 
                                         ledc_channel_boost.channel , 
                                         ledc_channel_boost.duty , 
                                         fadeTime , 
                                         LEDC_FADE_NO_WAIT);
    }
}
