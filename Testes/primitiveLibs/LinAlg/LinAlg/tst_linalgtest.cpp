#include <QString>
#include <QtTest>

#define testMatrix
#include "../../../../headers/primitiveLibs/LinAlg/linalg.h"

class LinAlgTest : public QObject
{
    Q_OBJECT

public:
    LinAlgTest(){}

private Q_SLOTS:

    void traceDouble ();
    void HessDoubleCase1 ();
    void HessDoubleCase2 ();
    void HessFormDoubleCase1 ();
    void HessFormDoubleCase2 ();
    void QR_Factorization_ModifiedGramSchmidtDouble ();
    void QR_FactorizationDouble ();
    void QRDouble ();
    void LU_FactorizationDouble ();
    void balanceDouble ();
    void eigenDouble();
    void eigenValues_LUDouble ();
    void inv_numericDouble ();
    void caracteristicPolynomDouble ();
    void multPolyDouble ();
    void absDouble ();
    void sqrtMatrixDouble ();
    void powMatrixDouble ();
    void meanDouble ();
};

void LinAlgTest::traceDouble (){
    LinAlg::Matrix<double> B = LinAlg::Ones<double>(10,10);
    double A;
    QBENCHMARK {
        A = LinAlg::trace(B);
    }
    QVERIFY2(A == 10, "Falhou ao calcular o traco da matriz com valor double");
}

void LinAlgTest::HessDoubleCase1 ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::Hess(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001      && fabs(A(1,2) - 2.8111) <= 0.001   && abs(A(1,3) - (-12.4939)) <= 0.001  &&
             fabs(A(2,1) - 6.4031) <= 0.001 && fabs(A(2,2) - 8.5854) <= 0.001   && abs(A(2,3) - (-3.2683)) <= 0.001   &&
             fabs(A(3,1)) <= 0.001          && fabs(A(3,2) - (-1.2683)) <= 0.001 && abs(A(3,3) - 1.4146) <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessDoubleCase2 ()
{
    LinAlg::Matrix<double> A, B = "1,7,7,2,9;3,1,9,0,6;3,7,9,7,6;7,5,3,5,9;1,8,7,5,8";
    QBENCHMARK {
        A = LinAlg::Hess(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 5 && A.getNumberOfRows() == 5, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1)         <= 0.001      && fabs(A(1,2) - (-7.8824)) <= 0.001   && abs(A(1,3) - (-9.5752)) <= 0.001 && fabs(A(1,4) - (5.4014))  <= 0.001   && abs(A(1,5) - (0.0890))  <= 0.001 &&
             fabs(A(2,1) - (-8.2462)) <= 0.001      && fabs(A(2,2) - (14.4265)) <= 0.001   && abs(A(2,3) - (12.3793)) <= 0.001 && fabs(A(2,4) - (-4.7446)) <= 0.001   && abs(A(2,5) - (-2.0256)) <= 0.001 &&
             fabs(A(3,1) - 0)         <= 0.001      && fabs(A(3,2) - (12.1997)) <= 0.001   && abs(A(3,3) - ( 7.0241)) <= 0.001 && fabs(A(3,4) - (-4.2974)) <= 0.001   && abs(A(3,5) - (2.1237))  <= 0.001 &&
             fabs(A(4,1) - 0)         <= 0.001      && fabs(A(4,2) - (0))       <= 0.001   && abs(A(4,3) - (-6.3114)) <= 0.001 && fabs(A(4,4) - (-1.3976)) <= 0.001   && abs(A(4,5) - (-2.7984)) <= 0.001 &&
             fabs(A(5,1) - 0)         <= 0.001      && fabs(A(5,2) - (0))       <= 0.001   && abs(A(5,3) - (0))       <= 0.001 && fabs(A(5,4) - ( 2.7502)) <= 0.001   && abs(A(5,5) - (2.9470))  <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessFormDoubleCase1 ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::Hessemberg_Form(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001      && fabs(A(1,2) - 2.8111) <= 0.001   && abs(A(1,3) - (-12.4939)) <= 0.001  &&
             fabs(A(2,1) - 6.4031) <= 0.001 && fabs(A(2,2) - 8.5854) <= 0.001   && abs(A(2,3) - (-3.2683)) <= 0.001   &&
             fabs(A(3,1)) <= 0.001          && fabs(A(3,2) - (-1.2683)) <= 0.001 && abs(A(3,3) - 1.4146) <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::HessFormDoubleCase2 ()
{
    LinAlg::Matrix<double> A, B = "1,7,7,2,9;3,1,9,0,6;3,7,9,7,6;7,5,3,5,9;1,8,7,5,8";
    QBENCHMARK {
        A = LinAlg::Hessemberg_Form(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 5 && A.getNumberOfRows() == 5, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1)         <= 0.001      && fabs(A(1,2) - (-7.8824)) <= 0.001   && abs(A(1,3) - (-9.5752)) <= 0.001 && fabs(A(1,4) - (5.4014))  <= 0.001   && abs(A(1,5) - (0.0890))  <= 0.001 &&
             fabs(A(2,1) - (-8.2462)) <= 0.001      && fabs(A(2,2) - (14.4265)) <= 0.001   && abs(A(2,3) - (12.3793)) <= 0.001 && fabs(A(2,4) - (-4.7446)) <= 0.001   && abs(A(2,5) - (-2.0256)) <= 0.001 &&
             fabs(A(3,1) - 0)         <= 0.001      && fabs(A(3,2) - (12.1997)) <= 0.001   && abs(A(3,3) - ( 7.0241)) <= 0.001 && fabs(A(3,4) - (-4.2974)) <= 0.001   && abs(A(3,5) - (2.1237))  <= 0.001 &&
             fabs(A(4,1) - 0)         <= 0.001      && fabs(A(4,2) - (0))       <= 0.001   && abs(A(4,3) - (-6.3114)) <= 0.001 && fabs(A(4,4) - (-1.3976)) <= 0.001   && abs(A(4,5) - (-2.7984)) <= 0.001 &&
             fabs(A(5,1) - 0)         <= 0.001      && fabs(A(5,2) - (0))       <= 0.001   && abs(A(5,3) - (0))       <= 0.001 && fabs(A(5,4) - ( 2.7502)) <= 0.001   && abs(A(5,5) - (2.9470))  <= 0.001,
    "Falhou ao verificar a forma de hessemberg");
}

void LinAlgTest::QR_Factorization_ModifiedGramSchmidtDouble (){
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR_Factorization_ModifiedGramSchmidt(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}
void LinAlgTest::QR_FactorizationDouble ()
{
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR_Factorization(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}
void LinAlgTest::QRDouble ()
{
    LinAlg::Matrix<double> Q, R, B = "5,7,5;5,0,1;1,1,8";
    QBENCHMARK {
        *(Q,R) = LinAlg::QR(B);
    }
    QVERIFY2(Q.getNumberOfColumns() == 3 && Q.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(Q(1,1) - 0.7001) <= 0.001 && fabs(Q(1,2) - (0.6999))  <= 0.001 && fabs(Q(1,3) - (-0.1412)) <= 0.001 &&
             fabs(Q(2,1) - 0.7001) <= 0.001 && fabs(Q(2,2) - (-0.7118)) <= 0.001 && fabs(Q(2,3) - (-0.0565)) <= 0.001 &&
             fabs(Q(3,1) - 0.1400) <= 0.001 && fabs(Q(3,2) - (0.0593))  <= 0.001 && fabs(Q(3,3) - (0.9884))  <= 0.001,
    "Falhou ao verificar o Q da Fatoração QR");

    QVERIFY2(R.getNumberOfColumns() == 3 && R.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(R(1,1) - 7.141) <= 0.01 && fabs(R(1,2) - 5.041) <= 0.01 && fabs(R(1,3) - 5.321) <= 0.01 &&
             fabs(R(2,1) - 0)     <= 0.01 && fabs(R(2,2) - 4.959) <= 0.01 && fabs(R(2,3) - 3.262) <= 0.01 &&
             fabs(R(3,1) - 0)     <= 0.01 && fabs(R(3,2) - 0)     <= 0.01 && fabs(R(3,3) - 7.144) <= 0.01,
    "Falhou ao verificar o R da Fatoração QR");
}

void LinAlgTest::LU_FactorizationDouble ()
{

}

void LinAlgTest::caracteristicPolynomDouble ()
{
    LinAlg::Matrix<double> A, B = "1, 8, -10; -4, 2, 4; -5, 2, 8";
    QBENCHMARK {
        A = LinAlg::characteristicPolynom(B);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(fabs(A(1,1) - 1) <= 0.001 && fabs(A(1,2) - (-11)) <= 0.001 && fabs(A(1,3)) <= 0.001 && fabs(A(1,4) - (-84)) <= 0.001,
             "Falhou ao verificar os coeficientes do polinomio caracteristico");
}


void LinAlgTest::inv_numericDouble (){}
void LinAlgTest::balanceDouble (){}
void LinAlgTest::eigenDouble(){}
void LinAlgTest::eigenValues_LUDouble (){}
void LinAlgTest::multPolyDouble (){}
void LinAlgTest::absDouble (){}
void LinAlgTest::sqrtMatrixDouble (){}
void LinAlgTest::powMatrixDouble (){}
void LinAlgTest::meanDouble (){}

QTEST_APPLESS_MAIN(LinAlgTest)

#include "tst_linalgtest.moc"
