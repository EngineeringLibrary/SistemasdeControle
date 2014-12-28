#include <src/simulationLibs/statespace.h>
#include <src/simulationLibs/arx.h>
#include <src/optimizationLibs/leastsquare.h>
#include <src/simulationLibs/conversions.h>

using namespace conversions;

int main(int argc, char *argv)
{
    Matrix<double> A,B,C,D,u;
    A = "1,0;-2,-1";
    B = "0;1";
    C = "0,1";
    D = "0";
    u = "1,2,3,-1,-3,8,8,8,1,1,1,1,1";
    StateSpace<double> SS(A,B,C,D);
    SS.sim(u).print();
    TransferFunction<double> TF = ss2tf(SS);
    TF.print();
    ARX<double> gz(2,2);
    gz.setLinearModel(~u,~SS.sim(u));
    Optimization<double> *LS = new LeastSquare<double>(&gz);
    LS->Optimize();
    LS->getOptimizatedVariable().print();
    return 0;
}
