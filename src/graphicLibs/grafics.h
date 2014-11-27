#ifndef GRAFICS_H
#define GRAFICS_H
#include <src/graphicLibs/glview.h>
#include <math.h>
#include <src/primitiveLibs/matrix.h>
#include <src/graphicLibs/graphicproperties.h>
#include <src/simulationLibs/simfunction.h>

//! Classe concreta que herda da Classe GlView.

/*!
    Classe concreta que herda da Classe GlView. Sua responsabilidade é gerar gráficos 2d. Para isso serão utilizadas duas outras classes, uma para gerar os pontos dos gráficos e outra classe para ser responsável por todas as propriedades gráficas.
    \param prop É uma instância da classe \sa {graphicProperties}. Esta composição permite alterar as propriedades gráficas de maneira a flexibilizar e desacoplar algumas funcionalidades, tais como, grid, legenda, entre outras.
    \param func É uma instância da classe \sa {simFunction}. Esta composição permite realizar simulações de funções que poderão ser plotadas na biblioteca gráfica.
*/

class grafics : public GlView
{
private:
    graphicProperties prop;
    simFunction func;
    void clearDraw();
    void DrawTitle();
    void DrawXLabel();
    void DrawYLabel();
    void DrawAxis(double ZeroXPosition = -40,
                  double ZeroYPosition =  0);
    void DrawGrid();
    void DrawData();
    void DrawGraphic();
//    void ZoomIn();
//    void ZoomOut();
    void DrawFunction();

public:
    //! Construtor padrão da biblioteca de plotagem de gráficos 2d
    /*!
        O construtor padrão da biblioteca de plotagem de gráficos 2d inicializa o objeto grafics com todos os parâmetros internos a classe default.

        Ex:

\code
            #include <src/graphicLibs/grafics.h>
            int main(int argc, char *argv)
            {
                GlView *plot = new grafics;
                return 0;
            }
\endcode

        Resultado:

        Obs: O exemplo não apresenta resultados em tela

         Ver também: \sa grafics(graphicProperties prop, simFunction func)
    */

    grafics();

    //! Sobrecarga do construtor da biblioteca de plotagem de gráficos 2d
    /*!
        Esta sobrecarga do construtor da biblioteca de plotagem de gráficos 2d inicializa o objeto grafics com func recebendo os parâmetros setados e prop sendo setado default.
        \param func objeto do tipo \sa simFunction que permite acessar os pontos ou uma função para plotar o seu gráfico.

        Ex:

\code
            #include <src/graphicLibs/grafics.h>
            int main(int argc, char *argv)
            {
                In  = "0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10";
                Out = "0,1,2,3,4,5,6,7,8,9,10;0,2,4,8,16,25,36,48,64,81,100;0,2,4,6,8,10,12,14,16,18,20";
                simFunction S(In,Out);

                GlView *plot = new grafics(func);

                return 0;
            }
\endcode

        Resultado:

        Obs: O exemplo não apresenta resultados em tela

         Ver também: \sa grafics(graphicProperties prop, simFunction func)
    */

    grafics(simFunction func);

    //! Sobrecarga do construtor da biblioteca de plotagem de gráficos 2d
    /*!
        Esta sobrecarga do construtor da biblioteca de plotagem de gráficos 2d inicializa o objeto grafics com prop recebendo os parâmetros setados e func sendo setado default.
        \param prop objeto do tipo graphicProperties que permite inserir legenda, grid, títulos, etc.

        Ex:

\code
        #include <src/graphicLibs/grafics.h>
        int main(int argv, char *argc[])
        {
            graphicProperties prop;
            prop.setLimits(-40,40,0,35);
            prop.setGridStatus(true);
            prop.setTitle("Avaliacao dos resultados obtidos com PSO");

            GlView *plot = new grafics(prop);
            plot->setInstance(plot);
            plot->startFramework(argv,argc);

            return 0;
        }
\endcode

        Resultado:

        Obs: O exemplo não apresenta resultados em tela

         Ver também: \sa simFunction(Matrix<double> in, Matrix<double> out)
    */

    grafics(graphicProperties prop);

    //! Sobrecarga do construtor da biblioteca de plotagem de gráficos 2d
    /*!
        Esta sobrecarga do construtor da biblioteca de plotagem de gráficos 2d inicializa o objeto grafics com prop e func recebendo os parâmetros setados.
        \param prop objeto do tipo graphicProperties que permite inserir legenda, grid, títulos, etc.

        Ex:

\code
        #include <src/graphicLibs/grafics.h>
        int main(int argv, char *argc[])
        {
            Matrix<double> In, Out;
            In  = "0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10;0,1,2,3,4,5,6,7,8,9,10";
            Out = "0,1,2,3,4,5,6,7,8,9,10;0,2,4,8,16,25,36,48,64,81,100;0,2,4,6,8,10,12,14,16,18,20";
            simFunction S(In,Out);

            graphicProperties prop;
            prop.setLimits(-40,40,0,35);
            prop.setGridStatus(true);
            prop.setTitle("Avaliacao dos resultados obtidos com PSO");

            GlView *plot = new grafics(prop,S);
            plot->setInstance(plot);
            plot->startFramework(argv,argc);

            return 0;
        }
\endcode

        Resultado:

        Obs: O exemplo não apresenta resultados em tela

         Ver também: \sa simFunction(Matrix<double> in, Matrix<double> out)
    */

    grafics(graphicProperties prop, simFunction func);

    //! Método implementado da classe abstrata GlView que apresenta o gráfico na tela com todas as propriedades setadas.
    void display();
    //! Método implementado da classe abstrata GlView para tratar o click do mouse, se o mouse está clicado e sua posição x e y no gráfico.
    void MouseClickProcess(int button, int state, int x, int y);
    //! Método implementado da classe abstrata GlView para tratar a posição do mouse enquanto ele está em movimento e com o botão apertado em cima do gráfico.
    void MotionFunc(int x, int y);
    //! Método implementado da classe abstrata GlView para tratar a posição do mouse enquanto ele está em movimento sem que o botão esteja apertado em cima do gráfico.
    void PassiveMotionFunc(int x, int y);
};

#endif // GRAFICS_H
