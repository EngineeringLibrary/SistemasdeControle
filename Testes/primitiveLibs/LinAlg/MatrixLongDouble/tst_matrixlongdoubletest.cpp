#include <QString>
#include <QtTest>

class MatrixLongDoubleTest : public QObject
{
    Q_OBJECT

public:
    MatrixLongDoubleTest();

private Q_SLOTS:
    void constructorMatrixLongDoubleTypeInt();
    void constructorMAtrixLongDoubleTypechar();
    void constructorMatrixLongDoubleTypeShort();
    void constructorMatrixLongDoubleTypeFloat();


//    Testes utilizando o tipo long double
    void constructorMatrixLongDouble();
    void constructorMatrixCStringAndLongDouble();
    void constructorMatrixStringAndLongDouble();
    void constructorSizedVoidMatrixLongDouble();
    void constructorNULLMatrixLongDouble();
    void copyconstructorLongDouble();
    void copyconstructorOtherTypeDoubleAndInt();
    void destructorLongDouble();
    void removeRowLongDoublefirstTest();
    void removeRowLongDoubleSecondTest();
    void removeRowLongDoubleTrirdTest();
    void removeColumnLongDoubleFistTest();
    void removeColumnLongDoubleSecondTest();
    void removeColumnLongDoubleThirdTest();
    void getNumberOfRowsLongDouble();
    void getNumberOfColumnLongDouble();
    void getRowDouble();
    void swapRowsDouble();
    void swapColumnDouble();
    void lenghtDouble();
    void sizeDouble();
    void isNullDouble();
    void isSquareDouble();
    void operatorParenthesisInputTwoUsingnedLongDouble();
    void operatorParenthesisInputTwoUsiginedOutputConstLongDouble();
    void operatorParenthesisInputFromToAndUnsignedLongDouble();
    void operatorParenthesisInputUnsignedAndFromToLongDouble();
    void operatorParenthesisInputFromToAndFromToLongDouble();
    void operatorParenthesisInputFromToAndLongMatrixDouble();
    void operatorParenthesisInputMatrixAndFromToDouble();
    void opetatorParenthesisInputUnsignedAndMAtriLongDoubl();
    void operatorParenthesisInputMatrixAndMatrixLongDouble();
    void operatorParenthesisInputMatrixAndMatrixLongDouble();
    void operatorParenthesisInputFromToAndUnsignedInvertAccessLongDouble();
    void operatorParenthesisInputUnsiginedAndFromToInvertedAccessLongDouble();
    void operatorParenthesisInputFromToAndFromToInvertedAccessLongDouble();
    void operatorParenthesisInputFromToAndUnsignedInvertAccessLongDouble();
    void operatorParenthesisInputMatrixAndFromToInvertedAccessLongDouble();
    void operatorPatenthesisInputUnsignedAndMatrixInvertedAccessLongDouble();
    void operatorParenthesisInputMAtrixAndUnsignedInvertedAccessLongDouble();
    void operatorParenthesisInputMatrixAndMatrixInvertedAccessLongDouble();


MatrixLongDoubleTest::MatrixLongDoubleTest()
{
}

void MatrixLongDoubleTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MatrixLongDoubleTest)

#include "tst_matrixlongdoubletest.moc"
