#ifndef ARMAX_H
#define ARMAX_H
#include "model.h"

template <class UsedType>
class ARMAX : public Model<UsedType>
{
public:
    ARMAX();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARMAX_H
