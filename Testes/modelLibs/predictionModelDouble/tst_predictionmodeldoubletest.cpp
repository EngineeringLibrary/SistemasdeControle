#include <QString>
#include <QtTest>

class PredictionModelDoubleTest : public QObject
{
    Q_OBJECT

public:
    PredictionModelDoubleTest();

private Q_SLOTS:
    void testCase1();
};

PredictionModelDoubleTest::PredictionModelDoubleTest()
{
}

void PredictionModelDoubleTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(PredictionModelDoubleTest)

#include "tst_predictionmodeldoubletest.moc"
