#ifndef SIMFUNCTION_H
#define SIMFUNCTION_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/modelLibs/model.h"

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
    void setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);

    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> X, LinAlg::Matrix<UsedType> Y);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);

    typedef UsedType(*FunctionCall)(UsedType);
    FunctionCall GetFunctionCall(){return FunctionToCall;}


    void   GenerateDataFunction();
    UsedType normalize(UsedType input, UsedType xUp, UsedType xDown,
                     UsedType yUp, UsedType yDown);

    void   SetDataStep    (UsedType step);
    void   SetDataLimits  (UsedType lMin, UsedType lMax);
    void   SetInputData   (LinAlg::Matrix<UsedType> input);
    void   SetOutputData  (LinAlg::Matrix<UsedType> Output);
    void   SetFunctionCall(UsedType (*FunctionToCall)(UsedType));

    LinAlg::Matrix<UsedType> GetInputData ();
    LinAlg::Matrix<UsedType> GetOutputData();
    UsedType   GetDataStep  ();
    UsedType   GetDataMinLimit();
    UsedType   GetDataMaxLimit();
};

#endif // SIMFUNCTION_H
