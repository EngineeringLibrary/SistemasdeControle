#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>

template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    bool isContinuous;
    UsedType sampleTime, timeSimulation;
    unsigned nRowsTF, nColsTF;
    Polynom<UsedType> **TF;
    void initTfNumber();
    void c2dConversion();

public:
    TransferFunction();
    TransferFunction(unsigned rows, unsigned cols);
    TransferFunction(std::string num, std::string den,
                     unsigned rows  , unsigned cols);

    void c2d(UsedType sampleTime);
    Polynom<UsedType> operator()(unsigned row, unsigned col);
    void operator()(unsigned row, unsigned col, Polynom<UsedType> P);
    void operator= (TransferFunction<UsedType> TF);

    void print();
    void setLinearVectorPhi();
    void setLinearVectorPhiEstimation();
    void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output);


    void setTF(Polynom<UsedType> **TF, unsigned rows, unsigned cols);
    Polynom<UsedType> **getTF();
    unsigned getNRowsTF();
    unsigned getNColsTF();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
