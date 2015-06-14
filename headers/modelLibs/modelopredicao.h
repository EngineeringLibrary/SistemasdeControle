#ifndef MODELOPREDICAO_H
#define MODELOPREDICAO_H
#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/model.h"
#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/statespace.h"
#include "C:/Users/hbarbosa/Documents/GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "Model/modelointegrativo.h"

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
