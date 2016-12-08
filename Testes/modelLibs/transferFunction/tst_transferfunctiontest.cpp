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
//    TransferFunction<Type> operator+= (const Type& rhs /*scalar*/){ return TransferFunction<Type>(this->TF += rhs);} //testada
//    TransferFunction<Type> operator+= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF += rhs.TF);}
//    TransferFunction<Type> operator-= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF -= rhs);} // testada
//    TransferFunction<Type> operator-= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF -= rhs.TF);}
//    TransferFunction<Type> operator*= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF *= rhs);} // testada
//    TransferFunction<Type> operator*= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF *= rhs.TF);}
//    TransferFunction<Type> operator/= (const Type& rhs /*scalar*/){ //Definidos apenas para o caso monovariavel
//    TransferFunction<Type> operator/= (const TransferFunction<RightType>& rhs)
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

QTEST_APPLESS_MAIN(TransferFunctionTest)

#include "tst_transferfunctiontest.moc"
