#include "SistemasdeControle/headers/modelLibs/modelointegrativo.h"

template <class Type>
ModeloIntegrativo<Type>::ModeloIntegrativo(StateSpace<Type> SS)
{
    this->Continuous = SS.isContinuous();
    if(Continuous)
    {
//        this->A = (SS.getA() | LinAlg::Zeros(SS.getA().getNumberOfRows(),SS.getC().getNumberOfRows()))
//                || (SS.getC()*SS.getA() | LinAlg::Eye(SS.getC().getNumberOfRows()));

//        this->B = (SS.getB() || SS.getC()*SS.getB());
    }else{
        this->Ad = (SS.getA() | LinAlg::Zeros(SS.getA().getNumberOfRows(),SS.getC().getNumberOfColumns()))
                || (SS.getC()*SS.getA() | LinAlg::Eye(SS.getC().getNumberOfRows()));

        this->Bd = (SS.getB() || SS.getC()*SS.getB());
    }
    this->C = (LinAlg::Zeros(SS.getC().getNumberOfRows(),SS.getB().getNumberOfColumns()) | SS.getC().getNumberOfRows());

    this->D = SS.getD();
}
template <class Type>
ModeloIntegrativo<Type>::~ModeloIntegrativo()
{

}

template <class Type>
LinAlg::Matrix<Type> StateSpace<Type>::getA()
{
    if(this->Continuous)
        return this->A;
    else
        return this->Ad;
}

template <class Type>
LinAlg::Matrix<Type> StateSpace<Type>::getB()
{
    if(this->Continuous)
        return this->B;
    else
        return this->Bd;
}

template <class Type>
LinAlg::Matrix<Type> StateSpace<Type>::getC()
{
    return this->C;
}

template <class Type>
LinAlg::Matrix<Type> StateSpace<Type>::getD()
{
    return this->D;
}
