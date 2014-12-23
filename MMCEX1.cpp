#include <src/simulationLibs/transferfunction.h>
#include <src/simulationLibs/statespace.h>
#include "src/simulationLibs/conversions.h"

using namespace conversions;

int main()
{
    TransferFunction<double> TF(2,2);
    TF(1, 1, Polynom<double>("1","1,1"));
    TF(1, 2, Polynom<double>("1","1,2"));
    TF(2, 1, Polynom<double>("1","1,3"));
    TF(2, 2, Polynom<double>("1","1,4"));

    TF.printTF();

    Polynom<double> **Saida = TF.getTF();
    Saida = MMC(Saida,TF.getNRowsTF(),TF.getNColsTF());
    Saida[0][0].print();
    Saida[0][1].print();
    Saida[1][0].print();
    Saida[1][1].print();
    return 0;
}
