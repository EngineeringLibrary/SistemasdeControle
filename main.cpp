#include "src/simulationLibs/statespace.h"
#include "src/simulationLibs/arx.h"
#include "src/optimizationLibs/optimization.h"
#include "src/optimizationLibs/leastsquare.h"
#include "src/optimizationLibs/pso.h"

int main(int argc, char *argv)
{
    Matrix<double> u, syspar;

    u = "1,1,1,1,1,1,1,1,1,1";
    syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

    Model<double> *gz = new ARX<double>(2,2);
    gz->setModelCoef(syspar);
    gz->sim(~u).print();
    gz->setIO(~u,gz->sim(~u));
    Optimization<double> *P = new PSO<double>(gz,4,20,2000);
    P->Optimize();
    P->getOptimizatedVariable().print();

    Model<double> *gz2 = new ARX<double>(2,2);
    gz2->setModelCoef(~P->getOptimizatedVariable());
    (gz->getOutputMatrix()|gz2->sim(~u)).print();
    return 0;

//    Matrix<double> A;
//    A = "-1,-1;1,0";
//    A.eigenvalues().print();
//    double R = 2.7, L = 0.004, K = 0.105, b = 9.3e-6, j = 1e-5;
//    Matrix<double> A,B,C,D;
//    A(1,1,-R/L);   A(1,2,-K/L);
//    A(2,1,K/L);    A(2,2,-b/j);

//    B(1,1,1/L);
//    B(2,1,0.0);

//    C(1,1,0); C(1,2,1);

//    D = "0";

//    StateSpace<double> SS(A,B,C,D);
//    SS.print();
//    TransferFunction<double> TF = ss2tf(SS);
//    TF.print();
//    SS = tf2ss(TF);
//    SS.print();
//    SS.c2d(0.1);
//    A = SS.getA();
//    B = SS.getB();
//    SS.print();

//    Matrix<double> Aa, Ba, Ca, Z, I;

//    Z.zeros(A.getRows(), C.getRows());
//    I.eye(C.getRows());

//    Aa = (A|Z)||((C*A)|I);
//    Aa.print();

//    Ba = B||(C*B);
//    Ba.print();

//    Z.zeros(C.getRows(),A.getCols());
//    Ca = Z|I;
//    Ca.print();
//    unsigned N1 = 1, N2 = 20;

//    A = Aa;
//    for(unsigned i=N1+1; i<=N2; i++)
//        A = A||(Aa^i);
//    A.print();
    return 0;
}
