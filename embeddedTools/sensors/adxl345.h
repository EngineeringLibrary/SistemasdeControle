#ifndef ADRONE_ADXL345_H
#define ADRONE_ADXL345_H

#include <stdint.h>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/embeddedTools/communicationLibs/i2cHandler.h"
#include "iostream"
#include <math.h>
#include <EEPROM.h>
// #define PI 3.14159265359

EEPROMClass  accel_offset("eeprom0");
class adxl345
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
    // get X axie G aceleration
    const double& get_x() const;
    // get Y axie G aceleration
    const double& get_y() const;
    // get Z axie G aceleration
    const double& get_z() const;
    // get X axie G aceleration
    double get_filtered_x();
    // get Y axie G aceleration
    double get_filtered_y();
    // get Z axie G aceleration
    double get_filtered_z();
    // get pitch angle
    double get_pitch();
    // get roll angle
    double get_roll();

    void set_filter_constant(const double &filter_constant);

    LinAlg::Matrix<int16_t> getRawData(){LinAlg::Matrix<int16_t> ret(1,3);ret(0,0) = _raw[0]; ret(0,1)=_raw[1];ret(0,2)=_raw[2];return ret;}
    void setOffset(LinAlg::Matrix<int16_t> offset){_offset[0] = offset(0,0);_offset[1] = offset(0,1);_offset[2] = offset(0,2);}
    void saveOffset(){accel_offset.writeShort(0,_offset[0]);    accel_offset.writeShort(2,_offset[1]);    accel_offset.writeShort(4,_offset[2]);    accel_offset.commit();}

private:
    int16_t  _raw[3];     // raw data
    double   _data[3], _filtered_data[3], filter_constant;    // aceleration data
    int16_t  _offset[3];  // offset data
    LinAlg::Matrix<double> calibratedData;
    int sign(double value){if(value > 0) return 1; else return -1;}
};

#include "SistemasdeControle/embeddedTools/sensors/adxl345.cpp"
#endif // ADRONE_ADXL345_H
