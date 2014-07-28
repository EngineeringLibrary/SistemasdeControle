#ifndef __PSO_H_INCLUDED
#define __PSO_H_INCLUDED

#include "..\simulation libs\lsim.h"

template <class UsedType>
class PSO
{
private:
    bool MinMax;
    int varNum, PopSize, GenSize;
    double phi1, phi2, omega, Stime;
    Matrix<UsedType> V, X, P, G, GGen, GnTimes, Xfitness, Pfitness, Gfitness, GfitnessGen, GfitnessnTime, RunTime;
    Lsim<UsedType> Model;


    Matrix<UsedType> Evaluation(Matrix<UsedType> Matrix2Evaluate);
    void ParticleUpdate();
    void ParticleEvaluation();
    void VelocityUpdate();
    void initAlgorithm();
    void FitnessUpdate();
    void FitnessUpdateMin();
    void FitnessUpdateMax();

public:
    PSO();
    PSO(int varNum, int PopSize, int GenSize);
    PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2);
    PSO(int varNum, int PopSize, int GenSize, double phi1, double phi2, double omega, bool MinMax);
    ~PSO();

    void Run();
    void Run(int nTimes);
    void setData(Matrix<UsedType> dataIn, Matrix<UsedType> dataOut);

    double getTime();
};

#endif // PSO_H
