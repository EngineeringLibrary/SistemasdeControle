#include "SistemasdeControle/headers/modelLibs/preditivo.h"

template<typename Type>
Preditivo<Type>::Preditivo(ModeloPredicao<Type> MP, LinAlg::Matrix<Type> Q, LinAlg::Matrix<Type> R, LinAlg::Matrix<Type> W)
{
    this->K = (((~MP.getB())*(~MP.getC())*Q*MP.getC()*MP.getB()+R )^-1)*(~MP.getB())*(~MP.getC())*(~Q);
    this->W = W;
    this->MP = MP;
}

template<typename Type>
LinAlg::Matrix<Type> Preditivo<Type>::OutputControlCalc()
{
  //  X0 = (X(:,k)-X(:,k-1)); //Cd*X(:,k);

}
