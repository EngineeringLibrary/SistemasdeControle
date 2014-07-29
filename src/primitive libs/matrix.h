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

    //! Cálcula a média dos elementos da matriz.

    /*!
        Considera uma matriz como uma amostra, retirando a média aritmética das linhas da matriz.
    */
    Matrix Avarage();

    //! Cálcula a variância dos elemensto de uma matriz.

    /*
        Cálcula a média da matriz e retorna a variância dos elementos.
    */
    Matrix Variance();

    //! Cálcula o desvio padrão da matriz.

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


    void operator=(UsedType B(int row, int col));
    //---------------------------------//

    //-----Operadores de Multiplicação-----//
    Matrix operator*(Matrix Mat1);//Multiplicação Matriz Matriz
    Matrix operator*(UsedType a);//Multiplicação Escalar Matriz
    //------------------------------------//

    //-----Operadores de Multiplicação-----//
    Matrix operator/(Matrix Mat1);//Multiplicação Matriz Matriz
    Matrix operator/(UsedType a);//Multiplicação Escalar Matriz
    //------------------------------------//

    //-----Operadores de Concatenação Matrizes-----//
    Matrix operator| (Matrix Mat1);//Concatena Matrizes a Esquerda
    Matrix operator|| (Matrix Mat1);//Concatena Matrizes Abaixo
    //--------------------------------------------//

    //----Operador de Matriz Transposta-----//
    Matrix operator~();
    //-------------------------------------//

    //-----Operador de Potência de Matrizes-----//
    Matrix operator^(UsedType exp);//Eleva a matriz a um determinado expoente.
    Matrix operator> (UsedType num);//Eleva os elementos de uma matriz a um determinado
    UsedType operator() (int row,int col);//Acessa os elementos de uma matriz
    void operator() (int row, int col, UsedType value);

    void lineVector(int left, int rigth);//Cria uma matriz elementos crescentes ou decrescentes de um em um de left até rigth
    //-----------------------------------------//

    //##########################################//

    //#####Álgebra Linear#####//
    UsedType trace();//Cálculo do traço de uma matriz.
    Matrix inv();//Cálculo da matriz inversa da matriz.
    Matrix pol();//Cálculo dos índices do polinômio característico da matriz.
    Matrix eigenvalues();//Cálculo dos auto valores de uma matriz.
    UsedType det();//Cálculo do determinante de uma matriz.
    //##############################//



    //#####Retornando Informações da Matriz#####//
    int getRows();//Retorna o número de linhas da matriz.
    int getCols();//Retorna o número de colunas da matriz.
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
