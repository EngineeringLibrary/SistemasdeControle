#include <QString>
#include <QtTest>
#define testPolynom
#define testModel
#include "../../../headers/modelLibs/arx.h"

class ArxDoubleTest : public QObject
{
    Q_OBJECT

public:
    ArxDoubleTest(){}

private Q_SLOTS:
    void voidConstructorDouble();
};

void ArxDoubleTest::voidConstructorDouble()
{
    ModelHandler::ARX<double> arx(1,1);
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ArxDoubleTest)

#include "tst_arxdoubletest.moc"
