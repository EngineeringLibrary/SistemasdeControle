#ifndef GRAPHICPROPERTIES_H
#define GRAPHICPROPERTIES_H
#include <src/primitiveLibs/matrix.h>

//! Classe para auxiliar a construção de gráficos.

/*!
    A Classe graphicProperties tem como objetivo principal auxiliar as classes de plotagem de gráficos.

    \param title Variável responsável por armazenar a string que será apresentada como um título para o gráfico.
    \param xLabel Variável responsável por armazenar a string que será apresentada como um rótulo para o eixo x.
    \param yLabel Variável responsável por armazenar a string que será apresentada como um rótulo para o eixo y.
    \param XClicks Variável que guarda os clicks em x realizados em uma pilha, de maneira a permitir que quando o usuário clique com o botão esquerdo do mouse as telas sejam apresentadas com o caminho inverso de quando o gráfico foi aproximado.
    \param YClicks Variável que guarda os clicks em y realizados em uma pilha, de maneira a permitir que quando o usuário clique com o botão esquerdo do mouse as telas sejam apresentadas com o caminho inverso de quando o gráfico foi aproximado.
    \param GridStatus Variável que quando setada em 1 indica que o grid deve ser plotado juntamente com o gráfico e quando setada em zero indica o contrário.
    \param HoldStatus Variável que quando setada em 1 indica que outros gráficos podem ser plotados juntamente com o gráfico  da instancia atual e quando setada em zero indica o contrário.
    \param NumberOfClicks Variável inteira que é a diferença entre a quantidade de cliques realizados com o botão direito e esquerdo do mouse. Incrementa quando for clicado o botão direito e decrementa quando houver um clique com o botão esquerdo.
    \param GraphicDataSize Variável que indica a quantidade de pontos que serão, ou estão plotados no gráfico.
    \param MotionOcurrency Variável booleana que registra se houve movimento com o mouse quando ele foi clicado (1 houve e 0 não houve).
    \param GraphicXposition Variável inteira que registra a posição x em que houve um clique com o mouse.
    \param GraphicYposition Variável inteira que registra a posição y em que houve um clique com o mouse.
    \param GraphicYLimit_Up Variável inteira que armazena o limite superior do eixo y (para que não haja plotagem fora da região gráfica).
    \param GraphicXLimit_Left Variável inteira que armazena o limite inferior (lado esquerdo) do eixo x (para que não haja plotagem fora da região gráfica).
    \param GraphicYLimit_Down Variável inteira que armazena o limite inferior do eixo y (para que não haja plotagem fora da região gráfica).
    \param GraphicXLimit_Right Variável inteira que armazena o limite superior (lado direito) do eixo x (para que não haja plotagem fora da região gráfica).
    \param LastMotionXPosition Variável inteira que armazena a ultima posição de movimento do mouse no eixo x (com o objetivo de deslocar a região gráfica quando o mouse for clicado e arrastado).
    \param LastMotionYPosition Variável inteira que armazena a ultima posição de movimento do mouse no eixo y (com o objetivo de deslocar a região gráfica quando o mouse for clicado e arrastado).

*/


class graphicProperties
{
private:
    int            GraphicXLimit_Left, GraphicXLimit_Right,
                   GraphicYLimit_Down, GraphicYLimit_Up,
                   NumberOfClicks;
    double         GraphicDataSize,    GraphicXposition,
                   GraphicYposition,   LastMotionXPosition,
                   LastMotionYPosition;
    bool           GridStatus, HoldStatus, MotionOcurrency;
    Matrix<double> XClicks, YClicks;
    std::string    xLabel, yLabel, title;

public:
    //! Construtor padrão da biblioteca de propriedades gráficas
    graphicProperties();
    //! Método cuja responsabilidade é retornar verdadeiro (1) quando os parâmetros in (x) e out (x) estão dentro dos limites de plotagem do gráfico.
    bool isInGraphicRegion(double in, double out);
    //! Método cuja responsabilidade é retornar verdadeiro (1) quando o parâmetro in (x) está dentro dos limites de plotagem (x) do gráfico.
    bool isInXLimit       (double in);
    //! Método cuja responsabilidade é retornar verdadeiro (1) quando o parâmetro out (y) está dentro dos limites de plotagem (y) do gráfico.
    bool isInYLimit       (double out);
    //! Método cuja responsabilidade é inserir na variável xClicks os clicks realizados no gráfico (somente a componente x).
    void setXClicks(int i, int j, double number);
    //! Método cuja responsabilidade é inserir na variável yClicks os clicks realizados no gráfico (somente a componentey).
    void setYClicks(int i, int j, double number);
    //! Método cuja responsabilidade é inserir um valor na variável GraphicXposition.
    void setGraphicXposition   (double GraphicXposition);
    //! Método cuja responsabilidade é inserir um valor na variável GraphicYposition.
    void setGraphicYposition   (double GraphicYposition);
    //! Método cuja responsabilidade é inserir um valor booleano na variável MotionOcurrency.
    void setMotionOcurrency    (bool MotionOcurrency);
    //! Método cuja responsabilidade é inserir um valor booleano na variável GridStatus.
    void setGridStatus         (bool GridStatus);
    //! Método cuja responsabilidade é inserir um valor booleano na variável HoldStatus.
    void setHoldStatus         (bool HoldStatus);
    //! Método cuja responsabilidade é inserir um valor na variável GraphicDataSize.
    void setGraphicDataSize    (double GraphicDataSize);
    //! Método cuja responsabilidade é inserir um valor na variável NumberOfClicks.
    void setNumberOfClicks     (int NumberOfClicks);
    //! Método cuja responsabilidade é inserir uma string para colocar no eixo X como legenda.
    void setXLabel             (std::string xLabel);
    //! Método cuja responsabilidade é inserir uma string para colocar no eixo Y como legenda.
    void setYLabel             (std::string yLabel);
    //! Método cuja responsabilidade é inserir uma string para colocar no título.
    void setTitle              (std::string title);
    //! Método cuja responsabilidade é inserir valores que indiquem a posição do mouse na qual o botão direito do mouse foi despressionado.
    void setLastMotionPosition (double LastMotionXPosition,
                                double LastMotionYPosition);
    //! Método cuja responsabilidade é inserir valores que indiquem os limites do gráfico.
    void setLimits             (double GraphicXLimit_Left,
                                double GraphicXLimit_Rigth,
                                double GraphicYLimit_Down,
                                double GraphicYLimit_Up);

    //! Método cuja responsabilidade é obter o valor da variável NumberOfClicks.
    int            getNumberOfClicks();
    //! Método cuja responsabilidade é saber se houve movimento do mouse (obtendo o valor booleano de MotionOcurrency).
    bool           getMotionOcurrency();
    //! Método cuja responsabilidade é obter o valor booleano da variável HoldStatus.
    bool           getHoldStatus();
    //! Método cuja responsabilidade é obter o valor booleano da variável GridStatus.
    bool           getGridStatus();
    //! Método cuja responsabilidade é obter o valor da variável GraphicXposition.
    double         getGraphicXposition();
    //! Método cuja responsabilidade é obter o valor da variável GraphicYposition.
    double         getGraphicYposition();
    //! Método cuja responsabilidade é obter o valor da variável GraphicXLimit_Left.
    double         getXLimitLeft();
    //! Método cuja responsabilidade é obter o valor da variável GraphicXLimit_Rigth.
    double         getXLimitRight();
    //! Método cuja responsabilidade é obter o valor da variável GraphicYLimit_Down.
    double         getYLimitDown();
    //! Método cuja responsabilidade é obter o valor da variável GraphicYLimit_Up.
    double         getYLimitUp();
    //! Método cuja responsabilidade é obter o valor da variável LastXMotionPosition.
    double         getLastXMotionPosition();
    //! Método cuja responsabilidade é obter o valor da variável LastYMotionPosition.
    double         getLastYMotionPosition();
    //! Método cuja responsabilidade é obter o valor da variável GraphicDataSize.
    double         getGraphicDataSize();
    //! Método cuja responsabilidade é obter o valor da variável XLabel.
    std::string    getXLabel();
    //! Método cuja responsabilidade é obter o valor da variável YLabel.
    std::string    getYLabel();
    //! Método cuja responsabilidade é obter o valor da variável Title.
    std::string    getTitle ();
    //! Método cuja responsabilidade é obter o valor da variável XClicks.
    Matrix<double> getXClicks();
    //! Método cuja responsabilidade é obter o valor da variável YClicks.
    Matrix<double> getYClicks();
};

#endif // GRAPHICPROPERTIES_H
