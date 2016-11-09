#ifndef TST_TESTESTEST_H
#define TST_TESTESTEST_H

#include <QString>
#include <QtTest>


class TestesTest : public QObject
{
    Q_OBJECT

public:
    TestesTest(){}

private Q_SLOTS:
    void construtorMatrixTypeShort();
    void construtorMatrixTypeInt();
    void construtorMatrixTypeDouble();
};

QTEST_APPLESS_MAIN(TestesTest)

#include "tst_testestest.moc"

#endif // TST_TESTESTEST_H
