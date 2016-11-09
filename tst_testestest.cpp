#include <QString>
#include <QtTest>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

class TestesTest : public QObject
{
    Q_OBJECT

public:
    TestesTest(){}

private Q_SLOTS:

    void construtorMatrixTypeInt();
    void construtorMatrixTypeChar();
    void construtorMatrixTypeShort();
    void construtorMatrixTypeFloat();
    void construtorMatrixTypeDouble();
    void construtorMatrixTypeLongDouble();
//    void construtorMatrixTypeCString();
//    void construtorMatrixTypeString();
//    void construtorSizedVoidMatrix();
};

#include "Testes/SistemasdeControle/primitiveLibs/LinAlg/test_matrix.h"

QTEST_APPLESS_MAIN(TestesTest)

#include "tst_testestest.moc"
