#ifndef ARX_H
#define ARX_H
#include <src/simulationLibs/model.h>
//! Classe concreta para os modelos ARX (Modelos AutoRecursivos com entradas exógenas).

/*!
    Há diversas formas de representar modelos lineares. Uma das mais utilizadas é a forma de funções de transferência definida como a transformada da resposta ao impulso do sistema modelado, para condições iniciais nulas. Se a resposta ao impulso for contínua no tempo, então, utiliza-se a transformada de Laplace. Se a resposta ao impulso for discreta no tempo, a respectiva função de transferência é, por definição, a transformada Z (Aguirre, 2007).

Nas representações a seguir definiremos  \f$ A(z^{-1}) \f$, \f$ B(z^{-1}) \f$ conforme as equações 1 e 2 respectivamente.


    \f$ A(z^{-1})= 1 + a_1z^-1 + a_2z^{-2} +  ... + a_{n_a}z^{-n_a} \f$          1

    \f$ B(z^{-1})= 1 + b_1z^-1 + b_2z^{-2} +  ... + b_{n_b}z^{-n_b} \f$          2


Isto significa que os polinômios \f$ A(z^{-1}) \f$ e \f$ B(z^{-1}) \f$ representam sistemas discretos no tempo. Sendo eles polinômios arbitrários, o modelo ARX assume a forma da equação 3.

    \f$ y(k)=\frac{B(z^{-1})}{A(z^{-1})}u(k)+\frac{1}{A(z^{-1})}v(k) \f$         3

    Em que:

    @param y(k) É o sinal de saída, calculado pelo do modelo matemático
    @param u(k) É o sinal de entrada, que significa uma força externa a um sistema físico qualquer.
    @param v(k) É um ruído branco com média nula (Ruído branco gaussiano).

O modelo ARX (AutoRegressive with eXogenous inputs) apresentado no diagrama de blocos da figura 1, pode ser obtido a partir de um modelo polinomial linear mais geral de entradas e saídas resultando na equação 3 (Aguirre, 2007).

\image html Arx.jpg
\f$ Diagrama de Blocos do Modelo ARX. Fonte: Isermann (2011). \f$


Para o caso multivariável, podemos representar o modelo ARX conforme a seguinte equação na forma vetorial.

    \f$ Y(k) = \left [ \begin{matrix} y_1(k) \\ y_2(k) \\ \vdots \\ y_{qo}(k) \end{matrix}\right ] = \Theta \Phi = \left [ \begin{matrix} \theta_{1,1} & \cdots & \theta_{1,qo\,ny + qi\,nu -1} \\ \vdots & \ddots & \vdots \\ \theta_{qo,1} & \cdots & \theta_{qo,qo\,ny + qi\,nu -1} \end{matrix} \right ]\left [ \begin{matrix} y_1(k-1) \\ \vdots \\ y_1(k-ny) \\ \vdots \\ y_{qo}(k-1) \\ \vdots \\ y_{qo}(k-ny) \\ u_1(k-1-d) \\ \vdots \\ u_1(k-nu-d) \\ _{qi}(k-1-d) \\ \vdots \\ u_{qi}(k-nu-d) \end{matrix} \right ] \f$   Equação 4

    Em que:

    \param nu Na classe é representado por:
    @param nInputpar    Ou seja, o número de atrasos nas entradas do sistema.
    \param ny Na classe é representado por:
    @param nOutputpar   Ou seja, o número de atrasos nas saídas do sistema.
    \param d  Na classe é representado por:
    @param delay        Ou seja, o número de atrasos de transporte do sistema.
    \param qi Na classe é representado por:
    @param qdtInputVar  Ou seja, o número entradas aplicadas no sistema.
    \param qo Na classe é representado por:
    @param qdtOutputVar Ou seja, o número de saídas do sistema.

    Como é possível perceber, o objetivo desta classe é "ser" um modelo ARX, ou seja, os cálculos e estruturas aqui calculadas seguirão o padrão do modelo da equação 4. Para isso, são definidas, ainda as seguintes variáveis:

    \param maxnInOut É uma variável para cuidar do tamanho do vetor \f$\Phi\f$, para que não seja ultrapassada a quantidade de dados armazenados na memória do computador.
    \param nSample É o período de amostragem do sistema.

 */

template <class UsedType>
class ARX : public Model<UsedType>
{
private:
    unsigned nInputpar  , nOutputpar  , delay,
             qdtInputVar, qdtOutputVar, nSample,
             maxnInOut;
public:

//! Construtor da biblioteca de modelos ARX.

/*!
    O construtor da biblioteca de modelos ARX faz parte do bloco de classes que herdam de Model. Nele, todas as variáveis são setadas como mostrado a seguir:

    \param maxnInOut                   É inicializado com o maior valor entre o número de atrasos na entrada e o número de atrasos na saída.
    \param nInputpar                   É inicializado com os parâmetros setados pelo usuário.
    \param nOutputpar                  É inicializado com os parâmetros setados pelo usuário.
    \param delay                       É inicializado com os parâmetros setados pelo usuário. Caso não seja setado pelo usuário o seu valor será automaticamente iniciado com 0 (zero).
    \param qdtInputVar                 É inicializado com os parâmetros setados pelo usuário. Caso não seja setado pelo usuário o seu valor será automaticamente iniciado com 1 (um).
    \param qdtOutputVar                É inicializado com os parâmetros setados pelo usuário. Caso não seja setado pelo usuário o seu valor será automaticamente iniciado com 1 (um).
    \param Input     (da classe model) É inicializado com zeros, em que Input será uma matriz de nInputpar linhas e qdtInputVar colunas.
    \param Output    (da classe model) É inicializado com zeros, em que Output será uma matriz de nOutputpar linhas e qdtOutputVar colunas.
    \param EstOutput (da classe model) É inicializado com zeros e o mesmo tamanho de Output.
    \param nSample                     É inicializado com o valor de delay + maxnInOut + 1.

    \f$ Ex_1 \f$:

        \code
            #include "src/simulationLibs/model.h"
            #include <src/simulationLibs/arx.h>

            int main(int argc, char *argv)
            {
                Matrix<double> In, syspar;
                In = "1,1,1,1,1,1,1,1,1,1";
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                ARX<double> gz(2,2); // Construtor recebendo 2 parâmetros

                gz.setModelCoef(syspar);
                gz.sim(~In).print();
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
            0.191
            0.228
        \endcode

    \f$ Ex_2 \f$:

        \code
            #include "src/simulationLibs/model.h"
            #include <src/simulationLibs/arx.h>

            int main(int argc, char *argv)
            {
                Matrix<double> In, syspar;
                In = "1,1,1,1,1,1,1,1,1,1";
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                Model<double> *gz = new ARX<double>(2,2); // Construtor recebendo 2 parâmetros

                gz->setModelCoef(syspar);
                gz->sim(~In).print();
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
            0.191
            0.228
        \endcode

    Ver também: \sa setModelCoef(), sim(), Matrix, Model, print();
*/

    ARX(unsigned nInputpar , unsigned nOutputpar,
        unsigned delay = 0,
        unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1);

//! Método cuja responsabilidade é montar uma linha do sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear (No caso os modelos ARX, ARMAX, AR, MA, ARMA, FIR). Essa montagem será importante para as bibliotecas de otimização e possíveis simulações externas.

    Para esse caso específico a linha do sistema linear é montada utilizando as estimativas e não os dados inseridos em Output.

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
                Model<double> *model = &gz;
                model->setLinearVectorPhiEstimation();
                model->getLinearVectorPhi().print();

                    return 0;
            }
        \endcode

    Resultado:

        \code
            -0.000  -0.000  0.000  0.000
         \endcode

    Ver também: sim(), setLinearModel(), Matrix, print(), getLinearVectorPhi();

*/
    void setLinearVectorPhiEstimation();

//! Método cuja responsabilidade é montar uma linha do sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear (No caso os modelos ARX, ARMAX, AR, MA, ARMA, FIR). Essa montagem será importante para as bibliotecas de otimização e possíveis simulações externas.

    Para esse caso específico a linha do sistema linear é montada utilizando os valores reais e não os dados estimados e que são colocados na matriz EstOutput.

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
                Model<double> *model = &gz;
                model->setLinearVectorPhi();
                model->getLinearVectorPhi().print();

                    return 0;
            }
        \endcode

    Resultado:

        \code
            -0.000  -0.000  0.000  0.000
         \endcode

    Ver também: sim(), setLinearModel(), Matrix, print(), getLinearVectorPhi();

*/

    void setLinearVectorPhi();

//! Método cuja responsabilidade é montar o sistema linear AX = b.

/*!
    Algumas classes que herdam de model possuem uma implementação para montar um sistema linear (No caso os modelos ARX, ARMAX, AR, MA, ARMA, FIR). Essa montagem será importante para as bibliotecas de otimização e possíveis simulações externas.

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

    void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output);

//! Método cuja responsabilidade é simular os valores futuros da saída de um modelo.

/*!
    A responsabilidade deste método é retornar um escalar com o valor correspondente a simulação de um modelo ARX.

    Ex:

        \code
            #include "src/simulationLibs/model.h"
            #include <src/simulationLibs/arx.h>

            int main(int argc, char *argv)
            {
                Matrix<double> syspar;
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                Model<double> *gz = new ARX<double>(2,2); // Construtor recebendo 2 parâmetros

                gz->setModelCoef(syspar);
                gz->sim(10).print();
            }
        \endcode

    Resultado:
        \code
            0.000
        \endcode

    Ver também: \sa setModelCoef(), sim(), Matrix, Model, print();
*/

    UsedType sim(UsedType input);

//! Método cuja responsabilidade é simular os valores futuros da saída de um modelo a partir de duas entradas de dados, o Input (entrada exógena) e o Output (saída passada).

/*!
    A responsabilidade deste método é retornar um escalar com o valor correspondente a simulação de um modelo ARX.

    Ex:

        \code
            #include "src/simulationLibs/model.h"
            #include <src/simulationLibs/arx.h>

            int main(int argc, char *argv)
            {
                Matrix<double> syspar;
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                Model<double> *gz = new ARX<double>(2,2); // Construtor recebendo 2 parâmetros

                gz->setModelCoef(syspar);

                double temp = 0;
                for(int i = 1; i < 10; i++)
                {
                    temp = gz->sim(1,temp);
                    printf("%10.3f  \n", temp);
                }
                return 0;
            }
        \endcode

    Resultado:
        \code
            0.005
            0.018
            0.037
            0.062
            0.090
            0.122
            0.156
            0.191
            0.228
        \endcode

    Ver também: \sa setModelCoef(), sim(), Matrix, Model, print();
*/

    UsedType sim(UsedType input, UsedType output);

//! Método cuja responsabilidade é simular os valores futuros da saída do modelo ARX.

/*!
    A responsabilidade deste método é receber uma matriz (como sinal de entrada do modelo) e retornar uma matriz com a resposta do sistema para aquele conjunto de entradas determinadas.

    Ex:

        \code
            #include <src/simulationLibs/arx.h>

            int main(int argc, char *argv)
            {
                Matrix<double> U, syspar;
                U = "1;1;1;1;1;1;1;1;1;1";
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                ARX<double> gz(2,2); // Construtor recebendo 2 parâmetros

                gz.setModelCoef(syspar);
                gz.sim(U).print();

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
            0.191
            0.228
        \endcode

    Ver também: \sa print();
*/


    Matrix<UsedType> sim(Matrix<UsedType> x);
    //! Método não implementado
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    //! Método não implementado
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARX_H
