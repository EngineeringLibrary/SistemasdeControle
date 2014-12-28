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
       +1
     -------
      s + 1

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
       +1
     -------
      s + 1

          +2
     -------------
      s^2 + 2s + 1

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
       +1
     -------
      s + 1

          +2
     -------------
      s^2 + 2s + 1

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

          +1
     -------------
      s^2 + 2s + 1


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

          +1
     -------------
      s^2 + 2s + 1


    Ver também: \sa print(), getTF(), getNRowsTF(), getNColsTF();
    */

    void operator()(unsigned row, unsigned col, Polynom<UsedType> P);



    void operator= (TransferFunction<UsedType> TF);
    void print(); // Método Opcional

    void setTF(Polynom<UsedType> **TF, unsigned rows, unsigned cols);
    Polynom<UsedType> **getTF();
    unsigned getNRowsTF();
    unsigned getNColsTF();


    UsedType sim(UsedType input);
    UsedType sim(UsedType x, UsedType y);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // TRANSFERFUNCTION_H
