#include <src/simulationLibs/transferfunction.h>
#include <src/simulationLibs/statespace.h>
#include "src/simulationLibs/conversions.h"
#include "src/simulationLibs/fir.h"
#include "src/simulationLibs/arx.h"
#include "src/optimizationLibs/optimization.h"
#include "src/optimizationLibs/leastsquare.h"

using namespace conversions;

int main()
{
    ARX<double> gz(2,2,1);
    Matrix<double> syspar;
    syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";
    gz.setModelCoef(syspar);
    double temp = 0;
    for(int i = 1; i < 100; i++)
    {
        temp = gz.sim(1,temp);
        std::cout << temp << std::endl;
    }
    gz.setLinearModel(gz.getInputMatrix(),gz.getOutputMatrix());

//    Model<double> *EQD = &gz;
    Optimization<double> *Sys = new LeastSquare<double>(&gz);

    Sys->Optimize();
    Sys->getOptimizatedVariable().print();

    return 0;
}
