#ifndef ARX_H
#define ARX_H
#include <src/simulationLibs/model.h>

template <class UsedType>
class ARX : public Model<UsedType>
{
private:
    unsigned nInputpar  , nOutputpar  , delay,
             qdtInputVar, qdtOutputVar, nSample,
             maxnInOut;
public:
    ARX(unsigned nInputpar , unsigned nOutputpar,
        unsigned delay = 0,
        unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1);

    void setLinearVectorPhiEstimation();
    void setLinearVectorPhi();
    void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output);

    void print();
    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    Matrix<UsedType> sim(Matrix<UsedType> Input);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARX_H
