#ifndef __EQDIFSIM_H_INCLUDED
#define __EQDIFSIM_H_INCLUDED

#include "..\primitiveLibs\polynom.h"

template <class UsedType>
class EqdifSim
{
private:
    float SampleTime, TimeSimulation;
    Matrix<UsedType> A, B, C, D, Ad, Bd, Cd, Dd;
    Polynom<UsedType> **TransferFunction, **DiscreteTransferFunction;
    string typeModel;

    void tf2ssc();
    void tf2ssd();
    void ss2tfc();
    void ss2tfd();

    Matrix<UsedType> sumPoly();

public:
    EqdifSim();
    EqdifSim(Matrix<UsedType> AIn, Matrix<UsedType> BIn, Matrix<UsedType> CIn, Matrix<UsedType> DIn);
    EqdifSim(Matrix<UsedType> AdIn, Matrix<UsedType> BdIn, Matrix<UsedType> CdIn, Matrix<UsedType> DdIn, float Time);

    EqdifSim(Matrix<UsedType> NumIn, Matrix<UsedType> DenIn);
    EqdifSim(Matrix<UsedType> NumdIn, Matrix<UsedType> DendIn, float Time);

//    void ss2tf();

    Matrix<UsedType> Simulation(Matrix<UsedType> SystemInput, bool getState = 0);

    void printSS();
    void printTF();
    void print();
    void c2d(float Time);
    void d2c();
    void setModel(std::string model);

    UsedType factorial(float n);
};

#endif // EQDIFSIM_H
