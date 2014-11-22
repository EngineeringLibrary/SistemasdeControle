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

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A; //Instancia com linhas e colunas iguais a zero
            A.print();
            return 0;
        }

        Resultado:

        Obs: Não mostra nada na tela
    */
    Matrix();

    //! Construtor que recebe como parâmetro uma string

    /*!
        Instancia o objeto da classe Matrix convertendo uma string de valores numéricos em elementos para a matriz.
        \param value Cadeia de caracteres que define a matriz.

        Os elementos devem obedecer o seguinte critério:
        A vírgula "," é utilizada para separar os elementos de uma linha em colunas
        O ponto e vírgula ";" é utilizado para quebrar a linha da matriz

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            return 0;
        }

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

    */

    Matrix(string value);

    //! Construtor que recebe como parâmetros o número de linhas e colunas

    /*!
        Inicializa a matriz com o número corresponde de linhas e colunas, e com todos os elementos em 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A(3,3); //Instancia com linhas e colunas iguais a zero
            A.print();
            return 0;
        }

        Resultado:

        0.000  0.000  0.000
        0.000  0.000  0.000
        0.000  0.000  0.000
    */
    Matrix(int row, int col);

    //! Construtor de cópia da classe.

    /*!
        Construtor de cópia da classe, gerencia as aplicações de memória da classe
        \param otherMatrix Recebe como parâmetro uma cópia da matriz.

        OBS: Este construtor não tem exemplo associado. Funciona implícitamente.
    */
    Matrix(const Matrix & otherMatrix);

    //! Destrutor padrão da classe.

    /*!
        Libera todas as memórias alocadas durante a execução de objetos da classe.
        OBS: Este Destrutor não tem exemplo associado. Funciona implícitamente.
    */
    ~Matrix();//Destrutor

    //! Método de inicialização da matriz.

    /*!
        Inicializa a matriz com o respectivo número de linhas e colunas.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.init(3,3);
            A.print();
            return 0;
        }

        Resultado:

        0.000  0.000  0.000
        0.000  0.000  0.000
        0.000  0.000  0.000
    */
    void init(int row, int col);

    //! Método de inicialização da matriz tomando um valor de string como entrada.

    /*!
        Inicializa a matriz com uma determinada cadeia de caracteres dada como entrada.
        \param value Cadeia de caracteres que define a matriz.

        Os elementos devem obedecer o seguinte critério:
        A vírgula "," é utilizada para separar os elementos de uma linha em colunas
        O ponto e vírgula ";" é utilizado para quebrar a linha da matriz

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.init("1,2,3;4,5,6;7,8,9");
            A.print();
            return 0;
        }

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

    */
    void init(string value);

    //! Método inserir valores em uma determinada posição da matriz.

    /*!
        Recebe como parâmetro de entrada a posição da matriz e insere um determinado elemento.
        \param rol Linha a ser inserido o valor.
        \param col Linha a ser inserido o valor.
        \param number Valor a ser inserido.

        Ex:

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

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

    */
    void add(int rol, int col, UsedType number);

    //! Método para criar uma matriz identidade (Matriz com 1 nos elementos da diagonal principal).

    /*!
        Cria uma matriz identidade quadrada.
        \param num Número corresponde a dimensão da matriz identidade (Matriz quadrada).

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.eye(3);
            A.print();
            return 0;
        }

        Resultado:

        1.000  0.000  0.000
        0.000  1.000  0.000
        0.000  0.000  1.000

    */
    void eye(int num);

    //! Cria uma matriz preenchida com o valor 1 em todos os seus elementos.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz totalmente preenchida com o número 1.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.ones(3,3);
            A.print();
            return 0;
        }

        Resultado:

        1.000  1.000  1.000
        1.000  1.000  1.000
        1.000  1.000  1.000
    */
    void ones(int row, int col);

    //! Cria uma matriz de zeros.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz totalmente preeenchida com o número 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.zeros(3,3);
            A.print();
            return 0;
        }

        Resultado:

        0.000  0.000  0.000
        0.000  0.000  0.000
        0.000  0.000  0.000
    */
    void zeros(int row, int col);

    //! Cria uma matriz preenchida com valores aleatórios do tamanho desejado.

    /*!
        Recebe como parâmetros a dimensão da matriz, e cria uma matriz preeenchida com números aleatórios com distribuição uniforme (utiliza a função rand do próprio c).
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.

        Obs: Os números gerados na matriz estarão em uma faixa entre 0 e 1

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A;
            A.randU(3,3);
            A.print();
            return 0;
        }

        Possível resultado:

        0.485  0.189  0.195
        0.350  0.284  0.023
        0.463  0.848  0.048
    */
    void randU(int row, int col);

    //! Retorna o maior tamanho entre as linhas e colunas

    /*!
        Este método verifica os valores de rows e cols da matriz e retorna o maior valor entre os dois.

        Obs: A função não recebe parâmetros de entrada

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A(5,9);
            std::cout << A.length() << std::endl;
            return 0;
        }

        Resultado:

        9
    */

    int length();

    //! Retorna o elemento da matriz de maior valor numérico

    /*!
        Este método realiza uma busca interna na matriz pelo maior valor existente nela.

        Obs: A função não recebe parâmetros de entrada

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            std::cout << A.max() << std::endl;
            return 0;
        }

        Resultado:

        9
    */
    UsedType max();//Retorna o maior valor de uma matriz

    //! Retorna o elemento da matriz de menor valor numérico

    /*!
        Este método realiza uma busca interna na matriz pelo menor valor existente nela.

        Obs: A função não recebe parâmetros de entrada

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            std::cout << A.min() << std::endl;
            return 0;
        }

        Resultado:

        1
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

        Obs: Para que seja apresentado algum valor o usuário deverá utilizar algum dos métodos de preenchimento de matrizes

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            return 0;
        }

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000
    */

    void print();

    //! Sobrecarga do operador + para a soma entre matrizes.

    /*!
        O método é uma sobrecarga do operador +. Ele permite que a operação de soma entre matrizes seja simplificada. O método realiza a soma de uma matriz que está à esquerda (this) e uma à direita (Mat1) do operador +.
        \param Mat1 Matriz a ser somada com a matriz this.

        Obs: Para que a soma entre as matrizes seja realizada de maneira adequada, ambas as matrizes devem possuir a mesma quantidade de linhas e colunas.

        Ex:

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

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

        3.000  2.000  1.000
        6.000  5.000  4.000
        9.000  8.000  7.000

        4.000  4.000  4.000
       10.000 10.000 10.000
       16.000 16.000 16.000

    */
    Matrix operator+(Matrix Mat1);

    //! Sobrecarga do operador + para a soma entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador +. Ele permite que a operação de soma entre matriz e escalar seja simplificada. O método realiza a soma de uma matriz que está à esquerda (this) e um escalar à direita (a) do operador +.
        \param a escalar (número) a ser somado com a matriz this.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            (A+3).print();
            return 0;
        }

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

        4.000  5.000  6.000
        7.000  8.000  9.000
       10.000 11.000 12.000

    */

    Matrix operator+(UsedType a);

    //! Sobrecarga do operador - para a subtração entre matrizes.

    /*!
        O método é uma sobrecarga do operador -. Ele permite que a operação de subtração entre matrizes seja simplificada. O método realiza a subtração de uma matriz que está à esquerda (this) e uma à direita (Mat1) do operador +.
        \param Mat1 Matriz a ser subtraída com a matriz this.

        Obs: Para que a subtração entre as matrizes seja realizada de maneira adequada, ambas as matrizes devem possuir a mesma quantidade de linhas e colunas.

        Ex:

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

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

        3.000  2.000  1.000
        6.000  5.000  4.000
        9.000  8.000  7.000

        -2.000  0.000  2.000
        -2.000  0.000  2.000
        -2.000  0.000  2.000

    */

    Matrix operator-(Matrix Mat1);

    //! Sobrecarga do operador - para a subtração entre matriz e escalar.

    /*!
        O método é uma sobrecarga do operador -. Ele permite que a operação de subtração entre matriz e escalar seja simplificada. O método realiza a subtração de uma matriz que está à esquerda (this) e um escalar à direita (a) do operador -.
        \param a escalar (número) a ser subtraído com a matriz this.

        Ex:

        #include <src/primitiveLibs/matrix.h>
        int main(int argc, char *argv)
        {
            Matrix<double> A("1,2,3;4,5,6;7,8,9");
            A.print();
            (A-3).print();
            return 0;
        }

        Resultado:

        1.000  2.000  3.000
        4.000  5.000  6.000
        7.000  8.000  9.000

       -2.000 -1.000  0.000
        1.000  2.000  3.000
        4.000  5.000  6.000

    */

    Matrix operator-(UsedType a);

    //! Operador de igualdade de uma matriz.

    /*!
        Iguala uma matriz a outra matriz.
        \param Mat1 Matriz a ser igualada.
    */
    void operator=(Matrix Mat1);

    //! Operador de igualdade para uma string.

    /*!
        Iguala a matriz a uma string de entrada.
        \param value String a qual a matriz deve ser igualada.
        \sa void init(string value)
    */
    void operator=(string value);


    /*void operator=(UsedType B(int row, int col));*/


    //! Operador de multiplicação matriz matriz.

    /*!
        Realiza a operação de multiplicação matricial.
        \param Mat1 Matriz que irá multiplicar a matriz a esquerda.
    */
    Matrix operator*(Matrix Mat1);

    //! Sobrecarga operador de multiplicação matriz.

    /*!
        Realiza a multiplicação de todos os elementos de uma matriz por um escalar.
        \param a Escalar que irá multiplicar a matriz.
    */
    Matrix operator*(UsedType a);

    //! Operador de divisão matriz matriz.

    /*!
        A divisão matricial equivale a multiplicação da matriz a esquerda pela inversa da matriz a direita.
        \param Mat1 Matriz que irá dividir a matriz a esquerda.
        \sa Matrix inv()
    */
    Matrix operator/(Matrix Mat1);

    //! Sobrecarga operador divisão matriz.

    /*!
        Realiza a divisão de todos os elementos da matriz por um escalar.
        \param a Escalar que irá dividir os elementos da matriz.
    */
    Matrix operator/(UsedType a);

    //! Operador de concatenação de matrizes a direita.

    /*!
        Concatena duas matrizes, esse operador coloca a matriz mais a direita
        a esquerda da outra matriz.
        \param Mat1 Matriz a ser concatenada.
    */
    Matrix operator| (Matrix Mat1);

    //! Operador de concatenação de matrizes abaixo.

    /*!
        Concatena duas matrizes, esse operador coloca a matriz mais a direita
        abaixo da outra matriz.
        \param Mat1 Matriz a ser concatenada.
    */
    Matrix operator|| (Matrix Mat1);

    //! Operador de transposição de matrizes

    /*!
        Transpõe a matriz referida.
    */

    Matrix operator~();

    //! Operador de potenciação de matrizes

    /*!
        Eleva a matriz ao expoente especificado.
        \param exp Expoente o qual irá elevar a matriz.
    */
    Matrix operator^(UsedType exp);

    //! Operador de potenciação interna da matriz.

    /*!
        Eleva todos os elementos da matriz ao expoente especificado.
        \param num Expoente que irá elevar os elementos da matriz.
    */
    Matrix operator> (UsedType num);

    //! Operador de acesso a matriz.

    /*!
        Toma como parâmetro a linha e a coluna de um determinado elemento da matriz e o retorna.
        \param row Linha do elemento.
        \param col Coluna do elemento.
    */
    UsedType operator() (int row,int col);

    //! Sobrecarga do operador de acesso da matriz.

    /*!
        Recebe a linha e a coluna de uma posição da matriz e altera o elemento especificado.
        \param row Linha do elemento.
        \param col Coluna do elemento.
        \param value Valor a ser colocado na posição.
    */
    void operator() (int row, int col, UsedType value);

    //! Cria um vetor linha de elementos crescentes.

    /*!
        Recebe um intervalo e cria um vetor contando do intervalo menor até o maior de um em um.
        \param left Menor intervalo.
        \param rigth Maior intervalo.
    */
    void lineVector(int left, int rigth);

    //! Calcula o traço da matriz.

    /*!
        Calcula o traço da matriz. O traço corresponde a soma de todos os elementos da diagonal principal.
    */
    UsedType trace();

    //! Calcula a matriz inversa.
    Matrix inv();

    //! Encontra o polinômio característico da matriz.
    Matrix pol();

    //! Calcula os autovalores da matriz.
    Matrix eigenvalues();

    //! Calcula o determinante da matriz.
    UsedType det();

    //! Retorna o número de linhas da matriz.
    int getRows();

    //! Retorna o número de colunas da matriz.
    int getCols();


    void setLine(int num, Matrix<UsedType> Line);
    void setColumn(int num, Matrix<UsedType> Colummn);
    Matrix<UsedType> getLine(int num);
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
