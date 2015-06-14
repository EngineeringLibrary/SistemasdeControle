#ifndef PREDITIVO_H
#define PREDITIVO_H

#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/model.h"
#include "C:/Users/hbarbosa/Documents/GitHub/SistemasdeControle-master/headers/modelLibs/statespace.h"
#include "C:/Users/hbarbosa/Documents/GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "Model/modelointegrativo.h"
#include "Model/modelopredicao.h"

template <class Type>
class Preditivo
{
    ModeloPredicao MP;
    LinAlg::Matrix<UsedType> K, W, X0;

public:
    Preditivo(ModeloPredicao MP, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R);
    OutputControlCalc();
};

#endif // PREDITIVO_H
