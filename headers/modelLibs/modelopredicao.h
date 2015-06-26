#ifndef MODELOPREDICAO_H
#define MODELOPREDICAO_H
#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/modelLibs/modelointegrativo.h"

template <class Type>
class ModeloPredicao: public Model<Type>
{
    bool Continuous;
    unsigned nDiscretization, HorizontePredicaoMin, HorizontePredicaoMax, HorizonteControle;
    Type SampleTime, TimeSimulation;
    LinAlg::Matrix<Type> A, B, C, D, Ad, Bd, X, initialState;

public:
    ModeloPredicao(ModeloIntegrativo<Type> MI,
                   unsigned HorizontePredicaoMin, unsigned HorizontePredicaoMax, unsigned HorizonteControle);
    ~ModeloPredicao();

    LinAlg::Matrix<Type> getA();
    LinAlg::Matrix<Type> getB();
    LinAlg::Matrix<Type> getC();
    LinAlg::Matrix<Type> getD();
};

#endif // MODELOPREDICAO_H
