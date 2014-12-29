#include <src/simulationLibs/transferfunction.h>

int main(int argc, char *argv)
{
    TransferFunction<double> TF("0,1","1,2,1",1,1);
    std::cout << TF.getNColsTF()<< std::endl;
}
