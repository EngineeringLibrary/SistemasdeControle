#ifndef SIMFUNCTION_H
#define SIMFUNCTION_H
#include <src/primitiveLibs/matrix.h>
#include <src/simulationLibs/model.h>

template <class UsedType>
class simFunction : public Model<UsedType>
{
private:
    UsedType (*FunctionToCall)(UsedType);

public:
    simFunction(UsedType (*FunctionToCall)(UsedType));

    UsedType sim(UsedType input);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);

    typedef double(*FunctionCall)(double);
    FunctionCall   GetFunctionCall();


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

    void simulate();

};

#endif // SIMFUNCTION_H
