#ifndef STATESPACE_H
#define STATESPACE_H
#include <src/simulationLibs/model.h>
#include <src/simulationLibs/transferfunction.h>

//! Classe concreta de modelos para representar equações diferenciais em espaço de estados.

/*!
    O objetivo principal dessa classe é ser uma equação diferencial em espaço de estados, permitindo a sua simulação.

    \param Continuous Variável que quando setada em true permitirá que a equação diferencial esteja no domínio contínuo e quando setada em false, no domínio discreto.
    \param nDiscretization Variável que representa a precisão com a qual o sistema em espaço de estados será discretizado. A discretização do sistema é realizada utilizando série de Taylor e o nDiscretization representa quantos termos da série de taylor serão utilizados para transformar o sistema em espaço de estados de contínuo para discreto.
    \param SampleTime Variável que representa o período de amostragem que será utilizado para a discretização do sistema.
    \param TimeSimulation Essa variável representa a quantidade de tempo de simulação será utilizada na função sim.
    \param A Variável que representa a dinâmica dos polos do sistema. Ela está diretamente relacionada a estabilidade da equação.
    \param B Variável que representa o ganho do sinal de controle.
    \param C Variável que seleciona qual estado ou combinação de estados será apresentada na saída da equação diferencial.
    \param D Variável que está associada à transmissão direta de energia da entrada para a saída.
    \param Ad Variável que representa a dinâmica dos polos do sistema. Ela está diretamente relacionada a estabilidade da equação. Neste caso a variável está no domínio discreto.
    \param Bd Variável que representa o ganho do sinal de controle. Neste caso a variável está no domínio discreto.
    \param X  Variável que representa o estado atual da equação em espaço de estados.
    \param initialState Variável que representa o estado inicial do sistema em espaço de estados.

*/

template <class UsedType>
class StateSpace : public Model<UsedType>
{
private:
    bool Continuous;
    unsigned nDiscretization;
    UsedType SampleTime, TimeSimulation;
    Matrix<UsedType> A, B, C, D, Ad, Bd, X, initialState;

//! Método para calcular o fatorial de um número.

/*!
    Este método auxilia a função de discretização (que usa a expansão em série de taylor).

    Ver também: \sa c2dConversion(), c2d();
*/
    UsedType factorial(unsigned n);

//! Método para realizar a conversão de um sistema em espaço de estados na forma contínua para a forma discreta.

/*!
    Este método utiliza a expansão em série de taylor para encontrar e^At que é Ad e para encontrar Bd (Bd = (A^-1)*(Ad - (I))*B).

     Ver também: \sa d2cConversion();
*/


    void c2dConversion();

//! Método para realizar a conversão de um sistema em espaço de estados na forma discreta para a forma contínua.

/*!
    Este método utiliza uma transformação obtendo a matriz A, sabendo que ela foi obtida de Ad utilizando uma certa quantidade de termos da série de taylor. B = (((A^-1)*(Ad - I))^-1)*Bd;

     Ver também: \sa c2dConversion();
*/

    void d2cConversion();

public:

//! Construtor padrão da biblioteca de Equações diferenciais em espaço de estados.

/*!
    O construtor padrão da biblioteca de simulação inicializa o objeto StateSpace com um período de amostragem padrão de 0,1 e com os valores de A, B, C, e D dados pelo usuário. Inicializa também Contínuos como true, nDiscretization = 4, e TimeSimulation = 10.

    Ex1:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                StateSpace<double> SS(A,B,C,D);
                SS.print();
                return 0;
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
    Ex2:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                StateSpace<double> SS(A,B,C,D);
                Model<double> *model = &SS;
                model->print();
                return 0;
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
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                Model<double> *model = new StateSpace<double>(A,B,C,D);
                model->print();
                return 0;
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

    Ver também: \sa print(), sim();
*/
    StateSpace(Matrix<UsedType> A, Matrix<UsedType> B,
               Matrix<UsedType> C, Matrix<UsedType> D);

//! Método que imprime no prompt de comando o conteúdo de cada matriz (A,B,C,D).

/*!
    A responsabilidade deste método é apresentar os valores das matrizes da equação.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                StateSpace<double> SS(A,B,C,D);
                SS.print();
                return 0;
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

    Ver também: sim(UsedType u);
*/

    void print();

//! Método cujo objetivo é converter as equações em espaço de estados da forma contínua para a forma discreta.

/*!
    A responsabilidade deste método utilizar os métodos privados de conversão contínuo para discreto e converter as matrizes A e B para a forma discreta.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                StateSpace<double> SS(A,B,C,D);
                SS.print();
                SS.c2d(0.1);
                SS.print();
                return 0;
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


            Ad =
                1.105  0.000
               -0.200  0.905

            Bd =
                0.000
                0.095

            C =
                0.000  1.000


            D =
                0.000
        \endcode

    Ver também: \sa print(), getA(), getB(), getC(), getD();
*/

    void c2d(UsedType SampleTime);

//! Método cuja responsabilidade é receber uma matriz que representará o estado inicial para simulação do sistema em espaço de estados.

/*!
    A responsabilidade deste método é preparar o sistema para realizar a simulação, caso os estado iniciais não sejam nulos.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,X0,u;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                X0 = "0.2;1";
                u = "1,1,1,1,1,1,1,1,1,1,1,1,1";

                StateSpace<double> SS(A,B,C,D);
                SS.setInitialState(X0);
                SS.sim(u).print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            1.000  0.960  0.919  0.878  0.836  0.792  0.745  0.697  0.645  0.589  0.530  0.446  0.396
        \endcode

    Ver também: \sa print(), sim(Matrix<UsedType> u);
*/

    void setInitialState(Matrix<UsedType> X0);

//! Método cuja responsabilidade é retornar uma matriz contendo os valores da matriz A do espaço de estados.

/*!
    A responsabilidade deste método é retornar uma Matrix contendo os valores de A. Caso o sistema esteja no domínio discreto a matriz apresentada será Ad.

    Ex1:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.getA().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
                1.000  0.000
               -2.000 -1.000
        \endcode

    Ex2:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.c2d(0.1);
                SS.getA().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
                1.105  0.000
               -0.200  0.905
        \endcode

    Ver também: \sa print(), getB(), getC(), getD();
*/

    Matrix<UsedType> getA();

//! Método cuja responsabilidade é retornar uma matriz contendo os valores da matriz B do espaço de estados.

/*!
    A responsabilidade deste método é retornar uma Matrix contendo os valores de B. Caso o sistema esteja no domínio discreto será apresentado Bd.

    Ex1:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.getB().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
                0.000
                1.000
        \endcode

    Ex2:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,X0,u;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.c2d(0.1);
                SS.getB().print();
                return 0;
            }

        \endcode

    Resultado:

        \code
            0.000
            0.095
        \endcode

    Ver também: \sa print(), getA(), getC(), getD();
*/

    Matrix<UsedType> getB();

//! Método cuja responsabilidade é retornar uma matriz contendo os valores da matriz C do espaço de estados.

/*!
    A responsabilidade deste método é retornar uma Matrix contendo os valores de C. Este método independe do sistema estar no domínio contínuo ou discreto.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.getC().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  1.000
        \endcode

    Ver também: \sa print(), getA(), getB(), getD();
*/

    Matrix<UsedType> getC();

//! Método cuja responsabilidade é retornar uma matriz com os valores atuais do estado calculados na função sim.

/*!
    A responsabilidade deste método é retornar a Matrix X. A cada iteração uma matriz X de estados é calculada, e, a partir dela são obtidas as saídas da equação.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,X0;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                X0 = "0;0";
                StateSpace<double> SS(A,B,C,D);
                SS.setInitialState(X0);
                SS.getActualState().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000
            0.000
        \endcode

    Ver também: \sa print();
*/

    Matrix<UsedType> getActualState();

//! Método cuja responsabilidade é retornar uma matriz contendo os valores da matriz D do espaço de estados.

/*!
    A responsabilidade deste método é retornar uma Matrix contendo os valores de D. Este método independe do sistema estar no domínio contínuo ou discreto.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.getD().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  1.000
        \endcode

    Ver também: \sa print(), getA(), getB(), getC();
*/

    Matrix<UsedType> getD();

//! Método cuja responsabilidade é simular os valores futuros da saída da equação diferencial.

/*!
    A responsabilidade deste método é retornar um escalar com o valor correspondente a simulação da equação diferencial.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);

                for(int i = 0; i < 10; i++)
                {
                    std::cout << SS.sim(1) << std::endl;
                    SS.setInitialState(SS.getActualState());
                }
                return 0;
            }
        \endcode

    Resultado:

        \code
            0
            0.0951667
            0.181277
            0.259192
            0.329692
            0.393483
            0.451203
            0.50343
            0.550687
            0.593447
        \endcode

    Ver também: \sa print();
*/

    UsedType sim(UsedType u);

//! Método não implementado

    UsedType sim(UsedType u, UsedType y);

//! Método cuja responsabilidade é simular os valores futuros da saída da equação diferencial.

/*!
    A responsabilidade deste método é receber uma matriz (como sinal de entrada da equação diferncial) e retornar uma matriz com a resposta do sistema para aquele conjunto de entradas determinadas.

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,X0,u;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";
                X0 = "0;0";
                u = "1,1,1,1,1,1,1,1,1,1,1,1";
                StateSpace<double> SS(A,B,C,D);
                SS.setInitialState(X0);
                SS.sim(u).print();
                return 0;
            }
        \endcode

    Resultado:

        \code
           0.000  0.095  0.181  0.259  0.330  0.393  0.451  0.503  0.551  0.593  0.632  0.667
        \endcode

    Ver também: \sa print();
*/

    Matrix<UsedType> sim(Matrix<UsedType> u);

//! Método não implementado

    Matrix<UsedType> sim(Matrix<UsedType> u, Matrix<UsedType> y);

//! Método cuja responsabilidade é simular os valores futuros da saída da equação diferencial.

/*!
    A responsabilidade deste método é simular a equação diferencial a partir de um sinal de entrada contido em um dado intervalo. Em que:

    \param lmin é o limite mínimo da entrada da equação diferencial
    \param lmax é o limite máximo da entrada da equação diferencial
    \param step é o valor incremental da entrada da equação diferencial

    Ex:

        \code
            #include <src/simulationLibs/statespace.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D;
                A = "1,0;-2,-1";
                B = "0;1";
                C = "0,1";
                D = "0";

                StateSpace<double> SS(A,B,C,D);
                SS.sim(0,5,1).print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            0.000  0.000  0.095  0.276  0.536  0.865
        \endcode

    Ver também: \sa print();
*/

    Matrix<UsedType> sim(UsedType lmim, UsedType lmax, UsedType step);
};

#endif // STATESPACE_H
