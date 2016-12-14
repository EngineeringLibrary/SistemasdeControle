#include <QString>
#include <QtTest>

class StateSpaceDoubleTest : public QObject
{
    Q_OBJECT

public:
    StateSpaceDoubleTest();

private Q_SLOTS:
    void testCase1();
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
