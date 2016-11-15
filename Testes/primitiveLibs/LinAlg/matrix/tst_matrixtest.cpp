#include <QString>
#include <QtTest>
#define testMatrix
#include "../../../../headers/primitiveLibs/LinAlg/matrix.h"

class MatrixTest : public QObject
{
    Q_OBJECT

public:
    MatrixTest(){}

private Q_SLOTS:
    void constructorMatrixTypeInt();
    void constructorMatrixTypeChar();
    void constructorMatrixTypeShort();
    void constructorMatrixTypeFloat();

    //Testes utilizando o tipo Double
    void constructorMatrixTypeDouble ();
    void constructorMatrixTypeLongDouble ();
    void constructorMatrixTypeCStringAndDouble ();
    void constructorMatrixTypeStringAndDouble ();
    void constructorSizedVoidMatrixDouble ();
    void constructorNULLMatrixDouble ();
    void copyconstructorDouble ();
    void copyconstructorOtherTypeDoubleAndInt ();
    void destructorDouble ();
    void removeRowDoubleFirstTest ();
    void removeRowDoubleSecondTest ();
    void removeRowDoubleThirdTest ();
    void removeColumnDoubleFirstTest ();
    void removeColumnDoubleSecondTest ();
    void removeColumnDoubleThirdTest ();
    void getNumberOfRowsDouble ();
    void getNumberOfColumnsDouble ();
    void getRowDouble ();
    void getColumnDouble ();
    void swapRowsDouble ();
    void swapColumnsDouble ();
    void lengthDouble ();
    void sizeDouble ();
    void isNullDouble ();
    void isSquareDouble ();
    void operatorParenthesisInputTwoUnsignedDouble ();
    void operatorParenthesisInputTwoUnsignedOutputConstDouble ();
    //Falta a inclusão de testes com valores nulos e com posições invertidas para os operadores().
    void operatorParenthesisInputFromToAndUnsignedDouble ();
    void operatorParenthesisInputUnsignedAndFromToDouble ();
    void operatorParenthesisInputFromToAndFromToDouble ();
    void operatorParenthesisInputFromToAndMatrixDouble ();
    void operatorParenthesisInputMatrixAndFromToDouble ();
    void operatorParenthesisInputUnsignedAndMatrixDouble ();
    void operatorParenthesisInputMatrixAndUnsignedDouble ();
    void operatorParenthesisInputMatrixAndMatrixDouble ();
    void operatorParenthesisInputFromToAndUnsignedInvertedAccessDouble ();
    void operatorParenthesisInputUnsignedAndFromToInvertedAccessDouble ();
    void operatorParenthesisInputFromToAndFromToInvertedAccessDouble ();
    void operatorParenthesisInputFromToAndMatrixInvertedAccessDouble ();
    void operatorParenthesisInputMatrixAndFromToInvertedAccessDouble ();
    void operatorParenthesisInputUnsignedAndMatrixInvertedAccessDouble ();
    void operatorParenthesisInputMatrixAndUnsignedInvertedAccessDouble ();
    void operatorParenthesisInputMatrixAndMatrixInvertedAccessDouble ();
    void operatorAtributionDoubleReturningVoid ();
    void operatorAtributionDoubleReturningDouble ();
    void operatorAtributionDoubleReturningInt ();
    void operatorAtributionDoubleReturningShort ();
    void operatorAtributionDoubleReturningLongInt ();
    void operatorAtributionDoubleReturningLongFloat ();

    void operatorSumAccumulatorScalarDouble ();
    void operatorSumAccumulatorMatrixDouble ();
    void operatorSubtractionAccumulatorScalarDouble ();
    void operatorSubtractionAccumulatorMatrixDouble ();
    void operatorMultiplicationAccumulatorScalarDouble ();
    void operatorMultiplicationAccumulatorMatrixDouble ();
//    void operatorDivisionAccumulatorScalarDouble ();
//    void operatorDivisionAccumulatorMatrixDouble ();
//    void operatorPotentiationAccumulatorScalarDouble ();

//    LinAlg::Matrix<Type> operator<= (const Type& rhs /*scalar*/);
//    LinAlg::Matrix<Type> operator>= (const Type& rhs /*scalar*/);
//    LinAlg::Matrix<Type> operator| (LinAlg::Matrix<RightType> rhs);
//    LinAlg::Matrix<Type> operator| (RightType rhs);
//    LinAlg::Matrix<Type> operator|| (LinAlg::Matrix<RightType> rhs);
//    void operator<< (const LinAlg::Matrix<Type>& mat);
//    void swap (const LinAlg::Matrix<OtherMatrixType>& otherMatrix);
//    friend void swap (LinAlg::Matrix<Type>& lhs, LinAlg::Matrix<OtherMatrixType>& rhs) {lhs.swap(rhs);};
};

void MatrixTest::constructorMatrixTypeChar()
{
    QBENCHMARK {
        LinAlg::Matrix<char> A('a');
    }
    LinAlg::Matrix<char> A('a');
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 'a', "Falhou ao comparar o elemento da matriz com valor char");
    QVERIFY2(sizeof(A(1,1)) == sizeof(char), "Falhou ao comparar o tipo do elemento da matriz com valor char");
}

void MatrixTest::constructorMatrixTypeShort()
{
    QBENCHMARK {
        LinAlg::Matrix<short> A(1);
    }
    LinAlg::Matrix<short> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor short");
    QVERIFY2(sizeof(A(1,1)) == sizeof(short), "Falhou ao comparar o tipo do elemento da matriz com valor short");
}

void MatrixTest::constructorMatrixTypeInt()
{
    QBENCHMARK {
        LinAlg::Matrix<int> A(1);
    }
    LinAlg::Matrix<int> A(1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1, "Falhou ao comparar o elemento da matriz com valor inteiro");
    QVERIFY2(sizeof(A(1,1)) == sizeof(int), "Falhou ao comparar o tipo do elemento da matriz com valor inteiro");
}

void MatrixTest::constructorMatrixTypeFloat()
{
    QBENCHMARK {
        LinAlg::Matrix<float> A(1.5);
    }
    LinAlg::Matrix<float> A(1.5);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.5, "Falhou ao comparar o elemento da matriz com valor float");
    QVERIFY2(sizeof(A(1,1)) == sizeof(float), "Falhou ao comparar o tipo do elemento da matriz com valor float");
}

void MatrixTest::constructorMatrixTypeDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A(1.1);
    }
    LinAlg::Matrix<double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(double), "Falhou ao comparar o tipo do elemento da matriz com valor double");
}

void MatrixTest::constructorMatrixTypeLongDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<long double> A(1.1);
    }
    LinAlg::Matrix<long double> A(1.1);
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.1, "Falhou ao comparar o elemento da matriz com valor long double");
    QVERIFY2(sizeof(A(1,1)) == sizeof(long double), "Falhou ao comparar o tipo do elemento da matriz com valor long double");
}

void MatrixTest::constructorMatrixTypeCStringAndDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A("1,2,3,4;5,6,7,8");
    }
    LinAlg::Matrix<double> A("1,2,3,4;5,6,7,8");
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(1,2) == 2.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 5.0 && A(2,2) == 6.0 && A(2,3) == 7.0 && A(2,4) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::constructorMatrixTypeStringAndDouble()
{
    std::string str = "1,2,3,4;5,6,7,8";
    QBENCHMARK {
        LinAlg::Matrix<double> A(str);
    }
    LinAlg::Matrix<double> A(str);
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(1,2) == 2.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 5.0 && A(2,2) == 6.0 && A(2,3) == 7.0 && A(2,4) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::constructorSizedVoidMatrixDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A(3,3);
    }
    LinAlg::Matrix<double> A(3,3);
    QVERIFY2(A.getNumberOfColumns() == 3 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 0.0 && A(1,2) == 0.0 && A(1,3) == 0.0 &&
             A(2,1) == 0.0 && A(2,2) == 0.0 && A(2,3) == 0.0 &&
             A(3,1) == 0.0 && A(3,2) == 0.0 && A(3,3) == 0.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::constructorNULLMatrixDouble()
{
    QBENCHMARK {
        LinAlg::Matrix<double> A;
    }
    LinAlg::Matrix<double> A;
    QVERIFY2(A.getNumberOfColumns() == 0 && A.getNumberOfRows() == 0, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::copyconstructorDouble()
{
    LinAlg::Matrix<double> A = "1,2;3,4";
    QBENCHMARK {
        LinAlg::Matrix<double> B(A);
    }
    LinAlg::Matrix<double> B(A);
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1.0 && B(1,2) == 2.0 &&
             B(2,1) == 3.0 && B(2,2) == 4.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::copyconstructorOtherTypeDoubleAndInt()
{
    LinAlg::Matrix<int> A = "1,2;3,4";
    QBENCHMARK {
        LinAlg::Matrix<double> B(A);
    }
    LinAlg::Matrix<double> B(A);
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1.0 && B(1,2) == 2.0 &&
             B(2,1) == 3.0 && B(2,2) == 4.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::destructorDouble()
{
    LinAlg::Matrix<int> A = "1,2;3,4";
    QBENCHMARK {
        A.~Matrix();
    }
    QVERIFY2(A.getNumberOfColumns() == 0 && A.getNumberOfRows() == 0, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::removeRowDoubleFirstTest()
{
    std::string str = "1,2,3,4";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeRow(1);
    }
    QVERIFY2(A.getNumberOfColumns() == 0 && A.getNumberOfRows() == 0, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::removeRowDoubleSecondTest()
{
    std::string str = "1,2,3,4;5,6,7,8";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeRow(1);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 5.0 && A(1,2) == 6.0 && A(1,3) == 7.0 && A(1,4) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::removeRowDoubleThirdTest()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeRow(2);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(1,2) == 2.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 9.0 && A(2,2) == 10.0 && A(2,3) == 11.0 && A(2,4) == 12.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::removeColumnDoubleFirstTest()
{
    std::string str = "1;2;3;4";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeColumn(1);
    }
    QVERIFY2(A.getNumberOfColumns() == 0 && A.getNumberOfRows() == 0, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::removeColumnDoubleSecondTest()
{
    std::string str = "1,5;2,6;3,7;4,8";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeColumn(1);
    }
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 4, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 5.0 && A(2,1) == 6.0 && A(3,1) == 7.0 && A(4,1) == 8.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::removeColumnDoubleThirdTest()
{
    std::string str = "1,5,9;2,6,10;3,7,11;4,8,12";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.removeColumn(2);
    }
    QVERIFY2(A.getNumberOfColumns() == 2 && A.getNumberOfRows() == 4, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 1.0 && A(2,1) == 2.0 && A(3,1) == 3.0 && A(4,1) == 4.0 &&
             A(1,2) == 9.0 && A(2,2) == 10.0 && A(3,2) == 11.0 && A(4,2) == 12.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::getNumberOfRowsDouble()
{
    std::string str = "1;2;3;4;5;6;7;8;9;0";
    LinAlg::Matrix<double> A;
    A = str.c_str();
    QBENCHMARK {
        A.getNumberOfRows();
    }
    QVERIFY2(A.getNumberOfColumns() == 1 && A.getNumberOfRows() == 10, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::getNumberOfColumnsDouble()
{
    std::string str = "1,2,3,4,5,6,7,8,9,0";
    LinAlg::Matrix<double> A;
    A = str.c_str();
    QBENCHMARK {
        A.getNumberOfColumns();
    }
    QVERIFY2(A.getNumberOfColumns() == 10 && A.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
}

void MatrixTest::getRowDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A,B;
    A = str.c_str();
    QBENCHMARK {
        B = A.getRow(1);
    }
    QVERIFY2(B.getNumberOfColumns() == 4 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1.0 && B(1,2) == 2.0 && B(1,3) == 3.0 && B(1,4) == 4.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::getColumnDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A,B;
    A = str.c_str();
    QBENCHMARK {
        B = A.getColumn(1);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1.0 && B(2,1) == 5.0 && B(3,1) == 9.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::swapRowsDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.swapRows(1,2);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 5.0 && A(1,2) == 6.0 && A(1,3) == 7.0 && A(1,4) == 8.0 &&
             A(2,1) == 1.0 && A(2,2) == 2.0 && A(2,3) == 3.0 && A(2,4) == 4.0 &&
             A(3,1) == 9.0 && A(3,2) == 10.0 && A(3,3) == 11.0 && A(3,4) == 12.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::swapColumnsDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A;
    QBENCHMARK {
        A = str.c_str();
        A.swapColumns(1,2);
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A(1,1) == 2.0 && A(1,2) == 1.0 && A(1,3) == 3.0 && A(1,4) == 4.0 &&
             A(2,1) == 6.0 && A(2,2) == 5.0 && A(2,3) == 7.0 && A(2,4) == 8.0 &&
             A(3,1) == 10.0 && A(3,2) == 9.0 && A(3,3) == 11.0 && A(3,4) == 12.0
             , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::lengthDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str;
    QBENCHMARK {
        A.length();
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(A.length() == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::sizeDouble()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A.size();
    }
    QVERIFY2(A.getNumberOfColumns() == 4 && A.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 3 && B(1,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::isNullDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        A.isNull();
        B.isNull();
    }
    QVERIFY2(B.isNull(), "Matriz deveria ser vazia");
    QVERIFY2(!A.isNull(), "Matriz não deveria ser vazia");
}

void MatrixTest::isSquareDouble ()
{
    LinAlg::Matrix<double> A = LinAlg::Zeros<double>(1,5), B = LinAlg::Zeros<double>(5,5);
    QBENCHMARK {
        A.isSquare();
        B.isSquare();
    }
    QVERIFY2(B.isSquare(), "Matriz deveria ser quadrada");
    QVERIFY2(!A.isSquare(), "Matriz não deveria ser quadrada");
}

void MatrixTest::operatorParenthesisInputTwoUnsignedDouble ()
{
    LinAlg::Matrix<double> A = LinAlg::Zeros<double>(1,5);
    QBENCHMARK {
        A(1,1) = 2.0;
    }
    A(1,1) = 2.0;
    QVERIFY2(A(1,1) == 2.0, "Atribuição não realizada com sucesso");
}

void MatrixTest::operatorParenthesisInputTwoUnsignedOutputConstDouble ()
{
    LinAlg::Matrix<double> A = LinAlg::Zeros<double>(1,5);
    QBENCHMARK {
        A(1,1) == 0.0;
    }
    QVERIFY2(A(1,1) == 0.0, "Acesso ao elemento da matriz não realizado com sucesso");
}

void MatrixTest::operatorParenthesisInputFromToAndUnsignedDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(2)-->3,2);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputUnsignedAndFromToDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(2,from(2)-->3);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(1,2) == 7, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputFromToAndFromToDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(2)-->3,from(2)-->3);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10 && B(1,2) == 7 && B(2,2) == 11, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputFromToAndMatrixDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(2)-->3,"2,3");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10 && B(1,2) == 7 && B(2,2) == 11, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndFromToDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("2,3",from(2)-->3);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10 && B(1,2) == 7 && B(2,2) == 11, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputUnsignedAndMatrixDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(2,"2,3");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(1,2) == 7, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndUnsignedDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("2,3",2);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndMatrixDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("2,3","2,3");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 6 && B(2,1) == 10 && B(1,2) == 7 && B(2,2) == 11, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputFromToAndUnsignedInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(3)-->2,2);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 10 && B(2,1) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputUnsignedAndFromToInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(2,from(3)-->2);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 7 && B(1,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputFromToAndFromToInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(3)-->2,from(3)-->2);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 11 && B(2,1) == 7 && B(1,2) == 10 && B(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputFromToAndMatrixInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(from(3)-->2,"3,2");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 11 && B(2,1) == 7 && B(1,2) == 10 && B(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndFromToInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("3,2",from(3)-->2);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 11 && B(2,1) == 7 && B(1,2) == 10 && B(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputUnsignedAndMatrixInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A(2,"3,2");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 7 && B(1,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndUnsignedInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("3,2",2);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 10 && B(2,1) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorParenthesisInputMatrixAndMatrixInvertedAccessDouble ()
{
    std::string str = "1,2,3,4;5,6,7,8;9,10,11,12";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A("3,2","3,2");
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 11 && B(2,1) == 7 && B(1,2) == 10 && B(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}







void MatrixTest::operatorAtributionDoubleReturningVoid ()
{
    LinAlg::Matrix<double> B;
    QBENCHMARK {
        B = "3,2";
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 3 && B(1,2) == 2, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorAtributionDoubleReturningDouble ()
{
    std::string str = "1,2;3,4";
    LinAlg::Matrix<double> A = str,B;
    QBENCHMARK {
        B = A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 3 && B(1,2) == 2 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorAtributionDoubleReturningInt ()
{
    std::string str = "1,2;3,4";
    LinAlg::Matrix<double> A = str;
    LinAlg::Matrix<int> B;
    QBENCHMARK {
        B = A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 3 && B(1,2) == 2 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorAtributionDoubleReturningShort ()
{
    std::string str = "1,2;3,4";
    LinAlg::Matrix<double> A = str;
    LinAlg::Matrix<short> B;
    QBENCHMARK {
        B = A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 3 && B(1,2) == 2 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorAtributionDoubleReturningLongInt ()
{
    std::string str = "1,2;3,4";
    LinAlg::Matrix<double> A = str;
    LinAlg::Matrix<long int> B;
    QBENCHMARK {
        B = A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 3 && B(1,2) == 2 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorAtributionDoubleReturningLongFloat ()
{
    std::string str = "1,2;3,4";
    LinAlg::Matrix<double> A = str;
    LinAlg::Matrix<float> B;
    QBENCHMARK {
        B = A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 3 && B(1,2) == 2 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}




void MatrixTest::operatorSumAccumulatorScalarDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Zeros<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Zeros<double>(2,2);
        B += 1;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSumAccumulatorMatrixDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Zeros<double>(2,2), A = LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Zeros<double>(2,2);
        B += A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSubtractionAccumulatorScalarDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Zeros<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Zeros<double>(2,2);
        B -= 1;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == -1 && B(2,1) == -1 && B(1,2) == -1 && B(2,2) == -1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSubtractionAccumulatorMatrixDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Zeros<double>(2,2), A = LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Zeros<double>(2,2);
        B -= A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == -1 && B(2,1) == -1 && B(1,2) == -1 && B(2,2) == -1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorMultiplicationAccumulatorScalarDouble ()
{
    LinAlg::Matrix<double> B = 2*LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = 2*LinAlg::Ones<double>(2,2);
        B *= 2;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 4 && B(2,1) == 4 && B(1,2) == 4 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorMultiplicationAccumulatorMatrixDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Ones<double>(2,2), A = LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Ones<double>(2,2);
        B *= A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 2 && B(2,1) == 2 && B(1,2) == 2 && B(2,2) == 2, "Falhou ao comparar todos os elementos da matriz com valor double");
}

//void operatorDivisionAccumulatorScalarDouble ();
//void operatorDivisionAccumulatorMatrixDouble ();
//void operatorPotentiationAccumulatorScalarDouble ();

QTEST_APPLESS_MAIN(MatrixTest)

#include "tst_matrixtest.moc"
