#ifndef ARX_H
#define ARX_H
#include <src/simulationLibs/model.h>

template <class UsedType>
class ARX : public Model<UsedType>
{
public:
    ARX();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARX_H
