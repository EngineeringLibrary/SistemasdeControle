#ifndef ARMAX_H
#define ARMAX_H
#include <src/simulationLibs/model.h>

template <class UsedType>
class ARMAX : public Model<UsedType>
{
public:
    ARMAX();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARMAX_H
