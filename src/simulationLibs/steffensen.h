#ifndef STEFFENSEN_H
#define STEFFENSEN_H

#include "fzero.h"


//! Classe steffensen, com o intuito de encontrar o zero de uma função modelo.

/*!  similar ao método de Newton.
 * Usando a seguinte fórmula:
 *      \f$g(x_n)\f$ = \f$\frac{f(x_n + f(x_n)) - f(x_n)}{f(x_n)}\f$
*/
template <class UsedType>
class steffensen : public FZero<UsedType>
{
   UsedType x;  //! valor final.
   UsedType fx; //! função modelo a ser simulada.


public:
   //! Construtor padrão da classe.

/*!
   Instancia o objeto da classe steffensen recebendo uma função modelo.
   \param f Função modelo a ser simulada.
   Ex:
        \code
           #include "src/simulationLibs/simfunction.h"
           #include "src/simulationLibs/steffensen.h"

           //! Função modelo
           double func(double x)
           {
               return pow((x+1),2)*exp(pow(x,2)-2)-1;
           }

           int main(int argc, char *argv)
           {
                Model<double> *m = new simFunction<double>(func);   //Função modelo a ser simulada
                FZero<double> *a = new steffensen<double>(m);        //Objeto FZero do tipo steffensen
                a->setInterval(1);

                cout << a->zeroFind() << endl;
                return 0;
           }
        \endcode

    Resultado:

        \code
            0.866874
        \endcode

    Ver também:

    \sa fzero, newton, bisseccao, cordas;

*/
   steffensen(Model<UsedType> *f): FZero<UsedType>(f){}

   //! Função para encontrar o zero da função modelo.
   /*!
    * \brief setInterval O intervalo inicial para começar a procura pelo zero da função.
    * \param a  primeiro intervalo.
    * \param b  segundo intervalo, para esse método é obsoleto.
    */
   void setInterval(UsedType a, UsedType b);

   //! Função para encontrar o zero da função modelo.

       /*!
           A função aplica a fórmula de steffensen para encontrar o zero.
           Nenhum parametro de entrada é necessário.
           Retorna o valor em que aplicado na função modelo a resposta é zero.
       */
   UsedType zeroFind();
};

#endif // STEFFENSEN_H
