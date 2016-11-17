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
    void operatorAtributionMatrixPointerDouble ();
    void operatorAtributionMatrixMoreThanTwoParametersPointerDouble ();
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
    void operatorDivisionAccumulatorScalarDouble ();
    void operatorDivisionAccumulatorMatrixDouble ();
    void operatorPotentiationAccumulatorScalarDouble ();
    void operatorEqualDouble ();
    void operatorLessEqualThanDouble ();
    void operatorGreaterEqualThanDouble ();
    void operatorLessThanDouble ();
    void operatorGreaterThanDouble ();
    void horizontalConcatenationOperatorScalarDouble ();
    void horizontalConcatenationOperatorMatrixDouble ();
    void verticalConcatenationOperatorScalarDouble ();
    void verticalConcatenationOperatorMatrixDouble ();
    void bufferOperatorDouble ();
    void swapTwoMatrixDouble();
    void swapTwoMatrixFriendDouble();
    void operatorSumMatrixScalarDouble ();
    void operatorSumScalarMatrixDouble ();
    void operatorSumMatrixMatrixDouble ();
    void operatorSubtractionMatrixScalarDouble ();
    void operatorSubtractionScalarMatrixDouble ();
    void operatorSubtractionMatrixMatrixDouble ();
    //    LinAlg::Matrix<MatrixType> operator* (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs);
//    LinAlg::Matrix<MatrixType> operator* (const ScalarType& lhs, LinAlg::Matrix<MatrixType> rhs);
//    LinAlg::Matrix<LeftType> operator* (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs);
//    LinAlg::Matrix<MatrixType> operator/ (LinAlg::Matrix<MatrixType> lhs, const ScalarType& rhs);
//    LinAlg::Matrix<LeftType> operator/ (LinAlg::Matrix<LeftType> lhs, const LinAlg::Matrix<RightType>& rhs);
//    LinAlg::Matrix<Type> operator- (const LinAlg::Matrix<Type>& mat);
//    LinAlg::Matrix<Type> operator~ (LinAlg::Matrix<Type> mat);
//    LinAlg::Matrix<Type> operator^ (LinAlg::Matrix<Type> lhs, int exp);
//    std::ostream& operator<< (std::ostream& output, const LinAlg::Matrix<Type> mat);
//    std::ostream& operator<<= (std::ostream& output, const LinAlg::Matrix<Type> mat);
//    std::istream& operator>> (std::istream& input, LinAlg::Matrix<Type>& mat);
//    std::string& operator<< (std::string& output, const LinAlg::Matrix<Type> mat);
//    std::string& operator<<= (std::string& output, const LinAlg::Matrix<Type> mat);
////    bool operator== (const LinAlg::Matrix<Type>& lhs, const LinAlg::Matrix<Type>& rhs);
//    bool operator!= (const LinAlg::Matrix<Type>& lhs, const LinAlg::Matrix<Type>& rhs);
//    LinAlg::Matrix<Type> divPoint(const LinAlg::Matrix<Type> &A, const LinAlg::Matrix<Type> &B);
//    LinAlg::Matrix<Type> sortColumnVector(const LinAlg::Matrix<Type> &columnVector);
//    LinAlg::Matrix<Type> sortColumnVectorIndices(const LinAlg::Matrix<Type> &columnVector);
//    unsigned lineOfMinValue(const LinAlg::Matrix<Type> &mat);
//    unsigned columnOfMinValue(const LinAlg::Matrix<Type> &mat);
//    Type MinValue(const LinAlg::Matrix<Type> &mat);
//    unsigned lineOfMaxValue(const LinAlg::Matrix<Type> &mat);
//    unsigned columnOfMaxValue(const LinAlg::Matrix<Type> &mat);
//    Type MaxValue(const LinAlg::Matrix<Type> &mat);
//    LinAlg::Matrix<Type> sumOfRowsElements(const LinAlg::Matrix<Type> &mat);
//    LinAlg::Matrix<Type> sumOfColumnsElements(const LinAlg::Matrix<Type> &mat);
//    void Zeros (LinAlg::Matrix<Type>& Mat);
//    LinAlg::Matrix<Type> Zeros (unsigned rows, unsigned columns);
//    LinAlg::Matrix<Type> Eye (unsigned dimension);
//    LinAlg::Matrix<Type> LineVector (Type from, Type to, Type step = 1);
//    void Ones (LinAlg::Matrix<Type> & mat);
//    LinAlg::Matrix<Type> Ones (unsigned rows, unsigned columns);
//    LinAlg::Matrix<Type> Random (unsigned rows, unsigned columns);
//    Type Determinant (const LinAlg::Matrix<Type>& mat);
//    LinAlg::Matrix<Type> Cofactor(const LinAlg::Matrix<Type>& mat);
//    LinAlg::Matrix<Type> Inverse(const LinAlg::Matrix<Type>& mat);
//    void Print (const LinAlg::Matrix<Type>& mat);
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
    bool flag;
    QBENCHMARK {
        flag = (A(1,1) == 0.0);
    }
    QVERIFY2(flag, "Acesso ao elemento da matriz não realizado com sucesso");
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

void MatrixTest::operatorAtributionMatrixPointerDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", B = "1,2,3,4", C, D;
    QBENCHMARK {
        *(C,D) = (A,B);
    }
    QVERIFY2(C.getNumberOfColumns() == 2 && C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == A(1,1) && C(1,2) == A(1,2) &&
             C(2,1) == A(2,1) && C(2,2) == A(2,2), "Falhou ao comparar todos os elementos da matriz com valor double");
    QVERIFY2(&C != &A, "Falhou ao comparar os endereços da matriz com valor double");

    QVERIFY2(D.getNumberOfColumns() == 4 && D.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(D(1,1) == B(1,1) && D(1,2) == B(1,2) &&
             D(1,3) == B(1,3) && D(1,4) == B(1,4), "Falhou ao comparar todos os elementos da matriz com valor double");
    QVERIFY2(&D != &B, "Falhou ao comparar os endereços da matriz com valor double");
}

void MatrixTest::operatorAtributionMatrixMoreThanTwoParametersPointerDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", B = "1,2,3,4", C = "1,2", D, E, F;
    QBENCHMARK {
        *(D,E,F) = (A,B,C);
    }
    QVERIFY2(D.getNumberOfColumns() == 2 && D.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(D(1,1) == A(1,1) && D(1,2) == A(1,2) &&
             D(2,1) == A(2,1) && D(2,2) == A(2,2), "Falhou ao comparar todos os elementos da matriz com valor double");
    QVERIFY2(&D != &A, "Falhou ao comparar os endereços da matriz com valor double");

    QVERIFY2(E.getNumberOfColumns() == 4 && E.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(E(1,1) == B(1,1) && E(1,2) == B(1,2) &&
             E(1,3) == B(1,3) && E(1,4) == B(1,4), "Falhou ao comparar todos os elementos da matriz com valor double");
    QVERIFY2(&E != &B, "Falhou ao comparar os endereços da matriz com valor double");

    QVERIFY2(F.getNumberOfColumns() == 2 && F.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(F(1,1) == C(1,1) && F(1,2) == C(1,2) &&
             F(1,3) == C(1,3) && F(1,4) == C(1,4), "Falhou ao comparar todos os elementos da matriz com valor double");
    QVERIFY2(&F != &C, "Falhou ao comparar os endereços da matriz com valor double");
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

void MatrixTest::operatorDivisionAccumulatorScalarDouble ()
{
    LinAlg::Matrix<double> B = 2*LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = 2*LinAlg::Ones<double>(2,2);
        B /= 2;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorDivisionAccumulatorMatrixDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Ones<double>(2,2), A = LinAlg::Eye<double>(2);
    QBENCHMARK {
        B = LinAlg::Ones<double>(2,2);
        B /= A;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorPotentiationAccumulatorScalarDouble ()
{
    LinAlg::Matrix<double> B = LinAlg::Ones<double>(2,2), A = LinAlg::Ones<double>(2,2);
    QBENCHMARK {
        B = LinAlg::Ones<double>(2,2);
        B ^= 2;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 2 && B(2,1) == 2 && B(1,2) == 2 && B(2,2) == 2, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorEqualDouble ()
{
    LinAlg::Matrix<double> A = "1,2;1,2";
    LinAlg::Matrix<bool> B;
    QBENCHMARK {
        B = A == 1;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 0 && B(2,2) == 0, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorLessEqualThanDouble ()
{
    LinAlg::Matrix<double> A = "1,2;1,2";
    LinAlg::Matrix<bool> B;
    QBENCHMARK {
        B = A <= 1;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 0 && B(2,2) == 0, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorGreaterEqualThanDouble ()
{
    LinAlg::Matrix<double> A = "1,2;1,2";
    LinAlg::Matrix<bool> B;
    QBENCHMARK {
        B = A >= 2;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 0 && B(2,1) == 0 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorLessThanDouble ()
{
    LinAlg::Matrix<double> A = "1,2;1,2";
    LinAlg::Matrix<bool> B;
    QBENCHMARK {
        B = A < 2;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 1 && B(1,2) == 0 && B(2,2) == 0, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorGreaterThanDouble ()
{
    LinAlg::Matrix<double> A = "1,2;1,2";
    LinAlg::Matrix<bool> B;
    QBENCHMARK {
        B = A > 1;
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 0 && B(2,1) == 0 && B(1,2) == 1 && B(2,2) == 1, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::horizontalConcatenationOperatorScalarDouble ()
{
    LinAlg::Matrix<double> A = "1,2", B;

    QBENCHMARK {
        B = A|3;
    }
    QVERIFY2(B.getNumberOfColumns() == 3 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(1,2) == 2 && B(1,3) == 3, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::horizontalConcatenationOperatorMatrixDouble ()
{
    LinAlg::Matrix<double> A = "1,2", B;

    QBENCHMARK {
        B = A|LinAlg::Matrix<double>(3);
    }
    QVERIFY2(B.getNumberOfColumns() == 3 && B.getNumberOfRows() == 1, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(1,2) == 2 && B(1,3) == 3, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::verticalConcatenationOperatorScalarDouble()
{
    LinAlg::Matrix<double> A = "1;2", B;

    QBENCHMARK {
        B = A||3;
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 2 && B(3,1) == 3, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::verticalConcatenationOperatorMatrixDouble()
{
    LinAlg::Matrix<double> A = "1;2", B;

    QBENCHMARK {
        B = A||LinAlg::Matrix<double>(3);
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 3, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(2,1) == 2 && B(3,1) == 3, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::bufferOperatorDouble ()
{
    LinAlg::Matrix<double> A, B;

    QBENCHMARK {
        A = "1"; B = "2;3";
        B << A;
    }
    QVERIFY2(B.getNumberOfColumns() == 1 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 3 && B(2,1) == 1 , "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::swapTwoMatrixDouble()
{
    LinAlg::Matrix<double> A, B;

    QBENCHMARK {
        A = "1,2;3,4"; B = "4,3;2,1";
        B.swap(A);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(1,2) == 2 &&
             B(2,1) == 3 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::swapTwoMatrixFriendDouble()
{
    LinAlg::Matrix<double> A, B;

    QBENCHMARK {
        A = "1,2;3,4"; B = "4,3;2,1";
        swap(B,A);
    }
    QVERIFY2(B.getNumberOfColumns() == 2 && B.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(B(1,1) == 1 && B(1,2) == 2 &&
             B(2,1) == 3 && B(2,2) == 4, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSumMatrixScalarDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;

    QBENCHMARK {
        C = A+2;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == 3 && C(1,2) == 4 &&
             C(2,1) == 5 && C(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSumScalarMatrixDouble()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;

    QBENCHMARK {
        C = 2+A;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == 3 && C(1,2) == 4 &&
             C(2,1) == 5 && C(2,2) == 6, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSumMatrixMatrixDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;
    LinAlg::Matrix<int> B = "4,3;2,1";
    QBENCHMARK {
        C = A+B;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == 5 && C(1,2) == 5 &&
             C(2,1) == 5 && C(2,2) == 5, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSubtractionMatrixScalarDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;

    QBENCHMARK {
        C = A-2;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == -1 && C(1,2) == 0 &&
             C(2,1) == 1 && C(2,2) == 2, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSubtractionScalarMatrixDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;

    QBENCHMARK {
        C = 2-A;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == 1 && C(1,2) == 0 &&
             C(2,1) == -1 && C(2,2) == -2, "Falhou ao comparar todos os elementos da matriz com valor double");
}

void MatrixTest::operatorSubtractionMatrixMatrixDouble ()
{
    LinAlg::Matrix<double> A = "1,2;3,4", C;
    LinAlg::Matrix<int> B = "4,3;2,1";
    QBENCHMARK {
        C = A-B;

    }
    QVERIFY2(C.getNumberOfColumns() == 2 &&C.getNumberOfRows() == 2, "Falhou ao testar o tamanho da matriz");
    QVERIFY2(C(1,1) == -3 && C(1,2) == -1 &&
             C(2,1) == 1 && C(2,2) == 3, "Falhou ao comparar todos os elementos da matriz com valor double");
}

QTEST_APPLESS_MAIN(MatrixTest)

#include "tst_matrixtest.moc"
