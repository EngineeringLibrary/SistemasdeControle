#ifndef CONVERSIONS_H
#define CONVERSIONS_H
#include "SistemasdeControle/headers/modelLibs/statespace.h"
#include "SistemasdeControle/headers/modelLibs/transferfunction.h"

namespace Conversions{

    template <class UsedType>
    TransferFunction<UsedType> ss2tf(StateSpace<UsedType> SS)
    {
        LinAlg::Matrix<UsedType> A = SS.getA(), B = SS.getB(), tempB,
                         C = SS.getC(), D = SS.getD(), tempC;

        TransferFunction<UsedType> TF(C.getNumberOfRows(),B.getNumberOfColumns());

        for(unsigned i = 1; i <= C.getNumberOfRows(); i++)
        {
            for(unsigned j = 1; j<= B.getNumberOfColumns(); j++)
            {
                tempB = B.GetColumn(j);
                tempC = C.GetRow(i);

                TF(i,j, Polynom<UsedType>((LinAlg::CaracteristicPolynom(A - tempB*tempC) - LinAlg::CaracteristicPolynom(A)), LinAlg::CaracteristicPolynom(A)));
                TF(i,j, TF(i,j) + D(i,j));
            }
        }
        return TF;
    }

    template <class UsedType>
    StateSpace<UsedType> tf2ss(TransferFunction<UsedType> TF)
    {
        LinAlg::Matrix<UsedType> A, B, C, D;
//        TF.setTF(MMC(TF.getTF(),TF.getNRowsTF(),TF.getNColsTF()),
//                 TF.getNRowsTF(),TF.getNColsTF());

        unsigned TFdenCols = 2*(TF(1,1).getDen().getNumberOfColumns()-2);

        LinAlg::Matrix<UsedType> I, ZeroVector, tempDen(2, TFdenCols-1);

        I = LinAlg::Eye<UsedType> (TFdenCols);
        ZeroVector = LinAlg::Zeros<UsedType> ( TFdenCols, TF.getNColsTF());
        for (unsigned i = 1; i < TFdenCols; i++)
        {
            tempDen( 1, 2*i-1) = -(TF(1,1).getDen()( 1, i+1));
            tempDen( 2, 2*i)   = -(TF(1,1).getDen()( 1, i+1));
        }
//        tempDen.print();
        A = tempDen||(I|ZeroVector);

        B = LinAlg::Zeros<UsedType>(A.getNumberOfRows(), TF.getNColsTF());

        for (unsigned i = 1; i <= B.getNumberOfColumns(); i++)
            B(i, i) = 1;

        D = LinAlg::Zeros<UsedType>(TF.getNRowsTF(),TF.getNColsTF());
        for(unsigned i = 1; i <= TF.getNRowsTF(); i++)
            for(unsigned j = 1; j <= TF.getNColsTF(); j++)
                if(TF(i,j).getNum().getNumberOfColumns() == TF(i,j).getDen().getNumberOfColumns())
                    D(i,j) = TF(i,j).getNum()(1,1);

        C = LinAlg::Zeros<UsedType>(TF.getNRowsTF(),A.getNumberOfColumns());

        for(unsigned i = 1; i <= TF.getNRowsTF(); i++)
            for(unsigned j = 1; j <= TF.getNColsTF(); j++)
            {
                LinAlg::Matrix<UsedType> Num = TF(i,j).getNum();
                unsigned cont  = 1;
                unsigned cont2 = 0;
                if((TF(i,j).getDenSize() - Num.getNumberOfColumns()) > 1)
                    cont2 = TF.getNColsTF()*(TF(i,j).getDenSize() - Num.getNumberOfColumns() - 1);

                for(unsigned k = Num.getNumberOfColumns(); k > 0 ; k--)
                {
                    if(k < TF(i,j).getDenSize())
                    {
                        C(i,j + cont2) = Num(1,cont);
                        cont2 += TF.getNColsTF();
                    }
                    cont++;
                }
            }

        return StateSpace<UsedType>(A,B,C,D);
    }

}


#endif // CONVERSIONS_H
