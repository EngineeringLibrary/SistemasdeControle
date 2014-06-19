#ifndef PSO_H
#define PSO_H

#include "lsim.h"

class PSO
{
private:
    bool MinMax;
    int varNum, PopSize, GenSize;
    double phi1, phi2, omega, Stime;
    Matrix V, X, P, G, GGen, GnTimes, Xfitness, Pfitness, Gfitness, GfitnessGen, GfitnessnTime, RunTime;
    Lsim Model;


    Matrix Evaluation(Matrix Matrix2Evaluate);
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
    void setData(Matrix dataIn, Matrix dataOut);

    double getTime();
};

#endif // PSO_H
