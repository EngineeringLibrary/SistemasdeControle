#include <src/simulationLibs/transferfunction.h>

int main(int argc, char *argv)
{
    Polynom<double> P("0,1","1,2,1");
    TransferFunction<double> TF(1,1);

    TF(1,1,P);
    TF.print();

    return 0;
}
