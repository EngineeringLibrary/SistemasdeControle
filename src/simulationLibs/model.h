#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "src/primitiveLibs/matrix.h"

template <class UsedType>
class Model
{
protected:
    UsedType input,output, lmin,lmax, step;
    Model<UsedType> *instance;
    Matrix<UsedType> Input,Output;

public:
    Model();
    UsedType diff(UsedType x);
    void setInstance(Model<UsedType> *m);
    void setStep(UsedType step);

    virtual UsedType sim(UsedType x) = 0;
    virtual UsedType sim(UsedType x, UsedType y) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y) = 0;
    virtual Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

};

#endif // MODEL_H
