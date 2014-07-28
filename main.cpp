#include "src\optimization libs\optimization.h"
#include "src\simulation libs\sim.h"

int main()
{
    Matrix <double> in, out;

    in = "0.8147;0.9058;0.1270;0.9134;0.6324;0.0975;0.2785;0.5469;0.9575;0.9649;0.1576;0.9706;0.9572;0.4854;0.8003;0.1419;0.4218;0.9157;0.7922;0.9595";
    out = "0;0.0038;0.0147;0.0280;0.0435;0.0628;0.0812;0.0973;0.1133;0.1323;0.1554;0.1778;0.1998;0.2247;0.2496;0.2735;0.2948;0.3121;0.3296;0.3487";

    Sim<double> S1(in, out, "ARX", 2, 2);
    Matrix<double> par;
    par = "1,1,1,1";
    S1.RunSimulation(~par, 10);
//    Optimization <double>Solve;
//    Solve.RLS(2,2,1000,in,out);
//    PSO <double>P(4, 80, 1000, 3.7, 0.9, 0.5, 0);
//    P.setData(in,out);
//    P.Run(50);

    return 0;
}
