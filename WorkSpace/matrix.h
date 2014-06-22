#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "externalfunctions.h"
#define pi 3.14

using namespace std;

class Matrix
{
private:
//    Matrix *Address;
//    int rows, cols, MatOriginalRows, MatOriginalCols, vet1Rows, vet1Cols, vet2Rows, vet2Cols;
//    float **Mat, **MatOriginal, **vet1, **vet2; //criei essa variável temprária para criar uma função que permita realizar a seguinte intrução A(vet1,vet2) = A(vet1,vet2)
    int rows, cols;
    float **Mat;

//    void initMatOriginal(int row, int col);
//    void initVet1(int row, int col);
//    void initVet2(int row, int col);


    //#####Verificação de Matriz Quadrada#####//
    bool sqr(Matrix Mat1);
    //#######################################//

    //#####Verficação se é uma Matriz Idenditade#####//
    bool ind(Matrix Mat1);
    //##############################################//

public:

    //#####Construtores e Destrutores da Classe#####//
    Matrix(); //Construtor
    Matrix(int row, int col);//Constroi a matriz de acordo com o número de linhas e colunas informados, respectivamente.
    Matrix(const Matrix & otherMatrix);//Faz uma cópia da Matriz
    ~Matrix();//Destrutor
    //#############################################//


    //#####Métodos de Inicialização da Matriz#####//
    void init(int row, int col); //Inicializador da Matriz de acordo com o número de linhas e colunas informados, respectivamente.
    void init(string value);//Adiciona os valores de uma string a matriz, serparando os elementos por "," e as linhas por ";".
    void add(int rol, int col, float number);//Adiciona elementos a matriz pelos índices i e j respectivamente. Obs.: i e j iniciam de 1 para este método.
    void eye(int num);//Cria uma matriz identidade de ordem num.
    void ones(int row, int col);//Inicia uma matriz com todos os índices iguais a 1, de acordo com o número de linhas e colunas respectivamente.
    void zeros(int row, int col);//Inicia uma matriz com todos os índices iguais a 0, de acordo com o número de linhas e colunas, respectivamente.
    void randU(int row, int col);//Gera uma matriz contendo numeros aleatórios com distribuição uniforme
    int length();//Retorna o maior tamanho entre as linhas e colunas

    Matrix Average();
    Matrix Variance();
    Matrix Std();

    //###########################################//

    //#####Método de Impressão da Matriz#####//
    void print();

//    void printMatOr();

    //######################################//

    //#####Operadores da Matriz#####//

    //-----Operadores de Soma-----//
    Matrix operator+(Matrix Mat1);//Soma Matriz Matriz
    Matrix operator+(float a);//Soma Escalar Matriz
    friend Matrix operator+(float a, Matrix Mat1);//Soma Matriz Escalar
    //--------------------------//

    //-----Operadores de Subtração-----//
    Matrix operator-(Matrix Mat1);//Subtração Matriz Matriz
    Matrix operator-(float a);//Subtração Escalar Matriz
    friend Matrix operator-(float a, Matrix Mat1);//Subtração Matriz Escalar
    //--------------------------------//

    //-----Operadores de Atribuição-----//
    void operator=(Matrix Mat1);//Igualando Matriz Matriz
    void operator=(string value);//Atribuindo String a Entrada da Matriz
    void operator=(float B(int row, int col));
    //---------------------------------//

    //-----Operadores de Multiplicação-----//
    Matrix operator*(Matrix Mat1);//Multiplicação Matriz Matriz
    Matrix operator*(float a);//Multiplicação Escalar Matriz
    friend Matrix operator*(float a, Matrix Mat1);//Multiplicação Matriz Escalar
    //------------------------------------//

    Matrix operator/(Matrix Mat1);
    Matrix operator/(float a);
    friend Matrix operator/(float a, Matrix Mat1);

    //-----Operadores de Concatenação Matrizes-----//
    Matrix operator| (Matrix Mat1);//Concatena Matrizes a Esquerda
    Matrix operator|| (Matrix Mat1);//Concatena Matrizes Abaixo
    //--------------------------------------------//

    //----Operador de Matriz Transposta-----//
    Matrix operator~();
    //-------------------------------------//

    //-----Operador de Potência de Matrizes-----//
    Matrix operator^(float exp);//Eleva a matriz a um determinado expoente.
    Matrix operator> (float num);//Eleva os elementos de uma matriz a um determinado
    float operator() (int row,int col);//Acessa os elementos de uma matriz
    void operator() (int row, int col, float value);

//    Matrix operator() (Matrix M1,Matrix M2);//Acessa n elementos de uma matriz
//    Matrix operator() (string M1,string M2);//Acessa n elementos de uma matriz

    void lineVector(int left, int rigth);//Cria uma matriz elementos crescentes ou decrescentes de um em um de left até rigth
    //-----------------------------------------//

    //##########################################//

    //#####Álgebra Linear#####//
    float trace();//Cálculo do traço de uma matriz.
    Matrix inv();//Cálculo da matriz inversa da matriz.
    Matrix pol();//Cálculo dos índices do polinômio característico da matriz.
    Matrix eigenvalues();//Cálculo dos auto valores de uma matriz.
    float det();//Cálculo do determinante de uma matriz.
    friend Matrix diff(Matrix M, float h);//Cálcula a derivada de uma matriz.
    //##############################//



    //#####Retornando Informações da Matriz#####//
    int getRows();//Retorna o número de linhas da matriz.
    int getCols();//Retorna o número de colunas da matriz.
    Matrix getLine(int num);
    float getMat(int row, int col);//Retorna o elemento no índice ij da matriz.
    void setMat(int row, int col, float num);
    //#######################################################//

    friend float max(Matrix M);//Retorna o maior valor de uma matriz
    friend float min(Matrix M);//Retorna o menor valor de uma matriz
    friend float norm(Matrix M);//Retorna o maior valor de uma matriz
    friend Matrix abs(Matrix M);//Retorna o modulo dos valores de uma matriz
    friend Matrix cos(Matrix M1);//Retorna o cosseno dos elementos de uma matriz
    friend Matrix sin(Matrix M1);//Retorna o seno dos elementos de uma matriz
    friend Matrix tan(Matrix M1);//Retorna a tangente dos elementos de uma matriz
    friend Matrix acos(Matrix M1);//Retorna o arco cosseno dos elementos de uma matriz
    friend Matrix asin(Matrix M1);//Retorna o arco seno dos elementos de uma matriz
    friend Matrix atan(Matrix M1);//Retorna o arco tangente dos elementos de uma matriz
    friend Matrix cosh(Matrix M1);//Retorna o cosseno hiperbólico dos elementos de uma matriz
    friend Matrix sinh(Matrix M1);//Retorna o seno hiperbólico dos elementos de uma matriz
    friend Matrix tanh(Matrix M1);//Retorna a tangente hiperbólica dos elementos de uma matriz
    friend Matrix acosh(Matrix M1);//Retorna o arco cosseno hiperbólico dos elementos de uma matriz
    friend Matrix asinh(Matrix M1);//Retorna o arco seno hiperbólico dos elementos de uma matriz
    friend Matrix atanh(Matrix M1);//Retorna o arco tangente hiperbólica dos elementos de uma matriz
    friend Matrix exp(Matrix M1);//Retorna a exponencial dos elementos de uma matriz
    friend Matrix log(Matrix M1);//Retorna o logaritmo neperiano dos elementos de uma matriz
    friend Matrix log10(Matrix M1);//Retorna o logaritmo na base 10 dos elementos de uma matriz
    friend Matrix ceil(Matrix M1);//arredonda para cima os elementos de uma matriz
    friend Matrix round(Matrix M1);//arredonda os elementos de uma matriz
    friend Matrix floor(Matrix M1);//arredonda para baixo os elementos de uma matriz
};

#endif // MATRIX_H
