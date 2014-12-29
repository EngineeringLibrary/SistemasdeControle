#ifndef MODEL_H
#define MODEL_H
#include <cfloat>
#include "src/primitiveLibs/matrix.h"

//! Classe abstrata que tratam todos os modelos matemáticos.

/*!
    O objetivo principal dessa classe é ser uma abstração para tratar e simular modelos matemáticos (redes neurais, arx, armax, carima, espaço de estados, função de transferência, fuzzy, e etc.). A funcionalidade desta classe é inquestionável quando percebemos que precisamos simular, prever, derivar, obter um sistema linear (linearizar) dos modelos. Por isso, ter uma classe que integre e abstraia essas funcionalidades facilitará a implementação e, também, a desacoplará.

    \param *instance É uma instância do próprio objeto do tipo Model. Ele permite que, por exemplo, seja possível obter a derivada dos modelos sem precisar saber qual a sua implementação concreta.
    \param input É uma variável de memória que armazena a entrada fornecida pelo usuário.
    \param output É uma variável de memória que armazena a saida fornecida pela simulação, realizada pelo objeto concreto.
    \param lmin É o mínimo valor de entrada que será aplicada no modelo matemático com o objetivo de se obter uma saída.
    \param lmax É o máximo valor de entrada que será aplicada no modelo matemático com o objetivo de se obter uma saída.
    \param step É o incremento da entrada que será utilizado na simulação e obtenção de valores futuros das equações e modelos.
    \param Input É uma Matrix que armazena uma sequencia de entradas que será aplicada no modelo (fornecida pelo usuário).
    \param Output É uma Matrix que armazena uma sequencia de saídas que serão obtidas do modelo (fornecida pelo usuário). Estas saídas são comparadas com as saídas estimadas EstOutput para se obter o erro de estimação.
    \param EstOutput É uma Matrix que armazena uma sequencia de saídas que são resultado da aplicação de uma sequância de entradas no modelo.
    \param ModelCoef É uma Matrix que armazena os coeficientes do modelo matemático que será utilizado.
    \param LinearVectorPhi Um sistema linear é dado pela seguinte equação: AX = b. Esta variável representa uma linha da Matrix A e pode ser utilizada para se obter estimatidas em algoritmos recursivos, por exemplo.
    \param LinearMatrixA Um sistema linear é dado pela seguinte equação: AX = b. Esta variável representa a variável A do sistema linear.
    \param LinearEqualityB Um sistema linear é dado pela seguinte equação: AX = b. Esta variável representa a variável b do sistema linear.

*/


template <class UsedType>
class Model
{
protected:
    Model<UsedType> *instance;
    UsedType         input,output,    lmin,lmax,     step;
    Matrix<UsedType> Input,Output,    EstOutput,     ModelCoef,
                     LinearVectorPhi, LinearMatrixA, LinearEqualityB;
public:
    Model();
    UsedType diff(UsedType x);
    void setStep(UsedType step);
    void setInstance(Model<UsedType> *m);
    void setModelCoef(Matrix<UsedType> coef);
    void setIO(Matrix<UsedType> in, Matrix<UsedType> out);

    Matrix<UsedType> getModelCoef();
    Matrix<UsedType> getInputMatrix();
    UsedType getOutput();
    Matrix<UsedType> getOutputMatrix();
    Matrix<UsedType> getLinearMatrixA();
    Matrix<UsedType> getLinearEqualityB();
    Matrix<UsedType> getLinearVectorPhi();

    virtual UsedType         sim(UsedType x) = 0;
    virtual UsedType         sim(UsedType x, UsedType y) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x) = 0;
    virtual Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y) = 0;
    virtual Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

};

#endif // MODEL_H
