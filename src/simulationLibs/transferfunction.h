#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>

template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    unsigned nRowsTF;
    Polynom<UsedType> **TF;
    void initTfNumber();
    void initTF(unsigned lNum, unsigned lDen);

public:
    TransferFunction(std::string num, std::string den);

    UsedType sim(UsedType x);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
    void printTF(); // Método Opcional
};

#endif // TRANSFERFUNCTION_H
