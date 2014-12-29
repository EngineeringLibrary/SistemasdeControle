#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <src/simulationLibs/model.h>
#include <src/primitiveLibs/polynom.h>

//! Classe concreta de modelos para representar equações diferenciais na forma discreta e contínua (domínio de Laplace e Z).

/*!
    O objetivo principal dessa classe é ser uma equação diferencial, permitindo a sua simulação e utilização em outros componentes.

    \param isContinuous Variável que quando setada em true permitirá que a equação diferencial esteja no domínio contínuo e quando setada em false, no domínio discreto.
    \param sampleTime Variável que representa o período de amostragem que será utilizado para a discretização do sistema.
    \param timeSimulation Essa variável representa a quantidade de tempo de simulação será utilizada na função sim.
    \param nRowsTF Essa variável indica quantas linhas de polinômios existem na matriz de polinômios (cada polinômio representa uma equação diferencial).
    \param nColsTF Essa variável indica quantas colunas de polinômios existem na matriz de polinômios (cada polinômio representa uma equação diferencial).
    \param TF Essa variável armazena os polinômios que serão utilizados como equações diferenciais.

*/


template <class UsedType>
class TransferFunction : public Model<UsedType>
{
private:
    bool isContinuous;
    UsedType sampleTime, timeSimulation;
    unsigned nRowsTF, nColsTF;
    Polynom<UsedType> **TF;

    //! Método para inicializar os espaços que armazenarão as equações diferenciais.

            /*!
                Este método tem como responsabilidade criar o espaço para armazenas as nRowsTF*nColsTF equações diferenciais requeridas.

                Ver também: \sa TransferFunction(unsigned rows, unsigned cols);
            */


    void initTfNumber();

    //! Método para realizar a conversão de um sistema em espaço de estados na forma contínua para a forma discreta.

            /*!
                Este método se utiliza da estrutura de conversão criada em StateSpace para discretizar as equações diferenciais.

                 Ver também: \sa StateSpace;
            */


    void c2dConversion();

public:

    //! Construtor da biblioteca de Equações diferenciais em forma de função de transferência.

            /*!
                O construtor da biblioteca de simulação inicializa o objeto TransferFunction com o número de linhas (row) e colunas (col) indicados. Após, aloca o espaço para armazenar essas funções, e, em seguida, seta sampleTime = 0.1.

                Ex:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF(2,2);
                TF.print();
            }
        \endcode

    Resultado:
    OBS: Nenhum resultado é apresentado, pois os valores internos da função de transferência não foram preenchidos.


    Ver também: \sa print();
    */

    TransferFunction(unsigned rows, unsigned cols);

    //! Construtor da biblioteca de Equações diferenciais em forma de função de transferência.

/*!
    O construtor da biblioteca de simulação inicializa o objeto TransferFunction com o número de linhas (row) e colunas (col) indicados. Após, aloca o espaço para armazenar essas funções, e, em seguida, seta sampleTime = 0.1. Por ultimo, as strings de numerador e denominador são utlizizadas para construir os polinômios da função de transferência multivariável (caso geral).

    Ex1:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("1","1,1",1,1);
                TF.print();
            }
        \endcode

    Resultado:
         \code
               +1
             -------
              s + 1
         \endcode
    Ex2:

         \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("1;2","0,1,1;1,2,1",2,1);
                TF.print();
            }
         \endcode

    Resultado:
         \code
               +1
             -------
              s + 1

                  +2
             -------------
              s^2 + 2s + 1
         \endcode

    Ex3:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("1;2","0,1,1;1,2,1",1,2);
                TF.print();
            }
        \endcode

    Resultado:

        \code
               +1
             -------
              s + 1

                  +2
             -------------
              s^2 + 2s + 1
        \endcode

    Ex4:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("0,1;0,2;1,2;1,3",
                                            "1,2,1;1,2,1;1,2,1;1,2,1",
                                            2,2);
                TF.print();
            }
        \endcode

    Resultado:

        \code
                  +1
             -------------
              s^2 + 2s + 1

                  +2
             -------------
              s^2 + 2s + 1

                 s + 2
             -------------
              s^2 + 2s + 1

                 s + 3
             -------------
              s^2 + 2s + 1
        \endcode

     Ver também: \sa print();
    */

    TransferFunction(std::string num, std::string den,
                     unsigned rows  , unsigned cols);

    //! Método cuja responsabilidade é retornar a função de transferência indicada.

/*!
    A responsabilidade deste método é retornar a função de transferência localizado na linha rows e coluna cols. O usuário deve ser cuidadoso para não inserir uma linha e coluna não existente.

    Ex:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("0,1;0,2;1,2;1,3",
                                            "1,2,1;1,2,1;1,2,1;1,2,1",
                                            2,2);
                TF(1,1).print();
                return 0;
            }
        \endcode

    Resultado:

        \code

                   +1
             -------------
              s^2 + 2s + 1

        \endcode

    Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
    */

    Polynom<UsedType> operator()(unsigned row, unsigned col);

//! Método cuja responsabilidade é inserir uma função de transferência na posição indicada.

/*!
    A responsabilidade deste método é inserir um polinômio ( que neste caso representa uma função de transferência) na linha rows e coluna cols.

    Ex:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                Polynom<double> P("0,1","1,2,1");
                TransferFunction<double> TF(1,1);

                TF(1,1,P);
                TF.print();

                return 0;
            }
        \endcode

    Resultado:

        \code

                   +1
             -------------
              s^2 + 2s + 1

        \endcode

    Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
    */

    void operator()(unsigned row, unsigned col, Polynom<UsedType> P);

//! Método cuja responsabilidade atribuir à função de transferência a esquerda da igualdade os valores da função de transferência a direita da igualdade.

/*!
    A responsabilidade deste método é realizar uma atribuição profunda, ou seja, não apenas atribuir o ponteiro da função de transferência, mas criar uma nova função e atribuir os valores.

    Ex:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                Polynom<double> P("0,1","1,2,1");
                TransferFunction<double> TF(1,1);

                TF(1,1,P);
                TF.print();
                TransferFunction<double> TF2(1,1);
                TF2 = TF;
                TF2.print();

                return 0;
            }
        \endcode

    Resultado:

        \code

                   +1
             -------------
              s^2 + 2s + 1

                   +1
             -------------
              s^2 + 2s + 1

        \endcode

    Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
*/

    void operator= (TransferFunction<UsedType> TF);

//! Método que imprime no prompt de comando o conteúdo de cada função de transferência.

/*!
    A responsabilidade deste método é apresentar os valores de cada função de transferência adicionada pelo usuário (para o caso geral, multivariável).

    Ex:

        \code
            #include <src/simulationLibs/transferfunction.h>

            int main(int argc, char *argv)
            {
                TransferFunction<double> TF("0,1","1,2,1",1,1);
                TF.print();

                return 0;
            }
        \endcode

    Resultado:

        \code

                   +1
             -------------
              s^2 + 2s + 1

        \endcode

    Ver também: getTF(), getNRowsTF(), getNColsTF();
*/


    void print(); // Método Opcional

//! Método cuja responsabilidade é inserir um ponteiro de funções de transferência com um tamanho de linhas e colunas determinadas.

/*!
    A responsabilidade deste método é inserir um conjunto de polinômios ( que neste caso representa funções de transferência na forma multivariável) que possui rows linhas e cols colunas.

        Ex:

            \code
                #include <src/simulationLibs/transferfunction.h>

                int main(int argc, char *argv)
                {
                    TransferFunction<double> TF("0,1","1,2,1",1,1);
                    TF.print();

                    TransferFunction<double> TF2(1,1);

                    TF2.setTF(TF.getTF(),TF.getNRowsTF(),TF.getNColsTF());
                    TF2.print();
                    return 0;
                }
            \endcode

        Resultado:

            \code

                       +1
                 -------------
                  s^2 + 2s + 1
                       +1
                 -------------
                  s^2 + 2s + 1

            \endcode

        Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
*/

    void setTF(Polynom<UsedType> **TF, unsigned rows, unsigned cols);

//! Método cuja responsabilidade é pegar o conteúdo da variável **TF

/*!
    A responsabilidade deste método é retornar os polinômios que estão contidos na variável TF, que é um ponteiro duplo (Matriz de polinômios).

        Ex:

            \code
                #include <src/simulationLibs/transferfunction.h>

                int main(int argc, char *argv)
                {
                    TransferFunction<double> TF("0,1","1,2,1",1,1);
                    TF.print();

                    TF.getTF()[0][0].print();
                    return 0;
                }
            \endcode

        Resultado:

            \code

                       +1
                 -------------
                  s^2 + 2s + 1
                       +1
                 -------------
                  s^2 + 2s + 1

            \endcode

  Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
*/

    Polynom<UsedType> **getTF();

//! Método cuja responsabilidade é pegar o conteúdo da variável nRowsTF

/*!
    A responsabilidade deste método é retornar a quantidade de linhas da matriz de funções de transferência (Multivariável).

        Ex:

            \code
                #include <src/simulationLibs/transferfunction.h>

                int main(int argc, char *argv)
                {
                    TransferFunction<double> TF("0,1","1,2,1",1,1);
                    std::cout << TF.getNRowsTF() << std::endl;
                }
            \endcode

        Resultado:

            \code

                1

            \endcode

  Ver também: \sa print(), getTF(), getNColsTF();
*/

    unsigned getNRowsTF();

//! Método cuja responsabilidade é pegar o conteúdo da variável nColsTF

/*!
    A responsabilidade deste método é retornar a quantidade de colunas da matriz de funções de transferência (Multivariável).

        Ex:

            \code
                #include <src/simulationLibs/transferfunction.h>

                int main(int argc, char *argv)
                {
                    TransferFunction<double> TF("0,1","1,2,1",1,1);
                    std::cout << TF.getNColsTF()<< std::endl;
                }
            \endcode

        Resultado:

            \code

                1

            \endcode

  Ver também: \sa print(), getTF(), getNColsTF();
*/

    unsigned getNColsTF();

    //! Método não implementado

    UsedType sim(UsedType input);

    //! Método não implementado

    UsedType sim(UsedType x, UsedType y);

    //! Método não implementado

    Matrix<UsedType> sim(Matrix<UsedType> x);

    //! Método não implementado

    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);

    //! Método não implementado

    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
