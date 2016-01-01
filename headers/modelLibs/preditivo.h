#ifndef PREDITIVO_H
#define PREDITIVO_H

#include "SistemasdeControle/headers/modelLibs/model.h"
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/modelLibs/integrativemodel.h"
#include "SistemasdeControle/headers/modelLibs/predictionmodel.h"

template <class Type>
class Preditivo
{
    ModeloPredicao<Type> MP;
    LinAlg::Matrix<Type> K, W, X0;

public:
    Preditivo(ModeloPredicao<Type> MP, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W);
    LinAlg::Matrix<Type> OutputControlCalc();
};

#endif // PREDITIVO_H
