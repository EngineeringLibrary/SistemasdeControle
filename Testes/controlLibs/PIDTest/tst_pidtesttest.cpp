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
    void constructor();
    void setSampleTime();
    void setLimits();
    void setParamsCase1();
    void setParamsCase2();

    void OutputControl();
};

void PIDTestTest::constructor()
{
    ControlHandler::PID<double> PID;
    QBENCHMARK {
        ControlHandler::PID<double> PID;
    }
    QVERIFY2(true, "Failure");
}

void PIDTestTest::setSampleTime()
{

    QBENCHMARK {
//        SSP = ModelHandler::predictionModel(SSI,1,2,2);
    }
    QVERIFY2(true, "Failure");
}

void PIDTestTest::setLimits()
{

}

void PIDTestTest::setParamsCase1()
{

}

void PIDTestTest::setParamsCase2()
{

}

void PIDTestTest::OutputControl()
{

}

QTEST_APPLESS_MAIN(PIDTestTest)

#include "tst_pidtesttest.moc"
