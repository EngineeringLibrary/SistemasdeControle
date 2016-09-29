#include <QString>
#include <QtTest>

class TesteTest : public QObject
{
    Q_OBJECT

public:
    TesteTest();

private Q_SLOTS:
    void testCase1();
};

TesteTest::TesteTest()
{
}

void TesteTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TesteTest)

#include "tst_testetest.moc"
