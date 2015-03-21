#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

template <class UsedType>
class Model
{
protected:
    Model<UsedType> *instance;
    UsedType         input,output,    lmin,lmax,     step;
    LinAlg::Matrix<UsedType> Input,Output,    EstOutput,     ModelCoef,
                     LinearVectorPhi, LinearMatrixA, LinearEqualityB;
public:
    Model();
    UsedType diff(UsedType x);
    void setStep(UsedType step);
    void setInstance(Model<UsedType> *m);
    void setModelCoef(LinAlg::Matrix<UsedType> coef);
    void setIO(LinAlg::Matrix<UsedType> in, LinAlg::Matrix<UsedType> out);

    LinAlg::Matrix<UsedType> getModelCoef();
    LinAlg::Matrix<UsedType> getInputMatrix();
    UsedType getOutput();
    LinAlg::Matrix<UsedType> getOutputMatrix();
    LinAlg::Matrix<UsedType> getLinearMatrixA();
    LinAlg::Matrix<UsedType> getLinearEqualityB();
    LinAlg::Matrix<UsedType> getLinearVectorPhi();

    virtual UsedType         sim(UsedType x) = 0;
    virtual UsedType         sim(UsedType x, UsedType y) = 0;
    virtual LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x) = 0;
    virtual LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y) = 0;
    virtual LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

    virtual void print()=0;
    virtual void setLinearVectorPhi() = 0;
    virtual void setLinearVectorPhiEstimation()=0;
    virtual void setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output)=0;

};

#endif // MODEL_H
