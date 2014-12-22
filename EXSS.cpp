#include <src/simulationLibs/statespace.h>

int main()
{
    Matrix<double> A,B,C,D,u;
    A = "1,0;-2,-1";
    B = "0;1";
    C = "0,1";
    D = "0";
    u = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1";

    StateSpace<double> SS(A,B,C,D);
    SS.print();
    SS.sim(u).print();
    return 0;
}
