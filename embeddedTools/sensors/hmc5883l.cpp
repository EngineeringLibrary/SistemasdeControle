#include "SistemasdeControle/embeddedTools/sensors/hmc5883l.h"

// #define MAGN_ADDRESS  (0x3C)
// #define MADDR          0x3C  // i2c MADDRess
#define MADDR          0x1E  // i2c MADDRess
#define MID_A          0x48   // device id
#define MID_B          0x34
#define MID_C          0x33

#define MREG_WHO_AM_I  0x0A  // device reg id
#define MREG_A         0x00
#define MREG_B         0x01
#define MREG_MODE      0x02
#define MREG_DATA      0x03
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

bool hmc5883l::init()
{

    if (!connected()) return false;

    // 2 samples averaged - 75Hz
    i2c_master_write_slave(MADDR, MREG_A, 0b00111000);
    // to do...
    // write_byte(MADDR, REG_B, );
    //continuous measurement mode
    i2c_master_write_slave(MADDR, MREG_MODE, 0x00);

    mag_offset.begin(mag_offset.length());
    mag_calib[0] = mag_offset.readShort(0);
    mag_calib[1] = mag_offset.readShort(2);
    mag_calib[2] = mag_offset.readShort(4);
    std::cout << "Magnetometer offsetValues: " << mag_calib[0] << ',' << mag_calib[1] << ',' << mag_calib[2]<< std::endl;

    return true;
}


bool hmc5883l::connected()
{
    uint8_t reg[3];
    i2c_master_read_slave(MADDR, MREG_WHO_AM_I,  &(reg[0]));
    i2c_master_read_slave(MADDR, MREG_WHO_AM_I+1,  &(reg[1]));
    i2c_master_read_slave(MADDR, MREG_WHO_AM_I+2,  &(reg[2]));

    return (
        (reg[0] == MID_A) &&
        (reg[1] == MID_B) &&
        (reg[2] == MID_C)) ? true : false;
}


void hmc5883l::read()
{
    uint8_t reg[6];
    i2c_master_read_slave(MADDR, MREG_DATA, &(reg[0]));
    i2c_master_read_slave(MADDR, MREG_DATA+1, &(reg[1]));
    i2c_master_read_slave(MADDR, MREG_DATA+2, &(reg[2]));
    i2c_master_read_slave(MADDR, MREG_DATA+3, &(reg[3]));
    i2c_master_read_slave(MADDR, MREG_DATA+4, &(reg[4]));
    i2c_master_read_slave(MADDR, MREG_DATA+5, &(reg[5]));
    // std::cout << "Entroumag" << std::endl;
    // int16_t raw[3];
    raw[0] = ((int16_t)reg[0] << 8) | reg[1];
    raw[2] = ((int16_t)reg[2] << 8) | reg[3];
    raw[1] = ((int16_t)reg[4] << 8) | reg[5];

    _data[0] = (raw[0]-mag_calib[0]) * 0.92;
    _data[1] = (raw[1]-mag_calib[1]) * 0.92;
    _data[2] = (raw[2]-mag_calib[2]) * 0.92;
    // _data[0] = (raw[0]) * 0.92;
    // _data[1] = (raw[1]) * 0.92;
    // _data[2] = (raw[2]) * 0.92;
}


double hmc5883l::get_x()
{
    return _data[0];
}


double hmc5883l::get_y()
{
    return _data[1];
}


double hmc5883l::get_z()
{
    return _data[2];
}

void hmc5883l::calibrate()
{
    // int32_t min_x = 0, max_x = 0, min_y = 0, max_y = 0, min_z = 0, max_z = 0;
    // for (unsigned i = 0; i < 100; ++i)
    // {
    //     read();
    //     if (raw[0] < min_x)
    //         min_x = raw[0];
    //     if ( raw[1] < min_y)
    //         min_y =  raw[1];
    //     if (raw[2] < min_z)
    //         min_z = raw[2];

    //     if (raw[0] > max_x)
    //         max_x = raw[0];
    //     if ( raw[1] > max_y)
    //         max_y =  raw[1];
    //     if (raw[2] > max_z)
    //         max_z = raw[2];

    //     vTaskDelay(14 / portTICK_PERIOD_MS);
    //     printf("%d\n",i);
    // }

    // // printf("Aqui\n");
    // mag_calib[0] = (max_x + min_x) / 2;
    // mag_calib[1] = (max_y + min_y) / 2;
    // mag_calib[2] = (max_z + min_z) / 2;
// printf("Aqui1\n");
    
    // printf("Aqu2\n");
}