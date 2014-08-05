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
        Inicia o objeto da classe com os elementos em 0.
    */
    Matrix();

    //! Construtor que toma como parâmetros o número de linhas e colunas

    /*!
        Inicializa a matriz com o número corresponde de linhas e colunas, e inicia todos os elementos em 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.
    */
    Matrix(int row, int col);

    //! Construtor de cópia da classe.

    /*!
        Construtor de cópia da classe, gerencia as aplicações de memória da classe
        \param otherMatrix Recebe como parâmetro uma cópia da matriz.
    */
    Matrix(const Matrix & otherMatrix);

    //! Destrutor padrão da classe.

    /*!
        Libera todas as memórias alocadas durante a execução de objetos da classe.
    */
    ~Matrix();//Destrutor

    //! Método de inicialização da matriz.

    /*!
        Inicializa a matriz com o respectivo número de linhas e colunas.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.
    */
    void init(int row, int col);

    //! Método de inicialização da matriz tomando um valor de string como entrada.

    /*!
        Inicializa a matriz com uma determinada cadeia de caracteres dada como entrada.
        \param value Cadeia de caracteres que definem a matriz, separasse os elementos por vírgula
                     e as colunas por ponto e vírgula.
    */
    void init(string value);

    //! Método para se colocar valores em uma determinada posição da matriz.

    /*!
        Toma como entrada a posição da matriz e insere um determinado elemento.
        \param rol Linha a ser inserido o valor.
        \param col Linha a ser inserido o valor.
        \param number Valor a ser inseriodo.
    */
    void add(int rol, int col, UsedType number);

    //! Método para criar uma matriz identidade.

    /*!
        Cria uma matriz quadrada identidade.
        \param num Número corresponde a dimensão da matriz, a matriz criada é quadrada.
    */
    void eye(int num);

    //! Cria uma matriz de uns.

    /*!
        Toma como parâmetros a dimensão da matriz, e cria uma matriz totalmente preenchida com o número 1.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.
    */
    void ones(int row, int col);

    //! Cria uma matriz de zeros.

    /*!
        Toma como parâmetros a dimensão da matriz, e cria uma matriz totalmente preeenchida com o número 0.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.
    */
    void zeros(int row, int col);

    //! Cria uma matriz com valores aleatórios.

    /*!
        Toma como parâmetros a dimensão da matriz, e cria uma matriz preeenchida com números aleatórios.
        \param row Número de linhas da matriz.
        \param col Número de colunas da matriz.
    */
    void randU(int row, int col);

    //! Retorna o maior tamanho entre as linhas e colunas
    int length();

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
    void print();

    //! Operador de soma de matrizes.

    /*!
        Soma matriz matriz.
        \param Mat1 Matriz a ser somada.
    */
    Matrix operator+(Matrix Mat1);

    //! Soma matriz escalar.

    /*!
        Soma a matriz a um determinado escalar.
        \param a Escalar a ser somado.
    */
    Matrix operator+(UsedType a);

    //! Subtração matriz matriz.

    /*!
        Subtrai de uma matriz outra matriz.
        \param Mat1 Matriz que será subtraida.
    */
    Matrix operator-(Matrix Mat1);

    //! Subtração matriz escalar.

    /*!
        Subtrai um escalar de uma matriz.
        \param a Escalar a ser subtraído.
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

    //! Define uma linha.

    /*!
        Recebe o índice da linha e um matriz linha, a inserindo no índice da matriz original.
        \param num Número da linha a ser alterada.
        \param Line Matriz linha que será inserida na matriz original.
    */
    void setLine(int num, Matrix<UsedType> Line);

    //! Define uma coluna.

    /*!
        Recebe o índice da coluna e um matriz coluna, a inserindo no índice da matriz original.
        \param num Número da coluna a ser alterada.
        \param Colummn Matriz coluna que será inserida.
    */
    void setColumn(int num, Matrix<UsedType> Colummn);

    //! Retorna uma determinada linha da matriz.

    /*!
        Recebe o índice da linha e a retorna.
        \param num Índice da linha a ser retornada.
    */
    Matrix<UsedType> getLine(int num);

    //! Retorna uma determinada coluna da matriz.

    /*!
        Recebe o índice da coluna e a retorna.
        \param num Índice da coluna a ser retornada.
    */
    Matrix<UsedType> getColumn(int num);

    //! Retorna um determinado elemento da matriz.

    /*!
        Recebe os índices da matriz e retorna o elemento nessa posição.
        \param row Linha do elemento.
        \param col Coluna do elemento.
        \sa  UsedType operator()
    */
    UsedType getMat(int row, int col);//Retorna o elemento no índice ij da matriz.

    //! Altera o elemento na posição especificada.

    /*!
        Recebe os índices da matriz e um elemento a ser inserido nessa posição.
        \param row Linha do elemento a ser inserido.
        \param col Coluna do elemento a ser inserido.
    */
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
