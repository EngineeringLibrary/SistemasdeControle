#ifndef GLVIEW_H
#define GLVIEW_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

//! Classe para gerenciar interfaces com o OpenGl

/*!
    Essa parte da biblioteca objetiva gerenciar todos os pacotes que utilizarão o OpenGL
    Para inicializar utilizar essa biblioteca o usuário primeiramente deverá baixar o pacote Freeglut e deszipar na pasta do compilador Mingw.
    Além disso, para que o projeto seja compilado, o usuário deverá importar corretamente as bibliotecas do *.lib para serem compiladas
*/

class GlView
{
private:
    static GlView *instance;

public:

    //! Recebe uma instância do objeto GlView e seta a variável instance

    /*!
        O objetivo deste método é manter uma instância do objeto GlView para que seja possível a implementação sem acoplamento com as classes herdadas, sendo possível receber uma instância qualquer.
        \param Img É um objeto do tipo GlView

        Ex:

\code
        #include <src/graphicLibs/grafics.h>

        int main(int argv, char *argc[])
        {

            simFunction S(cos, 0,2*3.14,3.14/100);

            graphicProperties prop;
            GlView *f = new grafics(prop, S);

            f->setInstance(f);
            f->startFramework(argv,argc);
            return 0;
        }
\endcode

        Resultado:

         1.000  0.000  3.000\n
         4.000  5.000  6.000\n
         1.000  8.000  9.000\n

         1.000  0.000  0.000\n
         0.000  1.000  0.000\n
         0.000  0.000  1.000\n

        Resultado:

        \image <PNG> <Exemplo2> ‘‘Exemplo da apresentação do gráfico’’

        Ver também: \sa startFramework(ins argv, char *argc[])
    */

    static void setInstance(GlView *Img);

    //! Método para mostrar na janela desenhos criados com comandos no OpenGL
    static void displayWrapper(void);
    //! Método para obter o click do mouse, se o mouse está clicado e sua posição x e y na tela;
    static void MouseFuncWrapper(int button, int state, int x, int y);
    //! Método para obter a posição do mouse enquanto ele está em movimento e com o botão apertado
    static void MotionFuncWrapper(int x, int y);
    //! Método para obter a posição do mouse enquanto ele está em movimento sem que o botão esteja apertado
    static void PassiveMotionFuncWrapper(int x, int y);

    //! Inicializa a aplicação permitindo a abertura de uma janela e o desenhos quaisquer a partir do OpenGL

    /*!
        O objetivo deste método é inicializar a aplicação permitindo a abertura de uma janela e o desenhos quaisquer a partir do OpenGL
        \param argv parâmetro recebido da função main()
        \param *argc[] parâmetro recebido da função main()

        Ex:

\code
        #include <src/graphicLibs/grafics.h>

        int main(int argv, char *argc[])
        {

            simFunction S(cos, 0,2*3.14,3.14/100);

            graphicProperties prop;
            GlView *f = new grafics(prop, S);

            f->setInstance(f);
            f->startFramework(argv,argc);
            return 0;
        }
\endcode

        Resultado:

         1.000  0.000  3.000\n
         4.000  5.000  6.000\n
         1.000  8.000  9.000\n

         1.000  0.000  0.000\n
         0.000  1.000  0.000\n
         0.000  0.000  1.000\n

        Resultado:

        \image <PNG> <Exemplo2> ‘‘Exemplo da apresentação do gráfico’’

        Ver também: \sa setInstance(GlView *Img)
    */

    void startFramework(int argv, char *argc[]);
    //! Método virtual que permite que uma classe filha implemente um método para mostrar na janela desenhos criados com comandos no OpenGL
    virtual void display()=0;
    //! Método virtual que permite que uma classe filha implemente um Método para tratar o click do mouse, se o mouse está clicado e sua posição x e y na tela;
    virtual void MouseClickProcess(int button, int state, int x, int y)=0;
    //!  Método virtual que permite que uma classe filha implemente um Método para tratar a posição do mouse enquanto ele está em movimento e com o botão apertado
    virtual void MotionFunc(int x,int y)=0;
     //!  Método virtual que permite que uma classe filha implemente um Método para tratar a posição do mouse enquanto ele está em movimento sem que o botão esteja apertado
    virtual void PassiveMotionFunc(int x, int y)=0;
};

#endif // GLVIEW_H
