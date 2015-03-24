#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    bool isContinuous;
    UsedType sampleTime, timeSimulation;
    LinAlg::Matrix< PolynomOperations::Polynom<UsedType> > TF;
//    void initTfNumber();
    void c2dConversion();

public:
    TransferFunction();
    TransferFunction(unsigned rows, unsigned cols);
    TransferFunction(LinAlg::Matrix<UsedType> numerators, LinAlg::Matrix<UsedType> denominators);
    TransferFunction(std::string num, std::string den,
                     unsigned rows  , unsigned cols);

    void c2d(UsedType sampleTime);
    PolynomOperations::Polynom<UsedType>& operator()(unsigned row, unsigned col);
    PolynomOperations::Polynom<UsedType>  operator()(unsigned row, unsigned col)const;
    void operator= (TransferFunction<UsedType> TF);

    void print();
    void setLinearVectorPhi();
    void setLinearVectorPhiEstimation();
    void setLinearModel(LinAlg::Matrix<UsedType> Input, LinAlg::Matrix<UsedType> Output);


    void setTF(PolynomOperations::Polynom<UsedType> **TF, unsigned rows, unsigned cols);
    PolynomOperations::Polynom<UsedType> **getTF();
    unsigned getNRowsTF();
    unsigned getNColsTF();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
