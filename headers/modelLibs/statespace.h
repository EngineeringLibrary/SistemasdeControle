#ifndef STATESPACE_H
#define STATESPACE_H
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/transferfunction.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"

template <class UsedType>
class StateSpace : public Model<UsedType>
{
private:
    bool Continuous;
    unsigned nDiscretization;
    UsedType SampleTime, TimeSimulation;
    LinAlg::Matrix<UsedType> A, B, C, D, Ad, Bd, X, initialState;


    UsedType factorial(unsigned n);

    void c2dConversion();
    void d2cConversion();

public:

    StateSpace(LinAlg::Matrix<UsedType> A , LinAlg::Matrix<UsedType> B,
               LinAlg::Matrix<UsedType> C , LinAlg::Matrix<UsedType> D);
    StateSpace(LinAlg::Matrix<UsedType> Ad, LinAlg::Matrix<UsedType> Bd,
               LinAlg::Matrix<UsedType> C , LinAlg::Matrix<UsedType> D,
               UsedType SampleTime);

    void print();
    void setLinearVectorPhi();
    void setLinearVectorPhiEstimation();
    void setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);

    void c2d(UsedType SampleTime);
    void setInitialState(LinAlg::Matrix<UsedType> X0);

    LinAlg::Matrix<UsedType> getA();
    LinAlg::Matrix<UsedType> getB();
    LinAlg::Matrix<UsedType> getC();
    LinAlg::Matrix<UsedType> getD();
    LinAlg::Matrix<UsedType> getActualState();

    UsedType sim(UsedType u);
    UsedType sim(UsedType u, UsedType y);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> u);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> u, LinAlg::Matrix<UsedType> y);
    LinAlg::Matrix<UsedType> sim(UsedType lmim, UsedType lmax, UsedType step);
};

#endif // STATESPACE_H
