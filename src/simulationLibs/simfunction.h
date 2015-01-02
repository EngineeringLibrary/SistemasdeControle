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

    void print();
    void setLinearVectorPhi();
    void setLinearVectorPhiEstimation();
    void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output);

    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> X, Matrix<UsedType> Y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);

    typedef UsedType(*FunctionCall)(UsedType);
    FunctionCall GetFunctionCall(){return FunctionToCall;}


    void   GenerateDataFunction();
    UsedType normalize(UsedType input, UsedType xUp, UsedType xDown,
                     UsedType yUp, UsedType yDown);

    void   SetDataStep    (UsedType step);
    void   SetDataLimits  (UsedType lMin, UsedType lMax);
    void   SetInputData   (Matrix<UsedType> input);
    void   SetOutputData  (Matrix<UsedType> Output);
    void   SetFunctionCall(UsedType (*FunctionToCall)(UsedType));

    Matrix<UsedType> GetInputData ();
    Matrix<UsedType> GetOutputData();
    UsedType   GetDataStep  ();
    UsedType   GetDataMinLimit();
    UsedType   GetDataMaxLimit();
};

#endif // SIMFUNCTION_H
