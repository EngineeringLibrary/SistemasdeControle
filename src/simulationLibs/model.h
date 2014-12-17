#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "src/primitiveLibs/matrix.h"

template <class UsedType>
class Model
{
    double input,output, lmin,lmax, step;
    Matrix<UsedType> Input,Output;

public:
    Model();

    virtual UsedType sim(UsedType x) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x) = 0;
    virtual Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

};

#endif // MODEL_H
