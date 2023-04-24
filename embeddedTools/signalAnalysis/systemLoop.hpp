#include "systemLoop.h"
#include <thread>

 Devices::fes4channels::fes4channels(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq, const uint32_t &time_on, const uint32_t &period,  bool isCA)
 {
    periodic_timer = nullptr;
    counter = 0; activeChannel = 0;
    this->time_on = time_on;//microsseconds
    this->period = period;//microssenconds
    
     if(isCA)
        initCA(levelPin, modPin, channelQuantity, freq);
    else
        initCC(levelPin, modPin, channelQuantity, freq);

    this->stopLoopFlag = true;
    // startLoop();// depois tirar
 }

void Devices::fes4channels::initCC(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq){
    this->isCA = false;
    // this->fes = new ElectroStimulation::bioSignalController[channelQuantity];
    
    this->channelQuantity = channelQuantity;
    for(uint8_t i = 0; i < channelQuantity; ++i){
        this->fes[i].boostInit((gpio_num_t) levelPin[i], freq,(ledc_channel_t) i);
        this->fes[i].setOutputHandlerPin((gpio_num_t) modPin[i]);
    }
    
    counterMax = period/time_on;
    // std::cout << counterMax << std::endl;
    fesDivisionCounter[0] =   2;
    fesDivisionCounter[1] =   3;
    fesDivisionCounter[2] =   counterMax/5 + 2;
    fesDivisionCounter[3] =   counterMax/5 + 3;
    fesDivisionCounter[4] = 2*counterMax/5 + 2;
    fesDivisionCounter[5] = 2*counterMax/5 + 3;
    fesDivisionCounter[6] = 3*counterMax/5 + 2;
    fesDivisionCounter[7] = 3*counterMax/5 + 3;
}

void Devices::fes4channels::initCA(uint8_t *levelPin, uint8_t *modPin, uint8_t channelQuantity, const uint32_t &freq){
    this->isCA = true;
    
    this->channelQuantity = channelQuantity;
    uint8_t j = 0;
    for(uint8_t i = 0; i < channelQuantity; ++i){
        std::cout << (int) levelPin[i] << ' ' << (int)modPin[j] << ' ' << (int)modPin[j+1]  << '\n';
        this->fes[i].boostInit((gpio_num_t) levelPin[i], freq,(ledc_channel_t) i);
        this->fes[i].setOutputHandlerPins((gpio_num_t) modPin[j],(gpio_num_t) modPin[j+1]);
        j += 2;
    }
    
    counterMax = period/time_on;
    fesDivisionCounter[0]  =   2;
    fesDivisionCounter[1]  =   3;
    fesDivisionCounter[2]  =   counterMax/9 + 2;
    fesDivisionCounter[3]  =   counterMax/9 + 3;
    fesDivisionCounter[4]  = 2*counterMax/9 + 2;
    fesDivisionCounter[5]  = 2*counterMax/9 + 3;
    fesDivisionCounter[6]  = 3*counterMax/9 + 2;
    fesDivisionCounter[7]  = 3*counterMax/9 + 3;
    fesDivisionCounter[8]  = 4*counterMax/9 + 2;
    fesDivisionCounter[9]  = 4*counterMax/9 + 3;
    fesDivisionCounter[10] = 5*counterMax/9 + 2;
    fesDivisionCounter[11] = 5*counterMax/9 + 3;
    fesDivisionCounter[12] = 6*counterMax/9 + 2;
    fesDivisionCounter[13] = 6*counterMax/9 + 3;
    fesDivisionCounter[14] = 7*counterMax/9 + 2;
    fesDivisionCounter[15] = 7*counterMax/9 + 3;
}

static void Devices::fes4ChannelLoop(void *para){// timer group 0, ISR
    Devices::fes4channels *dispositivo = ((Devices::fes4channels*) para);
    
    dispositivo->counter++;
    
    if(dispositivo->isCA){
        for(uint8_t i = 0; i < dispositivo->channelQuantity; ++i){
            dispositivo->fes[i].resetOutputDirectPin();
            dispositivo->fes[i].resetOutputReversePin();
        }
        int8_t j = -1; 
        for(uint8_t i = 0; i < 4*dispositivo->channelQuantity; i+=3){
            // if(i%3 == 0)
            j++;
            if (j >= dispositivo->channelQuantity)
                break;
            if(dispositivo->counter == dispositivo->fesDivisionCounter[i]){
                dispositivo->fes[j].setOutputDirectPin();
                dispositivo->fes[j].resetOutputReversePin();
            }
            else if(dispositivo->counter == dispositivo->fesDivisionCounter[i+1]){
                dispositivo->fes[j].resetOutputDirectPin();
                dispositivo->fes[j].setOutputReversePin();
            }
            else if(dispositivo->counter == dispositivo->fesDivisionCounter[i+3]){
                dispositivo->fes[j].resetOutputDirectPin();
                dispositivo->fes[j].resetOutputReversePin();
            }
        }
    } else {
        for(uint8_t i = 0; i < dispositivo->channelQuantity; ++i)
            dispositivo->fes[i].resetOutputDirectPin();

        int8_t j = -1; 
        for(uint8_t i = 0; i < 2*dispositivo->channelQuantity; i+=2){
            if(i%2 == 0)
                j++;
            if(dispositivo->counter == dispositivo->fesDivisionCounter[i])
                dispositivo->fes[j].setOutputDirectPin();
            else if(dispositivo->counter == dispositivo->fesDivisionCounter[i+1])
                dispositivo->fes[j].resetOutputDirectPin();
        }
    }
    
    if(dispositivo->counter == dispositivo->counterMax)
        dispositivo->counter = 0;

    if(dispositivo->stopLoopFlag){
        // dispositivo->stopLoop();
        for(uint8_t i = 0; i < 2*dispositivo->channelQuantity; ++i)
            dispositivo->fes[i].setPowerLevel(0); 

        if(dispositivo->isCA){
        for(uint8_t i = 0; i < 2*dispositivo->channelQuantity; ++i)
            dispositivo->fes[i].resetOutputDirectPin();
        } else{
            for(uint8_t i = 0; i < dispositivo->channelQuantity; ++i)
                dispositivo->fes[i].resetOutputDirectPin();
        }
        
        ESP_ERROR_CHECK(esp_timer_stop(dispositivo->periodic_timer));
        ESP_ERROR_CHECK(esp_timer_delete(dispositivo->periodic_timer)); //Timer delete
        dispositivo->periodic_timer = nullptr;
        
    }
}

void Devices::fes4channels::startLoop(/*void (*loopFunction2Call)(void*)*/){
    if(!this->periodic_timer){
        this->periodic_timer_args.callback = &fes4ChannelLoop;
        this->periodic_timer_args.arg = (void*) this;
        this->periodic_timer_args.name = "periodic";
        ESP_ERROR_CHECK(esp_timer_create(&this->periodic_timer_args, &this->periodic_timer));
        ESP_ERROR_CHECK(esp_timer_start_periodic(this->periodic_timer, this->time_on));
    }
}

void Devices::fes4channels::stopLoop(){
    if(this->isCA){
        for(uint8_t i = 0; i <this->channelQuantity; ++i){
            this->fes[i].resetOutputDirectPin();
            this->fes[i].resetOutputReversePin();
        }
    } else{
        for(uint8_t i = 0; i < this->channelQuantity; ++i)
            this->fes[i].resetOutputDirectPin();
    }
    for(uint8_t i = 0; i < this->channelQuantity; ++i)
        this->fes[i].setPowerLevel(0); 
    if(!this->periodic_timer){
        ESP_ERROR_CHECK(esp_timer_stop(this->periodic_timer));
        ESP_ERROR_CHECK(esp_timer_delete(this->periodic_timer)); //Timer delete
        this->periodic_timer = nullptr;
    }
}

void Devices::fes4channels::timeOnAndPeriodUpdate(const uint32_t &time_on, const uint32_t &period){
    //  std::cout << "Entrou1" << time_on  << "   "<< period << std::endl;
    // stopLoop();
    
    this->period  = period;
    this->time_on = time_on;
    counterMax = period/time_on;

    if(!isCA){
        fesDivisionCounter[0] =   2;
        fesDivisionCounter[1] =   3;
        fesDivisionCounter[2] =   counterMax/5 + 2;
        fesDivisionCounter[3] =   counterMax/5 + 3;
        fesDivisionCounter[4] = 2*counterMax/5 + 2;
        fesDivisionCounter[5] = 2*counterMax/5 + 3;
        fesDivisionCounter[6] = 3*counterMax/5 + 2;
        fesDivisionCounter[7] = 3*counterMax/5 + 3;
    }
    else{
        fesDivisionCounter[0]  =   2;
        fesDivisionCounter[1]  =   3;
        fesDivisionCounter[2]  =   counterMax/9 + 2;
        fesDivisionCounter[3]  =   counterMax/9 + 3;
        fesDivisionCounter[4]  = 2*counterMax/9 + 2;
        fesDivisionCounter[5]  = 2*counterMax/9 + 3;
        fesDivisionCounter[6]  = 3*counterMax/9 + 2;
        fesDivisionCounter[7]  = 3*counterMax/9 + 3;
        fesDivisionCounter[8]  = 4*counterMax/9 + 2;
        fesDivisionCounter[9]  = 4*counterMax/9 + 3;
        fesDivisionCounter[10] = 5*counterMax/9 + 2;
        fesDivisionCounter[11] = 5*counterMax/9 + 3;
        fesDivisionCounter[12] = 6*counterMax/9 + 2;
        fesDivisionCounter[13] = 6*counterMax/9 + 3;
        fesDivisionCounter[14] = 7*counterMax/9 + 2;
        fesDivisionCounter[15] = 7*counterMax/9 + 3;
    }
}

LinAlg::Matrix<double> Devices::fes4channels::TwoDOFLimbControl(double ref1, double ref2, LinAlg::Matrix<double> sensorData){
    double u1, u2; LinAlg::Matrix<double> ret(1,6);
    u1 = this->pid[0].OutputControl(ref1, sensorData(0,0));
    if (u1 > 0){
        u1 += this->pid[0].getInputOperationalPoint();
        this->fes[0].setPowerLevel(u1); 
        this->fes[1].setPowerLevel(0); 
    }
    else{
        u1 = -u1 + this->pid[0].getInputOperationalPoint();
        this->fes[1].setPowerLevel(u1); 
        this->fes[0].setPowerLevel(0); 
        u1 = -u1;
    }

    u2 = this->pid[1].OutputControl(ref2, sensorData(1,0));
    if (u2 > 0){
        u2 += this->pid[1].getInputOperationalPoint();
        this->fes[2].setPowerLevel(u2); 
        this->fes[3].setPowerLevel(0); 
    }
    else{
        u2 = -u2 + this->pid[1].getInputOperationalPoint();
        this->fes[3].setPowerLevel(u2);
        this->fes[2].setPowerLevel(0); 
        u2 = -u2;
    }
    ret(0,0) = u1; ret(0,1) = u2; ret(0,2) = this->pid[0].getErrorValue(); ret(0,3) = this->pid[1].getErrorValue();
    ret(0,4) = this->pid[0].getIntegralErrorValue(); ret(0,5) = this->pid[1].getIntegralErrorValue();
    return ret;
}