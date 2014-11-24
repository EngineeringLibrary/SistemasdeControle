#ifndef SIMFUNCTION_H
#define SIMFUNCTION_H
#include <src/primitiveLibs/matrix.h>

class simFunction
{
private:
    Matrix<double> input, output;
    double         (*FunctionToCall)(double), lMin, lMax, step;

public:
    simFunction();
    simFunction(Matrix<double> in, Matrix<double> out);
    simFunction(double (*FunctionToCall)(double), double lMin,
                double lMax, double step);

    double FunctionCalculation(double input);
    void   GenerateDataFunction();
    double normalize(double input, double xUp, double xDown,
                     double yUp, double yDown);

    void   SetDataStep    (double step);
    void   SetDataLimits  (double lMin, double lMax);
    void   SetInputData   (Matrix<double> input);
    void   SetOutputData  (Matrix<double> Output);
    void   SetFunctionCall(double (*FunctionToCall)(double));

    Matrix<double> GetInputData ();
    Matrix<double> GetOutputData();
    double   GetDataStep  ();
    double   GetDataMinLimit();
    double   GetDataMaxLimit();
    typedef double(*FunctionCall)(double);
    FunctionCall   GetFunctionCall();

    void simulate();
};

#endif // SIMFUNCTION_H
