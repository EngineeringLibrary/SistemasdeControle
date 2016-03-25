#ifndef PLOT_H
#define PLOT_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include "qcustomplot.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace PlotHandler {
    struct plotProperties{

        QWidget *PlotFrame;
        std::string xLabel, yLabel, *variablesName, font, title;
        unsigned rows, columns, windowSizeX, windowSizeY, windowPosX, windowPosY;
        bool xLabelFlag, yLabelFlag, variablesNameFlag, fontFlag, titleFlag, windowFlag, sizeWindowwindowFlag;

        plotProperties()
        {
            this->font                 = "Helvetica";
            this->title                = "";
            this->xLabel               = "";
            this->yLabel               = "";
            this->fontFlag             = 0;
            this->titleFlag            = 0;
            this->yLabelFlag           = 0;
            this->xLabelFlag           = 0;
            this->windowFlag           = 0;
            this->windowPosX           = 0;
            this->windowPosY           = 0;
            this->windowSizeX          = 400;
            this->windowSizeY          = 300;
            this->variablesNameFlag    = 0;
            this->sizeWindowwindowFlag = 1;
        }

        void setPlotSize(unsigned posX, unsigned posY, unsigned sizeX, unsigned sizeY)
        {
            this->windowPosX           = posX;
            this->windowPosY           = posY;
            this->windowSizeX          = sizeX;
            this->windowSizeY          = sizeY;
            this->sizeWindowwindowFlag = 1;
        }

        void setVariablesNames(std::string *variablesName)
        {
            this->variablesName        = variablesName;
            this->variablesNameFlag    = 1;
        }

    //    void setLegend()
    //    {
    //        customPlot->legend->setVisible(true);
    //        customPlot->legend->setFont(QFont(this->properties.font.c_str(), 9));
    //        customPlot->legend->setRowSpacing(-3);
    //    }

        void setTitle(std::string title)
        {
            this->title     = title;
            this->titleFlag = 1;
        }

        void setxLabel(std::string xLabel)
        {
            this->xLabel     = xLabel;
            this->xLabelFlag = 1;
        }

        void setyLabel(std::string yLabel)
        {
            this->yLabel     = yLabel;
            this->yLabelFlag = 1;
        }

        void setFont(std::string font)
        {
            this->font     = font;
            this->fontFlag = 1;
        }
        void setPlotFrame(QWidget *Frame)
        {
            this->windowFlag = 1;
            this->PlotFrame = Frame;
        }
    };

    template<typename Type>
    class plot
    {
        QTimer          *dataTimer;
        QCustomPlot     *customPlot;
        plotProperties   properties;


        void generalPlot(LinAlg::Matrix<Type> X);
        void generalPlot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y);
        void realTimePlotInit();
    public:
        void realTimeDataUpdate(double i, double j);

    public:
        // COlocar os labels do plot em tempo real
        plot(QWidget *PlotFrame);
        plot(unsigned ySubplot, unsigned xSubplot, QWidget *PlotFrame);
        plot(unsigned ySubplot, unsigned xSubplot, plotProperties properties);
        plot(LinAlg::Matrix<Type> X, QWidget *PlotFrame); //precisa ajeitar
        plot(LinAlg::Matrix<Type> X, plotProperties properties); //precisa ajeitar
        plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, QWidget *PlotFrame);
        plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, plotProperties properties);
        plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, unsigned ySubplot, unsigned xSubplot, QWidget *PlotFrame);
        plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, unsigned ySubplot, unsigned xSubplot, plotProperties properties);
    };
}

#include "SistemasdeControle/src/graphicLibs/plot.hpp"
#endif // PLOT_H
