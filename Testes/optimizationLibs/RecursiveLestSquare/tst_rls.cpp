#define testPolynom
#define testModel

#include <QString>
#include <QtTest>
#include "../../../headers/primitiveLibs/LinAlg/matrix.h"
#include "../../../headers/modelLibs/model.h"
#include "../../../headers/modelLibs/arx.h"
#include "../../../headers/modelLibs/polynomial.h"
#include "../../../headers/modelLibs/transferfunction.h"
#include "../../../headers/modelLibs/conversions.h"
#include "../../../headers/optimizationLibs/leastsquare.h"
#include "../../../headers/optimizationLibs/recursiveleastsquare.h"
// add necessary includes here

class rls : public QObject
{
    Q_OBJECT

public:
    rls(){}
    ~rls(){}

private slots:
    //void identification_SISO_case1();
    //void identification_MIMO_case1();
    void identification_Polynomial_SISO_case1();
    //void identification_Hammerstein_SISO_case1();

};
/*
void rls::identification_SISO_case1()
{
    ModelHandler::TransferFunction<double> TF("10","1,2,1");
    ModelHandler::TransferFunction<double> TFd = ModelHandler::c2d(TF,0.1);
    LinAlg::Matrix<double> U = 0.43*LinAlg::Ones<double>(1,10);
    LinAlg::Matrix<double> Y = TFd.sim(U);
    ModelHandler::ARX<double> arx(2,2);
    OptimizationHandler::RecursiveLeastSquare<double> RLS(&arx,1e6);

    QBENCHMARK {
        ModelHandler::TransferFunction<double> TF("10","1,2,1");
        ModelHandler::TransferFunction<double> TFd = ModelHandler::c2d(TF,0.1);
        LinAlg::Matrix<double> U = 0.43*LinAlg::Ones<double>(1,10);
        LinAlg::Matrix<double> Y = TFd.sim(U);
        ModelHandler::ARX<double> arx(2,2);
        OptimizationHandler::RecursiveLeastSquare<double> RLS(&arx,1e6);

        for(unsigned i = 0; i < 9; ++i)
        {
            RLS.Optimize(U(0,i),Y(0,i+1));
            std::cout << (arx) << std::endl;
        }

        std::cout << ModelHandler::arx2tf(arx) << std::endl;
        std::cout << TFd << std::endl;
    }

    for(unsigned i = 0; i < 9; ++i)
    {
        RLS.Optimize(U(0,i),Y(0,i+1));
    }
    //std::cout << arx << "\n";
}

void rls::identification_MIMO_case1()
{
    QBENCHMARK {
        ModelHandler::TransferFunction<double> TFd(2,4,0.1);
        PolynomHandler::Polynom<double> TFsiso1("0,0.0502643150445874,0.0486265591254919", "1,-1.80682836869774,0.905709516037680");
        PolynomHandler::Polynom<double> TFsiso2("0,0.0694528157694939,0.0671898433202834", "1,-1.80682836869774,0.905709516037680");
        PolynomHandler::Polynom<double> TFsiso3("0,0.0550157982343233,0.0532226351589859", "1,-1.79748080135868,0.905709516037680");
        PolynomHandler::Polynom<double> TFsiso4("0,0.0646020956501844,0.0624964806045582", "1,-1.79748080135868,0.905709516037680");
        PolynomHandler::Polynom<double> TFsiso0("0", "1");

        TFd(0,0) = TFsiso1; TFd(0,1) = TFsiso2; TFd(0,2) = TFsiso0; TFd(0,3) = TFsiso0;
        TFd(1,0) = TFsiso0; TFd(1,1) = TFsiso0; TFd(1,2) = TFsiso3; TFd(1,3) = TFsiso4;
        //std::cout << TFd << std::endl;

        LinAlg::Matrix<double> In = 10*LinAlg::Random<double>(4,10);
        LinAlg::Matrix<double> U;
        for(int i = 0; i < In.getNumberOfColumns(); ++i)
            U = U|((In(0,i)*LinAlg::Ones<double>(1,20)||In(1,i)*LinAlg::Ones<double>(1,20)||In(2,i)*LinAlg::Ones<double>(1,20)||In(3,1)*LinAlg::Ones<double>(1,20)));
        LinAlg::Matrix<double> Y = TFd.sim(U);
        ModelHandler::ARX<double> arx(2,2,0,4,2,0.1);
        OptimizationHandler::RecursiveLeastSquare<double> RLS(&arx,1e6);

        for(unsigned i = 0; i < 200; ++i)
        {
            RLS.Optimize(U(from(0)-->(3),i),Y(from(0)-->(1),i+1));
            std::cout << (arx) << std::endl;
        }

        std::cout << ModelHandler::arx2tf(arx) << std::endl;
        std::cout << TFd << std::endl;
    }
*/
void rls::identification_Polynomial_SISO_case1()
{
    ModelHandler::Polynomial<double> pol(6);
    pol.setModelCoef("0; 11.9677550168665; 0; 4.34814267315048;0;0;1.92078367330958");
    std::cout << (pol.print()) << std::endl;

    LinAlg::Matrix<double> U = 10*LinAlg::Random<double>(1,20);
    LinAlg::Matrix<double> Y = pol.sim(U);

    std::cout << Y << "\n";
    ModelHandler::Polynomial<double> pol2(6);
    OptimizationHandler::RecursiveLeastSquare<double> RLS(&pol2,1e9);

    for(unsigned i = 0; i < 9; ++i)
    {
        RLS.Optimize(U(0,i),Y(0,i));
        std::cout << (pol2.print()) << std::endl;
    }

    std::cout << (pol.print()) << std::endl;
}

/*
void rls::identification_Hammerstein_SISO_case1()
{
    QBENCHMARK {
        ModelHandler::TransferFunction<double> TFd("0,0.0502643150445874,0.0486265591254919", "1,-1.80682836869774,0.905709516037680");
        LinAlg::Matrix<double> In = 10*LinAlg::Random<double>(1,10);
        LinAlg::Matrix<double> U;
        for(int i = 0; i < In.getNumberOfColumns(); ++i)
            U = U|((In(0,i)*LinAlg::Ones<double>(1,20)||In(1,i)*LinAlg::Ones<double>(1,20)||In(2,i)*LinAlg::Ones<double>(1,20)||In(3,1)*LinAlg::Ones<double>(1,20)));

        LinAlg::Matrix<double> Y = TFd.sim(U);
        ModelHandler::ARX<double> arx(2,2);
        OptimizationHandler::RecursiveLeastSquare<double> RLS(&arx,1e6);

        for(unsigned i = 0; i < 9; ++i)
        {
            RLS.Optimize(U(0,i),Y(0,i+1));
            std::cout << (arx) << std::endl;
        }

        std::cout << ModelHandler::arx2tf(arx) << std::endl;
        std::cout << TFd << std::endl;
    }
}

}
*/

QTEST_APPLESS_MAIN(rls)

#include "tst_rls.moc"
