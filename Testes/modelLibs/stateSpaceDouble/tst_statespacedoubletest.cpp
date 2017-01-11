#include <QString>
#include <QtTest>
#define testPolynom
#define testModel
#include "../../../headers/primitiveLibs/LinAlg/matrix.h"
#include "../../../headers/primitiveLibs/polynom.h"
#include "../../../headers/modelLibs/transferfunction.h"
#include "../../../headers/modelLibs/arx.h"
#include "../../../headers/modelLibs/conversions.h"

class StateSpaceDoubleTest : public QObject
{
    Q_OBJECT

public:
    StateSpaceDoubleTest(){}

private Q_SLOTS:
    void SSVoidConstructorDouble ();
    void SSContinuousConstructorDouble ();
    void SSDiscreteConstructorDouble ();

//    unsigned getNumberOfVariables() const {}
//    unsigned getNumberOfInputs() const {}
//    unsigned getNumberOfOutputs() const {}
//    StateSpace<Type>& operator= (const StateSpace<Type>& otherStateSpaceFunction); //ok
//    void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
//    void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
//    void SetObserverParameter(LinAlg::Matrix<Type> L);//ok
//    LinAlg::Matrix<Type> Observer(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y);
//    LinAlg::Matrix<Type> KalmanFilterObserver(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y);

    void getSampleTime();
    void getA();
    void getB();
    void getC();
    void getD();
    void getActualState();
    void setA();
    void setB();
    void setC();
    void setD();
    void setContinuous();
    void setSampleTime();
    void setInitialState();
    void isContinuous();
    void isObservableCase1();
    void isObservableCase2();
    void isControlableCase1();
    void isControlableCase2();

//    Type sim(Type u); //ok
//    Type sim(Type u, Type y); // não é usado
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u); //ok
//    LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step); //ok
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y); // não é usado

//    void c2dConversion(); //ok
//    void d2cConversion();
//    std::string print(); //ok
};

void StateSpaceDoubleTest::SSVoidConstructorDouble ()
{
    ModelHandler::StateSpace<double> A;
    QBENCHMARK {
        ModelHandler::StateSpace<double> A;
    }
    QVERIFY2(A.getTimeSimulation() == 10, "Falhou ao comparar o tempo de simulacao.");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::StateSpace<double>), "Falhou ao comparar o tipo da equacao de estados");
}

void StateSpaceDoubleTest::SSContinuousConstructorDouble()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        ModelHandler::StateSpace<double> SS(A,B,C,D);
    }
    QVERIFY2(SS.getTimeSimulation() == 10, "Falhou ao comparar o tempo de simulacao.");
    QVERIFY2(SS.isContinuous() && SS.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(SS.getA()(1,1) == 0 && SS.getA()(1,2) == 1 && SS.getA()(2,1) == -1 && SS.getA()(2,2) == -2 , "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2((SS.getB()(1,1) == 0) & (SS.getB()(2,1) == 1), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2((SS.getC()(1,1) == 1) & (SS.getC()(1,2) == 0), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2(SS.getD()(1,1) == 0, "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2(SS.getActualState()(1,1) == 0 && SS.getActualState()(2,1) == 0, "Falhou ao verificar a matriz de estados");
    QVERIFY2(sizeof(SS) == sizeof(ModelHandler::StateSpace<double>), "Falhou ao comparar o tipo da equacao de estados");
}

void StateSpaceDoubleTest::SSDiscreteConstructorDouble()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D,0.2);
    QBENCHMARK {
        ModelHandler::StateSpace<double> SS(A,B,C,D,0.2);
    }
    QVERIFY2(SS.getTimeSimulation() == 10, "Falhou ao comparar o tempo de simulacao.");
    QVERIFY2(!SS.isContinuous() && SS.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(SS.getA()(1,1) == 0 && SS.getA()(1,2) == 1 && SS.getA()(2,1) == -1 && SS.getA()(2,2) == -2 , "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2((SS.getB()(1,1) == 0) & (SS.getB()(2,1) == 1), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2((SS.getC()(1,1) == 1) & (SS.getC()(1,2) == 0), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2(SS.getD()(1,1) == 0, "Falhou ao verificar as matrizes dos sistema em espaco de estados");
    QVERIFY2(SS.getActualState()(1,1) == 0 && SS.getActualState()(2,1) == 0, "Falhou ao verificar a matriz de estados");
    QVERIFY2(sizeof(SS) == sizeof(ModelHandler::StateSpace<double>), "Falhou ao comparar o tipo da equacao de estados");
}

void StateSpaceDoubleTest::getSampleTime()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D,0.2);
    QBENCHMARK {
        SS.getSampleTime();
    }
    QVERIFY2(!SS.isContinuous() && SS.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
}

void StateSpaceDoubleTest::getA()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.getA();
    }
    QVERIFY2(SS.getA()(1,1) == 0 && SS.getA()(1,2) == 1 && SS.getA()(2,1) == -1 && SS.getA()(2,2) == -2 , "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::getB()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.getB();
    }
    QVERIFY2((SS.getB()(1,1) == 0) & (SS.getB()(2,1) == 1), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::getC()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.getC();
    }
    QVERIFY2((SS.getC()(1,1) == 1) & (SS.getC()(1,2) == 0), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::getD()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.getC();
    }
    QVERIFY2(SS.getD()(1,1) == 0, "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::getActualState()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.getActualState();
    }
    QVERIFY2(SS.getActualState()(1,1) == 0 && SS.getActualState()(2,1) == 0, "Falhou ao verificar a matriz de estados");
}

void StateSpaceDoubleTest::setA()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setA("1,2;-2,-3");
    }
    QVERIFY2(SS.getA()(1,1) == 1 && SS.getA()(1,2) == 2 && SS.getA()(2,1) == -2 && SS.getA()(2,2) == -3 , "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::setB()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setB("1;0");
    }
    QVERIFY2((SS.getB()(1,1) == 1) & (SS.getB()(2,1) == 0), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::setC()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setC("0,1");
    }
    QVERIFY2((SS.getC()(1,1) == 0) & (SS.getC()(1,2) == 1), "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::setD()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setD(1.0);
    }
    QVERIFY2(SS.getD()(1,1) == 1, "Falhou ao verificar as matrizes dos sistema em espaco de estados");
}

void StateSpaceDoubleTest::setContinuous()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setContinuous(false);
    }
    QVERIFY2(!SS.isContinuous() && SS.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
}

void StateSpaceDoubleTest::setSampleTime()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setSampleTime(0.2);
    }
    QVERIFY2(SS.isContinuous() && SS.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
}

void StateSpaceDoubleTest::setInitialState()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.setInitialState("1;2");
    }
    QVERIFY2(SS.getActualState()(1,1) == 1 && SS.getActualState()(2,1) == 2, "Falhou ao verificar a matriz de estados");
}

void StateSpaceDoubleTest::isContinuous()
{
    LinAlg::Matrix<double> A = "0,1;-1,-2", B = "0;1", C = "1,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.isContinuous();
    }
    QVERIFY2(SS.isContinuous() , "Falhou ao verificar se o sistema e continuo");
}

void StateSpaceDoubleTest::isObservableCase1()
{
    LinAlg::Matrix<double> A = "-2,0;0,-1", B = "2;1", C = "3,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.isObservable();
    }
    QVERIFY2(!SS.isObservable() , "Falhou ao verificar a observabilidade do sistema");
}

void StateSpaceDoubleTest::isObservableCase2()
{
    LinAlg::Matrix<double> A = "-2,0;0,-1", B = "2;0", C = "3,2", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.isObservable();
    }
    QVERIFY2(SS.isObservable() , "Falhou ao verificar a observabilidade do sistema");
}

void StateSpaceDoubleTest::isControlableCase1()
{
    LinAlg::Matrix<double> A = "-2,0;0,-1", B = "2;1", C = "3,0", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.isControlable();
    }
    QVERIFY2(SS.isControlable(), "Falhou ao verificar a controlabilidade do sistema");
}

void StateSpaceDoubleTest::isControlableCase2()
{
    LinAlg::Matrix<double> A = "-2,0;0,-1", B = "2;0", C = "3,2", D = 0.0;
    ModelHandler::StateSpace<double> SS(A,B,C,D);
    QBENCHMARK {
        SS.isControlable();
    }
    QVERIFY2(!SS.isControlable(), "Falhou ao verificar a controlabilidade do sistema");
}

QTEST_APPLESS_MAIN(StateSpaceDoubleTest)

#include "tst_statespacedoubletest.moc"







