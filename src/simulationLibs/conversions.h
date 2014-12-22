#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include <src/simulationLibs/statespace.h>
#include <src/simulationLibs/transferfunction.h>

namespace conversions{
    template <class UsedType>
    TransferFunction<UsedType> ss2tf(StateSpace<UsedType> SS)
    {
        Matrix<UsedType> A = SS.getA(), B = SS.getB(), tempB,
                         C = SS.getC(), D = SS.getD(), tempC;

        TransferFunction<UsedType> TF(C.getRows(),B.getCols());

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
//        unsigned TFdenCols = TF(1,1).getDen().getCols();
//        unsigned TFnumCols = TF(1,1).getNum().getCols();
//        Matrix<UsedType> I, ZeroVector, tempDen(1, TFdenCols-1);

//        I.eye(TFdenCols-2);
//        ZeroVector.zeros( TFdenCols-2, 1);
//        for (int i = 2; i <= TFdenCols; i++)
//            tempDen( 1, i-1, -(TF(1,1).getDen()( 1, i)));

//        this->A = tempDen||(I|ZeroVector);
//        this->B.zeros(this->A.getRows(), 1);
//        this->B.add( 1, 1, 1);

//        if (TFnumCols == 1)
//        {
//            this->C( 1, this->B.getRows(), TF(1,1).getNum()( 1, 1));
//            this->D( 1, 1, 0);
//        }
//        else if (TFnumCols < TFdenCols)
//        {
//            for (int i = this->B.getRows(); i > 1; i--)
//                this->C.add( 1, i, TF(1,1).getNum()( 1, TFnumCols -( this->B.getRows() - i )));
//            this->D.add( 1, 1, 0);
//        }

//        else if (TFnumCols == TFdenCols)
//        {
//            float B0 = TF(1,1).getNum()( 1, 1);

//            for (int i = 1; i <= this->B.getRows(); i++)
//             {
//                this->C.add( 1, i, TF(1,1).getNum()( 1, i+1)- TF(1,1).getDen()( 1, i+1)*B0);
//             }
//            this->D.add( 1, 1,  B0);
//        }

    }

}


#endif // CONVERSIONS_H
