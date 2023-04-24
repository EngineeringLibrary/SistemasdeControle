#ifndef ADRONE_L3G4200D_H
#define ADRONE_L3G4200D_H

#include <stdint.h>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/embeddedTools/communicationLibs/i2cHandler.h"
#include <EEPROM.h>

EEPROMClass  gyr_offset("eeprom1");
class l3g4200d
{
public:
    // setup registers
    bool init();
    // check wire connection
    bool connected();
    // read data from sensor
    void read();
    // calibrate sensor
    void calibrate();
    // get Y axie degree per second
    const double& get_x() const;
    // get X axie degree per second
    const double& get_y() const;
    // get Z axie degree per second
    const double& get_z() const;

    LinAlg::Matrix<int16_t> getRawData(){LinAlg::Matrix<int16_t> ret(1,3);ret(0,0) = _raw[0]; ret(0,1)=_raw[1];ret(0,2)=_raw[2];return ret;}
    void setOffset(LinAlg::Matrix<int16_t> offset){_offset[0] = offset(0,0);_offset[1] = offset(0,1);_offset[2] = offset(0,2);}
    void saveOffset(){gyr_offset.writeShort(0,_offset[0]);    gyr_offset.writeShort(2,_offset[1]);    gyr_offset.writeShort(4,_offset[2]);    gyr_offset.commit();}

private:
    int16_t  _raw[3];    // raw data
    double   _data[3];   // degree per second data
    int16_t  _offset[3];  // offset data
};

#include "SistemasdeControle/embeddedTools/sensors/l3g4200d.cpp"
#endif
