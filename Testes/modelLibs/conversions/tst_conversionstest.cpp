#include <QString>
#include <QtTest>

class ConversionsTest : public QObject
{
    Q_OBJECT

public:
    ConversionsTest();

private Q_SLOTS:
    void testCase1();
};

ConversionsTest::ConversionsTest()
{
}

void ConversionsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ConversionsTest)

#include "tst_conversionstest.moc"
