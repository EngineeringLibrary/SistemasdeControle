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

//    void setContinuous(const bool &continuous); //ok
//    void setSampleTime(const double &sampleTime);//ok
//    void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito
//    void setLinearModel (LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output); // não feito

//    PolynomHandler::Polynom<Type>& operator()(unsigned row, unsigned column); // ok
//    PolynomHandler::Polynom<Type>  operator()(unsigned row, unsigned column) const; // ok

//    void operator= (const PolynomHandler::Polynom<Type> &rhs);
//    TransferFunction<Type>& operator= (const TransferFunction<Type>& otherTransferFunction); //ok
//    template<typename OtherTransferFunctionType> // não funciona
//    TransferFunction<Type>& operator= (const TransferFunction<OtherTransferFunctionType>& otherTransferFunction);

//    TransferFunction<Type> operator+= (const Type& rhs /*scalar*/){ return TransferFunction<Type>(this->TF += rhs);} //testada
//    template<typename RightType> //testada
//    TransferFunction<Type> operator+= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF += rhs.TF);}

//    TransferFunction<Type> operator-= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF -= rhs);} // testada
//    template<typename RightType>
//    TransferFunction<Type> operator-= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF -= rhs.TF);}

//    TransferFunction<Type> operator*= (const Type& rhs /*scalar*/){return TransferFunction<Type>(this->TF *= rhs);} // testada
//    template<typename RightType>
//    TransferFunction<Type> operator*= (const TransferFunction<RightType>& rhs){return TransferFunction<Type>(this->TF *= rhs.TF);}

//    TransferFunction<Type> operator/= (const Type& rhs /*scalar*/){ //Definidos apenas para o caso monovariavel
//        if(this->TF.getNumberOfColumns() == 1 && this->TF.getNumberOfRows() == 1)
//            return TransferFunction<Type>(this->TF(1,1) /= rhs);
//    }
//    template<typename RightType>
//    TransferFunction<Type> operator/= (const TransferFunction<RightType>& rhs){ //Definidos apenas para o caso monovariavel
//        if(this->TF.getNumberOfColumns() == 1 && this->TF.getNumberOfRows() == 1)
//            return TransferFunction<Type>(this->TF(1,1) /= rhs.TF(1,1));
//    }


//    Type sim(Type input);
//    Type sim(Type x, Type y);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x);
//    LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y);
//    LinAlg::Matrix<Type> sim(Type lsim, Type lmax, Type step);

//    std::string ContinuosFirstOrderCaracteristics();
//    std::string ContinuosSecondOrderCaracteristics();

//    std::string print();
//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator+ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs += rhs;}
//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator+ (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return rhs += lhs;}
//    template<typename LeftType, typename RightType>
//    TransferFunction<LeftType> operator+ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs += rhs;}

//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator- (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs -= rhs;}
//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator- (const ScalarType& lhs, TransferFunction<PolynomType> rhs) {return -1*(rhs -= lhs);}
//    template<typename LeftType, typename RightType>
//    TransferFunction<LeftType> operator- (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs -= rhs;}

//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType>  operator* (TransferFunction<PolynomType>  lhs, const ScalarType& rhs) {return lhs *= rhs;}
//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType>  operator* (const ScalarType& lhs, TransferFunction<PolynomType>  rhs) {return rhs *= lhs;}
//    template<typename LeftType, typename RightType>
//    TransferFunction<LeftType> operator* (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs *= rhs;}

//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator/ (TransferFunction<PolynomType> lhs, const ScalarType& rhs) {return lhs /= rhs;}
//    template<typename PolynomType, typename ScalarType>
//    TransferFunction<PolynomType> operator/ (ScalarType rhs, TransferFunction<PolynomType> lhs) {return TransferFunction<PolynomType>(rhs) /= lhs;}
//    template<typename LeftType, typename RightType>
//    TransferFunction<LeftType> operator/ (TransferFunction<LeftType> lhs, const TransferFunction<RightType>& rhs) {return lhs /= rhs;}

//    template<typename Type> // ok
//    std::ostream& operator<< (std::ostream& output, ModelHandler::TransferFunction<Type> TF);
//    template<typename Type> //ok
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

QTEST_APPLESS_MAIN(TransferFunctionTest)

#include "tst_transferfunctiontest.moc"
