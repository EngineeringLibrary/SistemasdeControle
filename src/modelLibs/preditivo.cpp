#include "preditivo.h"

Preditivo::Preditivo(ModeloPredicao MP, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{
    this->K = (((~MP.getB())*(~MP.getC())*Q*MP.getC()*MP.getB()+R )^-1)*(~MP.getB())*(~MP.getC())*(~Q);
    this->W = W;
    this->MP = MP;
}

LinAlg::Matrix<Type> Preditivo::OutputControlCalc()
{
    X0 = (X(:,k)-X(:,k-1)); Cd*X(:,k);

}
