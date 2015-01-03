#include "matrix.h"


//#####Início Verificação de tipos de Matrizes#####//
template <class UsedType>
bool Matrix<UsedType>::sqr(Matrix<UsedType> Mat1)//Verifica se a matriz é quadrada.
{
    bool vef;

    if (Mat1.rows == Mat1.cols)
        vef = true;
    else
        vef = false;

    return vef;
}

template <class UsedType>
bool Matrix<UsedType>::ind(Matrix<UsedType> Mat1)//Verifica se a matriz é identidade.
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

template <class UsedType>
Matrix<UsedType>::Matrix() //Inicializa linhas e colunas com zero
{
    this->rows = 0;
    this->cols = 0;
}

template <class UsedType>
Matrix<UsedType>::Matrix(string value) //Inicializa linhas e colunas com zero
{
    this->rows = 0;
    this->cols = 0;
    this->init(value);
}

template <class UsedType>
Matrix<UsedType>::Matrix(unsigned row, unsigned col)//Inicializa a Matriz com as linhas e colunas determinadas.
{
    this->init(row, col);
}

template <class UsedType>
Matrix<UsedType>::Matrix(const Matrix<UsedType> & otherMatrix)//Cria uma cópia da Matriz
{

    this->init(otherMatrix.rows, otherMatrix.cols);
    for (unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            this->Mat[i][j] = otherMatrix.Mat[i][j];
}

template <class UsedType>
Matrix<UsedType>::~Matrix()//Destrutor da Classe Matriz
{
    if ((this->rows != 0) && (this->cols != 0))
    {
        for (unsigned i = 0; i < this->rows; i++)
        {
            free(this->Mat[i]);
            this->Mat[i] = NULL;
        }
        free(this->Mat);
        this->rows = 0;
        this->cols = 0;
        this->Mat = NULL;
    }
}
//#####Fim Construtores e Destrutores da Classe#####//

//#####Início Métodos de Inicialização de Matrizes#####//

template <class UsedType>
void Matrix<UsedType>::init(unsigned row, unsigned col)//Aloca o espaço de memória para a Matriz e inicializa com 0
{
    this->Mat = (UsedType**)calloc(col,(row)*sizeof(UsedType*)); //Cria as linhas
    for (unsigned i = 0; i < row; i++)
        this->Mat[i] = (UsedType*)calloc(col,(col)*sizeof(UsedType)); //Cria as colunas
    this->rows = row;
    this->cols = col;
}

template <class UsedType>
void Matrix<UsedType>::init(string value)//Inicializa a Matriz com uma cadeia de strings como entrada
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
            UsedType num = (UsedType)atof(temp2.c_str());
            this->add(row, col, num);
            temp.erase(0, posComma+1);
            col++;
        }
        value.erase(0,posSemiComma+1);
        col = 1;
        row++;
    }
}

template <class UsedType>
void Matrix<UsedType>::add(unsigned row, unsigned col, UsedType number)//Adiciona valores a matriz,
{                                               //se tiver valores maiores que as dimensões da matriz, coloca o valor na posição indicada completando o resto com 0
     Matrix<UsedType> Temp;

    if (this->rows < row || this->cols < col)
    {
        if(this->rows == 0 || this->cols == 0)
            this->init(1,1);

        if (this->rows < row && row > 0)
           Temp.init(row, this->cols);
        else
           Temp.init(this->rows, col);

        if((this->rows != 0) && (this->cols != 0))
        {
            for(unsigned i = 0; i < this->rows; i++)
                for (unsigned j = 0; j < this->cols; j++)
                    Temp.Mat[i][j] = this->Mat[i][j];
        }
        Temp.Mat[row-1][col-1] = number;
        this->init(Temp.rows, Temp.cols);

        for(unsigned i = 0; i < this->rows; i++)
            for (unsigned j = 0; j < this->cols; j++)
                this->Mat[i][j] = Temp.Mat[i][j];
    }
    else
        this->Mat[row-1][col-1] = number;


}

template <class UsedType>
void Matrix<UsedType>::eye(unsigned num)//Gera uma Matriz Identidade, entrando como parâmetro a dimensão quadrada da Matriz
{
    this->init(num,num);
    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            if (i == j)
                this->Mat[i][j] = 1;

}

template <class UsedType>
void Matrix<UsedType>::ones(unsigned row, unsigned col)//Cria uma matriz preenchida com 1s.
{
    this->init(row, col);
    for (unsigned i = 0; i < row; i++)
        for (unsigned j = 0; j < col; j++)
            this->Mat[i][j] = 1;
}

template <class UsedType>
void Matrix<UsedType>::zeros(unsigned row, unsigned col)//Gera uma Matriz de Zeros, tendo como entrada as dimensões indicadas.
{
    this->init(row, col);
    for(unsigned i = 0; i < row; i++)
        for(unsigned j = 0; j < col; j++)
            this->Mat[i][j] = 0;
}

template <class UsedType>
void Matrix<UsedType>::randU(unsigned row, unsigned col)
{
    srand((time(NULL)));
    UsedType t;
    this->init(row, col);
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->cols; j++)
        {
            t = (UsedType)rand()/RAND_MAX;
            this->Mat[i][j] = t;
        }
}

template <class UsedType>
unsigned Matrix<UsedType>::length()
{
    unsigned tam;

    if(this->rows > this->cols)
        tam = this->rows;
    else
        tam = this->cols;

    return tam;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Avarage()
{
    Matrix<UsedType> ret;
    ret.zeros(1, this->cols);
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + (this->Mat[i][j])/this->cols;

    return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Variance()
{
    Matrix<UsedType> Media, ret;

    Media = this->Avarage();
    ret.zeros(1, this->cols);
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->cols; j++)
            ret.Mat[0][j] = ret.Mat[0][j] + pow((this->Mat[i][j]-Media.Mat[0][j]),2)/this->cols;

    return ret;


}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::Std()
{
    Matrix<UsedType> ret, Variancia;

    Variancia = this->Variance();
    ret.zeros(1, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        ret.Mat[0][i] = sqrt(Variancia.Mat[0][i]);

    return ret;
}

template <class UsedType>
void Matrix<UsedType>::print()//Imprime a Matriz na Tela
{
    cout<<"\n";
    for (unsigned i = 0; i< this->rows; i++)
    {
        for (unsigned j = 0; j< this->cols; j++)
        {
            printf("%6.3f", (float)this->Mat[i][j]);
            cout<<" ";
        }
        cout<<endl;
    }
}

//#####Fim Métodos de Inicialização de Matrizes#####//

//#####Início Sobrecarga de Operadores#####//

//-----Início Operadores de Soma-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator +(Matrix<UsedType> Mat1)//Operador de soma Matriz Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + Mat1.Mat[i][j];

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator +(UsedType a)//Operador de soma Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] + a;

    return Ret;
}

template <class UsedType>
Matrix<UsedType> operator+(UsedType a, Matrix<UsedType> Mat1)//Operador de soma Matriz Escalar
{
    return Mat1+a;
}
//-----Fim Operadores de Soma-----//

//-----Início Operadores de Subtração-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator -(Matrix<UsedType> Mat1)//Operador de subtração Matriz Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - Mat1.Mat[i][j];

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator -(UsedType a)//Operador de subtração Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j] - a;

    return Ret;
}

template <class UsedType>
Matrix<UsedType> operator-(UsedType a, Matrix<UsedType> Mat1)//Operador de subtração Matriz Escalar
{
    return Mat1-a;
}
//-----Fim Operadores de Subtração-----//

//-----Início Operadores de Igualdade-----//

template <class UsedType>
void Matrix<UsedType>::operator= (Matrix<UsedType> Mat1)//Operador de Igualdade entre Matrizes
{
    this->init(Mat1.rows, Mat1.cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            this->Mat[i][j] = Mat1.Mat[i][j];
}

template <class UsedType>
void Matrix<UsedType>::operator=(string value)//Operador para a entrada de uma String
{
    this->init(value);
}

//-----Fim Operadores de Igualdade-----//

//-----Início Operadores de Multplicação-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator *(Matrix<UsedType> Mat1)//Operador de Multiplicação Matriz Matriz
{

    UsedType temp = 0;
    Matrix<UsedType> Ret(this->rows, Mat1.cols);

    try
    {
        if(this->cols == Mat1.rows)
        {
            for(unsigned i = 0; i < this->rows; i++)
            {
                for (unsigned col = 0; col < Mat1.cols; col++)
                {
                    temp = 0;
                    for (unsigned j = 0; j < this->cols; j++)
                        temp += this->Mat[i][j]*Mat1.Mat[j][col];
                    Ret.Mat[i][col] = temp;
                }

            }

            return Ret;
       }

        else
        {
            throw "As dimensoes das matrizes nao batem, a multiplicacao nao e possivel";
            Ret.zeros(this->rows, Mat1.cols);
        }
    }
    catch(const char* msg)
    {
        cerr<<endl<<msg<<endl;
    }
    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator *(UsedType a)//Operador de multiplicação Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = a*this->Mat[i][j];

    return Ret;
}

template <class FriendType>
Matrix<FriendType> operator*(FriendType a, Matrix<FriendType> Mat1)//Operador de multiplicação Matriz Escalar
{
    return Mat1*a;
}
//-----Fim Operadores de Multiplicação-----//

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator /(Matrix<UsedType> Mat1)//Operador de Multiplicação Matriz Matriz
{
    if(Mat1.rows == 1 && Mat1.cols == 1)
        return (*this)/(Mat1(1,1));
    else if(this->rows == 1 && this->cols == 1)
        return ((*this)(1,1))*Mat1.inv();
    else
        return (*this)*Mat1.inv();
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator/ (UsedType a)//Operador de multiplicação Escalar Matriz
{
    Matrix<UsedType> Ret(this->rows, this->cols);

    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
            Ret.Mat[i][j] = this->Mat[i][j]/a;

    return Ret;
}

template <class FriendType>
Matrix<FriendType> operator/ (FriendType a, Matrix<FriendType> Mat1)//Operador de multiplicação Matriz Escalar
{
    return a*Mat1.inv();
}


//-----Início Operadores de Concatenação Matrizes-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator|(Matrix<UsedType> Mat1)//Concatenção de Matrizes a Esquerda
{
    Matrix<UsedType> temp;

    if (this->rows > 0)
        temp.init(this->rows,this->cols+Mat1.cols);
    else
        temp.init(1,this->cols+Mat1.cols);

    for(unsigned i = 0; i < temp.rows; i++)
        for (unsigned j = 0; j < temp.cols; j++)
            if(j<this->cols)
                temp.add(i+1,j+1,this->Mat[i][j]);
            else
                temp.add(i+1,j+1,Mat1.Mat[i][j-this->cols]);

    return temp;

}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator||(Matrix<UsedType> Mat1)//Concatenação de Matrizes Abaixo
{
    Matrix<UsedType> temp(this->rows+Mat1.rows,this->cols);

    if(this->rows == 0 and this->cols == 0)
        temp = Mat1;
    else
    {
        for(unsigned j = 0; j < temp.cols; j++)
            for (unsigned i = 0; i < temp.rows; i++)
                if(i<this->rows)
                    temp.add(i+1,j+1,this->Mat[i][j]);
                else
                temp.add(i+1,j+1,Mat1.Mat[i-this->rows][j]);
    }

    return temp;

}
//-----Fim Operadores de Concatenação Matrizes-----//

//----Início Operador de Matriz Transposta-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator~()//Faz a transporta da Matriz
{
    Matrix<UsedType> Ret (this->cols, this->rows);
    for(unsigned i = 0; i < this->rows; i++)
        for (unsigned j = 0; j < this->cols; j++)
                Ret.Mat[j][i] = this->Mat[i][j];

    return Ret;
}
//----Fim Operador de Matriz Transposta-----//

//-----Início Operador de Potência de Matrizes-----//
template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator^(UsedType exp)
{
    Matrix<UsedType> Ret, temp = *this;

    Ret.eye(this->rows);

    if(exp < 0)
    {
        temp = this->inv();
        exp = exp*(-1);
    }


    Ret.eye(this->rows);

    for(unsigned i = 0; i < exp; i++)
    {
            Ret = Ret*temp;
    }

    return Ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::operator >(UsedType num)//Eleva os elementos da Matriz a um determinado expoente
{
    Matrix<UsedType> Ret = *this;

    for(unsigned i = 0; i < Ret.rows; i++)
        for(unsigned j = 0; j < Ret.cols; j++)
            Ret.Mat[i][j] = pow(this->Mat[i][j],num);

    return Ret;
}
//-----Fim Operador de Potência de Matrizes-----//

//#####Fim Sobrecarga de Operadores#####//

//#####Início Álgebra Linear#####//
template <class UsedType>
UsedType Matrix<UsedType>::trace()//Cálcula o Traço da Matriz
{
   UsedType traco = 0;

   try
   {
        if(!this->sqr(*this))
            throw "A matrix nao e quadrada";
        else
            for(unsigned i = 0; i < this->rows; i++ )
                for(unsigned j = 0; j < this->cols; j++)
                    if( i == j)
                        traco = traco + this->Mat[i][j];
   }
   catch (const char* msg)
   {
        cerr<<msg<<endl;
   }

    return traco;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::transpose()
{
  Matrix trans;
  trans.zeros(this->cols, this->rows);

  for(int i = 0; i < this->rows; i++)
    for(int j = 0; j < this->cols; j++)
      trans.Mat[j][i] = this->Mat[i][j];

  return trans;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::cofactor()
{
  unsigned i, j, ii, jj, i1, j1;
//  double det;
  Matrix<UsedType> Temp, ret;
  unsigned n = this->rows;
  Temp.zeros(n-1, n-1);
  ret.zeros(n, n);

  if(this->rows != this->cols)
    return ret;
  if (n < 1) { /* Error */

  }

  for(j=0; j<n; j++)
    for(i=0; i<n; i++) {

      /* Form the adjoint a_ij */
      i1 = 0;
      for(ii=0; ii<n; ii++) {
        if(ii == i)
          continue;

        j1 = 0;
        for(jj=0; jj<n; jj++) {
          if(jj == j)
            continue;

          Temp.Mat[i1][j1] = this->Mat[ii][jj];
          j1++;
        }
        i1++;
      }

      /* Fill in the elements of the cofactor */
      ret.Mat[i][j] = pow(-1.0, i+j+2.0) * Temp.det();
    }

  return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::NumericInv()
{
    Matrix<UsedType> Ret =*this, Id;


    try
    {
        if (!this->sqr(*this))
            throw "A matriz nao e quadrada";
        else
        {
            Id.eye(this->rows);

            for(unsigned i = 0; i < this->rows; i++ )
                for(unsigned j = i+1; j<this->rows; j++)
                {
                    UsedType m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(int k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }


            for(unsigned i = this->rows-1; i >=0 ; i-- )
                for(unsigned j = i-1; j>=0; j--)
                {
                    UsedType m = Ret.Mat[j][i]/Ret.Mat[i][i];
                    for(unsigned k = 0; k <this->cols; k++)
                    {
                        Ret.Mat[j][k] = Ret.Mat[j][k]-m*Ret.Mat[i][k];
                        Id.Mat[j][k] = Id.Mat[j][k]-m*Id.Mat[i][k];
                    }
                }

            for(unsigned i=0; i< this->rows; i++)
            {
                UsedType m = 1/Ret.Mat[i][i];
                for(unsigned j=0; j<this->rows; j++)
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

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::inv()//Encontra a Matriz Inversa.
{
    Matrix<UsedType> ret;
    ret = this->cofactor();
    ret = ret.transpose() / this->det();

    return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::pol()//Encontra os Índices do Polinômio Característico
{
    Matrix<UsedType> A = *this, B, I, C, ind(1, this->cols + 1);
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
             for(unsigned i = 1; i <= this->rows; i++ )
             {
                    ind.Mat[0][i] = (C.trace()/i);
                    B = C - ind.Mat[0][i]*I;
                    C = A*B;
                    ind.Mat[0][i] = -ind.Mat[0][i];

             }
             for (unsigned i = 0; i < (ind.cols); i++)
                 ind.Mat[0][i] = ind.Mat[0][i]*sinal;

    }
    catch (const char* msg)
    {
         cerr<<msg<<endl;
    }

    return ind;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::eigenvalues()//Encontra os Auto Valores da Matriz.
{
    Matrix<UsedType> autovlr(this->rows, 2);

    try
    {
       if (!this->sqr(*this))
           throw "A matrix não é quadrada";
       else
           if (!this->ind(*this))
           {
               Matrix<UsedType> A;
               unsigned k = 0;

               A = *this;

               for(unsigned i = 0; i < 100; i++)
               {
                   if((A.rows == 0) && (A.cols == 0))
                   {
                       break;
                   }
                   else
                   {
                       Matrix<UsedType> Ai, I, Q, R;
                       UsedType sum = 0;

                       I.eye(A.rows);

                       (A - A.Mat[A.rows - 1][A.cols -1]*I).QR(Q, R);

                       Ai = R*Q + A.Mat[A.rows - 1][A.cols -1]*I;

                       for(unsigned j = 0; j < Ai.cols - 1; j++)
                       {
                            sum += abs(Ai.Mat[Ai.rows - 1][j]);
                       }

                       if(sum < 1e-30)
                       {
                           Matrix<UsedType> temp;

                           autovlr.Mat[k][0] = Ai.Mat[Ai.rows - 1][Ai.cols - 1];

                           temp = Ai;
                           A.zeros(A.rows - 1, A.cols -1);

                           for(unsigned m = 0; m < A.rows; m++)
                            for(unsigned n = 0; n < A.cols; n++)
                           {
                               A.Mat[m][n] = temp.Mat[m][n];
                           }

                           k++;

                           A.print();
                       }
                       else
                       {
                           A = Ai;
                       }
                   }
               }

               if((A.rows != 0) && (A.cols != 0))
               {
                   for(unsigned i = 0; i < autovlr.rows; i++)
                   {
                       if((autovlr.Mat[i][0] == 0) && (autovlr.Mat[i+1][0] == 0))
                       {
                           autovlr.Mat[i][0] = A.trace()/2;
                           autovlr.Mat[i][1] = -sqrt(abs(A.Mat[0][1] * A.Mat[1][0]));
                           autovlr.Mat[i + 1][0] = A.trace()/2;
                           autovlr.Mat[i + 1][1] = sqrt(abs(A.Mat[0][1] * A.Mat[1][0]));
                       }
                   }
               }
            }
            else
               for(unsigned i = 0; i < this->rows; i++ )
                   autovlr.Mat[i][0] = 1;
      }

    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    return autovlr;
}

template <class UsedType>
UsedType Matrix<UsedType>::NumericDet()
{
    UsedType x = 1;
    Matrix<UsedType> A;

    try
    {
        if (!this->sqr(*this))
            throw "A matrix não é quadrada";
        else if(!this->ind(*this))
             {
                A = this->eigenvalues();

                for (unsigned i = 0; i < A.cols; i++)
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

template <class UsedType>
UsedType Matrix<UsedType>::det()//Encontra o determinante da Matriz.
{
    unsigned i, j, j1, j2;
    double det = 0;
    Matrix Temp;
    unsigned n = this->rows;

    if(this->rows != this->cols)
        return 0.0;

    if (n < 1)
    { /* Error */

    }
    else if (n == 1)
    { /* Shouldn't get used */
        det = this->Mat[0][0];
    }
    else if (n == 2)
    {
        det = this->Mat[0][0] * this->Mat[1][1] - this->Mat[1][0] * this->Mat[0][1];
    }
    else
    {
        for(j1=0; j1<n; j1++)
        {
            Temp.zeros(n-1,n-1);
            for(i=1; i<n; i++)
            {
                j2 = 0;
                for(j=0; j<n; j++)
                {
                    if(j == j1)
                        continue;

                    Temp.Mat[i-1][j2] = this->Mat[i][j];
                    j2++;
                }
            }
            det += pow(-1.0, j1+2.0) * this->Mat[0][j1] * Temp.det();

        }
    }
    return(det);
}

template <class FriendType>
Matrix<FriendType> diff(Matrix<FriendType> M, FriendType h)//Encontra a derivada de uma Matriz
{
    Matrix<FriendType> Ret;
    for(unsigned i = 0; i < M.rows-1; i++)
        for(unsigned j = 0; j < M.cols; j++)
            Ret.add(i+1,j+1,(M.Mat[i+1][j] - M.Mat[i][j])/h);

    return Ret;
}

//#####Fim Álgebra Linear#####//

//#####Início Funções de Retorno de Informações da Matriz#####//
template <class UsedType>
unsigned Matrix<UsedType>::getRows()//Retorna o numéro de linhas de uma Matriz.
{
    return this->rows;
}

template <class UsedType>
unsigned Matrix<UsedType>::getCols()//Retorna o numéro de colunas de uma Matriz.
{
    return this->cols;
}

template <class UsedType>
void Matrix<UsedType>::setLine(unsigned num, Matrix<UsedType> Line)
{
    try
    {
        if(!(this->getCols() == Line.getCols()))
            throw "Numero de colunas incompativel";
        else
        {
            for(unsigned i = 1; i <= Line.getCols(); i++)
                this->add(num,i,Line.Mat[0][i-1]);
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
    }
}

template <class UsedType>
void Matrix<UsedType>::setColumn(unsigned num, Matrix<UsedType> Column)
{
    try
    {
        if(!(this->getRows() == Column.getRows()))
            throw "Numero de linhas incompativel";
        else
        {
            for(unsigned i = 0; i < Column.getRows(); i++)
                this->Mat[i][num-1] = Column.Mat[i][num-1];
        }
    }
    catch(const char* msg)
    {
        cerr<<msg<<endl;
    }
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::getLine(unsigned num)
{
    Matrix<UsedType> ret(1,this->cols);

    for (unsigned i = 0; i < this->cols; i++)
        ret.Mat[0][i] = this->Mat[num-1][i];

    return ret;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::getColumn(unsigned num)
{
    Matrix<UsedType> ret(this->rows, 1);

    for (unsigned i = 0; i < this->rows; i++)
        ret.Mat[i][0] = this->Mat[i][num-1];

    return ret;
}

//UsedType Matrix::getMat(unsigned row, unsigned col)//Retorna o valor do elemento no índice ij.
//{
//    return this->Mat[row-1][col-1];
//}
//#####Fim Funções de Retorno de Informações da Matriz#####//
//-----Funções Auxiliares para biblioteca de matrizes------//

template <class UsedType>
UsedType Matrix<UsedType>::max()
{
    UsedType  maximum = this->Mat[0][0];
     if(this->rows != 0 && this->cols != 0)
         for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->cols; j++)
                if(maximum < this->Mat[i][j])
                    maximum = this->Mat[i][j];

     return maximum;
}
template <class UsedType>
UsedType Matrix<UsedType>::min()
{
    UsedType  minimun;
    minimun = this->Mat[0][0];
    if(this->rows != 0 && this->cols != 0)
        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->cols; j++)
                if(minimun > this->Mat[i][j])
                    minimun = this->Mat[i][j];

    return minimun;
}

template <class UsedType>
Matrix<UsedType> Matrix<UsedType>::normalize(UsedType yUp, UsedType yDown)
{
  Matrix<UsedType>  ret;
  ret.init(this->getRows(),this->getCols());
  UsedType xDown = this->min(), xUp = this->max();

  for(unsigned i = 0; i < this->rows; i++)
    for(unsigned j = 0; j < this->cols; j++)
        ret(i+1,j+1,((this->Mat[i][j] - xDown)/(xUp - xDown))*(yUp - yDown) + yDown);

  return ret;
}

template <class UsedType>
UsedType Matrix<UsedType>::operator()(unsigned row, unsigned col)
{
    return this->Mat[row-1][col-1];
}

template <class UsedType>
void Matrix<UsedType>::operator ()(unsigned row, unsigned col, UsedType value)
{
    this->add(row, col, value);
}

template <class UsedType>
void Matrix<UsedType>::lineVector(unsigned left, unsigned rigth)
{
    unsigned j = 1;
    if (left > rigth)
        for(unsigned i = left; i >= rigth; i--)
        {
            this->add(1,j, i);
            j++;
        }
    else
        for(unsigned i = left; i <= rigth; i++)
        {
            this->add(1,j, i);
            j++;
        }
}

template <class UsedType>
Matrix<UsedType> abs(Matrix<UsedType> M)
{
    Matrix<UsedType> ret = M;
    for(  unsigned i = 0; i < M.rows; i++)
        for(  unsigned j = 0; j < M.cols; j++)
            if (ret.Mat[i][j] < 0)
                ret.Mat[i][j] = -ret.Mat[i][j];

    return ret;
}

//-----------------------------------------------------//

template <class UsedType>
Matrix<UsedType> cos(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cos(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> sin(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sin(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
Matrix<UsedType> tan(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tan(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> acos(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acos(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> asin(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asin(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> atan(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atan(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> cosh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, cosh(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> sinh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, sinh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> tanh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, tanh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> acosh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, acosh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> asinh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, asinh(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> atanh(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, atanh(M1(i+1,j+1)));

    return ret;

}

template <class UsedType>
Matrix<UsedType> exp(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, exp(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> log(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> log10(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, log10(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> ceil(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, ceil(M1(i+1,j+1)));

    return ret;


}

template <class UsedType>
Matrix<UsedType> floor(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, floor(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
Matrix<UsedType> round(Matrix<UsedType> M1)
{
    Matrix<UsedType> ret = M1;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            ret.add(i+1, j+1, round(M1(i+1,j+1)));

    return ret;
}

template <class UsedType>
UsedType norm(Matrix<UsedType> M1)
{
    UsedType sum = 0;
    for(  unsigned i = 0; i < M1.getRows(); i++)
        for(  unsigned j = 0; j < M1.getCols(); j++)
            sum += pow(M1(i+1,j+1), 2);

    return sqrt(sum);
}

template <class UsedType>
void Matrix<UsedType>::QR(Matrix<UsedType>& Q, Matrix<UsedType>& R)
{
    UsedType tal, sigma, gama;

    Q.eye(this->rows);
    R = *this;

    for(unsigned j = 0; j < R.cols; j++)
        for(unsigned i = (R.rows - 1); i >= (j + 1); i--)
        {
            Matrix<UsedType> temp;

            temp.eye(this->rows);

            if(abs(R.Mat[i-1][j]) > abs(R.Mat[i][j]))
            {
                tal = R.Mat[i][j]/R.Mat[i-1][j];
                gama = 1/(sqrt(1 + pow(tal, 2)));
                sigma = tal*gama;
            }
            else
            {
                tal = R.Mat[i-1][j]/R.Mat[i][j];
                sigma = 1/(sqrt(1 + pow(tal, 2)));
                gama = sigma*tal;
            }

            temp.Mat[i][i] = gama;
            temp.Mat[i][i - 1] = sigma;
            temp.Mat[i - 1][i] = -sigma;
            temp.Mat[i - 1][i - 1] = gama;

            R = ~temp*R;
            Q = Q*(temp);
        }
}

//double operator ^(double num1, double num2)
//{
//    return pow(num1,num2);
//}
//template Matrix<double>::Matrix<double>();
//--------------------------------------------------------------------------------//
//-----------------------------Int Template---------------------------------------//
template class Matrix<int>;
//template Matrix<int> operator+<int> (int, Matrix<int>);
//template Matrix<int> operator-<int> (int, Matrix<int>);
template Matrix<int> operator*<int> (int, Matrix<int>);
template Matrix<int> operator/<int> (int, Matrix<int>);
template Matrix<int> diff<int> (Matrix<int>, int);
//template int max<int> (Matrix<int>);
//template int min<int> (Matrix<int>);
//template int norm<int> (Matrix<int>);
//template Matrix<int> abs<int> (Matrix<int>);
//template Matrix<int> cos<int> (Matrix<int>);
//template Matrix<int> sin<int> (Matrix<int>);
//template Matrix<int> tan<int> (Matrix<int>);
//template Matrix<int> acos<int> (Matrix<int>);
//template Matrix<int> asin<int> (Matrix<int>);
//template Matrix<int> atan<int> (Matrix<int>);
//template Matrix<int> cosh<int> (Matrix<int>);
//template Matrix<int> sinh<int> (Matrix<int>);
//template Matrix<int> tanh<int> (Matrix<int>);
//template Matrix<int> acosh<int> (Matrix<int>);
//template Matrix<int> asinh<int> (Matrix<int>);
//template Matrix<int> atanh<int> (Matrix<int>);
//template Matrix<int> exp<int> (Matrix<int>);
//template Matrix<int> log<int> (Matrix<int>);
//template Matrix<int> log10<int> (Matrix<int>);
template Matrix<int> ceil<int> (Matrix<int>);
template Matrix<int> round<int> (Matrix<int>);
template Matrix<int> floor<int> (Matrix<int>);
//-------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//-----------------------------Int Template---------------------------------------//
template class Matrix<double>;
//template Matrix<double> operator+<double> (double, Matrix<double>);
//template Matrix<double> operator-<double> (double, Matrix<double>);
template Matrix<double> operator*<double> (double, Matrix<double>);
template Matrix<double> operator/<double> (double, Matrix<double>);
template Matrix<double> diff<double> (Matrix<double>, double);
//template double max<double> (Matrix<double>);
//template double min<double> (Matrix<double>);
template double norm<double> (Matrix<double>);
template Matrix<double> abs<double> (Matrix<double>);
template Matrix<double> cos<double> (Matrix<double>);
template Matrix<double> sin<double> (Matrix<double>);
template Matrix<double> tan<double> (Matrix<double>);
template Matrix<double> acos<double> (Matrix<double>);
template Matrix<double> asin<double> (Matrix<double>);
template Matrix<double> atan<double> (Matrix<double>);
template Matrix<double> cosh<double> (Matrix<double>);
template Matrix<double> sinh<double> (Matrix<double>);
template Matrix<double> tanh<double> (Matrix<double>);
template Matrix<double> acosh<double> (Matrix<double>);
template Matrix<double> asinh<double> (Matrix<double>);
template Matrix<double> atanh<double> (Matrix<double>);
template Matrix<double> exp<double> (Matrix<double>);
template Matrix<double> log<double> (Matrix<double>);
template Matrix<double> log10<double> (Matrix<double>);
template Matrix<double> ceil<double> (Matrix<double>);
template Matrix<double> round<double> (Matrix<double>);
template Matrix<double> floor<double> (Matrix<double>);
//-------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//-----------------------------Int Template---------------------------------------//
template class Matrix<float>;
//template Matrix<float> operator+<float> (float, Matrix<float>);
//template Matrix<float> operator-<float> (float, Matrix<float>);
template Matrix<float> operator*<float> (float, Matrix<float>);
template Matrix<float> operator/<float> (float, Matrix<float>);
template Matrix<float> diff<float> (Matrix<float>, float);
//template float max<float> (Matrix<float>);
//template float min<float> (Matrix<float>);
template float norm<float> (Matrix<float>);
template Matrix<float> abs<float> (Matrix<float>);
template Matrix<float> cos<float> (Matrix<float>);
template Matrix<float> sin<float> (Matrix<float>);
template Matrix<float> tan<float> (Matrix<float>);
template Matrix<float> acos<float> (Matrix<float>);
template Matrix<float> asin<float> (Matrix<float>);
template Matrix<float> atan<float> (Matrix<float>);
template Matrix<float> cosh<float> (Matrix<float>);
template Matrix<float> sinh<float> (Matrix<float>);
template Matrix<float> tanh<float> (Matrix<float>);
template Matrix<float> acosh<float> (Matrix<float>);
template Matrix<float> asinh<float> (Matrix<float>);
template Matrix<float> atanh<float> (Matrix<float>);
template Matrix<float> exp<float> (Matrix<float>);
template Matrix<float> log<float> (Matrix<float>);
template Matrix<float> log10<float> (Matrix<float>);
template Matrix<float> ceil<float> (Matrix<float>);
template Matrix<float> round<float> (Matrix<float>);
template Matrix<float> floor<float> (Matrix<float>);
//-------------------------------------------------------------------------------//

//template class Matrix<complex>;
////template Matrix<complex> operator+<complex> (complex, Matrix<complex>);
////template Matrix<complex> operator-<complex> (complex, Matrix<complex>);
//template Matrix<complex> operator*<complex> (complex, Matrix<complex>);
//template Matrix<complex> operator/<complex> (complex, Matrix<complex>);
//template Matrix<complex> diff<complex> (Matrix<complex>, complex);
////template complex max<complex> (Matrix<complex>);
////template complex min<complex> (Matrix<complex>);
//template complex norm<complex> (Matrix<complex>);
//template Matrix<complex> abs<complex> (Matrix<complex>);
//template Matrix<complex> cos<complex> (Matrix<complex>);
//template Matrix<complex> sin<complex> (Matrix<complex>);
//template Matrix<complex> tan<complex> (Matrix<complex>);
//template Matrix<complex> acos<complex> (Matrix<complex>);
//template Matrix<complex> asin<complex> (Matrix<complex>);
//template Matrix<complex> atan<complex> (Matrix<complex>);
//template Matrix<complex> cosh<complex> (Matrix<complex>);
//template Matrix<complex> sinh<complex> (Matrix<complex>);
//template Matrix<complex> tanh<complex> (Matrix<complex>);
//template Matrix<complex> acosh<complex> (Matrix<complex>);
//template Matrix<complex> asinh<complex> (Matrix<complex>);
//template Matrix<complex> atanh<complex> (Matrix<complex>);
//template Matrix<complex> exp<complex> (Matrix<complex>);
//template Matrix<complex> log<complex> (Matrix<complex>);
//template Matrix<complex> log10<complex> (Matrix<complex>);
//template Matrix<complex> ceil<complex> (Matrix<complex>);
//template Matrix<complex> round<complex> (Matrix<complex>);
//template Matrix<complex> floor<complex> (Matrix<complex>);


