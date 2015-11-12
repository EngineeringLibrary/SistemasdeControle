#ifndef __POLYNOM_H_INCLUDED
#define __POLYNOM_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <string>
#include "matrix.h"

//! Classe responsável por criar e efetuar operações com polinômios.

/*! Classe que gerencia polinômios, tais como as suas  operações e propriedades.
 *
 * \param sizeNum
 * \param sizeDen
 * \param *num
 * \param *den
 * \param x
 */

template <class TypeOfClass>
class Polynom
{
private:
    int sizeNum, sizeDen;
    TypeOfClass *num, *den;
    char x;

    //! Método de inicialização do polinômio.

    /*! Inicializa o polinômio com o tamanho do numerador.
     *
     * \brief init
     * \param NumSize   Tamanho máximo do numerador.
     */

    void init(int NumSize);

    //! Método de inicilização do polinômio.

    /*! Inicializa o polinômio com o tamanho do numerador e denominador.
     *
     * \brief init
     * \param NumSize   Tamanho máximo do numerador.
     * \param DenSize   Tamanho máximo do denominador.
     */

    void init(int NumSize, int DenSize);

    //! Método de inicialização de um polinômio usando carácteres.

    /*! Inicializa o polinômio com o tamanho do numerador sendo convertido de um carácter(númerica) para um valor inteiro.
     *
     * \brief init
     * \param Num   Carácter que define o tamanho do numerador.
     */

    void init(std::string Num);

    //! Método de inicialização de um polinômio usando carácteres.

    /*! Inicializa o polinômio com o tamanho do numerador e denominador de dois carácteres(númericas) para dois valores inteiros.
     *
     * \brief init
     * \param Num   Carácter que define o tamanho do numerador.
     * \param Den   Carácter que define o tamanho do denominador.
     */

    void init(std::string Num, string Den);

    //! Método de inicialização de um polinômio usando matriz.

    /*! Inicializa o polinômio com o tamanho do numerador e denominador sendo duas matrizes.
     *
     * \brief init
     * \param Num   Matriz de numerador.
     * \param Den   Matriz de denominador.
     */

    void init(Matrix<TypeOfClass> Num, Matrix<TypeOfClass> Den);

    //! Método responsável por verificar se é possivel efetuar a soma dos polinômios.

    /*! Verifica se é possivel a soma entre dois polinômios. È possivel qunando os denominadores forem iguais.

     * \brief VefDen
     * \param den1  Ponteiro que recebe o primeiro denominador.
     * \param den2  ponteiro que recebe o segundo denominador.
     * \param sizeden1  Tamanho do denominador.
     * \param sizeden2  Tamanho do denominador.
     */

    bool VefDen(TypeOfClass *den1, TypeOfClass *den2, int sizeden1, int sizeden2);

    //! .

    /*!

     * \brief initPointer
     * \param Size
     */

    TypeOfClass *initPointer(int Size);

    //! .

    /*!

     * \brief SumPoly
     * \param value1
     * \param value2
     * \param SizeValue1
     * \param SizeValue2
     */

    TypeOfClass *SumPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);

    //! .

    /*!

     * \brief SubPoly
     * \param value1
     * \param value2
     * \param SizeValue1

     */

    TypeOfClass *SubPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);

    //! .

    /*!

     * \brief MultPoly
     * \param value1
     * \param value2
     * \param SizeValue1
     * \param SizeValue2
     */

    TypeOfClass *MultPoly(TypeOfClass *value1, TypeOfClass *value2, int SizeValue1, int SizeValue2);

public:

    //! Construtor padrão da biblioteca polynomio.

    /*! O construtor padrão permite que um objeto do tipo Polynom seja criado.
     *
     * \brief Polynom
     *
    */
    Polynom();

    //! Construtor que recebe como parâmetro um valor inteiro.

    /*! O construtor permite que um objeto do tipo Polynom seja criado com o valor do numerador.
     *
     * \brief Polynom
     * \param Num È uma váriavel do tipo inteiro que recebe o valor do numerador.
     *
     */
    Polynom(int Num);

    //! Construtor recebe como parâmetro dois valores inteiros.

    /*! Inicializa um polinômio com os valores do numerador e denominador.
     *
     * \brief Polynom
     * \param Num È uma váriavel do tipo inteiro que recebe o valor do numerador
     * \param Den   È uma váriavel do tipo inteiro que recebe o valor do denominador
     *
     */
    Polynom(int Num, int Den);

    //! Construtor que recebe como parâmetro uma string.

    /*! Inicializa um objeto do tipo Polynom convertendo uma string(valor númerico) em um valor inteiro para o numerador.
     *
     * \brief Polynom
     * \param Num   Cadeia de carácteres que define o valor do numerador.
     *
     */
    Polynom(std::string Num);

    //! Construtor que recebe como parâmetro duas strings.

    /*! Inicializa um objeto do tipo Polynom convertendo as strings(valores númericos) em dois valores inteiros para o numerador e denominador.
     *
     * \brief Polynom
     * \param Num   Cadeia de carácteres que define o valor do numerador.
     * \param Den   Cadeia de carácteres que defina o valor do denominador.
     *
     */
    Polynom(std::string Num, std::string Den);

    //! Construtor que recebe duas matrizes como parâmetro.

    /*! Inicializa um objeto do tipo Polynom usando matrizes como valores para o numerador e denominador.

     * \brief Polynom
     * \param Num   Matriz com os valores do numerador.
     * \param Den   Matriz com os valores do denominador.
     *
     */
    Polynom(Matrix<TypeOfClass> Num, Matrix<TypeOfClass> Den);

    //! Construtor de cópia da classe.

    /*! Construtor de cópia da classe, gerencia as aplicações de memória da classe.
     *
     * \brief Polynom
     * \param CopyPolynom   Recebe como parâmetro uma cópia do polinômio.
     *
     */
    Polynom(const Polynom<TypeOfClass> &CopyPolynom);

    //! Destrutor padrão da classe.

    /*! Libera todas as memórias alocadas durante a execução de objetos da classe.
           OBS: Este Destrutor não tem exemplo associado. Funciona implícitamente.
    *
    */
    ~Polynom();

    //! Sobrecarga do operador + para a soma entre polinômios.

    /*! O método é uma sobrecarga do operador +. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um polinômio (P) a esquerda do operador +.

     * \brief operator +
     * \param P Polinômio a ser somado com o polinômio this.
     */

    Polynom<TypeOfClass> operator+(Polynom<TypeOfClass> P);

    //! Sobrecarga do operador + para a soma entre um polinômio e scalar.

    /*! O método é uma sobrecarga do operador +. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um escalar (P) a esquerda do operador +.
     *
     * \brief operator +
     * \param scalar    É um escalar a ser somado ao polinômio(this).
     */

    Polynom<TypeOfClass> operator+(TypeOfClass scalar);

    //! Sobrecarga do operador - para a subtração entre polinômios.

    /*! O método é uma sobrecarga do operador -. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um polinômio (P) a esquerda do operador -.

     * \brief operator -
     * \param P Polinômio a ser subtraída com o polinômio this.
     */

    Polynom<TypeOfClass> operator-(Polynom<TypeOfClass> P);

    //! Sobrecarga do operador - para a subtração entre polinômio e scalar.

    /*! O método é uma sobrecarga do operador -. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um escalar (P) a esquerda do operador -.

     * \brief operator -
     * \param scalar     É um escalar a ser subtraido ao polinômio(this).
     */

    Polynom<TypeOfClass> operator-(TypeOfClass scalar);

   //! Sobrecarga do operador * para a multiplicação entre polinômios.

    /*! O método é uma sobrecarga do operador *. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinõmio a direita(this) e um polinômio (P) a esquerda do operador *.

     * \brief operator *
     * \param scalar     É um scalar a ser multiplicado ao polinômio(this).
     */

    Polynom<TypeOfClass> operator*(TypeOfClass scalar);

    //! Sobrecarga do operador * para a multiplicação entre polinômio e scalar.

    /*! O método é uma sobrecarga do operador *. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um escalar (P) a esquerda do operador *.

     * \brief operator *
     * \param P Polinômio a ser multiplicado com o polinômio this.
     */

    Polynom<TypeOfClass> operator*(Polynom<TypeOfClass> P);

    //! Sobrecarga do operador / para a divisão entre polinômios.

    /*! O método é uma sobrecarga do operador /. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinômio a direita(this) e um polinômio (P) a esquerda do operador /.

     * \brief operator /
     * \param P Polinômio a ser dividido com o polinômio this.
     */

    Polynom<TypeOfClass> operator/(Polynom<TypeOfClass> P);

    //! Sobrecarga do operador / para a divisão entre polinômio e scalar.

    /*! O método é uma sobrecarga do operador /. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um polinmio a direita(this) e um escalar (P) a esquerda do operador /.

     * \brief operator /
     * \param scalar    É um escalar a ser dividido ao polinômio(this).
     */

    Polynom<TypeOfClass> operator/(TypeOfClass scalar);

    //! Operador de atribuição entre polinômios.

    /*! O método é uma sobrecarga do operador =. Ele permite que a operação de atribuição entre polinômios seja realizada.
     * Ele armazena o valor do polinomio a direita do operador = no polinômio a esquerda.

     * \brief operator =
     * \param P È um polinômio qualquer que está do lado direito da igualdade.

     */

    void operator=(Polynom<TypeOfClass> P);
    //! Sobrecarga do operador ^ para obter a potenciação de polinômios.

    /*! O operador ^ foi sobrecarregado de tal forma a simplificar a operação de potenciação de polinômios,
     * dado um polinômio e um escalar (à esquerda e à direita do operador ^ respectivamente)

     * \brief operator ^
     * \param scalar    Expoente cujo módulo significa a quantidade de vezes que a multiplicação entre o polinômio com ele mesmo será repetida.

     */

    Polynom<TypeOfClass> operator^(int scalar);

    //! Inserir um vetor de numerador ao polinômio.

    /*! Essa função vai inserir um vetor em um polinômio com os valores do numerador.

     * \brief setNum
     * \param Num   Ponteiro simples que vai armazenar o vetor de numerador.
     * \param sizenum   Tamanho do vetor de numerador.

     */

    void setNum(TypeOfClass *Num, int sizenum);

    //! Inserir um vetor de denominador ao polinômio.

    /*! Vai inserir um vetor em um polinômio com os valores do denominador.

     * \brief setDen
     * \param Den   Ponteiro simples que vai armazenar o vetor de denominador
     * \param sizeden   Tamanho do vetor de numerador..
     */

    void setDen(TypeOfClass *Den, int sizeden);

    //! .

    /*!
     * \brief setVar
     * \param var
     */

    void setVar(char var);

    //! Retorna o vetor com os valores do numerador.

    /*! Função responsável por pegar o vetor de numerador do polinômio.

     * \brief getNum
     */

    Matrix<TypeOfClass> getNum();

    //! Retorna o vetor com os valores do denominador.

    /*! Função responsável por pegar o vetor de denominador do polinômio.
     *
     * \brief getDen
     */

    Matrix<TypeOfClass> getDen();

    //! Exibe o polinômio.

    /*! Esta função mostra na tela o valor do polinômio.

     * \brief print
     */

    void print();

    //! Sobrecarga do operador+ para a soma entre escalar e polinômio.

    /*! O método é uma sobrecarga do operador +. Ele simplifica a soma entre polinômios.
     * O método realiza a soma de um escalar a direita(scalar) e um polinomio (P) a esquerda do operador +.
     *
     * \brief operator +
     * \param scalar    Escalar a ser somado ao polinômio (P).
     * \param P    Polinômio a ser somado ao escalar(scalar).
     */

    friend Polynom<TypeOfClass> operator+(TypeOfClass scalar, Polynom<TypeOfClass> P){return P+scalar;}

    //! Sobrecarga do operador- para a subtração entre escalar e polinômio.

    /*! O método é uma sobrecarga do operador -. Ele simplifica a subtração entre polinômios.
     * O método realiza a soma de um escalar a direita(scalar) e um polinômio (P) a esquerda do operador -.
     *
     * \brief operator -
     * \param scalar    Escalar que vai subtrair o polinômio(P).
     * \param P     Polinômio a ser subtraido pelo escalar(scalar).
     */

    friend Polynom<TypeOfClass> operator-(TypeOfClass scalar, Polynom<TypeOfClass> P){return (-1)*P+scalar;}

    //! Sobrecarga do operador* para a multiplicação entre escalar e polinômio.

    /*! O método é uma sobrecarga do operador *. Ele simplifica a multiplicação entre polinômios.
     * O método realiza a soma de um escalar a direita(scalar) e um polinômio (P) a esquerda do operador *.
     *
     * \brief operator *
     * \param scalar    Escalar que vai multiplicar o pilinômio(P).
     * \param P     Polinômio a ser multiplicado pelo escalar(scalar).
     */

    friend Polynom<TypeOfClass> operator*(TypeOfClass scalar, Polynom<TypeOfClass> P){return P*scalar;}

    //! Sobrecarga do operador/ para a divisão entre escalar e polinômio.

    /*! O método é uma sobrecarga do operador /. Ele simplifica a divisão entre polinômios.
     * O método realiza a soma de um escalar a direita(scalar) e um polinômio (P) a esquerda do operador /.
     *
     * \brief operator /
     * \param scalar    Escalar que vai dividir o polinômio(P).
     * \param P     Polinômio que vai ser dividido pelo escalar(scalar).
     */

    friend Polynom<TypeOfClass> operator/(TypeOfClass scalar, Polynom<TypeOfClass> P){return (P^-1)*scalar;}
};


#endif // POLYNOM_H
