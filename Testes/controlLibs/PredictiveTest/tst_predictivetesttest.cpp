#include <QString>
#include <QtTest>

#define testPolynom
#define testModel
#define testControl
#include "../../../headers/primitiveLibs/LinAlg/matrix.h"
#include "../../../headers/primitiveLibs/polynom.h"
#include "../../../headers/modelLibs/transferfunction.h"
#include "../../../headers/modelLibs/arx.h"
#include "../../../headers/modelLibs/conversions.h"
#include "../../../headers/controlLibs/modelpredictivecontrol.h"


class PredictiveTestTest : public QObject
{
    Q_OBJECT

public:
    PredictiveTestTest(){}

private Q_SLOTS:
    void ModelPredictiveControlConstructorCase1();
    void ModelPredictiveControlConstructorCase2();
    void ModelPredictiveControlConstructorCase3();

    void setLimitsCase1();
    void setLimitsCase2();
    void setReference();
    void setErrorWeight();
    void setControlWeight();
    void setInitialState();
    void setOptimizationAlgorithm2QuadProg();

    void LimitControlOutput();

    void setNewModelCase1();
    void setNewModelCase2();

    void getReference();
    void getErrorWeight();
    void getInitialState();
    void getControlWeight();
    void getControlerGain();

    void OutputControlCalcCase1();
    void OutputControlCalcCase2();
    void OutputControlCalcCase3();
    void OutputControlCalcCase4();
};

void PredictiveTestTest::ModelPredictiveControlConstructorCase1()
{
    ControlHandler::ModelPredictiveControl<double> MPC;
    QBENCHMARK {
        ControlHandler::ModelPredictiveControl<double> MPC;
    }
}

void PredictiveTestTest::ModelPredictiveControlConstructorCase2()
{
    LinAlg::Matrix<double> A(2,2), B(2,1), C(1,2), D(1,1);
    unsigned N1= 1, N2 = 2, NU = 2;
    double Q = 1, R, W = 1, L, b, J, K;
    R = 2.7; L = 0.004;
    K = 0.105; b = 9.3e-6; J = 1e-5;
    A(1,1) = -R/L; A(1,2) = -K/L;
    A(2,1) = K/L; A(2,2) = -b/J;
    B(1,1) = 1/L;
    B(2,1) = 0;
    C(1,1) = 0; C(1,2) = 1;
    D(1,1) = 0;

    ModelHandler::StateSpace<double> SS(A,B,C,D);
    ControlHandler::ModelPredictiveControl<double> MPC(SS,N1,N2,NU,Q,10,W);
    QBENCHMARK {
        ControlHandler::ModelPredictiveControl<double> MPC(SS,N1,N2,NU,Q,10,W);
    }

    QVERIFY2(LinAlg::isEqual(MPC.getControlerGain(), LinAlg::Matrix<double>("0.068,0.100;-0.014,0.107"),0.01), "Ganho do controlador errado!");
    QVERIFY2(LinAlg::isEqual(MPC.getControlWeight(), LinAlg::Matrix<double>("10.00,0;0,10.00"),0.01), "Ponderacao no sinal de controle errada!");
    QVERIFY2(LinAlg::isEqual(MPC.getErrorWeight(), LinAlg::Matrix<double>("1.000,0;0,1.000"),0.01), "Ponderacao do erro errada!");
    QVERIFY2(LinAlg::isEqual(MPC.getInitialState(), LinAlg::Matrix<double>("0;0")), "Valores dos estados errados!");
    QVERIFY2(LinAlg::isEqual(MPC.getReference(), LinAlg::Matrix<double>("1;1")), "Referencia errada!");
}

void PredictiveTestTest::ModelPredictiveControlConstructorCase3()
{
    ModelHandler::ARX<double> gz(2,2);
    gz.setModelCoef("-0.823; -0.000; 0.873; 0.012");
    ControlHandler::ModelPredictiveControl<double> MPC(gz,1,2,2,1,10,1);
    QBENCHMARK {
        ControlHandler::ModelPredictiveControl<double> MPC(gz,1,2,2,1,10,1);
    }

    QVERIFY2(LinAlg::isEqual(MPC.getControlerGain(), LinAlg::Matrix<double>("0.068,0.100;-0.014,0.107"),0.01), "Ganho do controlador errado!");
    QVERIFY2(LinAlg::isEqual(MPC.getControlWeight(), LinAlg::Matrix<double>("10.00,0;0,10.00"),0.01), "Ponderacao no sinal de controle errada!");
    QVERIFY2(LinAlg::isEqual(MPC.getErrorWeight(), LinAlg::Matrix<double>("1.000,0;0,1.000"),0.01), "Ponderacao do erro errada!");
    QVERIFY2(LinAlg::isEqual(MPC.getInitialState(), LinAlg::Matrix<double>("0;0")), "Valores dos estados errados!");
    QVERIFY2(LinAlg::isEqual(MPC.getReference(), LinAlg::Matrix<double>("1;1")), "Referencia errada!");
}

void PredictiveTestTest::setLimitsCase1()
{

}

void PredictiveTestTest::setLimitsCase2()
{

}

void PredictiveTestTest::setReference()
{

}

void PredictiveTestTest::setErrorWeight()
{

}

void PredictiveTestTest::setControlWeight()
{

}

void PredictiveTestTest::setInitialState()
{

}

void PredictiveTestTest::setOptimizationAlgorithm2QuadProg()
{

}

void PredictiveTestTest::LimitControlOutput()
{

}

void PredictiveTestTest::setNewModelCase1()
{

}

void PredictiveTestTest::setNewModelCase2()
{

}

void PredictiveTestTest::getReference()
{

}

void PredictiveTestTest::getErrorWeight()
{

}

void PredictiveTestTest::getInitialState()
{

}

void PredictiveTestTest::getControlWeight()
{

}

void PredictiveTestTest::getControlerGain()
{

}

void PredictiveTestTest::OutputControlCalcCase1()
{

}

void PredictiveTestTest::OutputControlCalcCase2()
{

}

void PredictiveTestTest::OutputControlCalcCase3()
{

}

void PredictiveTestTest::OutputControlCalcCase4()
{

}

QTEST_APPLESS_MAIN(PredictiveTestTest)

#include "tst_predictivetesttest.moc"
