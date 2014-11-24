#ifndef __MATRIX_H_INCLUDED
#define __MATRIX_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#define pi 3.14

using namespace std;

//! Classe Matriz, com o intuito de realizar operações entre matrizes entre outras funções.

/*!
    Biblioteca que gerencia matrizes, tais como as suas operações e propriedades.
*/


template <class UsedType>
class Matrix
{
private:

    int rows; //! Membro que armazena o número de linhas da Matriz.
    int cols; //! Membro que armazena o número de colunas da Matriz.
    UsedType **Mat; //! Ponteiro duplo aonde serão armazenados os dados da Matriz.

    //! Função de verificação a interna das dimensões da matriz.

    /*!
        A função verifica se a matriz é quadrada ou não.
        \param Mat1 Matriz de entrada a se verificar as dimensões.
    */
    bool sqr(Matrix<UsedType> Mat1);

    //! Função de verificação interna da matriz.

    /*!
        A função verifica se a matriz é identidade.
        \param Mat1 Matriz de entrada a se verificar se é identidade.
    */
    bool ind(Matrix<UsedType> Mat1);


public:

    //! Construtor padrão da classe.

    /*!
        Instancia o objeto da classe Matrix com os elementos em 0.

        Ex:

        \code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
           Matrix<double> A; //Instancia com linhas e colunas iguais a zero
           A.print();
           return 0;
        }
        \endcode

         Resultado:

         Obs: Não mostra nada na tela
    */
    Matrix();

    //! Construtor que recebe como parâmetro uma string

    /*!
        Instancia o objeto da classe Matrix convertendo uma string de valores numéricos em elementos para a matriz.
        \param value Cadeia de caracteres que define a matriz.

        Os elementos devem obedecer o seguinte critério:\n
         A vírgula "," é utilizada para separar os elementos de uma linha em colunas\n
         O ponto e vírgula ";" é utilizado para quebrar a linha da matriz\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
           Matrix<double> A("1,2,3;4,5,6;7,8,9");
           A.print();
           return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

    */

    Matrix(string value);

    //! Construtor que recebe como parâmetros o número de linhas e colunas

    /*!
        Inicializa a matriz com o número corresponde de linhas e colunas, e com todos os elementos em 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A(3,3); //Instancia com linhas e colunas iguais a zero
          A.print();
          return 0;
         }
\endcode

        Resultado:

         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
    */
    Matrix(int row, int col);

    //! Construtor de cópia da classe.

    /*!
        Construtor de cópia da classe, gerencia as aplicações de memória da classe
        \param otherMatrix Recebe como parâmetro uma cópia da matriz.

         OBS: Este construtor não tem exemplo associado. Funciona implícitamente.\n
    */
    Matrix(const Matrix & otherMatrix);

    //! Destrutor padrão da classe.

    /*!
        Libera todas as memórias alocadas durante a execução de objetos da classe.\n
         OBS: Este Destrutor não tem exemplo associado. Funciona implícitamente.\n
    */
    ~Matrix();//Destrutor

    //! Método de inicialização da matriz.

    /*!
        Inicializa a matriz com o respectivo número de linhas e colunas.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.init(3,3);
          A.print();
          return 0;
         }
\endcode

        Resultado:

         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
    */
    void init(int row, int col);

    //! Método de inicialização da matriz tomando um valor de string como entrada.

    /*!
        Inicializa a matriz com uma determinada cadeia de caracteres dada como entrada.
        \param value Cadeia de caracteres que define a matriz.

        Os elementos devem obedecer o seguinte critério:\n
         A vírgula "," é utilizada para separar os elementos de uma linha em colunas\n
         O ponto e vírgula ";" é utilizado para quebrar a linha da matriz\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.init("1,2,3;4,5,6;7,8,9");
          A.print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

    */
    void init(string value);

    //! Método inserir valores em uma determinada posição da matriz.

    /*!
        Recebe como parâmetro de entrada a posição da matriz e insere um determinado elemento.
        \param rol Linha a ser inserido o valor.
        \param col Linha a ser inserido o valor.
        \param number Valor a ser inserido.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.add(1,1,1);
          A.add(1,2,2);
          A.add(1,2,3);
          A.add(2,1,4);
          A.add(2,2,5);
          A.add(2,3,6);
          A.add(3,1,7);
          A.add(3,2,8);
          A.add(3,3,9);
          A.print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

    */
    void add(int rol, int col, UsedType number);

    //! Método para criar uma matriz identidade (Matriz com 1 nos elementos da diagonal principal).

    /*!
        Cria uma matriz identidade quadrada.
        \param num Número corresponde a dimensão da matriz identidade (Matriz quadrada).

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.eye(3);
          A.print();
          return 0;
         }
\endcode

        Resultado:

         1.000  0.000  0.000\n
         0.000  1.000  0.000\n
         0.000  0.000  1.000\n

    */
    void eye(int num);

    //! Cria uma matriz preenchida com o valor 1 em todos os seus elementos.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz totalmente preenchida com o número 1.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.ones(3,3);
          A.print();
          return 0;
         }
\endcode

        Resultado:

         1.000  1.000  1.000\n
         1.000  1.000  1.000\n
         1.000  1.000  1.000\n
    */
    void ones(int row, int col);

    //! Cria uma matriz de zeros.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz totalmente preeenchida com o número 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.zeros(3,3);
          A.print();
          return 0;
         }
\endcode

        Resultado:

         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
         0.000  0.000  0.000\n
    */
    void zeros(int row, int col);

    //! Cria uma matriz preenchida com valores aleatórios do tamanho desejado.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz preeenchida com números aleatórios com distribuição uniforme (utiliza a função rand do próprio c).
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

         Obs: Os números gerados na matriz estarão em uma faixa entre 0 e 1\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A;
          A.randU(3,3);
          A.print();
          return 0;
         }
\endcode

        Possível resultado:

         0.485  0.189  0.195\n
         0.350  0.284  0.023\n
         0.463  0.848  0.048\n
    */
    void randU(int row, int col);

    //! Retorna o maior tamanho entre as linhas e colunas

    /*!
        Este método verifica os valores de rows e cols da matriz e retorna o maior valor entre os dois.

         Obs: A função não recebe parâmetros de entrada

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A(5,9);
          std::cout << A.length() << std::endl;
          return 0;
         }
\endcode

        Resultado:

         9\n
    */

    int length();

    //! Retorna o elemento da matriz de maior valor numérico

    /*!
        Este método realiza uma busca interna na matriz pelo maior valor existente nela.

         Obs: A função não recebe parâmetros de entrada

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          std::cout << A.max() << std::endl;
          return 0;
         }
\endcode

        Resultado:

         9\n

    */
    UsedType max();//Retorna o maior valor de uma matriz

    //! Retorna o elemento da matriz de menor valor numérico

    /*!
        Este método realiza uma busca interna na matriz pelo menor valor existente nela.

         Obs: A função não recebe parâmetros de entrada

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          std::cout << A.min() << std::endl;
          return 0;
         }
\endcode

        Resultado:

         1\n
    */

    UsedType min();//Retorna o menor valor de uma matriz


    //! Calcula a média dos elementos da matriz.

    /*!
        Considera uma matriz como uma amostra, retirando a média aritmética das linhas da matriz.
    */
    Matrix Avarage();

    //! Calcula a variância dos elementos de uma matriz.

    /*
        Calcula a média da matriz e retorna a variância dos elementos.
    */
    Matrix Variance();

    //! Calcula o desvio padrão da matriz.

    /*!
        Retorna o desvio padrão de uma matriz.
    */
    Matrix Std();

    //! Exibe a matriz.

    /*!
        Este método apresenta na tela todos os valores da matriz de maneira ordenada.

         Obs: Para que seja apresentado algum valor o usuário deverá utilizar algum dos métodos de preenchimento de matrizes\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          A.print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n
    */

    void print();

    //! Sobrecarga do operador + para a soma entre matrizes.

    /*!
        O método é uma sobrecarga do operador +. Ele permite que a operação de soma entre matrizes seja simplificada. O método realiza a soma de uma matriz que está à esquerda (this) e uma à direita (Mat1) do operador +.
        \param Mat1 Matriz a ser somada com a matriz this.

         Obs: Para que a soma entre as matrizes seja realizada de maneira adequada, ambas as matrizes devem possuir a mesma quantidade de linhas e colunas.\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          Matrix<double> B("3,2,1;6,5,4;9,8,7");
          A.print();
          B.print();
          (A+B).print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         3.000  2.000  1.000\n
         6.000  5.000  4.000\n
         9.000  8.000  7.000\n

         4.000  4.000  4.000\n
        10.000 10.000 10.000\n
        16.000 16.000 16.000\n

    */
    Matrix operator+(Matrix Mat1);

    //! Sobrecarga do operador + para a soma entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador +. Ele permite que a operação de soma entre matriz e escalar seja simplificada. O método realiza a soma de uma matriz que está à esquerda (this) e um escalar à direita (a) do operador +.
        \param a escalar (número) a ser somado com a matriz this.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          A.print();
          (A+3).print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         4.000  5.000  6.000\n
         7.000  8.000  9.000\n
        10.000 11.000 12.000\n

    */

    Matrix operator+(UsedType a);

    //! Sobrecarga do operador - para a subtração entre matrizes.

    /*!
        O método é uma sobrecarga do operador -. Ele permite que a operação de subtração entre matrizes seja simplificada. O método realiza a subtração de uma matriz que está à esquerda (this) e uma à direita (Mat1) do operador +.
        \param Mat1 Matriz a ser subtraída com a matriz this.

         Obs: Para que a subtração entre as matrizes seja realizada de maneira adequada, ambas as matrizes devem possuir a mesma quantidade de linhas e colunas.\n

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          Matrix<double> B("3,2,1;6,5,4;9,8,7");
          A.print();
          B.print();
          (A-B).print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         3.000  2.000  1.000\n
         6.000  5.000  4.000\n
         9.000  8.000  7.000\n

         -2.000  0.000  2.000\n
         -2.000  0.000  2.000\n
         -2.000  0.000  2.000\n

    */

    Matrix operator-(Matrix Mat1);

    //! Sobrecarga do operador - para a subtração entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador -. Ele permite que a operação de subtração entre matriz e escalar seja simplificada. O método realiza a subtração de uma matriz que está à esquerda (this) e um escalar à direita (a) do operador -.
        \param a escalar (número) a ser subtraído com a matriz this.

        Ex:

\code
         #include <src/primitiveLibs/matrix.h>
         int main(int argc, char *argv)
         {
          Matrix<double> A("1,2,3;4,5,6;7,8,9");
          A.print();
          (A-3).print();
          return 0;
         }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

        -2.000 -1.000  0.000\n
         1.000  2.000  3.000\n
         4.000  5.000  6.000\n

    */

    Matrix operator-(UsedType a);

    //! Operador de atribuição entre matrizes.

    /*!
        O método é uma sobrecarga do operador =. Ele permite que a operação de atribuição entre matrizes seja realizada sem que haja a cópia do ponteiro da matriz à direita. O método cria um espaço de memória na matriz à esquerda da igualdade do mesmo tamanho da do lado direito e, após, cópia os valores para a matriz à esquerda.
        \param Mat1 é uma matriz qualquer que está do lado direito da igualdade.

        Ex:

            \code
            #include <src/primitiveLibs/matrix.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A("1,2,3;4,5,6;7,8,9");
                Matrix<double> B;
                B = A;
                A.print();
                B.print();
                return 0;
            }
            \endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

    */

    void operator=(Matrix Mat1);

    //! Operador de atribuição entre matriz e string.

    /*!
        O método é uma sobrecarga do operador =. Ele permite que a operação de atribuição entre matriz e string seja simplificada. O método cria um espaço de memória na matriz à esquerda da igualdade, converte a string à direita da igualdade, converte-a em uma matriz e coloca os seus valores na matriz à esquerda da igualdade.
        \param value é uma string qualquer que está do lado direito da igualdade.

        Ex:

\code
            #include <src/primitiveLibs/matrix.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A("1,2,3;4,5,6;7,8,9");
                Matrix<double> B;
                B = A;
                A.print();
                B.print();
                return 0;
            }
            \endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         Ver também: \sa void init(string value), \sa Matrix(string value)
    */

    void operator=(string value);


    /*void operator=(UsedType B(int row, int col));*/


    //! Operador de multiplicação entre matrizes.

    /*!
        O método é uma sobrecarga do operador *. Ele permite que a operação de multiplicação entre matrizes seja simplificada. O método realiza a multiplicação entre duas matrizes que estão a esquerda e a direita do operador *.
        \param Mat1 É uma matriz qualquer a direita do operador *.

        Ex:

            \code
            #include <src/primitiveLibs/matrix.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A("1,2,3;4,5,6;7,8,9");
                Matrix<double> B;
                B.eye(A.length());
                A.print();
                B.print();
                (A*B).print();
                return 0;
            }
            \endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         1.000  0.000  0.000\n
         0.000  1.000  0.000\n
         0.000  0.000  1.000\n

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         Ver também: \sa Matrix(string value), \sa Matrix()
    */

    Matrix operator*(Matrix Mat1);

    //! Operador de multiplicação entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador *. Ele permite que a operação de multiplicação entre matriz e escalar seja simplificada. O método realiza a multiplicação entre uma matriz que está a esquerda e um escalar a direita do operador *.
        \param a É um escalar qualquer a direita do operador *.

        Ex:

\code
            #include <src/primitiveLibs/matrix.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A("1,2,3;4,5,6;7,8,9");
                Matrix<double> B;
                B = A*2;
                A.print();
                B.print();
                return 0;
            }
            \endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         2.000  4.000  6.000\n
         8.000 10.000 12.000\n
        14.000 16.000 18.000\n

         Ver também: \sa Matrix(string value), \sa Matrix()
    */

    Matrix operator*(UsedType a);

    //! Sobrecarga do operador / para "divisão" entre matrizes.

    /*!
        A "divisão" matricial equivale a multiplicação com uma das matrizes (a direita do operador /) invertida (matriz^-1).
        \param Mat1 É a matriz que será invertida (à direita do oprador /) para depois ser multiplicada pela matriz que está a esquerda do operador /.

        Obs: Uma matriz vezes a sua inversa resulta na matriz identidade.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,0,3;4,5,6;1,8,9");
            A.print();
            (A/A).print();
            return 0;

        }
\endcode

        Resultado:

         1.000  0.000  3.000\n
         4.000  5.000  6.000\n
         1.000  8.000  9.000\n

         1.000  0.000  0.000\n
         0.000  1.000  0.000\n
         0.000  0.000  1.000\n

        Ver também: \sa Matrix inv()
    */

    Matrix operator/(Matrix Mat1);

    //! Operador de divisão entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador /. Ele permite que a operação de divisão entre matriz e escalar seja simplificada. O método realiza a divisão entre uma matriz que está a esquerda e um escalar a direita do operador /.
        \param a É um escalar qualquer a direita do operador /.

        Ex:

    \code
            #include <src/primitiveLibs/matrix.h>
            int main(int argc, char *argv)
            {
                Matrix<double> A("2,4,6;8,10,12;14,16,18");
                Matrix<double> B;
                B = A/2;
                A.print();
                B.print();
                return 0;
            }
            \endcode

        Resultado:

         2.000  4.000  6.000\n
         8.000 10.000 12.000\n
        14.000 16.000 18.000\n

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n


         Ver também: \sa Matrix(string value), \sa Matrix()
    */

    Matrix operator/(UsedType a);

    //! Sobrecarga do operador | para realizar a concatenação de matrizes (adicionando às colunas).

    /*!
        O operador | foi sobrecarregado de tal forma que concatena duas matrizes (a direita e a esquerda do operador | ) retornando como resultado uma matriz (formada pela junção das duas matrizas, colocando uma ao lado da outra).
        \param Mat1 Matriz a ser concatenada juntamente com a matriz à direita do operador || para formar uma nova matriz.

        Ex:

\code

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            Matrix<double> B("4;7;10");
            A.print();
            B.print();
            (A|B).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         4.000\n
         7.000\n
        10.000\n

         1.000  2.000  3.000  4.000\n
         4.000  5.000  6.000  7.000\n
         7.000  8.000  9.000 10.000\n

        Ver também: \sa Matrix operator|| (Matrix Mat1)
    */

    Matrix operator| (Matrix Mat1);

    //! Sobrecarga do operador || para realizar a concatenação de matrizes (adicionando às linhas).

    /*!
        O operador || foi sobrecarregado de tal forma que concatena duas matrizes (a direita e a esquerda do operador || ) retornando como resultado uma matriz (formada pela junção das duas matrizas, colocando uma abaixo da outra).
        \param Mat1 Matriz a ser concatenada juntamente com a matriz à direita do operador || para formar uma nova matriz.

        Ex:

\code

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            Matrix<double> B("10,11,12");
            A.print();
            B.print();
            (A||B).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

        10.000 11.000 12.000\n

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n
        10.000 11.000 12.000\n

        Ver também: \sa Matrix operator| (Matrix Mat1)
    */

    Matrix operator|| (Matrix Mat1);

    //! Sobrecarga do operador ~ para obter a transposta da matriz.

    /*!
        O operador ~ foi sobrecarregado de tal forma que retorna a transposta da matriz em que ele está a esquerda.

        Obs: O método não requer parâmetro de entrada (exceto a matriz que estará localizada à direita do operador ~)

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("4;7;10");
            A.print();
            (~A).print();
            return 0;
        }
\endcode

        Resultado:

         4.000\n
         7.000\n
        10.000\n

        10.000 11.000 12.000\n

        Ver também: \sa Matrix operator* (Matrix Mat1)
    */

    Matrix operator~();

    //! Sobrecarga do operador ^ para obter a potenciação de matrizes.

    /*!
        O operador ^ foi sobrecarregado de tal forma a simplificar a operação de potenciação de matrizes, dada uma matriz e um escalar (à esquerda e à direita do operador ^ respectivamente).
        \param exp Expoente cujo módulo significa a quantidade de vezes que a multiplicação entre a matriz com ela mesma será repetida. Caso o expoente seja negativo o programa primeiramente invertará a matriz para depois realizar a potenciação.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.eye(3);
            A = A*3;
            A.print();
            (A^3).print();
            return 0;
        }
\endcode

        Resultado:

         3.000  0.000  0.000\n
         0.000  3.000  0.000\n
         0.000  0.000  3.000\n

        27.000  0.000  0.000\n
         0.000 27.000  0.000\n
         0.000  0.000 27.000\n

        Ver também: \sa Matrix operator* (Matrix Mat1)
    */

    Matrix operator^(UsedType exp);

    //! Sobrecarga do operador > para obter a potenciação dos elementos da matriz.

    /*!
        O operador > foi sobrecarregado de tal forma a simplificar a operação de potenciação dos elementos internos de uma matriz.
        \param exp Expoente que indica a potência de cada elemento interno da matriz.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.ones(3,3);
            A = A*3;
            A.print();
            (A>2).print();
            return 0;
        }
\endcode

        Resultado:

         3.000  3.000  3.000\n
         3.000  3.000  3.000\n
         3.000  3.000  3.000\n

         9.000  9.000  9.000\n
         9.000  9.000  9.000\n
         9.000  9.000  9.000\n

        Ver também: \sa Matrix operator* (Matrix Mat1), \sa Matrix operator> (Matrix Mat1)
    */

    Matrix operator> (UsedType num);

    //! Sobrecarga do operador () para acessar os elementos da matriz.

    /*!
        O operador () foi sobrecarregado de tal forma a simplificar o acesso aos elementos internos de uma matriz. A partir da indicação da linha e coluna (parâmetros que são recebidos) o resultado da operação será o elemento da matriz que se encontra naquela posição.
        \param row Linha do elemento.
        \param col Coluna do elemento.

        Obs: Lembrando que o elemento da primeira posição é o que tem linha 1 e coluna 1, também.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            std::cout <<  A(1,1) << std::endl;
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         1\n

        Ver também: \sa Matrix operator* (Matrix Mat1) \sa Matrix operator^ (Matrix Mat1)
    */

    UsedType operator() (int row,int col);

    //! Sobrecarga do operador () para inserir elementos em uma matriz.

    /*!
        O operador () foi sobrecarregado de tal forma a simplificar a inserção de elementos em uma matriz. A partir da indicação da linha e coluna (parâmetros que são recebidos) um novo elemento pode ser inserido (na posição determinada).
        \param rol Linha do elemento.
        \param col Coluna do elemento.
        \param value Valor a ser inserido na linha e coluna especificada

        Obs: Lembrando que o elemento da primeira posição é o que tem linha 1 e coluna 1, também.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A(1,1,1);
            A(1,2,2);
            A(1,3,3);
            A(2,1,4);
            A(2,2,5);
            A(2,3,6);
            A(3,1,7);
            A(3,2,8);
            A(3,3,9);
            A.print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

        Ver também: \sa void add(int rol, int col, UsedType number)
    */

    void operator() (int row, int col, UsedType value);

    //! Cria um vetor linha de elementos crescentes.

    /*!
        Recebe um intervalo e cria um vetor contando do intervalo menor até o maior de um em um.
        \param left limite inferior do vetor.
        \param rigth limite superior do vetor.

        Obs: Lembrando que o elemento da primeira posição é o que tem linha 1 e coluna 1, também.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.lineVector(10,15);
            A.print();
            return 0;
        }
\endcode

        Resultado:

         10.000  11.000  12.000  13.000  14.000  15.000\n

        Ver também:
    */
    void lineVector(int left, int rigth);

    //! Calcula o traço da matriz.

    /*!
        Calcula o traço da matriz, ou seja, a soma de todos os elementos da diagonal principal.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            std::cout << A.trace() << std::endl;
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         15\n

        Ver também:

    */

    UsedType trace();

    //! Calcula a matriz inversa.

    /*!
        Calcula a inversa da matriz dada.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;0,5,6;7,1,9");
            A.print();
            (A.inv()).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         0.000  5.000  6.000\n
         7.000  1.000  9.000\n

         2.167 -0.833  -0.167\n
         2.333 -0.667  -0.333\n
        -1.944  0.722   0.278\n

        Ver também:

    */

    Matrix inv();

    //! Encontra o polinômio característico da matriz.

    /*!
        Calcula o polinômio característico da matriz dada e devolve os índices do polinômio. O vetor resultante representa o polinômio característico onde o último elemtento é a constante e o primeiro multiplica \f$ x^{n-1} \f$.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;0,5,6;7,1,9");
            A.print();
            (A.pol()).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         0.000  5.000  6.000\n
         7.000  1.000  9.000\n

        -1.000  15.000 -32.000 18.000\n

        Ver também:

    */

    Matrix pol();

    //! Calcula os autovalores da matriz.

    /*!
        Calcula os autovalores da matriz dada e devolve um vetor (matriz) que representam os autovalores (desordenados).

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;0,5,6;7,1,9");
            A.print();
            (A.eigenvalues()).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         0.000  5.000  6.000\n
         7.000  1.000  9.000\n

        12.714  1.000 1.286\n

        Ver também:

    */

    Matrix eigenvalues();

    //! Calcula o determinante da matriz.

    /*!
        Calcula o determinante da matriz dada e devolve um escalar que simboliza esse determinante.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;0,5,6;7,1,9");
            A.print();
            std::cout << A.det() << std::endl;
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         0.000  5.000  6.000\n
         7.000  1.000  9.000\n

         -0.000175765\n

        Ver também:

    */

    UsedType det();

    //! Retorna o número de linhas da matriz.

    /*!
        A responsabilidade desta função é permitir o acesso (obter) a variável rows da classe, ou seja, saber qual o número de linhas que a matriz tem.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            std::cout << A.getRows() << std::endl;
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         3\n

        Ver também: \sa int getCols()

    */

    int getRows();

    //! Retorna o número de colunas da matriz.

    /*!
        A responsabilidade desta função é permitir o acesso (obter) a variável cols da classe, ou seja, saber qual o número de colunas que a matriz tem.

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            std::cout << A.getCols() << std::endl;
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         3\n

        Ver também: \sa int getRows()

    */

    int getCols();

    //! Inserir em uma matriz uma linha inteira em uma matriz

    /*!
        A responsabilidade desta função é permitir a inserção de uma linha inteira em uma matriz.
        \param num É a linha que será alterada na matriz de destino
        \param Line é a linha que será inserida na matriz

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            Matrix<double> B("1,2,3");
            A.print();
            A.setLine(2,B);
            A.print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         1.000  2.000  3.000\n
         1.000  2.000  3.000\n
         7.000  8.000  9.000\n

        Ver também: \sa void setColumn(int num, Matrix<UsedType> Colummn)

    */

    void setLine(int num, Matrix<UsedType> Line);

    //! Inserir em uma matriz uma coluna inteira em uma matriz

    /*!
        A responsabilidade desta função é permitir a inserção de uma coluna inteira em uma matriz.
        \param num É a coluna que será alterada na matriz de destino
        \param Colummn é a coluna que será inserida na matriz

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            Matrix<double> B("1;2;3");
            A.print();
            A.setColumn(2,B);
            A.print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         1.000  1.000  3.000\n
         4.000  2.000  6.000\n
         7.000  3.000  9.000\n

        Ver também: \sa void setLine(int num, Matrix<UsedType> Line)

    */

    void setColumn(int num, Matrix<UsedType> Colummn);

    //! Obter uma linha inteira de uma matriz

    /*!
        A responsabilidade desta função é permitir a obtenção de uma linha inteira de uma matriz.
        \param num É a linha que será obtida da matriz

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            (A.getLine(2)).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         4.000  5.000  6.000\n

        Ver também: \sa Matrix<UsedType> getColumn(int num)

    */

    Matrix<UsedType> getLine(int num);

    //! Obter uma coluna inteira de uma matriz

    /*!
        A responsabilidade desta função é permitir a obtenção de uma coluna inteira de uma matriz.
        \param num É a coluna que será obtida da matriz

        Ex:

\code
        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            (A.getColumn(2)).print();
            return 0;
        }
\endcode

        Resultado:

         1.000  2.000  3.000\n
         4.000  5.000  6.000\n
         7.000  8.000  9.000\n

         2.000\n
         5.000\n
         8.000\n

        Ver também: \sa Matrix<UsedType> getLine(int num)

    */

    Matrix<UsedType> getColumn(int num);

    UsedType getMat(int row, int col);//Retorna o elemento no índice ij da matriz.

    void setMat(int row, int col, UsedType num);


    //#######################################################//
//Friend functions
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Soma Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Subtração Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator* (FriendType a, Matrix<FriendType> Mat1);//Multiplicação Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator/ (FriendType a, Matrix<FriendType> Mat1);//divisão Matriz Escalar

    template<class FriendType> friend Matrix<FriendType> diff(Matrix<FriendType> M, FriendType h);//Cálcula a derivada de uma matriz.

    template<class FriendType> friend FriendType max(Matrix<FriendType> M);//Retorna o maior valor de uma matriz
    template<class FriendType> friend FriendType min(Matrix<FriendType> M);//Retorna o menor valor de uma matriz
    template<class FriendType> friend FriendType norm(Matrix<FriendType> M);//Retorna o maior valor de uma matriz
    template<class FriendType> friend Matrix<FriendType> abs(Matrix<FriendType> M);//Retorna o modulo dos valores de uma matriz
    template<class FriendType> friend Matrix<FriendType> cos(Matrix<FriendType> M1);//Retorna o cosseno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> sin(Matrix<FriendType> M1);//Retorna o seno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> tan(Matrix<FriendType> M1);//Retorna a tangente dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> acos(Matrix<FriendType> M1);//Retorna o arco cosseno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> asin(Matrix<FriendType> M1);//Retorna o arco seno dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> atan(Matrix<FriendType> M1);//Retorna o arco tangente dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> cosh(Matrix<FriendType> M1);//Retorna o cosseno hiperbólico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> sinh(Matrix<FriendType> M1);//Retorna o seno hiperbólico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> tanh(Matrix<FriendType> M1);//Retorna a tangente hiperbólica dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> acosh(Matrix<FriendType> M1);//Retorna o arco cosseno hiperbólico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> asinh(Matrix<FriendType> M1);//Retorna o arco seno hiperbólico dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> atanh(Matrix<FriendType> M1);//Retorna o arco tangente hiperbólica dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> exp(Matrix<FriendType> M1);//Retorna a exponencial dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> log(Matrix<FriendType> M1);//Retorna o logaritmo neperiano dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> log10(Matrix<FriendType> M1);//Retorna o logaritmo na base 10 dos elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> ceil(Matrix<FriendType> M1);//arredonda para cima os elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> round(Matrix<FriendType> M1);//arredonda os elementos de uma matriz
    template<class FriendType> friend Matrix<FriendType> floor(Matrix<FriendType> M1);//arredonda para baixo os elementos de uma matriz
};

#endif // __MATRIX_H_INCLUDED
