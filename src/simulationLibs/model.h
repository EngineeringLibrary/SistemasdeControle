#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "src/primitiveLibs/matrix.h"

template <class UsedType>
class Model
{
protected:
    Model<UsedType> *instance;
    UsedType         input,output,    lmin,lmax,     step;
    Matrix<UsedType> Input,Output,    EstOutput,     ModelCoef,
                     LinearVectorPhi, LinearMatrixA, LinearEqualityB;
public:
    Model();
    UsedType diff(UsedType x);
    void setStep(UsedType step);
    void setInstance(Model<UsedType> *m);
    void setModelCoef(Matrix<UsedType> coef);
    void setIO(Matrix<UsedType> in, Matrix<UsedType> out);

    Matrix<UsedType> getModelCoef();
    Matrix<UsedType> getInputMatrix();
    UsedType getOutput();
    Matrix<UsedType> getOutputMatrix();
    Matrix<UsedType> getLinearMatrixA();
    Matrix<UsedType> getLinearEqualityB();
    Matrix<UsedType> getLinearVectorPhi();

    virtual UsedType         sim(UsedType x) = 0;
    virtual UsedType         sim(UsedType x, UsedType y) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y) = 0;
    virtual Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

    virtual void print()=0;
    virtual void setLinearVectorPhi() = 0;
    virtual void setLinearVectorPhiEstimation()=0;
    virtual void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output)=0;

};

#endif // MODEL_H
