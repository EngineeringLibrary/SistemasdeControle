#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>
#include <QWidget>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "qcustomplot.h"

template<typename Type>
class plot: public QMainWindow
{
    QWidget *centralWidget;
    QCustomPlot *customPlot;

    unsigned rows, columns, windowSizeX, windowSizeY, windowPosX, windowPosY;
    std::string xLabel, yLabel, *variablesName, font, title;

    void initPlot(QMainWindow *MainWindow);

public:
    plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, QMainWindow *MainWindow);
    void setPlotSize(unsigned posX = 0, unsigned posY = 0, unsigned sizeX = 400, unsigned sizeY = 300);
    void setLegend();
    void setVariablesNames(std::string *varNames);
    void setTitle(std::string title = "");
    void setxLabel(std::string xLabel = "");
    void setyLabel(std::string yLabel = "");
    void setFont(std::string font = "Helvetica");
};

#endif // PLOT_H
