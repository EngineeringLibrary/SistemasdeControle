#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>
#include <QWidget>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "qcustomplot.h"

struct plotProperties{
    QMainWindow *MainWindow;
    std::string xLabel, yLabel, *variablesName, font, title;
    unsigned rows, columns, windowSizeX, windowSizeY, windowPosX, windowPosY;

    plotProperties()
    {
        this->title       = "";
        this->xLabel      = "";
        this->yLabel      = "";
        this->windowPosX  = 0;
        this->windowPosY  = 0;
        this->windowSizeX = 400;
        this->windowSizeY = 300;
        this->font        = "Helvetica";
    }
};

template<typename Type>
class plot: public QMainWindow
{
    plotProperties properties;
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    void initPlot();

public:
    plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, plotProperties properties);
//    void setPlotSize();
//    void setLegend();
//    void setVariablesNames();
//    void setTitle();
//    void setxLabel();
//    void setyLabel();
//    void setFont();
};

#endif // PLOT_H
