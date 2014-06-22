#include "matrix.h"
#include <cstdlib>
#include <iostream>

//#####Início Verificação de tipos de Matrizes#####//

bool Matrix::sqr(Matrix Mat1)//Verifica se a matriz é quadrada.
{
    bool vef;

    if (Mat1.rows == Mat1.cols)
        vef = true;
    else
        vef = false;

    return vef;
}

bool Matrix::ind(Matrix Mat1)//Verifica se a matriz é identidade.
{
    bool vef;
    int x = 0, a = 0, b = 0;

    for (int i = 0; i < Mat1.rows; i ++)//Neste for o valor de x
        for(int j = 0; j < Mat1.rows; j++)//será igual a quantidade 1
            if ((i == j) && (Mat1.Mat[i][j]) == 1)//que se encontram na diagonal principal da matriz.
                x++;
    for(int i = 0; i < Mat1.rows; i++ )//Este for navega pelos elementos
        for(int j = i+1; j < Mat1.cols; j++)//acima da diagonal principal
        {                                   //verificando se algum deles for diferente de 0
            if (Mat1.Mat[i][j] != 0)        //se algum número for diferente de 0, o for é quebrado.
            {                               //Caso não a é incrementado.
                i = Mat1.rows + 1;
                a = -1;
                break;
            }
            else
                a++;
        }


    for(int i = 0; i < Mat1.rows; i++ )//Este for navega pelos elementos
        for(int j = i+1; j < Mat1.cols; j++)//abaixo da diagonal principal
        {                                   //verificando se algum deles for diferente de 0
            if (Mat1.Mat[j][i] != 0)        //se algum número for diferente de 0, o for é quebrado.
            {                                //Caso não b é incrementado.
                i = Mat1.rows +1;
                b = -1;
                break;
            }
            else
                b++;
        }

    if (x == (Mat1.rows) && (a != -1) && (b != -1))//Verifica se x possui o mesmo valor
        vef = true;                                //das linhas da matriz, e se foi encontrado
    else                                           //elementos diferente de 0 acima ou abaixo da diagonal principal.
        vef = false;

    return vef;
}
//#####Fim Verificação de tipos de Matrizes#####//

//#####Início Construtores e Destrutores da Classe#####//

Matrix::Matrix() //Inicializa linhas e colunas com zero
{
    this->rows = 0;
    this->cols = 0;
//    this->MatOriginalRows = 0;
//    this->MatOriginalCols = 0;
//    this->vet1Rows = 0;
//    this->vet1Cols = 0;
//    this->vet2Rows = 0;
//    this->vet2Cols = 0;
}

Matrix::Matrix(int row, int col)//Inicializa a Matriz com as linhas e colunas determinadas.
{
    this->init(row, col);

//    this->MatOriginalRows = 0;
//    this->MatOriginalCols = 0;
//    this->vet1Rows = 0;
//    this->vet1Cols = 0;
//    this->vet2Rows = 0;
//    this->vet2Cols = 0;

}

Matrix::Matrix(const Matrix & otherMatrix)//Cria uma cópia da Matriz
{

    this->init(otherMatrix.rows, otherMatrix.cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->Mat[i][j] = otherMatrix.Mat[i][j];

//    this->initMatOriginal(otherMatrix.MatOriginalRows, otherMatrix.MatOriginalCols);
//    for (int i = 0; i < this->MatOriginalRows; i++)
//        for (int j = 0; j < this->MatOriginalCols; j++)
//            this->MatOriginal[i][j] = otherMatrix.MatOriginal[i][j];

//    this->initVet1(otherMatrix.vet1Rows, otherMatrix.vet1Cols);
//    for (int i = 0; i < this->vet1Rows; i++)
//        for (int j = 0; j < this->vet1Cols; j++)
//            this->vet1[i][j] = otherMatrix.vet1[i][j];

//    this->initVet2(otherMatrix.vet2Rows, otherMatrix.vet2Cols);
//    for (int i = 0; i < this->vet2Rows; i++)
//        for (int j = 0; j < this->vet2Cols; j++)
//            this->vet2[i][j] = otherMatrix.vet2[i][j];
}

Matrix::~Matrix()//Destrutor da Classe Matriz
{
//    if ((this->rows != 0) && (this->cols != 0))
//    {
//        for (int i = 0; i < this->rows; i++)
//        {
//            delete [] Mat[i];
//        }
//        delete [] Mat;
//        this->rows = 0;
//        this->cols = 0;
//        this->Mat = NULL;
//    }

    if ((this->rows != 0) && (this->cols != 0))
    {
        for (int i = 0; i < this->rows; i++)
        {
            free(this->Mat[i]);
            this->Mat[i] = NULL;
        }
        free(this->Mat);
        this->rows = 0;
        this->cols = 0;
        this->Mat = NULL;
    }

//    if ((this->MatOriginalRows != 0) && (this->MatOriginalCols != 0))
//    {
//        for (int i = 0; i < this->MatOriginalRows; i++)
//        {
//            free(this->MatOriginal[i]);
//            this->MatOriginal[i] = NULL;
//        }
//        free(this->MatOriginal);
//        this->MatOriginalRows = 0;
//        this->MatOriginalCols = 0;
//        this->MatOriginal = NULL;
//    }

//    if ((this->vet1Rows != 0) && (this->vet1Cols != 0))
//    {
//        for (int i = 0; i < this->vet1Rows; i++)
//        {
//            free(this->vet1[i]);
//            this->vet1[i] = NULL;
//        }
//        free(this->vet1);
//        this->vet1Rows = 0;
//        this->vet1Cols = 0;
//        this->vet1 = NULL;
//    }

//    if ((this->vet2Rows != 0) && (this->vet2Cols != 0))
//    {
//        for (int i = 0; i < this->vet2Rows; i++)
//        {
//            free(this->vet2[i]);
//            this->vet2[i] = NULL;
//        }
//        free(this->vet2);
//        this->vet2Rows = 0;
//        this->vet2Cols = 0;
//        this->vet2 = NULL;
//    }
}
//#####Fim Construtores e Destrutores da Classe#####//

//#####Início Métodos de Inicialização de Matrizes#####//

void Matrix::init(int row, int col)//Aloca o espaço de memória para a Matriz e inicializa com 0
{
    this->Mat = (float**)calloc(col,(row)*sizeof(float*)); //Cria as linhas
    for (int i = 0; i < row; i++)
        this->Mat[i] = (float*)calloc(col,(col)*sizeof(float)); //Cria as colunas
    this->rows = row;
    this->cols = col;

//    this->Mat = new float*[row];
//    for(int i = 0; i < row; i++)
//        this->Mat[i] = new float[col];

    this->rows = row;
    this->cols = col;
}

//void Matrix::initMatOriginal(int row, int col)
//{
//    this->MatOriginal = (float**)calloc(col,(row)*sizeof(float*)); //Cria as linhas
//    for (int i = 0; i < row; i++)
//        this->MatOriginal[i] = (float*)calloc(row,(col)*sizeof(float)); //Cria as colunas
//    this->MatOriginalRows = row;
//    this->MatOriginalCols = col;
//}

//void Matrix::initVet1(int row, int col)
//{
//    this->vet1 = (float**)calloc(col,(row)*sizeof(float*)); //Cria as linhas
//    for (int i = 0; i < row; i++)
//        this->vet1[i] = (float*)calloc(row,(col)*sizeof(float)); //Cria as colunas
//    this->vet1Rows = row;
//    this->vet1Cols = col;
//}

//void Matrix::initVet2(int row, int col)
//{
//    this->vet2 = (float**)calloc(col,(row)*sizeof(float*)); //Cria as linhas
//    for (int i = 0; i < row; i++)
//        this->vet2[i] = (float*)calloc(row,(col)*sizeof(float)); //Cria as colunas
//    this->vet2Rows = row;
//    this->vet2Cols = col;
//}

void Matrix::init(string value)//Inicializa a Matriz com uma cadeia de strings como entrada
{
    int posComma, posSemiComma, col = 1, row = 1;
    string temp;

    while (!value.empty())
    {
        posSemiComma = value.find(";");
        if (posSemiComma != -1)
            temp = value.substr(0,posSemiComma);
        else
        {
            temp = value;
            posSemiComma = value.length();
        }
        while (!temp.empty())
        {
            posComma = temp.find(",");
            if( posComma == -1)
                posComma = temp.length();

            string temp2 = temp.substr(0, posComma);
            float num = atof(temp2.c_str());
            this->add(row, col, num);
            temp.erase(0, posComma+1);
            col++;
        }
        value.erase(0,posSemiComma+1);
        col = 1;
        row++;
    }
}

void Matrix::add(int row, int col, float number)//Adiciona valores a matriz,
{                                               //se tiver valores maiores que as dimensões da matriz, coloca o valor na posição indicada completando o resto com 0
     Matrix Temp;

    if (this->rows < row || this->cols < col)
    {
        if(this->rows == 0 || this->cols == 0)
            this->init(1,1);

        if (this->rows < row)
           Temp.init(row, this->cols);
        else
           Temp.init(this->rows, col);

        if((this->rows != 0) && (this->cols != 0))
        {
            for(int i = 0; i < this->rows; i++)
                for (int j = 0; j < this->cols; j++)
                    Temp.Mat[i][j] = this->Mat[i][j];
        }
        Temp.Mat[row-1][col-1] = number;
        this->init(Temp.rows, Temp.cols);

        for(int i = 0; i < this->rows; i++)
            for (int j = 0; j < this->cols; j++)
                this->Mat[i][j] = Temp.Mat[i][j];
    }
    else
        this->Mat[row-1][col-1] = number;


}

void Matrix::eye(int num)//Gera uma Matriz Identidade, entrando como parâmetro a dimensão quadrada da Matriz
{
    this->init(num,num);
    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            if (i == j)
                this->Mat[i][j] = 1;

}

void Matrix::ones(int row, int col)//Cria uma matriz preenchida com 1s.
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->Mat[i][j] = 1;
}

void Matrix::zeros(int row, int col)//Gera uma Matriz de Zeros, tendo como entrada as dimensões indicadas.
{
    this->init(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            this->Mat[i][j] = 0;
}

void Matrix::randU(int row, int col)
{
    srand((time(NULL)));
    float t;
    this->init(row, col);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
        {
            t = (float)rand()/RAND_MAX;
            this->Mat[i][j] = t;
        }
}

int Matrix::length()
{
    int tam;

    if(this->rows > this->cols)
        tam = this->rows;
    else
        tam = this->cols;

    return tam;
}

Matrix Matrix::Average()
{
    Matrix ret;
    ret.zeros(1, this->cols);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + (this->Mat[i][j])/this->cols;

    return ret;
}

Matrix Matrix::Variance()
{
    Matrix Media, ret;

    Media = this->Average();
    ret.zeros(1, this->cols);
    for(int i = 0; i < this->rows; i++)
        for(int j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + pow((this->Mat[i][j]-Media.Mat[0][j]),2)/this->cols;

    return ret;


}

Matrix Matrix::Std()
{
    Matrix ret, Variancia;

    Variancia = this->Variance();
    ret.zeros(1, this->cols);

    for(int i = 0; i < this->rows; i++)
        ret.Mat[0][i] = sqrt(Variancia.Mat[0][i]);

    return ret;
}

void Matrix::print()//Imprime a Matriz na Tela
{
    cout<<"\n";
    for (int i = 0; i< this->rows; i++)
    {
        for (int j = 0; j< this->cols; j++)
        {
            printf("%6.3f", this->Mat[i][j]);
            cout<<" ";
        }
        cout<<endl;
    }
}

//void Matrix::printMatOr()//Imprime a Matriz na Tela
//{
//    cout<<"\n";
//    for (int i = 0; i< this->MatOriginalRows; i++)
//    {
//        for (int j = 0; j< this->MatOriginalCols; j++)
//            cout<<this->MatOriginal[i][j]<<" ";
//        cout<<endl;
//    }
//}

//#####Fim Métodos de Inicialização de Matrizes#####//

//#####Início Sobrecarga de Operadores#####//

//-----Início Operadores de Soma-----//
Matrix Matrix::operator +(Matrix Mat1)//Operador de soma Matriz Matriz
{
    Matrix Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + Mat1.Mat[i][j];

    return Ret;
}

Matrix Matrix::operator +(float a)//Operador de soma Escalar Matriz
{
    Matrix Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + a;

    return Ret;
}

Matrix operator+(float a, Matrix Mat1)//Operador de soma Matriz Escalar
{
    return Mat1+a;
}
//-----Fim Operadores de Soma-----//

//-----Início Operadores de Subtração-----//
Matrix Matrix::operator -(Matrix Mat1)//Operador de subtração Matriz Matriz
{
    Matrix Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - Mat1.Mat[i][j];

    return Ret;
}

Matrix Matrix::operator -(float a)//Operador de subtração Escalar Matriz
{
    Matrix Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - a;

    return Ret;
}

Matrix operator-(float a, Matrix Mat1)//Operador de subtração Matriz Escalar
{
    return Mat1-a;
}
//-----Fim Operadores de Subtração-----//

//-----Início Operadores de Igualdade-----//

//void Matrix::operator= (Matrix Mat1)//Operador de Igualdade entre Matrizes
//{
//    if( this->MatOriginalRows == 0)
//    {
//        this->init(Mat1.rows, Mat1.cols);

//        for(int i = 0; i < this->rows; i++)
//            for (int j = 0; j < this->cols; j++)
//               this->Mat[i][j] = Mat1.Mat[i][j];
//        if(Mat1.MatOriginalRows != 0)
//        {
//            this->initMatOriginal(Mat1.MatOriginalRows, Mat1.MatOriginalCols);
//            for(int i = 0; i < this->MatOriginalRows; i++)
//                for (int j = 0; j < this->MatOriginalCols; j++)
//                   this->MatOriginal[i][j] = Mat1.MatOriginal[i][j];

//            this->initVet1(Mat1.vet1Rows, Mat1.vet1Cols);
//            for(int i = 0; i < this->vet1Rows; i++)
//                for (int j = 0; j < this->vet1Cols; j++)
//                   this->vet1[i][j] = Mat1.vet1[i][j];

//            this->initVet2(Mat1.vet2Rows, Mat1.vet2Cols);
//            for(int i = 0; i < this->vet2Rows; i++)
//                for (int j = 0; j < this->vet2Cols; j++)
//                    this->vet2[i][j] = Mat1.vet2[i][j];
//        }
//    }
//    else if((Mat1.vet1Rows == 0 || this->vet1Rows == 0) || (Mat1.vet2Cols == 0 || this->vet2Cols == 0))
//    {
//        try
//        {
//            throw "As dimensoes das matrizes nao batem, atribuição nao e possivel";
//        }
//        catch(const char* msg)
//        {
//            cerr<<endl<<msg<<endl;
//        }
//    }
//    else
//    {
//        if (this->vet1Cols == Mat1.vet1Cols && this->vet2Cols == Mat1.vet2Cols )
//        {

//            for(int i = 0; i < this->vet1Cols; i++)
//                for (int j = 0; j < this->vet2Cols; j++)
//                {
//                    int rowTemp = (int) this->vet1[0][i] - 1;
//                    int colTemp = (int) this->vet2[0][j] - 1;
//                    this->MatOriginal[rowTemp][colTemp] = Mat1.Mat[i][j];
//                }
//            Matrix Temp;
//            Temp.init(this->MatOriginalRows, this->MatOriginalCols);
//            for(int i = 0; i < Temp.rows; i++)
//                for (int j = 0; j < Temp.cols; j++)
//                    Temp.Mat[i][j] = this->MatOriginal[i][j];

//            this->Address->init(Temp.rows,Temp.cols);
//            for(int i = 0; i < this->Address->rows; i++)
//                for (int j = 0; j < this->Address->cols; j++)
//                    this->Address->Mat[i][j] = Temp.Mat[i][j];
////            this->Address->print();
//        }
//        else
//        {
//            try
//            {
//                throw "As dimensoes das matrizes nao batem, atribuição nao e possivel";
//            }
//            catch(const char* msg)
//            {
//                cerr<<endl<<msg<<endl;
//            }
//        }
//    }
//}

void Matrix::operator= (Matrix Mat1)//Operador de Igualdade entre Matrizes
{
    this->init(Mat1.rows, Mat1.cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->Mat[i][j] = Mat1.Mat[i][j];
}


void Matrix::operator=(string value)//Operador para a entrada de uma String
{
    this->init(value);
}

//-----Fim Operadores de Igualdade-----//

//-----Início Operadores de Multplicação-----//
Matrix Matrix::operator *(Matrix Mat1)//Operador de Multiplicação Matriz Matriz
{

    float temp = 0;
    Matrix Ret(this->rows, Mat1.cols);

    try
    {
        if (this->cols != Mat1.rows)
        {
            throw "As dimensoes das matrizes nao batem, a multiplicacao nao e possivel";
            Ret.zeros(this->rows, Mat1.cols);
        }
        else
        {
            for(int i = 0; i < this->rows; i++)
            {
                for (int col = 0; col < Mat1.cols; col++)
                {
                    temp = 0;
                    for (int j = 0; j < this->cols; j++)
                        temp += this->Mat[i][j]*Mat1.Mat[j][col];
                    Ret.Mat[i][col] = temp;
                }

            }
            return Ret;
       }
    }
    catch(const char* msg)
    {
        cerr<<endl<<msg<<endl;
    }
    return Ret;
}

Matrix Matrix::operator *(float a)//Operador de multiplicação Escalar Matriz
{
    Matrix Ret(this->rows, this->cols);

    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = a*this->Mat[i][j];

    return Ret;
}

Matrix operator*(float a, Matrix Mat1)//Operador de multiplicação Matriz Escalar
{
    return Mat1*a;
}
//-----Fim Operadores de Multiplicação-----//

//-----Início Operadores de Concatenação Matrizes-----//
Matrix Matrix::operator|(Matrix Mat1)//Concatenção de Matrizes a Esquerda
{
    Matrix temp(this->rows,this->cols+Mat1.cols);

    for(int i = 0; i < temp.rows; i++)
        for (int j = 0; j < temp.cols; j++)
            if(j<this->cols)
                temp.add(i+1,j+1,this->Mat[i][j]);
            else
                temp.add(i+1,j+1,Mat1.Mat[i][j-this->cols]);

    return temp;

}

Matrix Matrix::operator||(Matrix Mat1)//Concatenação de Matrizes Abaixo
{
    Matrix temp(this->rows+Mat1.rows,this->cols);

    if(this->rows == 0 and this->cols == 0)
        temp = Mat1;
    else
    {
        for(int j = 0; j < temp.cols; j++)
            for (int i = 0; i < temp.rows; i++)
                if(i<this->rows)
                    temp.add(i+1,j+1,this->Mat[i][j]);
                else
                temp.add(i+1,j+1,Mat1.Mat[i-this->rows][j]);
    }

    return temp;

}
//-----Fim Operadores de Concatenação Matrizes-----//

//----Início Operador de Matriz Transposta-----//
Matrix Matrix::operator~()//Faz a transporta da Matriz
{
    Matrix Ret (this->cols, this->rows);
    for(int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
                Ret.Mat[j][i] = this->Mat[i][j];

    return Ret;
}
//----Fim Operador de Matriz Transposta-----//

//-----Início Operador de Potência de Matrizes-----//
Matrix Matrix::operator^(float exp)
{
    Matrix Ret, temp = *this;

    Ret.eye(this->rows);

    if(exp < 0)
    {
        temp = this->inv();
        exp = exp*(-1);
    }


    Ret.eye(this->rows);

    for(float i = 0; i < exp; i++)
    {
            Ret = Ret*temp;
    }

    return Ret;
}

Matrix Matrix::operator >(float num)//Eleva os elementos da Matriz a um determinado expoente
{
    Matrix Ret = *this;

    for(int i = 0; i < Ret.rows; i++)
        for(int j = 0; j < Ret.cols; j++)
            Ret.Mat[i][j] = pow(this->Mat[i][j],num);

    return Ret;
}
//-----Fim Operador de Potência de Matrizes-----//

//#####Fim Sobrecarga de Operadores#####//

//#####Início Álgebra Linear#####//
float Matrix::trace()//Cálcula o Traço da Matriz
{
   float traco = 0;

   try
   {
        if(!this->sqr(*this))
            throw "A matrix nao e quadrada";
        else
            for(int i = 0; i < this->rows; i++ )
                for(int j = 0; j < this->cols; j++)
                    if( i == j)
                        traco = traco + this->Mat[i][j];
   }
   catch (const char* msg)
   {
        cerr<<msg<<endl;
   }

    return traco;
}

Matrix Matrix::inv()//Encontra a Matriz Inversa.
{
    Matrix Ret =*this, Id;


    try
    {
        if (!this->sqr(*this))
            throw "A matriz nao e quadrada";
        else
        {
            Id.eye(this->rows);

            for(int i = 0; i < this->rows; i++ )
                for(int j = i+1; j<this->rows; j++)
                {
                    float m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(int k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }


            for(int i = this->rows-1; i >=0 ; i-- )
                for(int j = i-1; j>=0; j--)
                {
                    float m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(int k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }

            for(int i=0; i< this->rows; i++)
            {
                float m = 1/Ret.Mat[i][i];
                for(int j=0; j<this->rows; j++)
                {
                     Ret.Mat[i][j] = m*Ret.Mat[i][j];
                     Id.Mat[i][j] = m*Id.Mat[i][j];
                }

            }
        }

    }

    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return Id;
}

Matrix Matrix::pol()//Encontra os Índices do Polinômio Característico
{
    Matrix A = *this, B, I, C, ind(1, this->cols + 1);
    int sinal;

    try
    {
         if(!this->sqr(*this))
             throw "A matrix nao e quadrada";
         else
             I.eye(this->rows);
             C = A;
             sinal = pow(-1, this->rows);
             ind.Mat[0][0] = 1;
             for(int i = 1; i <= this->rows; i++ )
             {
                    ind.Mat[0][i] = (C.trace()/i);
                    B = C - ind.Mat[0][i]*I;
                    C = A*B;
                    ind.Mat[0][i] = -ind.Mat[0][i];

             }
             for (int i = 0; i < (ind.cols); i++)
                 ind.Mat[0][i] = ind.Mat[0][i]*sinal;

    }
    catch (const char* msg)
    {
         cerr<<msg<<endl;
    }

    return ind;
}

Matrix Matrix::eigenvalues()//Encontra os Auto Valores da Matriz.
{
    Matrix autovlr(1, this->rows);

    try
    {
       if (!this->sqr(*this))
           throw "A matrix não é quadrada";
       else
           if (!this->ind(*this))
       {
                   Matrix Q, temp, R, A = *this;
                   float max = 1000;

                   Q.eye(this->rows);
                   R.eye(this->rows);
                   while (max > 0.00001)
                   {
                       for(int i = 0; i < this->rows; i++ )
                           for(int j = i+1; j<this->rows; j++)
                               {
                                        temp.eye(this->rows);
                                        if (A.Mat[i][j] != 0)
                                        {
                                            temp.Mat[i][i] = (A.Mat[i][i])/sqrt(pow(A.Mat[i][i],2) + pow(A.Mat[i][j],2));
                                            temp.Mat[j][j] = temp.Mat[i][i];
                                            temp.Mat[i][j] = (A.Mat[i][j])/sqrt(pow(A.Mat[i][i],2) + pow(A.Mat[i][j],2));
                                            temp.Mat[j][i] = - temp.Mat[i][j];
                                        }
                                       R = temp*A;
                                       A = R*(~temp);
                           }
                       for(int i = 0; i < this->rows; i++ )
                           for(int j = i+1; j< this->rows; j++)
                           {
                               if ((A.Mat[i][j] > 0) && (A.Mat[i][j]) < max)
                                   max = A.Mat[i][j];
                               else if((A.Mat[i][j] < 0) && (-1*A.Mat[i][j]) < max)
                                   max = -1*(A.Mat[i][j]);
                           }
                    }
                   for(int i = 0; i < this->rows; i++ )
                       for(int j = 0; j< this->rows; j++)
                           if (i == j)
                                autovlr.Mat[0][i] = A.Mat[i][j];
       }
            else
               for(int i = 0; i < this->rows; i++ )
                   autovlr.Mat[0][i] = 1;

      }

    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return autovlr;
}

float Matrix::det()//Encontra o determinante da Matriz.
{
    float x = 1;
    Matrix A;

    try
    {
        if (!this->sqr(*this))
            throw "A matrix não é quadrada";
        else if(!this->ind(*this))
             {
                A = this->eigenvalues();

                for (int i = 0; i < A.cols; i++)
                    x *= A.Mat[0][i];
             }
             else
                x = 1;
    }
    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return x;
}

Matrix diff(Matrix M, float h)//Encontra a derivada de uma Matriz
{
    Matrix Ret;
    for(int i = 0; i < M.rows-1; i++)
        for(int j = 0; j < M.cols; j++)
            Ret.add(i+1,j+1,(M.Mat[i+1][j] - M.Mat[i][j])/h);

    return Ret;
}
//#####Fim Álgebra Linear#####//

//#####Início Funções de Retorno de Informações da Matriz#####//
int Matrix::getRows()//Retorna o numéro de linhas de uma Matriz.
{
    return this->rows;
}

int Matrix::getCols()//Retorna o numéro de colunas de uma Matriz.
{
    return this->cols;
}

Matrix Matrix::getLine(int num)
{
    Matrix ret(1,this->cols);

    for (int i = 0; i < this->cols; i++)
        ret.Mat[0][i] = this->Mat[num-1][i];

    return ret;
}

//float Matrix::getMat(int row, int col)//Retorna o valor do elemento no índice ij.
//{
//    return this->Mat[row-1][col-1];
//}
//#####Fim Funções de Retorno de Informações da Matriz#####//
//-----Funções Auxiliares para biblioteca de matrizes------//

float max(Matrix M)
{
     float  maximum = M.Mat[0][0];

     for(int i = 0; i < M.rows; i++)
       for(int j = 0; j < M.cols; j++)
         if(maximum < M.Mat[i][j])
           maximum = M.Mat[i][j];

     return maximum;
}

float Matrix::operator()(int row, int col)
{
    return this->Mat[row-1][col-1];
}

void Matrix::operator ()(int row, int col, float value)
{
    this->add(row, col, value);
}


float min(Matrix M)
{
  float  minimun;
  minimun = M.Mat[0][0];

  for(int i = 0; i < M.rows; i++)
    for(int j = 0; j < M.cols; j++)
      if(minimun > M.Mat[i][j])
        minimun = M.Mat[i][j];

  return minimun;
}

//Matrix Matrix::operator() (Matrix M1,Matrix M2)
//{
//    float maxM1 = max(M1), maxM2 = max(M2), minM1 = min(M1), minM2 = min(M2);
//    Matrix Ret;
//    try
//    {
//        if (minM1 < 1 || minM2 < 1 || maxM1 > this->rows || maxM2 > this->cols)
//            throw "A matrix não é quadrada";
//        else
//        {
//            for(int i = 1; i <= M1.getCols(); i++)
//                for(int j = 1; j <= M2.getCols(); j++)
//                    Ret.add(i, j, this->Mat[(int)M1(1,i) - 1][(int)M2(1,j) - 1]);
//            Ret.initMatOriginal(this->rows, this->cols);
//            Ret.initVet1(M1.rows, M1.cols);
//            Ret.initVet2(M2.rows, M2.cols);
////            this->print();
//            for(int i = 0; i < Ret.MatOriginalRows; i++)
//                for(int j = 0; j < Ret.MatOriginalCols; j++)
//                    Ret.MatOriginal[i][j] = this->Mat[i][j];

////            Ret.printMatOr();

//            for(int i = 0; i < Ret.vet1Rows; i++)
//                for(int j = 0; j < Ret.vet1Cols; j++)
//                    Ret.vet1[i][j] = M1.Mat[i][j];

//            for(int i = 0; i < Ret.vet2Rows; i++)
//                for(int j = 0; j < Ret.vet2Cols; j++)
//                    Ret.vet2[i][j] = M2.Mat[i][j];
//        }
//    }
//    catch (const char* msg)
//    {
//        cerr<<msg<<endl;
//    }
//    Ret.Address = this;
//    return Ret;
//}

//Matrix Matrix::operator() (string S1,string S2)
//{
//    Matrix M1, M2, Ret;

//    M1 = S1;
//    M2 = S2;
//    Ret = this->operator ()(M1,M2);
////    Ret.print();
//    Ret.Address = this;
////    this->print();
////    Ret.printMatOr();
//    return Ret;
//}


void Matrix::lineVector(int left, int rigth)
{
    int j = 1;
    if (left > rigth)
        for(int i = left; i >= rigth; i--)
        {
            this->add(1,j, i);
            j++;
        }
    else
        for(int i = left; i <= rigth; i++)
        {
            this->add(1,j, i);
            j++;
        }
}



Matrix abs(Matrix M)
{
    Matrix ret = M;
    for(  int i = 0; i < M.rows; i++)
        for(  int j = 0; j < M.cols; j++)
            if (ret.Mat[i][j] < 0)
                ret.Mat[i][j] = -ret.Mat[i][j];

    return ret;
}

//-----------------------------------------------------//

Matrix cos(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cos(M1(i+1,j+1)));

    return ret;

}

Matrix sin(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sin(M1(i+1,j+1)));

    return ret;
}

Matrix tan(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tan(M1(i+1,j+1)));

    return ret;

}

Matrix acos(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acos(M1(i+1,j+1)));

    return ret;


}

Matrix asin(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asin(M1(i+1,j+1)));

    return ret;


}

Matrix atan(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atan(M1(i+1,j+1)));

    return ret;

}

Matrix cosh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cosh(M1(i+1,j+1)));

    return ret;

}

Matrix sinh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sinh(M1(i+1,j+1)));

    return ret;


}

Matrix tanh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tanh(M1(i+1,j+1)));

    return ret;


}

Matrix acosh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acosh(M1(i+1,j+1)));

    return ret;


}

Matrix asinh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asinh(M1(i+1,j+1)));

    return ret;


}

Matrix atanh(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atanh(M1(i+1,j+1)));

    return ret;

}

Matrix exp(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, exp(M1(i+1,j+1)));

    return ret;


}

Matrix log(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log(M1(i+1,j+1)));

    return ret;


}

Matrix log10(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log10(M1(i+1,j+1)));

    return ret;


}

Matrix ceil(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, ceil(M1(i+1,j+1)));

    return ret;


}

Matrix floor(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, floor(M1(i+1,j+1)));

    return ret;
}

Matrix round(Matrix M1)
{
    Matrix ret = M1;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, round(M1(i+1,j+1)));

    return ret;
}

float norm(Matrix M1)
{
    float sum = 0;
    for(  int i = 0; i < M1.getRows(); i++)
        for(  int j = 0; j < M1.getCols(); j++)
            sum += pow(M1(i+1,j+1), 2);

    return sqrt(sum);
}

//double operator ^(double num1, double num2)
//{
//    return pow(num1,num2);
//}

Matrix Matrix::operator /(Matrix Mat1)
{
    return *this*(Mat1.inv());
}

Matrix Matrix::operator /(float a)
{
    return *this*(1/a);
}

Matrix operator/(float a, Matrix Mat1)
{
    return Mat1*(1/a);
}




