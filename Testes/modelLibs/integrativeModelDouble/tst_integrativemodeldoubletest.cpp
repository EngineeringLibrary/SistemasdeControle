#include <QString>
#include <QtTest>

class IntegrativeModelDoubleTest : public QObject
{
    Q_OBJECT

public:
    IntegrativeModelDoubleTest();

private Q_SLOTS:
    void testCase1();
};

IntegrativeModelDoubleTest::IntegrativeModelDoubleTest()
{
}

void IntegrativeModelDoubleTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(IntegrativeModelDoubleTest)

#include "tst_integrativemodeldoubletest.moc"
