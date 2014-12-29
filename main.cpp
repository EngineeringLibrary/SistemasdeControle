#include "src/simulationLibs/model.h"
#include <src/simulationLibs/statespace.h>
int main(int argc, char *argv)
{
    Matrix<double> A,B,C,D;
    A = "1,0;-2,-1";
    B = "0;1";  C = "0,1";  D = "0";

    Model<double> *model = new StateSpace<double>(A,B,C,D);
    model->sim(0,5,1).print();
    return 0;
}
