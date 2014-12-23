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
        Matrix<UsedType> A, B, C, D;
//        TF.setTF(MMC(TF.getTF()),
//                 TF.getNRowsTF(),TF.getNColsTF());

        unsigned TFdenCols = 2*(TF(1,1).getDen().getCols()-2);

        Matrix<UsedType> I, ZeroVector, tempDen(2, TFdenCols-1);

        I.eye(TFdenCols);
        ZeroVector.zeros( TFdenCols, TF.getNColsTF());
        for (unsigned i = 1; i < TFdenCols; i++)
        {
            tempDen( 1, 2*i-1, -(TF(1,1).getDen()( 1, i+1)));
            tempDen( 2, 2*i, -(TF(1,1).getDen()( 1, i+1)));
        }
        tempDen.print();
        A = tempDen||(I|ZeroVector);

        B.zeros(A.getRows(), TF.getNColsTF());

        for (unsigned i = 1; i <= B.getCols(); i++)
            B(i, i, 1);

        D.zeros(TF.getNRowsTF(),TF.getNColsTF());
        for(unsigned i = 1; i <= TF.getNRowsTF(); i++)
            for(unsigned j = 1; j <= TF.getNColsTF(); j++)
                if(TF(i,j).getNum().getCols() == TF(i,j).getDen().getCols())
                    D(i,j, TF(i,j).getNum()(1,1));

        C.zeros(TF.getNRowsTF(),A.getCols());

        for(unsigned i = 1; i <= TF.getNRowsTF(); i++)
            for(unsigned j = 1; j <= TF.getNColsTF(); j++)
            {
                Matrix<UsedType> Num = TF(i,j).getNum();
                unsigned cont  = 1;
                unsigned cont2 = 0;
                if((TF(i,j).getDenSize() - Num.getCols()) > 1)
                    cont2 = TF.getNColsTF()*(TF(i,j).getDenSize() - Num.getCols() - 1);

                for(unsigned k = Num.getCols(); k > 0 ; k--)
                {
                    if(k < TF(i,j).getDenSize())
                    {
                        C(i,j + cont2, Num(1,cont));
                        cont2 += TF.getNColsTF();
                    }
                    cont++;
                }
            }

        return StateSpace<UsedType>(A,B,C,D);
    }

}


#endif // CONVERSIONS_H
