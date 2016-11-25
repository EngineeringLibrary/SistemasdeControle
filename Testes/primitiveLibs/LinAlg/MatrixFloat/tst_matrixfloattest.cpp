#include <QString>
#include <QtTest>

class MatrixFloatTest : public QObject
{
    Q_OBJECT

public:
    MatrixFloatTest();

private Q_SLOTS:
    void testCase1();
};

MatrixFloatTest::MatrixFloatTest()
{
}

void MatrixFloatTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MatrixFloatTest)

#include "tst_matrixfloattest.moc"
