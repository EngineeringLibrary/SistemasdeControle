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
#include "../../../headers/controlLibs/pid.h"

class PIDTestTest : public QObject
{
    Q_OBJECT

public:
    PIDTestTest(){}

private Q_SLOTS:
    void constructorCase1();
    void constructorCase2();
    void setSampleTime();
    void setLimits();
    void setParamsCase1();
    void setParamsCase2();

    void getSampleTime();
    void getErrorValue();
    void getDerivativeErrorValue();
    void getIntegralErrorValue();
    void getLimits();
    void getParams();

    void OutputControl();
};

void PIDTestTest::constructorCase1()
{
    ControlHandler::PID<double> PID;
    QBENCHMARK {
        ControlHandler::PID<double> PID;
    }
    LinAlg::Matrix<double> pidParams = PID.getParams();
    LinAlg::Matrix<double> pidLimits = PID.getLimits();
    double step   = PID.getSampleTime();
    double error  = PID.getErrorValue();
    double ierror = PID.getIntegralErrorValue();
    double derror = PID.getDerivativeErrorValue();

    QVERIFY2(step == 0.1, "Periodo de amostragem diferente do esperado");
    QVERIFY2(error == 0.0, "Erro diferente do esperado");
    QVERIFY2(ierror == 0.0, "Erro integral diferente do esperado");
    QVERIFY2(derror == 0.0, "Erro derivativo diferente do esperado");
    QVERIFY2(LinAlg::isEqual(pidParams,LinAlg::Matrix<double>("0,0,0")), "Periodo de amostragem diferente do esperado");
    QVERIFY2(LinAlg::isEqual(pidLimits,LinAlg::Matrix<double>("-200,200")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::constructorCase2()
{
    ControlHandler::PID<double> PID("1,1,1");
    QBENCHMARK {
        ControlHandler::PID<double> PID("1,1,1");
    }
    LinAlg::Matrix<double> pidParams = PID.getParams();
    LinAlg::Matrix<double> pidLimits = PID.getLimits();
    double step   = PID.getSampleTime();
    double error  = PID.getErrorValue();
    double ierror = PID.getIntegralErrorValue();
    double derror = PID.getDerivativeErrorValue();

    QVERIFY2(step == 0.1, "Periodo de amostragem diferente do esperado");
    QVERIFY2(error == 0.0, "Erro diferente do esperado");
    QVERIFY2(ierror == 0.0, "Erro integral diferente do esperado");
    QVERIFY2(derror == 0.0, "Erro derivativo diferente do esperado");
    QVERIFY2(LinAlg::isEqual(pidParams,LinAlg::Matrix<double>("1,1,1")), "Periodo de amostragem diferente do esperado");
    QVERIFY2(LinAlg::isEqual(pidLimits,LinAlg::Matrix<double>("-200,200")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::setSampleTime()
{
    ControlHandler::PID<double> PID("1,1,1");
    QBENCHMARK {
        PID.setSampleTime(0.01);
    }

    double step   = PID.getSampleTime();
    QVERIFY2(step == 0.01, "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::setLimits()
{
    ControlHandler::PID<double> PID("1,1,1");
    QBENCHMARK {
        PID.setLimits(-100,100);
    }
    LinAlg::Matrix<double> pidLimits = PID.getLimits();

    QVERIFY2(LinAlg::isEqual(pidLimits,LinAlg::Matrix<double>("-100,100")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::setParamsCase1()
{
    ControlHandler::PID<double> PID;
    QBENCHMARK {
        PID.setParams(1,1,1);
    }
    LinAlg::Matrix<double> pidParams = PID.getParams();

    QVERIFY2(LinAlg::isEqual(pidParams,LinAlg::Matrix<double>("1,1,1")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::setParamsCase2()
{
    ControlHandler::PID<double> PID;
    QBENCHMARK {
        PID.setParams("1,1,1");
    }
    LinAlg::Matrix<double> pidParams = PID.getParams();
    QVERIFY2(LinAlg::isEqual(pidParams,LinAlg::Matrix<double>("1,1,1")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::getSampleTime()
{
    ControlHandler::PID<double> PID("1,1,1");
    PID.setSampleTime(0.01);
    QBENCHMARK {
        PID.getSampleTime();
    }

    double step   = PID.getSampleTime();
    QVERIFY2(step == 0.01, "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::getErrorValue()
{
    ControlHandler::PID<double> PID("1.3642407803804,1.53755166084361,0.0821132680725003");
    ModelHandler::TransferFunction<double> TF("1","1,1");
    double u, error, y = 0;

    for(unsigned i = 0; i < 100; ++i)
    {
        u = PID.OutputControl(1,y);
        y = TF.sim(u);
    }

    QBENCHMARK {
        error = PID.getErrorValue();
    }

    QVERIFY2(error <= 1e-4, "Erro diferente do esperado");
}

void PIDTestTest::getDerivativeErrorValue()
{
    ControlHandler::PID<double> PID("1.3642407803804,1.53755166084361,0.0821132680725003");
    ModelHandler::TransferFunction<double> TF("1","1,1");
    double u, derror, y = 0;

    for(unsigned i = 0; i < 100; ++i)
    {
        u = PID.OutputControl(1,y);
        y = TF.sim(u);
    }

    QBENCHMARK {
        derror = PID.getDerivativeErrorValue();
    }

    QVERIFY2(derror <= 1e-4, "Erro derivativo diferente do esperado");
}

void PIDTestTest::getIntegralErrorValue()
{
    ControlHandler::PID<double> PID("1.3642407803804,1.53755166084361,0.0821132680725003");
    ModelHandler::TransferFunction<double> TF("1","1,1");
    double u, ierror, y = 0;

    for(unsigned i = 0; i <= 100; ++i)
    {
        u = PID.OutputControl(1,y);
        y = TF.sim(u);
    }

    QBENCHMARK {
        ierror = PID.getIntegralErrorValue();
    }

    QVERIFY2(fabs(ierror - 0.65035) <= 1e-2, "Erro integral diferente do esperado");
}

void PIDTestTest::getLimits()
{
    ControlHandler::PID<double> PID("1,1,1");
    PID.setLimits(-100,100);
    QBENCHMARK {
        PID.getLimits();
    }

    LinAlg::Matrix<double> pidLimits = PID.getLimits();
    QVERIFY2(LinAlg::isEqual(pidLimits,LinAlg::Matrix<double>("-100,100")), "Periodo de amostragem diferente do esperado");
}

void PIDTestTest::getParams()
{
    ControlHandler::PID<double> PID("1,1,1");
    QBENCHMARK {
        PID.getParams();
    }

    LinAlg::Matrix<double> pidParams = PID.getParams();
    QVERIFY2(LinAlg::isEqual(pidParams,LinAlg::Matrix<double>("1,1,1")), "Periodo de amostragem diferente do esperado");

}

void PIDTestTest::OutputControl()
{
    ControlHandler::PID<double> PID("1.3642407803804,1.53755166084361,0.0821132680725003");
    ModelHandler::TransferFunction<double> TF("1","1,1");
    double u, y = 0;

    for(unsigned i = 0; i < 100; ++i)
    {
        u = PID.OutputControl(1,y);
        y = TF.sim(u);
    }

    QBENCHMARK {
        PID.OutputControl(1,y);
    }

    QVERIFY2(fabs(y - 1) <= 1e-4, "Erro diferente do esperado");
}

QTEST_APPLESS_MAIN(PIDTestTest)

#include "tst_pidtesttest.moc"
