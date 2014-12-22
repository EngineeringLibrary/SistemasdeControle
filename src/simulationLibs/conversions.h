#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <src/simulationLibs/statespace.h>
#include <src/simulationLibs/transferfunction.h>

namespace convesions{
    template <class UsedType>
    TransferFunction<UsedType> ss2tf(StateSpace<UsedType> SS)
    {
        Matrix<UsedType> A = SS.getA(), B = SS.getB(), tempB,
                         C = SS.getC(), D = SS.getD(), tempC;

        TransferFunction<UsedType> TF(C.getRows());

        for(unsigned i = 1; i <= C.getRows(); i++)
        {
            for(unsigned j = 1; j<= B.getCols(); j++)
            {
                tempB = B.getColumn(j);
                tempC = C.getLine(i);

                TF(i,j, Polynom<UsedType>(((A - tempB*tempC).pol() - A.pol()), (A.pol())));
                TF(i,j, TF(i,j) + D(i,j));
            }
        }
        return TF;
    }
    template <class UsedType>
    StateSpace<UsedType> tf2ss(TransferFunction<UsedType> TF)
    {

    }

}


#endif // CONVERSIONS_H
