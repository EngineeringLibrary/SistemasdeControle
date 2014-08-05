#ifndef __SIM_H_INCLUDED
#define __SIM_H_INCLUDED
#include "..\primitive libs\matrix.h"
#include "fstream"

template <class UsedType>
class Sim
{
private:
    Matrix<UsedType> OutPut, InPut, Error, LinSysMultStep, LinSysOneStep, EstOutPut, LinSysParameters, LinSysOutPut;
    int Degree, nSample, nOutPut, nInPut, nError, NonLinDegree;
    bool DataChange;
    string TypeModel;

    void SetPolyOneStep();
    void SetMaOneStep();
    void SetFirOneStep();
    void SetArxOneStep();
    void SetArmaxOneStep();
//    void SetBillinearOneStep();
//    void SetNaxrOneStep  (int nInPut,  int OutPut, int NonLinDegree, int nSample);
//    void SetNarmaxOneStep(int nInPut,  int OutPut, int nError, int NonLinDegree, int nSample);

//    void SetArmaxOneStepReal();
    void SetArmaxOMultStep();
    void SetPolyMultStep();

    UsedType SimOneStep();
//    Matrix<UsedType> SimOneStep (int var1, int var2, int var3, string Model);
//    Matrix<UsedType> SimOneStep (int var1, int var2, int var3, int var4, string Model);
//    Matrix<UsedType> SimOneStep (int var1, int var2, int var3, int var4, int var5, string Model);

public:
    Sim(Matrix<UsedType> InPut, Matrix<UsedType> OutPut, string Model, int var1 = 0, int var2 = 0, int var3 = 0, int var4 = 0, int var5 = 0);

//    void SetParametersModel();
    Matrix<UsedType> RunSimulation(Matrix<UsedType> LinSysParameters, int nSteps = 0);
    Matrix<UsedType> GetInput();
    Matrix<UsedType> GetRealOutPut();
    Matrix<UsedType> GetEstimatedOutPut();
    Matrix<UsedType> GetError();
    Matrix<UsedType> GetLinSysOutPut();
    Matrix<UsedType> GetLinMatrix();

};

#endif // SIM_H
