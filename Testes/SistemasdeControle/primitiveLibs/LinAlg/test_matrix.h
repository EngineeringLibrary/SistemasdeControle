#ifndef TESTMATRIXIMPLEMENTACAO_H
#define TESTMATRIXIMPLEMENTACAO_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
//#include "tst_testestest.cpp"

void TestesTest::construtorMatrixTypeChar()
{
    QBENCHMARK {
        LinAlg::Matrix<char> A('a');
    }
    LinAlg::Matrix<char> A('a');
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 'a', "Falhou ao comparar o elemento da matriz com valor char");
    QVERIFY2(sizeof(A(1,1)) == sizeof(char), "Falhou ao comparar o tipo do elemento da matriz com valor char");
}

void TestesTest::construtorMatrixTypeShort()
{
    QBENCHMARK {
        LinAlg::Matrix<short> A(1);
    }
    LinAlg::Matrix<short> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor short");
    QVERIFY2(sizeof(A(1,1)) == sizeof(short), "Falhou ao comparar o tipo do elemento da matriz com valor short");
}

void TestesTest::construtorMatrixTypeInt()
{
    QBENCHMARK {
        LinAlg::Matrix<int> A(1);
    }
    LinAlg::Matrix<int> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor inteiro");
    QVERIFY2(sizeof(A(1,1)) == sizeof(int), "Falhou ao comparar o tipo do elemento da matriz com valor inteiro");
}

void TestesTest::construtorMatrixTypeFloat()
{
    QBENCHMARK {
        LinAlg::Matrix<float> A(1.5);
    }
    LinAlg::Matrix<float> A(1.5);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.5, "Falhou ao comparar o elemento da matriz com valor float");
    QVERIFY2(sizeof(A(1,1)) == sizeof(float), "Falhou ao comparar o tipo do elemento da matriz com valor float");
}

void TestesTest::construtorMatrixTypeDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A(1.1);
    }
    LinAlg::Matrix<double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 2 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(double), "Falhou ao comparar o tipo do elemento da matriz com valor double");
}

void TestesTest::construtorMatrixTypeLongDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<long double> A(1.1);
    }
    LinAlg::Matrix<long double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor long double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(long double), "Falhou ao comparar o tipo do elemento da matriz com valor long double");
}
#endif // TESTMATRIXIMPLEMENTACAO_H
