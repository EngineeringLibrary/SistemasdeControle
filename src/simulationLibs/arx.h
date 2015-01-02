#ifndef ARX_H
#define ARX_H
#include <src/simulationLibs/model.h>
//! Classe concreta para os modelos ARX (Modelos auto-recursivos com entradas exógenas).

/*!
    Há diversas formas de representar modelos lineares. Uma das mais utilizadas é a forma de funções de transferência definida como a transformada da resposta ao impulso do sistema modelado, para condições iniciais nulas. Se a resposta ao impulso for contínua no tempo, então, utiliza-se a transformada de Laplace. Se a resposta ao impulso for discreta no tempo, a respectiva função de transferência é, por definição, a transformada Z (Aguirre, 2007).

Nas representações a seguir definiremos  \f$ A(z^{-1}) \f$, \f$ B(z^{-1}) \f$ conforme as equações 1 e 2 respectivamente.


    \f$ A(z^{-1})= 1 + a_1z^-1 + a_2z^{-2} +  ... + a_{n_a}z^{-n_a} \f$          1

    \f$ B(z^{-1})= 1 + b_1z^-1 + b_2z^{-2} +  ... + b_{n_b}z^{-n_b} \f$          2


Isto significa que os polinômios \f$ A(z^{-1}) \f$ e \f$ B(z^{-1}) \f$ representam sistemas discretos no tempo. Sendo eles polinômios arbitrários, o modelo ARX assume a forma da equação 3.

    \f$ y(k)=\frac{B(z^{-1})}{A(z^{-1})}u(k)+\frac{1}{A(z^{-1})}v(k) \f$         3

    Em que:

    @param y(k) É o sinal de saída, calculado pelo do modelo matemático
    @param u(k) É o sinal de entrada, que significa uma força externa a um sistema físico qualquer.
    @param v(k) É um ruído branco com média nula (Ruído branco gaussiano).

O modelo ARX (AutoRegressive with eXogenous inputs) apresentado no diagrama de blocos da figura 1, pode ser obtido a partir de um modelo polinomial linear mais geral de entradas e saídas resultando na equação 3 (Aguirre, 2007).

\image html Arx.jpg
\f$ Diagrama de Blocos do Modelo ARX. Fonte: Isermann (2011). \f$


Para o caso multivariável, podemos representar o modelo ARX conforme a seguinte equação na forma vetorial.

    \f$ Y(k) = \left [ \begin{matrix} y_1(k) \\ y_2(k) \\ \vdots \\ y_{qo}(k) \end{matrix}\right ] = \Theta \Phi = \left [ \begin{matrix} \theta_{1,1} & \cdots & \theta_{1,qo\,ny + qi\,nu -1} \\ \vdots & \ddots & \vdots \\ \theta_{qo,1} & \cdots & \theta_{qo,qo\,ny + qi\,nu -1} \end{matrix} \right ]\left [ \begin{matrix} y_1(k-1) \\ \vdots \\ y_1(k-ny) \\ \vdots \\ y_{qo}(k-1) \\ \vdots \\ y_{qo}(k-ny) \\ u_1(k-1-d) \\ \vdots \\ u_1(k-nu-d) \\ _{qi}(k-1-d) \\ \vdots \\ u_{qi}(k-nu-d) \end{matrix} \right ] \f$   Equação 4

    Em que:

    \param nu Na classe é representado por:
    @param nInputpar    Ou seja, o número de atrasos nas entradas do sistema.
    \param ny Na classe é representado por:
    @param nOutputpar   Ou seja, o número de atrasos nas saídas do sistema.
    \param d  Na classe é representado por:
    @param delay        Ou seja, o número de atrasos de transporte do sistema.
    \param qi Na classe é representado por:
    @param qdtInputVar  Ou seja, o número entradas aplicadas no sistema.
    \param qo Na classe é representado por:
    @param qdtOutputVar Ou seja, o número de saídas do sistema.

    Como é possível perceber, o objetivo desta classe é "ser" um modelo ARX, ou seja, os cálculos e estruturas aqui calculadas seguirão o padrão do modelo da equação 4. Para isso, são definidas, ainda as seguintes variáveis:

    \param maxnInOut É uma variável para cuidar do tamanho do vetor \f$\Phi\f$, para que não seja ultrapassada a quantidade de dados armazenados na memória do computador.
    \param nSample É o período de amostragem do sistema.

 */

template <class UsedType>
class ARX : public Model<UsedType>
{
private:
    unsigned nInputpar  , nOutputpar  , delay,
             qdtInputVar, qdtOutputVar, nSample,
             maxnInOut;
public:
    ARX(unsigned nInputpar , unsigned nOutputpar,
        unsigned delay = 0,
        unsigned qdtInputVar = 1, unsigned qdtOutputVar = 1);

    void setLinearVectorPhiEstimation();
    void setLinearVectorPhi();
    void setLinearModel(Matrix<UsedType> Input, Matrix<UsedType> Output);

    UsedType sim(UsedType input);
    UsedType sim(UsedType input, UsedType output);
    Matrix<UsedType> sim(Matrix<UsedType> x);
    Matrix<UsedType> sim(Matrix<UsedType> x, Matrix<UsedType> y);
    Matrix<UsedType> sim(UsedType lsim, UsedType lmax, UsedType step);
};

#endif // ARX_H
