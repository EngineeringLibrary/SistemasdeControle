#ifndef MODELOINTEGRATIVO_H
#define MODELOINTEGRATIVO_H
#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/model.h"
#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/statespace.h"
#include "C:/Users/hbarbosa/Documents/GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

template <class Type>
class ModeloIntegrativo: public Model<Type>
{
    bool Continuous;
    unsigned nDiscretization;
    Type SampleTime, TimeSimulation;
    LinAlg::Matrix<Type> A, B, C, D, Ad, Bd, X, initialState;

public:
    ModeloIntegrativo(StateSpace<Type> SS);
    ~ModeloIntegrativo();

    LinAlg::Matrix<Type> getA();
    LinAlg::Matrix<Type> getB();
    LinAlg::Matrix<Type> getC();
    LinAlg::Matrix<Type> getD();
};

#endif // MODELOINTEGRATIVO_H
