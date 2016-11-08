#include <QString>
#include <QtTest>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
//#include "Teste/SistemasdeControle/primitiveLibs/LinAlg/test_construtor_matrix.h"


class TestesTest : public QObject
{
    Q_OBJECT

public:
    TestesTest();

private Q_SLOTS:

    void construtorMatrixTypeShort()
    {
        QBENCHMARK {
            LinAlg::Matrix<short> A(1);
        }
        LinAlg::Matrix<short> A(1);
        QVERIFY2(A(1,1) == 2, "Falhou ao comparar o elemento da matriz com valor short");
        QVERIFY2(sizeof(A(1,1)) == sizeof(short), "Falhou ao comparar o tipo do elemento da matriz com valor short");
    }

    void construtorMatrixTypeInt()
    {
        QBENCHMARK {
            LinAlg::Matrix<int> A(1);
        }
        LinAlg::Matrix<int> A(1);
        QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor inteiro");
        QVERIFY2(sizeof(A(1,1)) == sizeof(int), "Falhou ao comparar o tipo do elemento da matriz com valor inteiro");
    }

    void construtorMatrixTypeDouble()
    {
        QBENCHMARK {
            LinAlg::Matrix<double> A(1.1);
        }
        LinAlg::Matrix<double> A(1.1);
        QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor double");
        QVERIFY2(sizeof(A(1,1)) == sizeof(double), "Falhou ao comparar o tipo do elemento da matriz com valor double");
    }
};

TestesTest::TestesTest()
{
}



QTEST_APPLESS_MAIN(TestesTest)

#include "tst_testestest.moc"
