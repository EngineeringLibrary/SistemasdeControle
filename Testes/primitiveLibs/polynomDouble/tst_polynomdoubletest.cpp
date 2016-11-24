#include <QString>
#include <QtTest>
#define testMatrix
#define testPolynom
#include "../../../headers/primitiveLibs/polynom.h"

class PolynomDoubleTest : public QObject
{
    Q_OBJECT

public:
    PolynomDoubleTest(){}

private Q_SLOTS:
    void constructorPolynomEscalarDouble ();
    void constructorPolynomMatrixNumeratorDoubleCase1 ();
    void constructorPolynomMatrixNumeratorDoubleCase2 ();
    void constructorPolynomMatrixNumeratorDoubleCase3 ();
    void PolynomCopyConstructorDoubleCase1 ();
    void PolynomCopyConstructorDoubleCase2 ();
    void constructorPolynomMatrixNumeratorDenominatorDoubleCase1 ();
    void constructorPolynomMatrixNumeratorDenominatorDoubleCase2 ();
    void constructorPolynomVoidDouble ();
    void destructorPolynomDoubleCase1 ();
    void destructorPolynomDoubleCase2 ();
};

void PolynomDoubleTest::constructorPolynomEscalarDouble ()
{
    PolynomHandler::Polynom<double> A(1.5);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(1.5);
    }
    QVERIFY2(A.getNumSize() == 1 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1.5 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomMatrixNumeratorDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1,2,1");
    QBENCHMARK {
        PolynomHandler::Polynom<double> A("1,2,1");
    }
    QVERIFY2(A.getNumSize() == 3 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2 && A.getNum()(1,3) == 1 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomMatrixNumeratorDoubleCase2 ()
{
    LinAlg::Matrix<double> num = "1,2,1";
    PolynomHandler::Polynom<double> A(num);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(num);
    }
    QVERIFY2(A.getNumSize() == 3 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2 && A.getNum()(1,3) == 1 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomMatrixNumeratorDoubleCase3 ()
{
    LinAlg::Matrix<int> num = "1,2,1";
    PolynomHandler::Polynom<double> A(num);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(num);
    }
    QVERIFY2(A.getNumSize() == 3 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2 && A.getNum()(1,3) == 1 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::PolynomCopyConstructorDoubleCase1 ()
{
    PolynomHandler::Polynom<double> B("1,2,1");
    PolynomHandler::Polynom<double> A(B);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(B);
    }
    QVERIFY2(A.getNumSize() == 3 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2 && A.getNum()(1,3) == 1 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::PolynomCopyConstructorDoubleCase2 ()
{
    PolynomHandler::Polynom<int> B("1,2,1");
    PolynomHandler::Polynom<double> A(B);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(B);
    }
    QVERIFY2(A.getNumSize() == 3 && A.getDenSize() == 1, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2 && A.getNum()(1,3) == 1 && A.getDen()(1,1) == 1, "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomMatrixNumeratorDenominatorDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,2,1");
    QBENCHMARK {
        PolynomHandler::Polynom<double> A("1,1","1,2,1");
    }
    QVERIFY2(A.getNumSize() == 2 && A.getDenSize() == 3, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1 &&
             A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomMatrixNumeratorDenominatorDoubleCase2 ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";

    PolynomHandler::Polynom<double> A(num,den);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A(num,den);
    }
    QVERIFY2(A.getNumSize() == 2 && A.getDenSize() == 3, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1 &&
             A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao comparar elementos do polinomio com valor Double");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::constructorPolynomVoidDouble ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        PolynomHandler::Polynom<double> A;
    }
    QVERIFY2(A.getNumSize() == 0 && A.getDenSize() == 0, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::destructorPolynomDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A;
    A.~Polynom();
    QBENCHMARK {
        PolynomHandler::Polynom<double> A;
        A.~Polynom();
    }
    QVERIFY2(A.getNumSize() == 0 && A.getDenSize() == 0, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

void PolynomDoubleTest::destructorPolynomDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,2,1");
    A.~Polynom();
    QBENCHMARK {
        PolynomHandler::Polynom<double> A("1,1","1,2,1");
        A.~Polynom();
    }
    QVERIFY2(A.getNumSize() == 0 && A.getDenSize() == 0, "Falhou ao testar o tamanho do Polinomio");
    QVERIFY2(sizeof(A) == sizeof(PolynomHandler::Polynom<double>), "Falhou ao comparar o tipo do elemento do polinômio com valor double");
}

QTEST_APPLESS_MAIN(PolynomDoubleTest)

#include "tst_polynomdoubletest.moc"
