#define testPolynom
#define testModel

#include <QString>
#include <QtTest>
#include "../../../headers/modelLibs/model.h"
#include "../../../headers/modelLibs/arx.h"
#include "../../../headers/modelLibs/transferfunction.h"
#include "../../../headers/modelLibs/conversions.h"
#include "../../../headers/optimizationLibs/leastsquare.h"

class ArxDoubleTest : public QObject
{
    Q_OBJECT

public:
    ArxDoubleTest(){}

private Q_SLOTS:
    void voidConstructorCase1 ();
    void voidConstructorCase2 ();
    void voidConstructorCase3 ();
    void voidConstructorCase4 ();
    void voidConstructorCase5 ();
    void voidConstructorCase6 ();

    void copyConstructor ();
    void copyConstructorOtherType ();
    void copyAssignment ();
    void copyAssignmentOtherType ();

    void stringConversionCase1();
    void stringConversionCase2();
    void stringConversionCase3();
    void stringConversionCase4();
    void stringConversionCase5();
    void stringConversionCase6();
    void stringConversionCase7();
    void stringConversionCase8();
    void stringConversionCase9();
    void stringConversionCase10();
    void stringConversionCase11();
    void stringConversionCase12();
    void stringConversionCase13();
    void stringConversionCase14();
    void stringConversionCase15();

    void getNumberOfInputDelays();
    void getNumberOfInputs();
    void getNumberOfOutputDelays();
    void getNumberOfOutputs();
    void getNumberOfVariables();
    void getMaxnInOut ();
    void getNSample ();

//    Type getSingleInput() const { return this->input;}
//    Type getSingleOutput() const { return this->output;}
//    Type getSingleEstOutput() const { return this->estOutput;}
//    Type getLmin() const { return this->lmin;}
//    Type getLmax() const { return this->lmax;}
//    Type getStep() const { return this->step;}
//    Type getTimeSimulation() const { return this->timeSimulation;}
//    Type getTransportDelay() const { return this->delay;}

//    LinAlg::Matrix<Type> getInput() const { return this->Input;}
//    LinAlg::Matrix<Type> getOutput() const { return this->Output;}
//    LinAlg::Matrix<Type> getEstOutput() const { return this->EstOutput;}
//    LinAlg::Matrix<Type> getModelCoef() const { return this->ModelCoef;}

//    LinAlg::Matrix<Type> getLinearEqualityVectorB() const { return this->LinearEqualityVectorB;}
//    LinAlg::Matrix<Type> getLinearMatrixA() const { return this->LinearMatrixA;}
//    LinAlg::Matrix<Type> getLinearVectorA() const { return this->LinearVectorA;}
//    LinAlg::Matrix<Type> getLinearEqualityB() const { return this->LinearEqualityB;}
//    LinAlg::Matrix<Type> getInputLinearVector() const { return this->InputLinearVector;}
//    LinAlg::Matrix<Type> getOutputLinearVector() const { return this->OutputLinearVector;}

//    void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> PastOutput);
//    void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);

//    Type sim(Type input);
//    Type sim(Type input, Type output);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
//    LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

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
    QVERIFY2(arx.getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(arx.getNumberOfVariables() == 2, "Falha ao testar o numero de variaveis do modelo arx");
    QVERIFY2(arx.getStep() == 0.1, "Falha ao testar o periodo de amostragem do modelo arx");
    QVERIFY2(arx.getModelCoef()(1,1) == 0 && arx.getModelCoef()(2,1) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(arx.getInputMatrix()(1,1) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(arx.getOutputMatrix()(1,1) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(arx.getSingleOutput() == 0, "Falha ao testar as saidas do modelo arx");
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
    QVERIFY2(M->getSingleOutput() == 0, "Falha ao testar as saidas do modelo arx");
}

void ArxDoubleTest::voidConstructorCase3()
{
    ModelHandler::ARX<double> arx(2,2);

    QBENCHMARK {
        ModelHandler::ARX<double> arx(2,2);
    }

    QVERIFY2(arx.getNumberOfInputs()    == 1, "Falha ao testar o numero de entradas do modelo arx");
    QVERIFY2(arx.getNumberOfOutputs()   == 1, "Falha ao testar o numero de saidas do modelo arx");
    QVERIFY2(arx.getNumberOfVariables() == 4, "Falha ao testar o numero de variaveis do modelo arx");
    QVERIFY2(arx.getStep() == 0.1, "Falha ao testar o periodo de amostragem do modelo arx");
    QVERIFY2(arx.getModelCoef()(1,1) == 0 && arx.getModelCoef()(2,1) == 0 &&
             arx.getModelCoef()(3,1) == 0 && arx.getModelCoef()(4,1) == 0, "Falha ao testar os parametros do modelo arx");
    QVERIFY2(arx.getInputMatrix()(1,1) == 0 && arx.getInputMatrix()(1,2) == 0, "Falha ao testar as entradas do modelo arx");
    QVERIFY2(arx.getOutputMatrix()(1,1) == 0 && arx.getOutputMatrix()(1,2) == 0, "Falha ao testar as saidas do modelo arx");
    QVERIFY2(arx.getSingleOutput() == 0, "Falha ao testar as saidas do modelo arx");
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
    QVERIFY2(M->getSingleOutput() == 0, "Falha ao testar as saidas do modelo arx");
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
    QVERIFY2(M->getSingleOutput() == 0, "Falha ao testar as saidas do modelo arx");
}

void ArxDoubleTest::copyConstructor ()
{
    ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
    ModelHandler::ARX<double> arx(arx2);

    QBENCHMARK {
        ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
        ModelHandler::ARX<double> arx(arx2);
    }

    QVERIFY2(arx.getNumberOfInputDelays() == arx2.getNumberOfInputDelays(), "O numero de atrasos nas entradas e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfInputs() == arx2.getNumberOfInputs(), "O numero de variaveis de entrada e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfOutputDelays() == arx2.getNumberOfOutputDelays(), "O numero de atrasos nas saidas e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfOutputs() == arx2.getNumberOfOutputs(), "O numero de variaveis de saida e diferente na copia do construtor");
    QVERIFY2(arx.getMaxnInOut () == arx2.getMaxnInOut(), "O numero de maximo de atrasos e diferente na copia do construtor");
    QVERIFY2(arx.getNSample () == arx2.getNSample(), "O numero de amostras e diferente na copia do construtor");

    QVERIFY2(arx.getSingleInput() == arx2.getSingleInput(), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(arx.getSingleOutput() == arx2.getSingleOutput(), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(arx.getSingleEstOutput() == arx2.getSingleEstOutput(), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(arx.getLmin() == arx2.getLmin(), "O valor do limite minimo e diferente na copia do construtor");
    QVERIFY2(arx.getLmax() == arx2.getLmax(), "O valor do limite maximo e diferente na copia do construtor");
    QVERIFY2(arx.getStep() == arx2.getStep(), "O valor do passo de simulacao e diferente na copia do construtor");
    QVERIFY2(arx.getTimeSimulation() == arx2.getTimeSimulation(), "O tempo de simulacao e diferente na copia do construtor");
    QVERIFY2(arx.getTransportDelay() == arx2.getTransportDelay(), "O valor dos atrasos de transporte e diferente na copia do construtor");

    QVERIFY2(LinAlg::isEqual(arx.getInputMatrix(),arx2.getInputMatrix()), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputMatrix(),arx2.getOutputMatrix()), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getEstOutputMatrix(),arx2.getEstOutputMatrix()), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getModelCoef(),arx2.getModelCoef()), "O valor dos coeficientes do modelo e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityVectorB(),arx2.getLinearEqualityVectorB()), "O valor dos elementos de B no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearMatrixA(),arx2.getLinearMatrixA()), "O valor dos elementos de A na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearVectorA(),arx2.getLinearVectorA()), "O valor dos elementos de A no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityB(),arx2.getLinearEqualityB()), "O valor dos elementos de B na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getInputLinearVector(),arx2.getInputLinearVector()), "O vetor de estados da entrada e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputLinearVector(),arx2.getOutputLinearVector()), "O vetor de estados da saida e diferente na copia do construtor");
}

void ArxDoubleTest::copyConstructorOtherType ()
{
    ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
    ModelHandler::ARX<long double> arx(arx2);

    QBENCHMARK {
        ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
        ModelHandler::ARX<long double> arx(arx2);
    }

    QVERIFY2(fabs(arx.getNumberOfInputDelays() - arx2.getNumberOfInputDelays()) < 1e-30, "O numero de atrasos nas entradas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfInputs() - arx2.getNumberOfInputs()) < 1e-30, "O numero de variaveis de entrada e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfOutputDelays() - arx2.getNumberOfOutputDelays()) < 1e-30, "O numero de atrasos nas saidas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfOutputs() - arx2.getNumberOfOutputs()) < 1e-30, "O numero de variaveis de saida e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getMaxnInOut() - arx2.getMaxnInOut()) < 1e-30, "O numero de maximo de atrasos e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNSample() - arx2.getNSample()) < 1e-30, "O numero de amostras e diferente na copia do construtor");

    QVERIFY2(fabs(arx.getSingleInput() - arx2.getSingleInput()) < 1e-30, "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getSingleOutput() - arx2.getSingleOutput()) < 1e-30, "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getSingleEstOutput() - arx2.getSingleEstOutput()) < 1e-30, "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getLmin() - arx2.getLmin()) < 1e-30, "O valor do limite minimo e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getLmax() - arx2.getLmax()) < 1e-30, "O valor do limite maximo e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getStep() - arx2.getStep()) < 1e-30, "O valor do passo de simulacao e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getTimeSimulation() - arx2.getTimeSimulation()) < 1e-30, "O tempo de simulacao e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getTransportDelay() - arx2.getTransportDelay()) < 1e-30, "O valor dos atrasos de transporte e diferente na copia do construtor");

    QVERIFY2(LinAlg::isEqual(arx.getInputMatrix(),arx2.getInputMatrix()), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputMatrix(),arx2.getOutputMatrix()), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getEstOutputMatrix(),arx2.getEstOutputMatrix()), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getModelCoef(),arx2.getModelCoef()), "O valor dos coeficientes do modelo e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityVectorB(),arx2.getLinearEqualityVectorB()), "O valor dos elementos de B no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearMatrixA(),arx2.getLinearMatrixA()), "O valor dos elementos de A na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearVectorA(),arx2.getLinearVectorA()), "O valor dos elementos de A no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityB(),arx2.getLinearEqualityB()), "O valor dos elementos de B na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getInputLinearVector(),arx2.getInputLinearVector()), "O vetor de estados da entrada e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputLinearVector(),arx2.getOutputLinearVector()), "O vetor de estados da saida e diferente na copia do construtor");
}

void ArxDoubleTest::copyAssignment ()
{
    ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
    ModelHandler::ARX<double> arx = arx2;

    QBENCHMARK {
        ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
        ModelHandler::ARX<double> arx = arx2;
    }

    QVERIFY2(arx.getNumberOfInputDelays() == arx2.getNumberOfInputDelays(), "O numero de atrasos nas entradas e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfInputs() == arx2.getNumberOfInputs(), "O numero de variaveis de entrada e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfOutputDelays() == arx2.getNumberOfOutputDelays(), "O numero de atrasos nas saidas e diferente na copia do construtor");
    QVERIFY2(arx.getNumberOfOutputs() == arx2.getNumberOfOutputs(), "O numero de variaveis de saida e diferente na copia do construtor");
    QVERIFY2(arx.getMaxnInOut () == arx2.getMaxnInOut(), "O numero de maximo de atrasos e diferente na copia do construtor");
    QVERIFY2(arx.getNSample () == arx2.getNSample(), "O numero de amostras e diferente na copia do construtor");

    QVERIFY2(arx.getSingleInput() == arx2.getSingleInput(), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(arx.getSingleOutput() == arx2.getSingleOutput(), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(arx.getSingleEstOutput() == arx2.getSingleEstOutput(), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(arx.getLmin() == arx2.getLmin(), "O valor do limite minimo e diferente na copia do construtor");
    QVERIFY2(arx.getLmax() == arx2.getLmax(), "O valor do limite maximo e diferente na copia do construtor");
    QVERIFY2(arx.getStep() == arx2.getStep(), "O valor do passo de simulacao e diferente na copia do construtor");
    QVERIFY2(arx.getTimeSimulation() == arx2.getTimeSimulation(), "O tempo de simulacao e diferente na copia do construtor");
    QVERIFY2(arx.getTransportDelay() == arx2.getTransportDelay(), "O valor dos atrasos de transporte e diferente na copia do construtor");

    QVERIFY2(LinAlg::isEqual(arx.getInputMatrix(),arx2.getInputMatrix()), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputMatrix(),arx2.getOutputMatrix()), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getEstOutputMatrix(),arx2.getEstOutputMatrix()), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getModelCoef(),arx2.getModelCoef()), "O valor dos coeficientes do modelo e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityVectorB(),arx2.getLinearEqualityVectorB()), "O valor dos elementos de B no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearMatrixA(),arx2.getLinearMatrixA()), "O valor dos elementos de A na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearVectorA(),arx2.getLinearVectorA()), "O valor dos elementos de A no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityB(),arx2.getLinearEqualityB()), "O valor dos elementos de B na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getInputLinearVector(),arx2.getInputLinearVector()), "O vetor de estados da entrada e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputLinearVector(),arx2.getOutputLinearVector()), "O vetor de estados da saida e diferente na copia do construtor");
}

void ArxDoubleTest::copyAssignmentOtherType ()
{
    ModelHandler::ARX<double> arx2(2,2,0,2,2,0.1);
    ModelHandler::ARX<long double> arx(1,1);
    QBENCHMARK {
        arx = arx2;
    }

    QVERIFY2(fabs(arx.getNumberOfInputDelays() - arx2.getNumberOfInputDelays()) < 1e-20, "O numero de atrasos nas entradas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfInputs() - arx2.getNumberOfInputs()) < 1e-20, "O numero de variaveis de entrada e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfOutputDelays() - arx2.getNumberOfOutputDelays()) < 1e-20, "O numero de atrasos nas saidas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNumberOfOutputs() - arx2.getNumberOfOutputs()) < 1e-20, "O numero de variaveis de saida e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getMaxnInOut() - arx2.getMaxnInOut()) < 1e-20, "O numero de maximo de atrasos e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getNSample() - arx2.getNSample()) < 1e-20, "O numero de amostras e diferente na copia do construtor");

    QVERIFY2(fabs(arx.getSingleInput() - arx2.getSingleInput()) < 1e-20, "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getSingleOutput() - arx2.getSingleOutput()) < 1e-20, "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getSingleEstOutput() - arx2.getSingleEstOutput()) < 1e-20, "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getLmin() - arx2.getLmin()) < 1e-20, "O valor do limite minimo e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getLmax() - arx2.getLmax()) < 1e-20, "O valor do limite maximo e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getStep() - arx2.getStep()) < 1e-20, "O valor do passo de simulacao e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getTimeSimulation() - arx2.getTimeSimulation()) < 1e-20, "O tempo de simulacao e diferente na copia do construtor");
    QVERIFY2(fabs(arx.getTransportDelay() - arx2.getTransportDelay()) < 1e-20, "O valor dos atrasos de transporte e diferente na copia do construtor");

    QVERIFY2(LinAlg::isEqual(arx.getInputMatrix(),arx2.getInputMatrix()), "O valor das entradas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputMatrix(),arx2.getOutputMatrix()), "O valor das saidas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getEstOutputMatrix(),arx2.getEstOutputMatrix()), "O valor das saidas estimadas e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getModelCoef(),arx2.getModelCoef()), "O valor dos coeficientes do modelo e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityVectorB(),arx2.getLinearEqualityVectorB()), "O valor dos elementos de B no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearMatrixA(),arx2.getLinearMatrixA()), "O valor dos elementos de A na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearVectorA(),arx2.getLinearVectorA()), "O valor dos elementos de A no vetor do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getLinearEqualityB(),arx2.getLinearEqualityB()), "O valor dos elementos de B na Matrix do sistema linear e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getInputLinearVector(),arx2.getInputLinearVector()), "O vetor de estados da entrada e diferente na copia do construtor");
    QVERIFY2(LinAlg::isEqual(arx.getOutputLinearVector(),arx2.getOutputLinearVector()), "O vetor de estados da saida e diferente na copia do construtor");
}

void ArxDoubleTest::stringConversionCase1()
{
    ModelHandler::TransferFunction<double> TF("20","1,2,1");
    ModelHandler::ARX<double> arx = ModelHandler::tf2arxSISO(TF,0.1);

    QBENCHMARK {
        arx.print();
    }

    QVERIFY2( arx.print() == " y1( k ) = 1.80967 y1( k - 1 )  - 0.818731 y1( k - 2 )  + 0.0935768 u1( k - 1 )  + 0.0875415 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase2()
{
    ModelHandler::ARX<double> arx(2,2,0,2,1,0.1);
    arx.setModelCoef("-1.810;0.819;0.094;0.088;0.094;0.088");

    QBENCHMARK {
        arx.print();
    }

    QVERIFY2( arx.print() == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase3()
{
    ModelHandler::ARX<double> arx(2,2,0,1,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0.094;0.088,0.094");

    QBENCHMARK {
        arx.print();
    }

    QVERIFY2( arx.print() == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.094 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase4()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0;0.088,0;0,0.094;0,0.088");

    QBENCHMARK {
        arx.print();
    }

    QVERIFY2( arx.print() == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase5()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,-1.908;0.819,0.741;-1.952,-1.810;0.881,0.819;0.094,0.045;0.088,0.43;0.038,0.094;0.049,0.088");

    QBENCHMARK {
        arx.print();
    }

    QVERIFY2( arx.print() == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 1.952 y2( k - 1 )  - 0.881 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.038 u2( k - 1 )  + 0.049 u2( k - 2 ) \n y2( k ) = 1.908 y1( k - 1 )  - 0.741 y1( k - 2 )  + 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.045 u1( k - 1 )  + 0.43 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase6()
{
    ModelHandler::TransferFunction<double> TF("20","1,2,1");
    ModelHandler::ARX<double> arx = ModelHandler::tf2arxSISO(TF,0.1);
    std::string str = arx;
    QBENCHMARK {
        std::string str = arx;
    }

    QVERIFY2( str == " y1( k ) = 1.80967 y1( k - 1 )  - 0.818731 y1( k - 2 )  + 0.0935768 u1( k - 1 )  + 0.0875415 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase7()
{
    ModelHandler::ARX<double> arx(2,2,0,2,1,0.1);
    arx.setModelCoef("-1.810;0.819;0.094;0.088;0.094;0.088");
    std::string str = arx;
    QBENCHMARK {
        std::string str = arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase8()
{
    ModelHandler::ARX<double> arx(2,2,0,1,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0.094;0.088,0.094");
    std::string str = arx;
    QBENCHMARK {
        std::string str = arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.094 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase9()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0;0.088,0;0,0.094;0,0.088");
    std::string str = arx;
    QBENCHMARK {
        std::string str = arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase10()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,-1.908;0.819,0.741;-1.952,-1.810;0.881,0.819;0.094,0.045;0.088,0.43;0.038,0.094;0.049,0.088");
    std::string str = arx;
    QBENCHMARK {
        std::string str = arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 1.952 y2( k - 1 )  - 0.881 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.038 u2( k - 1 )  + 0.049 u2( k - 2 ) \n y2( k ) = 1.908 y1( k - 1 )  - 0.741 y1( k - 2 )  + 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.045 u1( k - 1 )  + 0.43 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase11()
{
    ModelHandler::TransferFunction<double> TF("20","1,2,1");
    ModelHandler::ARX<double> arx = ModelHandler::tf2arxSISO(TF,0.1);
    std::string str;
    str << arx;
    QBENCHMARK {
        std::string str;
        str << arx;
    }

    QVERIFY2( str == " y1( k ) = 1.80967 y1( k - 1 )  - 0.818731 y1( k - 2 )  + 0.0935768 u1( k - 1 )  + 0.0875415 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase12()
{
    ModelHandler::ARX<double> arx(2,2,0,2,1,0.1);
    arx.setModelCoef("-1.810;0.819;0.094;0.088;0.094;0.088");
    std::string str;
    str << arx;
    QBENCHMARK {
        std::string str;
        str << arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase13()
{
    ModelHandler::ARX<double> arx(2,2,0,1,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0.094;0.088,0.094");
    std::string str;
    str << arx;
    QBENCHMARK {
        std::string str;
        str << arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.094 u1( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase14()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,0;0.819,0;0,-1.810;0,0.819;0.094,0;0.088,0;0,0.094;0,0.088");
    std::string str;
    str << arx;
    QBENCHMARK {
        std::string str;
        str << arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 ) \n y2( k ) = 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::stringConversionCase15()
{
    ModelHandler::ARX<double> arx(2,2,0,2,2,0.1);
    arx.setModelCoef("-1.810,-1.908;0.819,0.741;-1.952,-1.810;0.881,0.819;0.094,0.045;0.088,0.43;0.038,0.094;0.049,0.088");
    std::string str;
    str << arx;
    QBENCHMARK {
        std::string str;
        str << arx;
    }

    QVERIFY2( str == " y1( k ) = 1.81 y1( k - 1 )  - 0.819 y1( k - 2 )  + 1.952 y2( k - 1 )  - 0.881 y2( k - 2 )  + 0.094 u1( k - 1 )  + 0.088 u1( k - 2 )  + 0.038 u2( k - 1 )  + 0.049 u2( k - 2 ) \n y2( k ) = 1.908 y1( k - 1 )  - 0.741 y1( k - 2 )  + 1.81 y2( k - 1 )  - 0.819 y2( k - 2 )  + 0.045 u1( k - 1 )  + 0.43 u1( k - 2 )  + 0.094 u2( k - 1 )  + 0.088 u2( k - 2 ) \n", "Impressao do modelo ARX realizada de forma incorreta.");
}

void ArxDoubleTest::getNumberOfInputDelays()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNumberOfInputDelays();
    }

    QVERIFY2(arx.getNumberOfInputDelays() == 1, "O numero de atrasos nas entradas e diferente na copia do construtor");
}

void ArxDoubleTest::getNumberOfInputs()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNumberOfInputs();
    }

    QVERIFY2(arx.getNumberOfInputs() == 3, "O numero de variaveis de entrada e diferente na copia do construtor");
}

void ArxDoubleTest::getNumberOfOutputDelays()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNumberOfOutputDelays();
    }

    QVERIFY2(arx.getNumberOfOutputDelays() == 2, "O numero de atrasos nas saidas e diferente na copia do construtor");
}

void ArxDoubleTest::getNumberOfOutputs()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNumberOfOutputs();
    }

    QVERIFY2(arx.getNumberOfOutputs() == 4, "O numero de variaveis de saida e diferente na copia do construtor");
}

void ArxDoubleTest::getNumberOfVariables()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNumberOfVariables();
    }

    QVERIFY2(arx.getNumberOfVariables() == 11, "O numero de variaveis e diferente na copia do construtor");
}

void ArxDoubleTest::getMaxnInOut ()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getMaxnInOut();
    }

    QVERIFY2(arx.getMaxnInOut() == 2, "O numero de maximo de atrasos e diferente na copia do construtor");
}

void ArxDoubleTest::getNSample ()
{
    ModelHandler::ARX<double> arx(1,2,0,3,4,0.1);
    QBENCHMARK {
        arx.getNSample();
    }

    QVERIFY2(arx.getNSample() == 3, "O numero de amostras e diferente na copia do construtor");
}

QTEST_APPLESS_MAIN(ArxDoubleTest)

#include "tst_arxdoubletest.moc"
