#ifndef EQDIFSIM_H
#define EQDIFSIM_H

#include "lsim.h"

class EqdifSim
{
private:
    float SampleTime, TimeSimulation;
    Matrix A, B, C, D, Num, Den, Ad, Bd, Cd, Dd, Numd, Dend;
    string typeModel;
    void tf2ssc();
    void tf2ssd();
    void ss2tfc();
    void ss2tfd();
    Matrix sumPoly();
public:
    EqdifSim();
    EqdifSim(Matrix AIn, Matrix BIn, Matrix CIn, Matrix DIn);
    EqdifSim(Matrix AdIn, Matrix BdIn, Matrix CdIn, Matrix DdIn, float Time);
    EqdifSim(Matrix NumIn, Matrix DenIn);
    EqdifSim(Matrix NumdIn, Matrix DendIn, float Time);

//    void ss2tf();

    void printSS();
    void printTF();
    void print();
    void c2d(float Time);
    void d2c();

    float factorial(float n);

};

#endif // EQDIFSIM_H
