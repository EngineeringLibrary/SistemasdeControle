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

//! Construtor padrão da biblioteca modelos matemáticos.

/*!
    O construtor padrão da biblioteca de simulação permite que um objeto do tipo Model seja construído.

    Ex1:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                Model<double> *model;
                TransferFunction<double> TF("0,1","1,2,1",1,1);
                model = &TF;
                model->print();
            }
        \endcode

    Resultado:

        \code

                  +2
             -------------
              s^2 + 2s + 1

         \endcode

    Ex2:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Model<double> *model;
                Matrix<double> A,B,C,D;
                               A = "1,0;-2,-1";
                               B = "0;1";
                               C = "0,1";
                               D = "0";
                StateSpace<double> SS(A,B,C,D);

                model = &SS;
                model->print();
            }
        \endcode

    Resultado:

        \code
            A =
                1.000  0.000
               -2.000 -1.000

            B =
                0.000
                1.000

            C =
                0.000  1.000


            D =
                0.000
        \endcode


    Ex3:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/simfunction.h>

            double funcaoMatematica(double x)
            {
                return pow(x,2)*exp(4*x+5)*(cos(3*x) + sin(3*x));
            }

            int main(int argc, char *argv)
            {
                Model<double> *model;
                simFunction<double> F(funcaoMatematica);

                model = &F;
                model->sim(0,M_PI/10,M_PI/15).print();
            }
        \endcode

    Resultado:

        \code
            0.000
            21.016
        \endcode

    Ver também: \sa print();
*/

    Model();

//! Método que realiza a derivada de uma função de maneira numérica

/*!
    A responsabilidade deste método é retornar a derivada do modelo instanciado.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/simfunction.h>

            double funcaoMatematica(double x)
            {
                return pow(x,2)*exp(4*x+5)*(cos(3*x) + sin(3*x));
            }

            int main(int argc, char *argv)
            {
                Model<double> *model;
                simFunction<double> F(funcaoMatematica);

                model = &F;
                model->setStep(1e-10);
                model->setInstance(model);
                std::cout << model->diff(1) << std::endl;
            }
        \endcode

    Resultado:

        \code
            -68767.4
         \endcode

    Ver também: sim(), setInstance(), setStep();
*/

    UsedType diff(UsedType x);

//! Método que insere na variável step um valor determinado.

/*!
    A variável step tem duas responsabilidades, a primeira é ser o passo para a geração de pontos na simulação e a segunda é ser o passo de derivação e integração.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/simfunction.h>

            double funcaoMatematica(double x)
            {
                return pow(x,2)*exp(4*x+5)*(cos(3*x) + sin(3*x));
            }

            int main(int argc, char *argv)
            {
                Model<double> *model;
                simFunction<double> F(funcaoMatematica);

                model = &F;
                model->setStep(1e-10);
                model->setInstance(model);
                std::cout << model->diff(1) << std::endl;
            }
        \endcode

    Resultado:

        \code
            -68767.4
         \endcode

    Ver também: sim(), setInstance(), diff();
*/

    void setStep(UsedType step);

//! Método que insere na variável instance uma instância do objeto do tipo model

/*!
    Método que insere na variável instance uma instância do objeto do tipo model, ou um ponteiro de um objeto que herde de model.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/simfunction.h>

            double funcaoMatematica(double x)
            {
                return pow(x,2)*exp(4*x+5)*(cos(3*x) + sin(3*x));
            }

            int main(int argc, char *argv)
            {
                Model<double> *model;
                simFunction<double> F(funcaoMatematica);

                model = &F;
                model->setStep(1e-10);
                model->setInstance(model);
                std::cout << model->diff(1) << std::endl;
            }
        \endcode

    Resultado:

        \code
            -68767.4
         \endcode

    Ver também: sim(), setStep();, diff();
*/

    void setInstance(Model<UsedType> *m);

//! Método que insere na variável ModelCoef os coeficientes do modelo que será simulado.

/*!
    ModelCoef é uma variável utilizada em algums modelos que herdam de model. Devido a sua grande aplicação e a necessidade de simular modelos de forma simples esta variável foi adicionada em model e não nas implementações particulares.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            #include <src/simulationLibs/arx.h>
            #include <src/optimizationLibs/leastsquare.h>
            #include <src/simulationLibs/conversions.h>

            using namespace conversions;

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u.randU(1,5);
                StateSpace<double> SS(A,B,C,D,0.1);
                SS.sim(u).print();

                ARX<double> gz(2,2);
                gz.setLinearModel(~u,~SS.sim(u));
                Optimization<double> *LS = new LeastSquare<double>(&gz);
                LS->Optimize();
                LS->getOptimizatedVariable().print();

                Model<double> *model = new ARX<double>(2,2);
                model->setModelCoef(LS->getOptimizatedVariable());
                model->sim(~u).print();

                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  0.002  0.007  0.015  0.024

            -1.810
             0.819
             0.005
             0.004

             0.000
             0.002
             0.007
             0.015
             0.024
         \endcode

    Ver também: sim(), setStep();, diff();
*/

    void setModelCoef(Matrix<UsedType> coef);

//! Método que insere nas variáveis Input e Output os valores de entrada e saída de um modelo, ou função.

/*!
    A responsabilidade deste método é permitir a alteração dos valores de entradas e saídas fora da função de simulação (sim()).

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u = "1,1,1,1,1,1,1,1";
                Model<double> *model = new StateSpace<double>(A,B,C,D,0.1);

                model->setIO(~u,~model->sim(u));
                model->getInputMatrix().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
         \endcode

    Ver também: sim(), setStep(), getInputMatrix(), getOutputMatrix();
*/

    void setIO(Matrix<UsedType> in, Matrix<UsedType> out);

//! Método que retorna a variável ModelCoef, os coeficientes do modelo.

/*!
    ModelCoef é uma variável utilizada em algums modelos que herdam de model. Devido a sua grande aplicação e a necessidade de simular modelos de forma simples esta variável foi adicionada em model e não nas implementações particulares.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            #include <src/simulationLibs/arx.h>
            #include <src/optimizationLibs/leastsquare.h>
            #include <src/simulationLibs/conversions.h>

            using namespace conversions;

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u.randU(1,5);
                StateSpace<double> SS(A,B,C,D,0.1);
                SS.sim(u).print();

                ARX<double> gz(2,2);
                gz.setLinearModel(~u,~SS.sim(u));
                Optimization<double> *LS = new LeastSquare<double>(&gz);
                LS->Optimize();
                LS->getOptimizatedVariable().print();

                Model<double> *model = new ARX<double>(2,2);
                model->setModelCoef(LS->getOptimizatedVariable());
                model->sim(~u).print();

                model->getModelCoef().print();

                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  0.002  0.007  0.015  0.024

            -1.810
             0.819
             0.005
             0.004

             0.000
             0.002
             0.007
             0.015
             0.024

            -1.810
             0.819
             0.005
             0.004

         \endcode

    Ver também: sim(), setStep(), setModelCoef(), diff();
*/

    Matrix<UsedType> getModelCoef();

//! Método que retorna as variável Input os valores de entrada do um modelo, ou função.

/*!
    A responsabilidade deste método é permitir que o usuário tenha acesso aos valores de entradas externamente ao objeto.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u = "1,1,1,1,1,1,1,1";
                Model<double> *model = new StateSpace<double>(A,B,C,D,0.1);

                model->setIO(~u,~model->sim(u));
                model->getInputMatrix().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
            1.000
         \endcode

    Ver também: sim(), setStep(), setIO();, getOutputMatrix();
*/


    Matrix<UsedType> getInputMatrix();

//! Método que retorna a variável output, o valore de saída do modelo, ou função.

/*!
    A responsabilidade deste método é permitir que o usuário tenha acesso ao valor imediato de saida externamente ao objeto.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u = "1,1,1,1,1,1,1,1";
                Model<double> *model = new StateSpace<double>(A,B,C,D,0.1);

                model->sim(u(1,1));
                std::cout << model->getOutput();

                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000
            0.005
            0.018
            0.037
            0.062
            0.090
            0.122
            0.156
         \endcode

    Ver também: sim(), setStep(), setIO();, getOutputMatrix();
*/

    UsedType getOutput();

//! Método que retorna a variável Output, os valores de saída do um modelo, ou função.

/*!
    A responsabilidade deste método é permitir que o usuário tenha acesso aos valores de saida externamente ao objeto.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1.81,-0.8187;1,0";
                B = "0.125;0";
                C = "0.03743,0.03502";
                D = "0";
                u = "1,1,1,1,1,1,1,1";
                Model<double> *model = new StateSpace<double>(A,B,C,D,0.1);

                model->setIO(~u,~model->sim(u));
                model->getOutputMatrix().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000
            0.005
            0.018
            0.037
            0.062
            0.090
            0.122
            0.156
         \endcode

    Ver também: sim(), setStep(), setIO();, getOutputMatrix();
*/

    Matrix<UsedType> getOutputMatrix();

//! Método cuja responsabilidade é retornar a Matrix A do sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear. Essa montagem será importante para as bibliotecas de otimização.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            #include <src/simulationLibs/arx.h>
            #include <src/optimizationLibs/leastsquare.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "-2,-1;1,0";
                B = "1;0";  C = "0,1";  D = "0";
                u = "1,1,1,1";
                StateSpace<double> SS(A,B,C,D);

                ARX<double> gz(2,2);
                gz.setLinearModel(~u,~SS.sim(u));
                Model<double> *model = &gz;

                model->getLinearMatrixA().print();

                return 0;
            }
        \endcode

    Resultado:

        \code
            -0.000  -0.000  0.000  0.000
            -0.000  -0.000  1.000  0.000
            -0.005  -0.000  1.000  1.000
            -0.018  -0.005  1.000  1.000
         \endcode

    Ver também: sim(), setStep(), setIO(), getOutputMatrix();
*/

    Matrix<UsedType> getLinearMatrixA();

//! Método cuja responsabilidade é retornar a Matrix b do sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear. Essa montagem será importante para as bibliotecas de otimização.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            #include <src/simulationLibs/arx.h>
            #include <src/optimizationLibs/leastsquare.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "-2,-1;1,0";
                B = "1;0";  C = "0,1";  D = "0";
                u = "1,1,1,1";
                StateSpace<double> SS(A,B,C,D);

                ARX<double> gz(2,2);
                gz.setLinearModel(~u,~SS.sim(u));
                Model<double> *model = &gz;

                model->getLinearEqualityB().print();

                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000
            0.005
            0.018
            0.037
         \endcode

    Ver também: sim(), setStep(), setIO(), getOutputMatrix();
*/

    Matrix<UsedType> getLinearEqualityB();

//! Método cuja responsabilidade é retornar uma linha da Matrix A do sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear. Essa montagem será importante para as bibliotecas de otimização. Neste caso, com apenas uma linha do sistema é possível utilizar algoritmos de otimização online.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            #include <src/simulationLibs/arx.h>
            #include <src/optimizationLibs/leastsquare.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "-2,-1;1,0";
                B = "1;0";  C = "0,1";  D = "0";
                u = "1,1,1,1";
                StateSpace<double> SS(A,B,C,D);

                ARX<double> gz(2,2);
                gz.setLinearVectorPhi();
                Model<double> *model = &gz;

                model->getLinearVectorPhi().print();

                return 0;
            }
        \endcode

    Resultado:

        \code
            -0.000  -0.000  0.000  0.000
         \endcode

    Ver também: sim(), setStep(), setIO(), getOutputMatrix();
*/

    Matrix<UsedType> getLinearVectorPhi();

//! Método cuja responsabilidade é simular os valores futuros da saída de um modelo.

/*!
    A responsabilidade deste método é retornar um escalar com o valor correspondente a simulação de um modelo qualquer. Devido a abstração, independentemente do tipo de modelo matemático utilizado a simulação será realizada da mesma maneira.

    Ex:

        \code
            #include <src/simulationLibs/model.h>
            #include <src/simulationLibs/statespace.h>

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";  C = "0,1";  D = "0";

                Model<double> *model = new StateSpace<double>(A,B,C,D);
                std::cout << model->sim(1) << std::endl;

                return 0;
            }
        \endcode

    Resultado:

        \code
            0
        \endcode

    Ver também: \sa print();
*/

    virtual UsedType         sim(UsedType x) = 0;

//! Método não implementado

    virtual UsedType         sim(UsedType x, UsedType y) = 0;

//! Método cuja responsabilidade é simular os valores futuros da saída do modelo.

/*!
    A responsabilidade deste método é receber uma matriz (como sinal de entrada do modelo) e retornar uma matriz com a resposta do sistema para aquele conjunto de entradas determinadas.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "1,0;-2,-1";
                B = "0;1";  C = "0,1";  D = "0";
                u = "1,1,1,1,1,1,1,1,1,1,1,1";
                Model<double> *model = new StateSpace<double>(A,B,C,D);

                model->sim(u).print();

                return 0;
            }
        \endcode

    Resultado:

        \code
           0.000  0.095  0.181  0.259  0.330  0.393  0.451  0.503  0.551  0.593  0.632  0.667
        \endcode

    Ver também: \sa print();
*/

    virtual Matrix<UsedType> sim(Matrix<UsedType> x) = 0;

//! Método não implementado

    virtual Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y) = 0;

//! Método cuja responsabilidade é simular os valores futuros da saída do modelo.

/*!
    A responsabilidade deste método é simularum modelo a partir de um sinal de entrada contido em um dado intervalo. Em que:

    \param lmin é o limite mínimo da entrada
    \param lmax é o limite máximo da entrada
    \param step é o valor incremental da entrada

    Ex:

        \code
            #include "src/simulationLibs/model.h"
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";  C = "0,1";  D = "0";

                Model<double> *model = new StateSpace<double>(A,B,C,D);
                model->sim(0,5,1).print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  0.000  0.095  0.276  0.536  0.865
        \endcode

    Ver também: \sa print();
*/

    virtual Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step) = 0;

};

#endif // MODEL_H
