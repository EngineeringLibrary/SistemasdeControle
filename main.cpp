#include <src/simulationLibs/arx.h>

int main(int argc, char *argv)
{
    Matrix<double> U, syspar;
    U = "1;1;1;1;1;1;1;1;1;1";
    syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

    ARX<double> gz(2,2); // Construtor recebendo 2 parâmetros

    gz.setModelCoef(syspar);
    gz.sim(U).print();

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
