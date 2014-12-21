#ifndef STATESPACE_H
#define STATESPACE_H
#include <src/simulationLibs/model.h>

template <class UsedType>
class StateSpace : public Model<UsedType>
{
    UsedType SampleTime, TimeSimulation;
    Matrix<UsedType> A, B, C, D;
public:
    StateSpace();


    UsedType sim(UsedType x);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // STATESPACE_H
