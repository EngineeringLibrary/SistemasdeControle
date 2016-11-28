#include <QString>
#include <QtTest>
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

    void getVarDoubleCase1 ();
    void getVarDoubleCase2 ();
    void getVarDoubleCase3 ();
    void getVarDoubleCase4 ();
    void changeVarDouble ();
    void getNumSizeDouble ();
    void getDenSizeDouble ();
    void getNumDouble ();
    void getDenDouble ();
    void setNumDoubleCase1 ();
    void setNumDoubleCase2 ();
    void setDenDoubleCase1 ();
    void setDenDoubleCase2 ();
    void assignOperatorDouble ();
    void copyAssignOperatorDouble ();
    void assignOperatorOtherTypeDouble ();
    void operatorSumAccumulatorScalarDoubleCase1 ();
    void operatorSumAccumulatorScalarDoubleCase2 ();
    void operatorSumAccumulatorScalarDoubleCase3 ();
    void operatorSumAccumulatorScalarDoubleCase4 ();
    void operatorSumAccumulatorScalarDoubleCase5 ();
    void operatorSumAccumulatorPolynomDoubleCase1 ();
    void operatorSumAccumulatorPolynomDoubleCase2 ();
    void operatorSubtractionAccumulatorScalarDoubleCase1 ();
    void operatorSubtractionAccumulatorScalarDoubleCase2 ();
    void operatorSubtractionAccumulatorScalarDoubleCase3 ();
    void operatorSubtractionAccumulatorScalarDoubleCase4 ();
    void operatorSubtractionAccumulatorScalarDoubleCase5 ();
    void operatorSubtractionAccumulatorPolynomDoubleCase1 ();
    void operatorSubtractionAccumulatorPolynomDoubleCase2 ();
    void operatorMultiplicationAccumulatorScalarDoubleCase1 ();
    void operatorMultiplicationAccumulatorScalarDoubleCase2 ();
    void operatorMultiplicationAccumulatorPolynomDoubleCase1 ();
    void operatorMultiplicationAccumulatorPolynomDoubleCase2 ();
    void operatorDivisionAccumulatorScalarDoubleCase1 ();
    void operatorDivisionAccumulatorScalarDoubleCase2 ();
    void operatorDivisionAccumulatorPolynomDoubleCase1 ();
    void operatorDivisionAccumulatorPolynomDoubleCase2 ();
    void operatorPotentiationAccumulatorScalarDoubleCase1 ();
    void operatorPotentiationAccumulatorScalarDoubleCase2 ();
    void operatorPotentiationAccumulatorScalarDoubleCase3 ();
    void operatorPotentiationAccumulatorScalarDoubleCase4 ();

//    template<typename PolynomType>
//    PolynomHandler::Polynom<PolynomType> operator- (PolynomHandler::Polynom<PolynomType> rhs);

//    template<typename Type>
//    std::string printSmallPolynom(LinAlg::Matrix<Type> rhs, const char &variable = 'x');

//    template<typename Type> // testada
//    std::string& operator<< (std::string& output, PolynomHandler::Polynom<Type> rhs);

//    template<typename Type> // testada
//    bool VefDen(const Type *den1, const Type *den2, const unsigned &sizeden1, const unsigned &sizeden2);
//    template<typename Type> // testado
//    Type *SumPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

//    template <class Type> // com defeito
//    Type *MultPoly(const Type *lhs, const Type *rhs, const unsigned &lhsSize, const unsigned &rhsSize);

//    template <class Type> // com defeito
//    LinAlg::Matrix<Type> MultPoly(const LinAlg::Matrix<Type> &lhs, const LinAlg::Matrix<Type> &rhs);

//    template <typename Type>
//    Polynom<Type> simplify(const PolynomHandler::Polynom<Type> &P);//sincronizado

//    template <typename Type>
//    LinAlg::Matrix<Type> Roots(LinAlg::Matrix<Type> smallPoly);//sincronizado

//    template <typename Type>
//    LinAlg::Matrix<Type> Root2Poly(const LinAlg::Matrix<Type> &root);

//    template <typename Type>
//    bool rootsContainRoot(const Type &root, const LinAlg::Matrix<Type> &roots);
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

void PolynomDoubleTest::getVarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A(1);
    char x;
    QBENCHMARK {
        x = A.getVar();
    }
    QVERIFY2(x == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::getVarDoubleCase2 ()
{
    LinAlg::Matrix<double> num = "1,1";
    PolynomHandler::Polynom<double> A(num);
    char x;
    QBENCHMARK {
        x = A.getVar();
    }
    QVERIFY2(x == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::getVarDoubleCase3 ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";
    PolynomHandler::Polynom<double> A(num,den);
    char x;
    QBENCHMARK {
        x = A.getVar();
    }
    QVERIFY2(x == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::getVarDoubleCase4 ()
{
    PolynomHandler::Polynom<double> A;
    char x;
    QBENCHMARK {
        x = A.getVar();
    }
    QVERIFY2(x == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::changeVarDouble ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
       A.changeVar('s');
    }
    QVERIFY2(A.getVar() == 's', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::getNumSizeDouble ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";
    unsigned numSize;
    PolynomHandler::Polynom<double> A(num,den);
    QBENCHMARK {
        numSize = A.getNumSize();
    }
    QVERIFY2(numSize == 2, "Falhou ao testar o tamanho do Polinomio");
}

void PolynomDoubleTest::getDenSizeDouble ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";
    unsigned denSize;
    PolynomHandler::Polynom<double> A(num,den);
    QBENCHMARK {
        denSize = A.getDenSize();
    }
    QVERIFY2(denSize == 3, "Falhou ao testar o tamanho do Polinomio");
}

void PolynomDoubleTest::getNumDouble ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";
    PolynomHandler::Polynom<double> A(num,den);
    QBENCHMARK {
        num = A.getNum();
    }
    QVERIFY2(num.getNumberOfColumns() == 2, "Falhou ao testar o tamanho do numerador do Polinomio");
    QVERIFY2(num(1,1) == 1 && num(1,2) == 1, "Falhou ao testar os valores do numerador do Polinomio");
}

void PolynomDoubleTest::getDenDouble ()
{
    LinAlg::Matrix<double> num = "1,1", den = "1,2,1";
    PolynomHandler::Polynom<double> A(num,den);
    QBENCHMARK {
        den = A.getDen();
    }
    QVERIFY2(den.getNumberOfColumns() == 3, "Falhou ao testar o tamanho do denominador do Polinomio");
    QVERIFY2(den(1,1) == 1 && den(1,2) == 2 && den(1,3) == 1, "Falhou ao testar os valores do denominador do Polinomio");
}

void PolynomDoubleTest::setNumDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setNum("1,1");
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2, "Falhou ao testar o tamanho do numerador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1, "Falhou ao testar os valores do numerador do Polinomio");
}

void PolynomDoubleTest::setNumDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A;
    double *num = new double[2]; num[0] = 1; num[1] = 1;
    QBENCHMARK {
        A.setNum(num,2);
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2, "Falhou ao testar o tamanho do numerador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1, "Falhou ao testar os valores do numerador do Polinomio");
}

void PolynomDoubleTest::setDenDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setDen("1,2,1");
    }
    QVERIFY2(A.getDen().getNumberOfColumns() == 3, "Falhou ao testar o tamanho do denominador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
}

void PolynomDoubleTest::setDenDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A;
    double *den = new double[2]; den[0] = 1; den[1] = 2; den[2] = 1;
    QBENCHMARK {
        A.setDen(den,3);
    }
    QVERIFY2(A.getDen().getNumberOfColumns() == 3, "Falhou ao testar o tamanho do denominador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
}

void PolynomDoubleTest::assignOperatorDouble ()
{
    PolynomHandler::Polynom<double> A,B("1,1","1,2,1");
    B.changeVar('s');
    QBENCHMARK {
        A = B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == B.getVar(), "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::copyAssignOperatorDouble ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A = PolynomHandler::Polynom<double>("1,1","1,2,1");
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::assignOperatorOtherTypeDouble ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A = PolynomHandler::Polynom<int>("1,1","1,2,1");
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A += 0;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A += 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorScalarDoubleCase3 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,1");
    QBENCHMARK {
        A.setNum("1,1");
        A.setDen("1,1");
        A += 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 2 && A.getNum()(1,2) == 2,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorScalarDoubleCase4 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,2,1");
    QBENCHMARK {
        A.setNum("1,1");
        A.setDen("1,2,1");
        A += 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 3 && A.getNum()(1,3) == 2,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorScalarDoubleCase5 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A += 1;
        A += 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 2 && A.getNum()(1,2) == 3,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorPolynomDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1","1,1"), B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A += B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 2 && A.getNum()(1,2) == 3,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 3 && A.getDen()(1,3) == 2,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSumAccumulatorPolynomDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A("1","1,1"), B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A += B;
        A += B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 4,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 3 && A.getNum()(1,2) == 10 && A.getNum()(1,3) == 8,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 5 && A.getDen()(1,3) == 8 && A.getDen()(1,4) == 4,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}




void PolynomDoubleTest::operatorSubtractionAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A -= 0;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A -= 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == -1 && A.getNum()(1,2) == 0,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorScalarDoubleCase3 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,1");
    QBENCHMARK {
        A.setNum("1,1");
        A.setDen("1,1");
        A -= 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 0 && A.getNum()(1,2) == 0,
             "Falhou ao testar os valores do numerador do Polinomio");
//    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
//             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorScalarDoubleCase4 ()
{
    PolynomHandler::Polynom<double> A("1,1","1,2,1");
    QBENCHMARK {
        A.setNum("1,1");
        A.setDen("1,2,1");
        A -= 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == -1 && A.getNum()(1,2) == -1 && A.getNum()(1,3) == 0,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorScalarDoubleCase5 ()
{
    PolynomHandler::Polynom<double> A("1","1,1");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A -= 1;
        A -= 1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == -2 && A.getNum()(1,2) == -1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorPolynomDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A("1","1,1"), B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A -= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 0 && A.getNum()(1,2) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 3 && A.getDen()(1,3) == 2,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorSubtractionAccumulatorPolynomDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A("1","1,1"), B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A -= B;
        A -= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 4,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == -1 && A.getNum()(1,2) == -2 && A.getNum()(1,3) == 0,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 5 && A.getDen()(1,3) == 8 && A.getDen()(1,4) == 4,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorMultiplicationAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A *= 2;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 2,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorMultiplicationAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A *= 2;
        A *= 2;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 4,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorMultiplicationAccumulatorPolynomDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A, B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A *= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 3,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 3 && A.getDen()(1,3) == 2,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorMultiplicationAccumulatorPolynomDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A *= B;
        A *= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 4,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 6 && A.getNum()(1,3) == 9,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 5 && A.getDen()(1,3) == 8 && A.getDen()(1,4) == 4,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorDivisionAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A /= 2;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 0.5,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorDivisionAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A;
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A /= 2;
        A /= 2;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 0.25,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorDivisionAccumulatorPolynomDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A, B("1","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A /= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 2,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorDivisionAccumulatorPolynomDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A.setNum("1");
        A.setDen("1,1");
        A /= B;
        A /= B;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 3 && A.getDen().getNumberOfColumns() == 4,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 4 && A.getNum()(1,3) == 4,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 7 && A.getDen()(1,3) == 15 && A.getDen()(1,4) == 9,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorPotentiationAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A = B^4;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 5 && A.getDen().getNumberOfColumns() == 5,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 12 && A.getNum()(1,3) == 54 && A.getNum()(1,4) == 108 && A.getNum()(1,5) == 81,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 8 && A.getDen()(1,3) == 24 && A.getDen()(1,4) == 32 && A.getDen()(1,5) == 16,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorPotentiationAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A = B^-4;
    }
//    std::cout << A << std::endl;
    QVERIFY2(A.getNum().getNumberOfColumns() == 5 && A.getDen().getNumberOfColumns() == 5,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 8 && A.getNum()(1,3) == 24 && A.getNum()(1,4) == 32 && A.getNum()(1,5) == 16,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 12 && A.getDen()(1,3) == 54 && A.getDen()(1,4) == 108 && A.getDen()(1,5) == 81,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorPotentiationAccumulatorScalarDoubleCase3 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A = B^0;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 1 && A.getDen().getNumberOfColumns() == 1,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

void PolynomDoubleTest::operatorPotentiationAccumulatorScalarDoubleCase4 ()
{
    PolynomHandler::Polynom<double> A, B("1,3","1,2");
    QBENCHMARK {
        A = B^1;
    }
    QVERIFY2(A.getNum().getNumberOfColumns() == 2 && A.getDen().getNumberOfColumns() == 2,
             "Falhou ao testar o tamanho dos numerador e denominador do Polinomio");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getNum()(1,2) == 3,
             "Falhou ao testar os valores do numerador do Polinomio");
    QVERIFY2(A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2,
             "Falhou ao testar os valores do denominador do Polinomio");
    QVERIFY2(A.getVar() == 'x', "Falhou ao testar variável do Polinomio");
}

QTEST_APPLESS_MAIN(PolynomDoubleTest)

#include "tst_polynomdoubletest.moc"
