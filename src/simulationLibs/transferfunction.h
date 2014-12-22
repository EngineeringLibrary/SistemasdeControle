#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>
#include <src/simulationLibs/statespace.h>


template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    UsedType sampleTime, timeSimulation;
    unsigned nRowsTF;
    Polynom<UsedType> **TF;
    void initTfNumber();
    void c2dConversion();

public:
    TransferFunction(unsigned length);
    TransferFunction(StateSpace<UsedType> SS);
    TransferFunction(std::string num, std::string den);

    Polynom<UsedType> operator()(unsigned row, unsigned col);

    void printTF(); // Método Opcional

    UsedType sim(UsedType x);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
