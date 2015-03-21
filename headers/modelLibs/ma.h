#ifndef MA_H
#define MA_H
#include "SistemasdeControle/headers/modelLibs/model.h"

template <class UsedType>
class MA : public Model<UsedType>
{
public:
    MA();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x);
    LinAlg::Matrix<UsedType> sim(LinAlg::Matrix<UsedType> x, LinAlg::Matrix<UsedType> y);
    LinAlg::Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // MA_H
