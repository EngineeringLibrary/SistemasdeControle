#include "model.h"

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

template class Model<float>;
template class Model<double>;
