#ifndef STATESPACE_H
#define STATESPACE_H
#include <src/simulationLibs/model.h>
#include <src/simulationLibs/transferfunction.h>

template <class UsedType>
class StateSpace : public Model<UsedType>
{
private:
    bool Continuous;
    unsigned nDiscretization;
    UsedType SampleTime, TimeSimulation;
    Matrix<UsedType> A, B, C, D, Ad, Bd, X, initialState;


    UsedType factorial(unsigned n);

    void c2dConversion();
    void d2cConversion();

public:

    StateSpace(Matrix<UsedType> A, Matrix<UsedType> B,
               Matrix<UsedType> C, Matrix<UsedType> D);

    void print();

    void c2d(UsedType SampleTime);
    void setInitialState(Matrix<UsedType> X0);

    Matrix<UsedType> getA();
    Matrix<UsedType> getB();
    Matrix<UsedType> getC();
    Matrix<UsedType> getD();
    Matrix<UsedType> getActualState();

    UsedType sim(UsedType u);
    UsedType sim(UsedType u, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> u);
    Matrix<UsedType> sim(Matrix<UsedType> u, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lmim, UsedType lmax, UsedType step);
};

#endif // STATESPACE_H
