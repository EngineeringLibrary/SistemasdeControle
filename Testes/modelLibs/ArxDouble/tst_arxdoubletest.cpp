#include <QString>
#include <QtTest>
#define testPolynom
#define testModel
#include "../../../headers/modelLibs/model.h"
#include "../../../headers/modelLibs/arx.h"

class ArxDoubleTest : public QObject
{
    Q_OBJECT

public:
    ArxDoubleTest(){}

private Q_SLOTS:
    void voidConstructorCase1();
    void voidConstructorCase2();
    void voidConstructorCase3();
    void voidConstructorCase4();
    void voidConstructorCase5();
    void voidConstructorCase6();
};

void ArxDoubleTest::voidConstructorCase1()
{
    ModelHandler::ARX<double> arx(1,1);

    QBENCHMARK {
        ModelHandler::ARX<double> arx(1,1);
    }
    QVERIFY2(arx.getNumberOfInputDelays()  == 1, "Falha ao testar o numero de atrasos das entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputDelays() == 1, "Falha ao testar o numero de atrasos das saidas do modelo arx");
    QVERIFY2(arx.getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(arx.getNumberOfVariables() == 2, "Falha ao testar o numero de variaveis do modelo arx");
}

void ArxDoubleTest::voidConstructorCase2()
{
    ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(1,1);

    QBENCHMARK {
        ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(1,1);
    }

    QVERIFY2(M->getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(M->getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(M->getNumberOfVariables() == 2, "Falha ao testar o numero de variaveis do modelo arx");
    QVERIFY2(M->getStep() == 0.1, "Falha ao testar o periodo de amostragem do modelo arx");
    QVERIFY2(M->getModelCoef()(1,1) == 0 && M->getModelCoef()(2,1) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(M->getInputMatrix()(1,1) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(M->getOutputMatrix()(1,1) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(M->getOutput() == 0, "Falha ao testar as saidas do modelo arx");
}

void ArxDoubleTest::voidConstructorCase3()
{
    ModelHandler::ARX<double> arx(2,2);

    QBENCHMARK {
        ModelHandler::ARX<double> arx(2,2);
    }

    QVERIFY2(arx.getNumberOfInputDelays()  == 2, "Falha ao testar o numero de atrasos das entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputDelays() == 2, "Falha ao testar o numero de atrasos das saidas do modelo arx");
    QVERIFY2(arx.getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(arx.getNumberOfVariables() == 4, "Falha ao testar o numero de variaveis do modelo arx");
}

void ArxDoubleTest::voidConstructorCase4()
{
    ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(2,2);

    QBENCHMARK {
        ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(2,2);
    }

    QVERIFY2(M->getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(M->getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(M->getNumberOfVariables() == 4, "Falha ao testar o numero de variaveis do modelo arx");
    QVERIFY2(M->getStep() == 0.1, "Falha ao testar o periodo de amostragem do modelo arx");
    QVERIFY2(M->getModelCoef()(1,1) == 0 && M->getModelCoef()(2,1) == 0 &&
             M->getModelCoef()(3,1) == 0 && M->getModelCoef()(4,1) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(M->getInputMatrix()(1,1) == 0 && M->getInputMatrix()(1,2) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(M->getOutputMatrix()(1,1) == 0 && M->getOutputMatrix()(1,2) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(M->getOutput() == 0, "Falha ao testar as saidas do modelo arx");
}

void ArxDoubleTest::voidConstructorCase5()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);

    QBENCHMARK {
        ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    }

    QVERIFY2(arx.getNumberOfInputDelays()  == 2, "Falha ao testar o numero de atrasos das entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputDelays() == 2, "Falha ao testar o numero de atrasos das saidas do modelo arx");
    QVERIFY2(arx.getNumberOfInputs()    == 2, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputs()   == 2, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(arx.getNumberOfVariables() == 8, "Falha ao testar o numero de variaveis do modelo arx");
}

void ArxDoubleTest::voidConstructorCase6()
{
    ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(2,2,0,2,2,0.1);

    QBENCHMARK {
        ModelHandler::Model<double> *M = new ModelHandler::ARX<double>(2,2,0,2,2,0.1);
    }

    QVERIFY2(M->getNumberOfInputs()    == 2, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(M->getNumberOfOutputs()   == 2, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(M->getNumberOfVariables() == 8, "Falha ao testar o numero de variaveis do modelo arx");
    QVERIFY2(M->getStep() == 0.1, "Falha ao testar o periodo de amostragem do modelo arx");
    QVERIFY2(M->getModelCoef()(1,1) == 0 && M->getModelCoef()(2,1) == 0 &&
             M->getModelCoef()(3,1) == 0 && M->getModelCoef()(4,1) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(M->getModelCoef()(1,2) == 0 && M->getModelCoef()(2,2) == 0 &&
             M->getModelCoef()(3,2) == 0 && M->getModelCoef()(4,2) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(M->getInputMatrix()(1,1) == 0 && M->getInputMatrix()(1,2) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(M->getInputMatrix()(2,1) == 0 && M->getInputMatrix()(2,2) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(M->getOutputMatrix()(1,1) == 0 && M->getOutputMatrix()(1,2) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(M->getOutputMatrix()(2,1) == 0 && M->getOutputMatrix()(2,2) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(M->getOutput() == 0, "Falha ao testar as saidas do modelo arx");
}

QTEST_APPLESS_MAIN(ArxDoubleTest)

#include "tst_arxdoubletest.moc"
