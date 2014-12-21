#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>

template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    UsedType sampleTime;
    unsigned nRowsTF;
    Polynom<UsedType> **TF;
    void initTfNumber();
    void c2dConversion();

public:
    TransferFunction(std::string num, std::string den);


    void printTF(); // Método Opcional

    UsedType sim(UsedType x);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
