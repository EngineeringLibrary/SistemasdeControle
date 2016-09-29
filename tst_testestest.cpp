#include <QString>
#include <QtTest>

class TestesTest : public QObject
{
    Q_OBJECT

public:
    TestesTest();

private Q_SLOTS:
    void testCase1();
};

TestesTest::TestesTest()
{
}

void TestesTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestesTest)

#include "tst_testestest.moc"
