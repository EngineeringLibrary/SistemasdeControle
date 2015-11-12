#ifndef FIR_H
#define FIR_H
#include "SistemasdeControle/headers/modelLibs/model.h"

template <class UsedType>
class FIR : public Model<UsedType>
{
    unsigned nUpar, delay, qdtVar, cont;

    void setOneStepLinSys(UsedType input);
    void setMultStepLinSys(UsedType input);
public:
    FIR(unsigned nUpar, unsigned delay=0, unsigned qdtVar=1);

    void setLinearVector(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);
    void setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);

    void print();
    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> Input);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // FIR_H
