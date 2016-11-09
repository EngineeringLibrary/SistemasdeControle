#ifndef TESTMATRIX_H
#define TESTMATRIX_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
void construtorMatrixTypeShort()
{
    QBENCHMARK {
        LinAlg::Matrix<short> A(1);
    }
    LinAlg::Matrix<short> A(1);
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor short");
    QVERIFY2(sizeof(A(1,1)) == sizeof(short), "Falhou ao comparar o tipo do elemento da matriz com valor short");
}

#endif // TESTMATRIX_H
