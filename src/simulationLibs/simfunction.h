#ifndef SIMFUNCTION_H
#define SIMFUNCTION_H
#include <src/primitiveLibs/matrix.h>

//! Classe cuja responsabilidade é simular funções criadas externamente

/*!
    Muitas outras partes desta biblioteca necessitam simular uma função, estabelecer limites, normalizar a sua saída. Por isso, vários métodos foram agrupados de maneira a permitir e facilitar a utilização de funções.
    \param input Dados de entrada que serão inseridos na função (cujo ponteiro é passado no construtor) para obter os dados de saída.
    \param output Dados de saída obtidos a partir da inserção dos dados de entrada na função passada como ponteiro.
    \param (*FunctionToCall)(double) Ponterio que aponta para uma função criada para obter os dados de saída, a partir dos dados de entrada.
    \param lMin Limite mínimo, ou seja, o menor valor que será utilizado como entrada para a simulação da função.
    \param lMax Limite máximo, ou seja, o maior valor que será utilizado como entrada para a simulação da função.
    \param step passo que gerará os pontos que serão simulados juntamente com lMin e lMax da seguinte maneira: lMin:step:lMax.
*/

class simFunction
{
private:
    Matrix<double> input, output;
    double         (*FunctionToCall)(double), lMin, lMax, step;

public:

    //! Construtor padrão da biblioteca de simulação

    /*!
        O construtor padrão da biblioteca de simulação inicializa o objeto simFunction com todos os parâmetros internos a classe nulos.


        Ex:

\code
            #include <src/graphicLibs/grafics.h>
            int main(int argc, char *argv)
            {
                simFunction S(In,Out);
                return 0;
            }
\endcode

        Resultado:

        Obs: O exemplo não apresenta resultados em tela

         Ver também: \sa simFunction(Matrix<double> in, Matrix<double> out)
    */


    simFunction();

    //! Sobrecarga do construtor padrão da biblioteca de simulação

    /*!
        Nessa sobrecarga do construtor da biblioteca de simulação é possível inserir diretamente os valores de entrada e saída que serão utilizados na apresentação gráfica, por exemplo.
        \param in Valores de entrada que serão utilizados para obter os outputs, caso a função seja inserida. Neste caso, como serão inseridas as entrada e saída, não será necessário realizar a simulação.
        \param out Valores de saída que serão utilizados para obter os gráficos de saída.

        Ex:

\code
            #include <src/graphicLibs/grafics.h>
            int main(int argc, char *argv)
            {
                Matrix<double> In, Out;
                In  = "0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10";
                Out = "0,1,2,3,4,5,6,7,8,9,10;0,2,4,8,16,25,36,48,64,81,100;0,2,4,6,8,10,12,14,16,18,20";
                simFunction S(In,Out);

                graphicProperties prop;
                GlView *f = new grafics(prop, S);

                f->setInstance(f);
                f->startFramework(argv,argc);
                return 0;
            }
\endcode

        Resultado:

        \image <PNG> <Exemplo> ‘‘Exemplo da apresentação do gráfico’’

        Ver também: \sa simFunction()
    */

    simFunction(Matrix<double> in, Matrix<double> out);


    //! Sobrecarga do construtor padrão da biblioteca de simulação

    /*!
        Nessa sobrecarga do construtor da biblioteca de simulação é possível inserir diretamente os valores de entrada e saída que serão utilizados na apresentação gráfica, por exemplo.
        \param FunctionToCall Ponteiro da função que apontará para a função criada pelo usuário
        \param lMin Limite mínimo, ou seja, o menor valor que será utilizado como entrada para a simulação da função.
        \param lMax Limite máximo, ou seja, o maior valor que será utilizado como entrada para a simulação da função.
        \param step passo que gerará os pontos que serão simulados juntamente com lMin e lMax da seguinte maneira: lMin:step:lMax.

        Ex:

\code

            #include <src/graphicLibs/grafics.h>

            double funcaoExemplo(double f){
                double a = 90, b = 0, g = 0;// f = 15;//graus
                double Kp = 1.9;
                //    double x;
                a = PI*a/180;
                b = PI*b/180;
                g = PI*g/180;
                f = PI*f/180;

                double x = (pow(sin(a+f),2))/((pow(sin(a),2))*sin(a-g)*pow(1-sqrt((sin(f+g)*sin(f-b))/(sin(a-g)*sin(a+b))),2)) - Kp;
                return (x);
            }

            int main(int argc, char *argv)
            {

                simFunction S(funcaoExemplo, 0,2*3.14,3.14/100);

                graphicProperties prop;
                GlView *f = new grafics(prop, S);

                f->setInstance(f);
                f->startFramework(argv,argc);
                return 0;
            }
\endcode

        Resultado:

        \image <PNG> <Exemplo2> ‘‘Exemplo da apresentação do gráfico’’

        Ver também: \sa simFunction()
    */

    simFunction(double (*FunctionToCall)(double), double lMin,
                double lMax, double step);

    double FunctionCalculation(double input);
    void   GenerateDataFunction();
    double normalize(double input, double xUp, double xDown,
                     double yUp, double yDown);

    void   SetDataStep    (double step);
    void   SetDataLimits  (double lMin, double lMax);
    void   SetInputData   (Matrix<double> input);
    void   SetOutputData  (Matrix<double> Output);
    void   SetFunctionCall(double (*FunctionToCall)(double));

    Matrix<double> GetInputData ();
    Matrix<double> GetOutputData();
    double   GetDataStep  ();
    double   GetDataMinLimit();
    double   GetDataMaxLimit();
    typedef double(*FunctionCall)(double);
    FunctionCall   GetFunctionCall();

    void simulate();
};

#endif // SIMFUNCTION_H
