#ifndef ADRONE_HMC5883L_H
#define ADRONE_HMC5883L_H

#include <stdint.h>
#include "SistemasdeControle/embeddedTools/communicationLibs/i2cHandler.h"
#include <EEPROM.h>

EEPROMClass  mag_offset("eeprom2");
class hmc5883l
{
public:
    // setup registers
    bool init();
    // check wire connection
    bool connected();
    // read data from sensor
    void read();
    // get Y axie gauss
    double get_x();
    // get X axie gauss
    double get_y();
    // get Z axie gauss
    double get_z();

    void calibrate();

    LinAlg::Matrix<int16_t> getRawData(){LinAlg::Matrix<int16_t> ret(1,3);ret(0,0) = raw[0]; ret(0,1)=raw[1];ret(0,2)=raw[2];return ret;}
    void setOffset(LinAlg::Matrix<int16_t> offset){mag_calib[0] = offset(0,0);mag_calib[1] = offset(0,1);mag_calib[2] = offset(0,2);}
    void saveOffset(){mag_offset.writeShort(0,mag_calib[0]);    mag_offset.writeShort(2,mag_calib[1]);    mag_offset.writeShort(4,mag_calib[2]);    mag_offset.commit();}
private:
    double  _data[3];      // aceleration data
    int16_t  mag_calib[3]; 
    int16_t raw[3];
    
};

#include "SistemasdeControle/embeddedTools/sensors/hmc5883l.cpp"

#endif
