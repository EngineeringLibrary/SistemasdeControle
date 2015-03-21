#include "SistemasdeControle/headers/modelLibs/model.h"

template <class UsedType>
Model<UsedType>::Model()
{
}

template <class UsedType>
void Model<UsedType>::setInstance(Model<UsedType> *m)
{
    this->instance = m;
}

template <class UsedType>
void Model<UsedType>::setStep(UsedType step)
{
    this->step = step;
}

template <class UsedType>
UsedType Model<UsedType>::diff(UsedType x)
{
    return (instance->sim(x+step)-instance->sim(x))/step;
}

template <class UsedType>
void Model<UsedType>::setIO(LinAlg::Matrix<UsedType> in, LinAlg::Matrix<UsedType> out)
{
    this->Input  = in;
    this->Output = out;
}

template <class UsedType>
void Model<UsedType>::setModelCoef(LinAlg::Matrix<UsedType> coef)
{
    this->ModelCoef = coef;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getInputMatrix()
{
    return this->Input;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getOutputMatrix()
{
    return this->Output;
}

template <class UsedType>
UsedType Model<UsedType>::getOutput()
{
    return this->output;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getLinearVectorPhi()
{
    return this->LinearVectorPhi;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getLinearMatrixA()
{
    return this->LinearMatrixA;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getLinearEqualityB()
{
    return this->LinearEqualityB;
}

template <class UsedType>
LinAlg::Matrix<UsedType> Model<UsedType>::getModelCoef()
{
    return this->ModelCoef;
}


template class Model<float>;
template class Model<double>;
