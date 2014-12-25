#ifndef MA_H
#define MA_H
#include <src/simulationLibs/model.h>

template <class UsedType>
class MA : public Model<UsedType>
{
public:
    MA();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // MA_H
