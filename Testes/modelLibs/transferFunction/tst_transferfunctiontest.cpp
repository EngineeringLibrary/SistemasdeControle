#include <QString>
#include <QtTest>
#define testPolynom
#define testModel
#include "../../../headers/primitiveLibs/LinAlg/matrix.h"
#include "../../../headers/primitiveLibs/polynom.h"
#include "../../../headers/modelLibs/transferfunction.h"

class TransferFunctionTest : public QObject
{
    Q_OBJECT

public:
    TransferFunctionTest(){}

private Q_SLOTS:
    void TFVoidConstructorDouble ();
    void TFRowColumnConstructorDouble ();
    void TFPolynomConstructorDouble ();
    void TFMatrixPolynomConstructorDouble ();
    void TFMatrixNumDenConstructorDouble ();
    void TFDiscreteRowColumnConstructorDouble ();
    void TFDiscretePolynomConstructorDouble ();
    void TFDiscreteMatrixPolynomConstructorDouble ();
    void TFDiscreteMatrixNumDenConstructorDouble ();

    void isContinuousDouble ();
    void getSampleTimeDouble ();
    void getNumberOfRowsDouble ();
    void getNumberOfColumnsDouble ();
    void getNumberOfVariablesDouble ();
    void getNumberOfInputsDouble ();
    void getNumberOfOutputsDouble ();
    void getTimeSimulationDouble ();

    void setContinuousDouble ();
    void setSampleTimeDouble ();
    void operatorParenthesisDoubleCase1 ();
    void operatorParenthesisDoubleCase2 ();
    void operatorAtributionDoubleCase1();
    void operatorAtributionDoubleCase2();
    void operatorAtributionDoubleCase3();
    void operatorAtributionDoubleCase4();
    void operatorAtributionDoubleCase5();
    void operatorAtributionDoubleCase6();
    void operatorAtributionDoubleCase7();
    void operatorAtributionDoubleCase8();
    void operatorSumAccumulatorScalarDoubleCase1 ();
    void operatorSumAccumulatorScalarDoubleCase2 ();
    void operatorSumAccumulatorTFDoubleCase1 ();
    void operatorSumAccumulatorTFDoubleCase2 ();
    void operatorSubtractionAccumulatorScalarDoubleCase1 ();
    void operatorSubtractionAccumulatorScalarDoubleCase2 ();
    void operatorSubtractionAccumulatorTFDoubleCase1 ();
    void operatorSubtractionAccumulatorTFDoubleCase2 ();
    void operatorMultiplicationAccumulatorScalarDoubleCase1 ();
    void operatorMultiplicationAccumulatorScalarDoubleCase2 ();
    void operatorMultiplicationAccumulatorTFDoubleCase1 ();
    void operatorMultiplicationAccumulatorTFDoubleCase2 ();
    void operatorDivisionAccumulatorScalarDoubleCase1 ();
    void operatorDivisionAccumulatorScalarDoubleCase2 ();
    void operatorDivisionAccumulatorTFDoubleCase1 ();
    void operatorDivisionAccumulatorTFDoubleCase2 ();
//    Type sim(Type input);
//    Type sim(Type x, Type y);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y);
//    LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);
//    std::string ContinuosFirstOrderCaracteristics();
//    std::string ContinuosSecondOrderCaracteristics();
//    std::string print();
//    TransferFunction<PolynomType> operator+ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs += rhs;}
//    TransferFunction<PolynomType> operator+ (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return rhs += lhs;}
//    TransferFunction<LeftType> operator+ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs += rhs;}
//    TransferFunction<PolynomType> operator- (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
//    TransferFunction<PolynomType> operator- (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return -1*(rhs -= lhs);}
//    TransferFunction<LeftType> operator- (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs)
//    TransferFunction<PolynomType>  operator* (TransferFunction<PolynomType>  lhs, const ScalarType& rhs) {return lhs *= rhs;}
//    TransferFunction<PolynomType>  operator* (const ScalarType& lhs, TransferFunction<PolynomType>  rhs) {return rhs *= lhs;}
//    TransferFunction<LeftType> operator* (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs *= rhs;}
//    TransferFunction<PolynomType> operator/ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs /= rhs;}
//    TransferFunction<PolynomType> operator/ (ScalarType rhs, TransferFunction<PolynomType> lhs) {return TransferFunction<PolynomType>(rhs) /= lhs;}
//    TransferFunction<LeftType> operator/ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs /= rhs;}
//    std::ostream& operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF);
//    std::string&  operator<< (std::string& output,  ModelHandler::TransferFunction<Type> TF);
};

void TransferFunctionTest::TFVoidConstructorDouble ()
{
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFRowColumnConstructorDouble ()
{
    ModelHandler::TransferFunction<double> A(1,1);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(1,1);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFPolynomConstructorDouble ()
{
    PolynomHandler::Polynom<double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A(B);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(B);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFMatrixPolynomConstructorDouble ()
{
    PolynomHandler::Polynom<double> B("1","1,2,1");
    LinAlg::Matrix< PolynomHandler::Polynom<double> > C(1,2); C(1,1) = B; C(1,2) = B;
    ModelHandler::TransferFunction<double> A(C);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(C);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFMatrixNumDenConstructorDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1");
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A("1","1,2,1");
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFDiscreteRowColumnConstructorDouble ()
{
    ModelHandler::TransferFunction<double> A(1,1,0.2);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(1,1,0.2);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFDiscretePolynomConstructorDouble ()
{
    PolynomHandler::Polynom<double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A(B,0.2);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(B,0.2);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFDiscreteMatrixPolynomConstructorDouble ()
{
    PolynomHandler::Polynom<double> B("1","1,2,1");
    LinAlg::Matrix< PolynomHandler::Polynom<double> > C(1,2); C(1,1) = B; C(1,2) = B;
    ModelHandler::TransferFunction<double> A(C,0.2);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A(C,0.2);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::TFDiscreteMatrixNumDenConstructorDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::isContinuousDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    bool cont;
    QBENCHMARK {
        cont = A.isContinuous();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!cont && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
}

void TransferFunctionTest::getSampleTimeDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    double step;
    QBENCHMARK {
        step = A.getSampleTime();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && step == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::getNumberOfRowsDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    unsigned nRows;
    QBENCHMARK {
        nRows = A.getNumberOfRows();
    }
    QVERIFY2(nRows == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::getNumberOfColumnsDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    unsigned nColumns;
    QBENCHMARK {
        nColumns = A.getNumberOfColumns();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && nColumns == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::getNumberOfVariablesDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    unsigned variables;
    QBENCHMARK {
        variables = A.getNumberOfVariables();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(variables == 2, "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::getNumberOfInputsDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    unsigned nRows;
    QBENCHMARK {
        nRows = A.getNumberOfInputs();
    }
    QVERIFY2(nRows == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}
void TransferFunctionTest::getNumberOfOutputsDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    unsigned nColumns;
    QBENCHMARK {
        nColumns = A.getNumberOfOutputs();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && nColumns == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::getTimeSimulationDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1",0.2);
    double step;
    QBENCHMARK {
        step = A.getSampleTime();
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfOutputs() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && step == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
}

void TransferFunctionTest::setContinuousDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1");
    QBENCHMARK {
        A.setContinuous(false);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(!A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 'z', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
}

void TransferFunctionTest::setSampleTimeDouble ()
{
    ModelHandler::TransferFunction<double> A("1","1,2,1");
    QBENCHMARK {
        A.setSampleTime(0.2);
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.2, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
}

void TransferFunctionTest::operatorParenthesisDoubleCase1 ()
{
    ModelHandler::TransferFunction<double> B("1","1,2,1");
    PolynomHandler::Polynom<double> A = B(1,1);
    QBENCHMARK {
        PolynomHandler::Polynom<double> A = B(1,1);
    }
    QVERIFY2(A.getNumSize() == 1 && A.getDenSize() == 3, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.getVar() == 'x', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(A.getNum()(1,1) == 1 && A.getDen()(1,1) == 1 && A.getDen()(1,2) == 2 && A.getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
}

void TransferFunctionTest::operatorParenthesisDoubleCase2 ()
{
    PolynomHandler::Polynom<double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A(1,1) = B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase1()
{
    ModelHandler::TransferFunction<double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase2()
{
    ModelHandler::TransferFunction<double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A = B;
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase3()
{
    ModelHandler::TransferFunction<long double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A = B;
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase4()
{
    ModelHandler::TransferFunction<long double> B("1","1,2,1");
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}




void TransferFunctionTest::operatorAtributionDoubleCase5()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 1 && A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 1 && A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase6()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A = B;
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 1 && A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 1 && A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase7()
{
    PolynomHandler::Polynom<long double> C("1","1,2,1");
    ModelHandler::TransferFunction<long double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A = B;
    QBENCHMARK {
        ModelHandler::TransferFunction<double> A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 1 && A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 1 && A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorAtributionDoubleCase8()
{
    PolynomHandler::Polynom<long double> C("1","1,2,1");
    ModelHandler::TransferFunction<long double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 1 && A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 1 && A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSumAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A = C, B = C;
    QBENCHMARK {
        A = B;
        A += 2;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2 && A(1,1).getNum()(1,2) == 4 && A(1,1).getNum()(1,3) == 3,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSumAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A += 2;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2 && A(1,1).getNum()(1,2) == 4 && A(1,1).getNum()(1,3) == 3,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 2 && A(1,2).getNum()(1,2) == 4 && A(1,2).getNum()(1,3) == 3,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 2 && A(2,1).getNum()(1,2) == 4 && A(2,1).getNum()(1,3) == 3,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 2 && A(2,2).getNum()(1,2) == 4 && A(2,2).getNum()(1,3) == 3,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSumAccumulatorTFDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A, B("1","1,1");
    QBENCHMARK {
        A = C;
        A += B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getNum()(1,2) == 3 && A(1,1).getNum()(1,3) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSumAccumulatorTFDoubleCase2 ()
{
    PolynomHandler::Polynom<double> D("1","1,2,1"), E("1","1,1");
    ModelHandler::TransferFunction<double> B(2,2), C(2,2);
    B(1,1) = D; B(1,2) = D; B(2,1) = D; B(2,2) = D;
    C(1,1) = E; C(1,2) = E; C(2,1) = E; C(2,2) =E;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A += C;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getNum()(1,2) == 3 && A(1,1).getNum()(1,3) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 1 && A(1,2).getNum()(1,2) == 3 && A(1,2).getNum()(1,3) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 3 && A(1,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 1 && A(2,1).getNum()(1,2) == 3 && A(2,1).getNum()(1,3) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 3 && A(2,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 1 && A(2,2).getNum()(1,2) == 3 && A(2,2).getNum()(1,3) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 3 && A(2,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSubtractionAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A = C, B = C;
    QBENCHMARK {
        A = B;
        A -= 2;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == -2 && A(1,1).getNum()(1,2) == -4 && A(1,1).getNum()(1,3) == -1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSubtractionAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A -= 2;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == -2 && A(1,1).getNum()(1,2) == -4 && A(1,1).getNum()(1,3) == -1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == -2 && A(1,2).getNum()(1,2) == -4 && A(1,2).getNum()(1,3) == -1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == -2 && A(2,1).getNum()(1,2) == -4 && A(2,1).getNum()(1,3) == -1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == -2 && A(2,2).getNum()(1,2) == -4 && A(2,2).getNum()(1,3) == -1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSubtractionAccumulatorTFDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A, B("1","1,1");
    QBENCHMARK {
        A = C;
        A -= B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == -1 && A(1,1).getNum()(1,2) == -1 && A(1,1).getNum()(1,3) == 0,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorSubtractionAccumulatorTFDoubleCase2 ()
{
    PolynomHandler::Polynom<double> D("1","1,2,1"), E("1","1,1");
    ModelHandler::TransferFunction<double> B(2,2), C(2,2);
    B(1,1) = D; B(1,2) = D; B(2,1) = D; B(2,2) = D;
    C(1,1) = E; C(1,2) = E; C(2,1) = E; C(2,2) =E;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A -= C;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == -1 && A(1,1).getNum()(1,2) == -1 && A(1,1).getNum()(1,3) == 0,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == -1 && A(1,2).getNum()(1,2) == -1 && A(1,2).getNum()(1,3) == 0,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 3 && A(1,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == -1 && A(2,1).getNum()(1,2) == -1 && A(2,1).getNum()(1,3) == 0,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 3 && A(2,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == -1 && A(2,2).getNum()(1,2) == -1 && A(2,2).getNum()(1,3) == 0,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 3 && A(2,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorMultiplicationAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A = C, B = C;
    QBENCHMARK {
        A = B;
        A *= 2;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorMultiplicationAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A *= 2;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorMultiplicationAccumulatorTFDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A, B("1","1,1");
    QBENCHMARK {
        A = C;
        A *= B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorMultiplicationAccumulatorTFDoubleCase2 ()
{
    PolynomHandler::Polynom<double> D("1","1,2,1"), E("1","1,1");
    ModelHandler::TransferFunction<double> B(2,2), C(2,2);
    B(1,1) = D; B(1,2) = D; B(2,1) = D; B(2,2) = D;
    C(1,1) = E; C(1,2) = E; C(2,1) = E; C(2,2) =E;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A *= C;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 3 && A(1,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 3 && A(1,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 3 && A(2,1).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 3 && A(2,2).getDen()(1,3) == 3 && A(1,1).getDen()(1,4) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorDivisionAccumulatorScalarDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A = C, B = C;
    QBENCHMARK {
        A = B;
        A /= 0.5;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorDivisionAccumulatorScalarDoubleCase2 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> B(2,2);
    B(1,1) = C; B(1,2) = C; B(2,1) = C; B(2,2) = C;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A /= 0.5;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 1 && A(1,2).getDen()(1,2) == 2 && A(1,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 1 && A(2,1).getDen()(1,2) == 2 && A(2,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 2,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 1 && A(2,2).getDen()(1,2) == 2 && A(2,2).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorDivisionAccumulatorTFDoubleCase1 ()
{
    PolynomHandler::Polynom<double> C("1","1,2,1");
    ModelHandler::TransferFunction<double> A, B("1","1,1");
    QBENCHMARK {
        A = C;
        A /= B;
    }
    QVERIFY2(A.getNumberOfRows() == 1 && A.getNumberOfColumns() == 1, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == 1 && A(1,1).getNum()(1,2) == 1,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 1 && A(1,1).getDen()(1,2) == 2 && A(1,1).getDen()(1,3) == 1, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

void TransferFunctionTest::operatorDivisionAccumulatorTFDoubleCase2 ()
{
    PolynomHandler::Polynom<double> D("1","1,1"), E("1","1,1"), F("1","1,2"), G("1","1,3"), H("1","1,4");
    ModelHandler::TransferFunction<double> B(2,2), C(2,2);
    B(1,1) = D; B(1,2) = D; B(2,1) = D; B(2,2) = D;
    C(1,1) = E; C(1,2) = F; C(2,1) = G; C(2,2) = H;
    ModelHandler::TransferFunction<double> A;
    QBENCHMARK {
        A = B;
        A /= C;
    }
    QVERIFY2(A.getNumberOfRows() == 2 && A.getNumberOfColumns() == 2, "Falhou ao testar o tamanho da Funcao de transferencia");
    QVERIFY2(A.isContinuous() && A.getSampleTime() == 0.1, "Falhou ao verificar que a função e continua e ao verificar o periodo de amostragem");
    QVERIFY2(A(1,1).getNum()(1,1) == -2 && A(1,1).getNum()(1,2) == -22 && A(1,1).getNum()(1,3) == -90 && A(1,1).getNum()(1,4) == -170 && A(1,1).getNum()(1,5) == -148 && A(1,1).getNum()(1,6) == -48,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,1).getDen()(1,1) == 4  && A(1,1).getDen()(1,2) == 36  && A(1,1).getDen()(1,3) == 108 && A(1,1).getDen()(1,4) == 124  && A(1,1).getDen()(1,5) == 48, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(1,2).getNum()(1,1) == 2 && A(1,2).getNum()(1,2) == 22 && A(1,2).getNum()(1,3) == 90 && A(1,2).getNum()(1,4) == 170 && A(1,2).getNum()(1,5) == 148 && A(1,2).getNum()(1,6) == 48,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(1,2).getDen()(1,1) == 4  && A(1,2).getDen()(1,2) == 20  && A(1,2).getDen()(1,3) == 36 && A(1,2).getDen()(1,4) == 28  && A(1,2).getDen()(1,5) == 8, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,1).getNum()(1,1) == -2 && A(2,1).getNum()(1,2) == -22 && A(2,1).getNum()(1,3) == -90 && A(2,1).getNum()(1,4) == -170 && A(2,1).getNum()(1,5) == -148 && A(2,1).getNum()(1,6) == -48,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,1).getDen()(1,1) == 4  && A(2,1).getDen()(1,2) == 36  && A(2,1).getDen()(1,3) == 108 && A(2,1).getDen()(1,4) == 124  && A(2,1).getDen()(1,5) == 48, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A(2,2).getNum()(1,1) == 2 && A(2,2).getNum()(1,2) == 22 && A(2,2).getNum()(1,3) == 90 && A(2,2).getNum()(1,4) == 170 && A(2,2).getNum()(1,5) == 148 && A(2,2).getNum()(1,6) == 48,  "Falhou ao verificar os valores do numerador da funcao de transferencia");
    QVERIFY2(A(2,2).getDen()(1,1) == 4  && A(2,2).getDen()(1,2) == 20  && A(2,2).getDen()(1,3) == 36 && A(2,2).getDen()(1,4) == 28  && A(2,2).getDen()(1,5) == 8, "Falhou ao verificar os valores do denominador da funcao de transferencia");
    QVERIFY2(A.getVar() == 's', "Falhou ao verificar a variavel da funcao de transferencia");
    QVERIFY2(sizeof(A) == sizeof(ModelHandler::TransferFunction<double>), "Falhou ao comparar o tipo da funcao de transferencia");
}

QTEST_APPLESS_MAIN(TransferFunctionTest)

#include "tst_transferfunctiontest.moc"
