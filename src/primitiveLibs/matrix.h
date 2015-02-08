#ifndef __MATRIX_H_INCLUDED
#define __MATRIX_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <complex>

using namespace std;

template <class UsedType>
class Matrix
{
private:

    unsigned rows, cols;
    UsedType **Mat;

    //#####Verificação de Matriz Quadrada#####//
    bool sqr(Matrix<UsedType> Mat1);
    //#######################################//

    //#####Verficação se é uma Matriz Idenditade#####//
    bool ind(Matrix<UsedType> Mat1);
    //##############################################//

public:

    //#####Construtores e Destrutores da Classe#####//
    Matrix(); //Construtor
    Matrix(string value); //Construtor
    Matrix(unsigned row, unsigned col);//Constroi a matriz de acordo com o número de linhas e colunas informados, respectivamente.
    Matrix(const Matrix & otherMatrix);//Faz uma cópia da Matriz
    ~Matrix();//Destrutor
    //#############################################//


    //#####Métodos de Inicialização da Matriz#####//
    void init(unsigned row, unsigned col); //Inicializador da Matriz de acordo com o número de linhas e colunas informados, respectivamente.
    void init(string value);//Adiciona os valores de uma string a matriz, serparando os elementos por "," e as linhas por ";".
    void add(unsigned rol, unsigned col, UsedType number);//Adiciona elementos a matriz pelos índices i e j respectivamente. Obs.: i e j iniciam de 1 para este método.
    void eye(unsigned num);//Cria uma matriz identidade de ordem num.
    void ones(unsigned row, unsigned col);//Inicia uma matriz com todos os índices iguais a 1, de acordo com o número de linhas e colunas respectivamente.
    void zeros(unsigned row, unsigned col);//Inicia uma matriz com todos os índices iguais a 0, de acordo com o número de linhas e colunas, respectivamente.
    void randU(unsigned row, unsigned col);//Gera uma matriz contendo numeros aleatórios com distribuição uniforme
    unsigned  length();//Retorna o maior tamanho entre as linhas e colunas
    UsedType max();//Retorna o maior valor de uma matriz
    UsedType min();//Retorna o menor valor de uma matriz

    void QR (Matrix<UsedType>& Q, Matrix<UsedType>& R);


    Matrix Avarage();
    Matrix Variance();
    Matrix Std();

    //###########################################//

    //#####Método de Impressão da Matriz#####//
    void print();

//    void prunsignedMatOr();

    //######################################//

    //#####Operadores da Matriz#####//

    //-----Operadores de Soma-----//
    Matrix operator+(Matrix Mat1);//Soma Matriz Matriz
    Matrix operator+(UsedType a);//Soma Escalar Matriz
    //--------------------------//

    //-----Operadores de Subtração-----//
    Matrix operator-(Matrix Mat1);//Subtração Matriz Matriz
    Matrix operator-(UsedType a);//Subtração Escalar Matriz
    //--------------------------------//

    //-----Operadores de Atribuição-----//
    void   operator=(Matrix Mat1);//Igualando Matriz Matriz
    void   operator=(string value);//Atribuindo String a Entrada da Matriz
    void   operator=(UsedType B(unsigned row, unsigned col));
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
    Matrix operator|  (Matrix Mat1);//Concatena Matrizes a Esquerda
    Matrix operator|| (Matrix Mat1);//Concatena Matrizes Abaixo
    //--------------------------------------------//

    //----Operador de Matriz Transposta-----//
    Matrix operator~();
    //-------------------------------------//

    //-----Operador de Potência de Matrizes-----//
    Matrix   operator^  (UsedType exp);//Eleva a matriz a um determinado expoente.
    Matrix   operator>  (UsedType num);//Eleva os elementos de uma matriz a um determinado
    UsedType operator() (unsigned row,unsigned col);//Acessa os elementos de uma matriz
    void     operator() (unsigned row, unsigned col, UsedType value);

    void lineVector(unsigned left, unsigned rigth);//Cria uma matriz elementos crescentes ou decrescentes de um em um de left até rigth
    //-----------------------------------------//

    //##########################################//

    //#####Álgebra Linear#####//
    UsedType trace();//Cálculo do traço de uma matriz.
    Matrix   transpose();
    Matrix   NumericInv();
    Matrix   inv();//Cálculo da matriz inversa da matriz.
    Matrix   pol();//Cálculo dos índices do polinômio característico da matriz.
    Matrix   eigenvalues();//Cálculo dos auto valores de uma matriz.
    UsedType NumericDet();
    UsedType det();//Cálculo do determinante de uma matriz.
    Matrix   cofactor();
    //##############################//



    //#####Retornando Informações da Matriz#####//
    unsigned  getRows();//Retorna o número de linhas da matriz.
    unsigned  getCols();//Retorna o número de colunas da matriz.
    void setLine(unsigned num, Matrix<UsedType> Line);
    void setColumn(unsigned num, Matrix<UsedType> Colummn);
    Matrix<UsedType> getLine(unsigned num);
    Matrix<UsedType> getColumn(unsigned num);
    UsedType getMat(unsigned row, unsigned col);//Retorna o elemento no índice ij da matriz.
    void     setMat(unsigned row, unsigned col, UsedType num);
    Matrix<UsedType> normalize(UsedType yUp, UsedType yDown);//Retorna uma matriz Normalizada
    //#######################################################//
//Friend functions
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Soma Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator- (FriendType a, Matrix<FriendType> Mat1);//Subtração Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator* (FriendType a, Matrix<FriendType> Mat1);//Multiplicação Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> operator/ (FriendType a, Matrix<FriendType> Mat1);//divisão Matriz Escalar
    template<class FriendType> friend Matrix<FriendType> diff(Matrix<FriendType> M, FriendType h);//Cálcula a derivada de uma matriz.
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
template<class UsedType>
UsedType max(Matrix<UsedType> M)
{
    UsedType  maximum = M(1,1);
     if(M.getRows() != 0 && M.getCols() != 0)
         for(unsigned i = 1; i <= M.getRows(); i++)
            for(unsigned j = 1; j <= M.getCols(); j++)
                if(maximum < M(i,j))
                    maximum = M(i,j);

     return maximum;
}

#endif // __MATRIX_H_INCLUDED
