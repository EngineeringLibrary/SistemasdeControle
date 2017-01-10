#include <QString>
#include <QtTest>

class StateSpaceDoubleTest : public QObject
{
    Q_OBJECT

public:
    StateSpaceDoubleTest();

private Q_SLOTS:
    void testCase1();
//    StateSpace(){}
//    StateSpace(LinAlg::Matrix<Type> A , LinAlg::Matrix<Type> B,
//               LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D); //ok
//    StateSpace(LinAlg::Matrix<Type> Ad, LinAlg::Matrix<Type> Bd,
//               LinAlg::Matrix<Type> C , LinAlg::Matrix<Type> D,
//               Type SampleTime); //ok

//    StateSpace<Type>& operator= (const StateSpace<Type>& otherStateSpaceFunction); //ok

//    double getSampleTime() const; // ok
//    LinAlg::Matrix<Type> getA() const; //ok
//    LinAlg::Matrix<Type> getB() const; //ok
//    LinAlg::Matrix<Type> getC() const; //ok
//    LinAlg::Matrix<Type> getD() const; //ok
//    LinAlg::Matrix<Type> getActualState() const; //ok

//    unsigned getNumberOfVariables() const {}
//    unsigned getNumberOfInputs() const {}
//    unsigned getNumberOfOutputs() const {}

//    void setA(LinAlg::Matrix<Type> A); //ok
//    void setB(LinAlg::Matrix<Type> B); //ok
//    void setC(LinAlg::Matrix<Type> C); //ok
//    void setD(LinAlg::Matrix<Type> D); //ok
//    void setContinuous(bool Continuous); //ok
//    void setSampleTime(double SampleTime); //ok
//    void setInitialState(LinAlg::Matrix<Type> X0); //ok
//    void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
//    void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);
//    void SetObserverParameter(LinAlg::Matrix<Type> L);//ok

//    bool isContinuous()  const;
//    bool isObservable()  const;
//    bool isControlable() const;
//    LinAlg::Matrix<Type> Observer(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y);
//    LinAlg::Matrix<Type> KalmanFilterObserver(LinAlg::Matrix<Type> U, LinAlg::Matrix<Type> Y);

//    Type sim(Type u); //ok
//    Type sim(Type u, Type y); // não é usado
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u); //ok
//    LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step); //ok
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> u, LinAlg::Matrix<Type> y); // não é usado

//    void c2dConversion(); //ok
//    void d2cConversion();
//    std::string print(); //ok
};

StateSpaceDoubleTest::StateSpaceDoubleTest()
{
}

void StateSpaceDoubleTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(StateSpaceDoubleTest)

#include "tst_statespacedoubletest.moc"
