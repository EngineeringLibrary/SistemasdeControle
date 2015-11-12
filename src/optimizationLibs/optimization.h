#ifndef __OPTIMIZATION_H_INCLUDED
#define __OPTIMIZATION_H_INCLUDED

#include "src/simulationLibs/model.h"
#include "src/simulationLibs/arx.h"

//! Classe abstrata que tratam todos os métodos de otimização de sistemas.

/*!
    O objetivo principal dessa classe é ser uma abstração para tratar e otimizar modelos matemáticos (redes neurais, arx, armax, carima, espaço de estados, função de transferência, fuzzy, e etc.). A funcionalidade desta classe é inquestionável quando percebemos que precisamos obter uma solução otimizada para os sistemas lineares e não lineares dos modelos. Por isso, ter uma classe que integre e abstraia essas funcionalidades facilitará a implementação e, também, a desacoplará.

    \param OptimizatedVariable Matrix com a solução otimizada do modelo dado.
    \param RestrictionR  As restrições do sistema estão escritas na forma \f$ R\,\Beta = r \f$. A partir desta forma RestrictionR é a variável \f$R\f$ da equação.
    \param RestrictionEqualityr  As restrições do sistema estão escritas na forma \f$ R\,\Beta = r \f$. A partir desta forma RestrictionEqualityr é a variável \f$r\f$ da equação.
    \param model é o modelo abstrato matemático, onde as matrizes de otimização são montadas.

*/


template <class UsedType>
class Optimization
{
protected:
    Matrix<UsedType> OptimizatedVariable, RestrictionR, RestrictionEqualityr; //Error;
    Model<UsedType> *model;

//    void initRLS(int nu, int ny, unsigned long int  p0);
//    void setData(Matrix<UsedType> in, Matrix<UsedType> out);

public:

//! Construtor padrão da biblioteca de otimização

/*!
    O construtor padrão da biblioteca de otimização permite que um objeto do tipo Optimization seja construído. O objetivo da otimização é encontar o valor dos coeficientes dos modelos matemáticos quando estes estão sujeitos a restrições. Dependendo da furmulação matemática também é possível encontrar, por exemplo, o sinal de entrada u (que pode significar a aplicação de uma força a um sistema físico) necessário para se ter o melhor desempenho sob certas limitações.

    \f$Ex_1\f$:

        \code
            #include "src/simulationLibs/statespace.h"
            #include "src/simulationLibs/arx.h"
            #include "src/optimizationLibs/optimization.h"
            #include "src/optimizationLibs/leastsquare.h"

            int main(int argc, char *argv)
            {
                Matrix<double> A,B,C,D,u;
                A = "-2,-1;1,0";
                B = "0;1";  C = "0,1";  D = "0";
                u = "1,2,3,-1,-3,8,8,8,1,1,1,1,1";
                StateSpace<double> SS(A,B,C,D);

                ARX<double> gz(2,2);
                gz.setLinearModel(~u,~SS.sim(u));
                Optimization<double> *LS = new LeastSquare<double>(&gz);
                LS->Optimize();
                LS->getOptimizatedVariable().print();
                return 0;
            }
        \endcode

    Resultado:

        \code
            -1.810
             0.819
             0.100
            -0.082
         \endcode

    Ex2:

        \code
            #include "src/simulationLibs/statespace.h"
            #include "src/simulationLibs/arx.h"
            #include "src/optimizationLibs/optimization.h"
            #include "src/optimizationLibs/leastsquare.h"
            #include "src/optimizationLibs/pso.h"

            int main(int argc, char *argv)
            {
                Matrix<double> u, syspar;

                u = "1,1,1,1,1,1,1,1,1,1";
                syspar = "-1.809674836071920;0.818730753077982;0.004678840160444;0.004377076845618";

                Model<double> *gz = new ARX<double>(2,2);
                gz->setModelCoef(syspar);
                gz->sim(~u).print();
                gz->setIO(~u,gz->sim(~u));
                Optimization<double> *P = new PSO<double>(gz,4,20,2000);
                P->Optimize();
                P->getOptimizatedVariable().print();

                Model<double> *gz2 = new ARX<double>(2,2);
                gz2->setModelCoef(~P->getOptimizatedVariable());
                (gz->getOutputMatrix()|gz2->sim(~u)).print();
                return 0;
            }
        \endcode

    Resultado Possível:

        \code
            0.000
            0.005
            0.018
            0.037
            0.062
            0.090
            0.122
            0.156
            0.191
            0.228

            -0.078  -0.689  -0.061  0.133

            0.000  0.000
            0.005 -0.061
            0.018  0.067
            0.037  0.035
            0.062  0.121
            0.090  0.106
            0.122  0.164
            0.156  0.158
            0.191  0.197
            0.228  0.196
        \endcode


    Ex3:

        \code
            //O exemplo a ser colocado aqui será o de RLS
            (mínimos quadrados recursivo)
        \endcode

    Resultado Possível:

        \code

        \endcode

    Ver também: \sa print();
*/

    Optimization();

    Matrix<UsedType> getOptimizatedVariable();
    Matrix<UsedType> getRestrictionEqualityr();
    Matrix<UsedType> getRestrictionR();

    void AddRestrictionsEquality(Matrix<UsedType> A, Matrix<UsedType> B);
    void AddRestrictionsInequality(Matrix<UsedType> A, Matrix<UsedType> B, bool isRigth);

    void setRestrictionsEquality(Matrix<UsedType> A, Matrix<UsedType> B);
    void setRestrictionsInequality(Matrix<UsedType> A, Matrix<UsedType> B, bool isRigth);

    virtual void Optimize()=0;
//    void RLS(int nu, int ny, unsigned long int p0, Matrix<UsedType> in, Matrix<UsedType> out);
};

#endif // OPTIMIZATION_H
