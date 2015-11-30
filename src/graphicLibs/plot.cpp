#include "SistemasdeControle/headers/graphicLibs/plot.h"

template<typename Type>
plot<Type>::plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, plotProperties properties)
{
    this->properties.MainWindow    = properties.MainWindow;
    this->properties.xLabel        = properties.xLabel;
    this->properties.yLabel        = properties.yLabel;
    this->properties.variablesName = properties.variablesName;
    this->properties.font          = properties.font;
    this->properties.title         = properties.title;
    this->properties.windowSizeX   = properties.windowSizeX;
    this->properties.windowSizeY   = properties.windowSizeY;
    this->properties.windowPosX    = properties.windowPosX;
    this->properties.windowPosY    = properties.windowPosY;

    this->initPlot();

    // add title layout element:
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(this->customPlot, this->properties.title.c_str()));

    if(X.getNumberOfColumns() == Y.getNumberOfColumns() && X.getNumberOfRows() == Y.getNumberOfRows())
    {
        this->properties.rows = X.getNumberOfRows();
        this->properties.columns = X.getNumberOfColumns();
//        this->setLegend();

        QPen pen;
        // add graphs with different scatter styles:
        for (unsigned i = 0; i < this->properties.rows; ++i)
        {
          customPlot->addGraph();
          pen.setColor(QColor(qSin(i*0.3)*100+100, qSin(i*0.6+0.7)*100+100, qSin(i*0.4+0.6)*100+100));
          // generate data:
          QVector<double> x(this->properties.columns), y(this->properties.columns);
          for (unsigned k = 0; k < this->properties.columns; ++k)
          {
            x[k] = X(i+1,k+1);
            y[k] = Y(i+1,k+1);
          }
          customPlot->graph()->setData(x, y);
          customPlot->graph()->rescaleAxes(true);
          customPlot->graph()->setPen(pen);
          customPlot->graph()->setName("Grafico" + QString::number(i+1));
          customPlot->graph()->setLineStyle(QCPGraph::lsLine);
          customPlot->xAxis->setLabel(this->properties.xLabel.c_str());
          customPlot->yAxis->setLabel(this->properties.yLabel.c_str());
          // set scatter style:
        }
     }
    customPlot->rescaleAxes();
}

template <typename Type>
void plot<Type>::initPlot()
{
//    this->setPlotSize();

    centralWidget = new QWidget(this->properties.MainWindow);
    centralWidget->setGeometry(QRect(this->properties.windowPosX, this->properties.windowPosY, this->properties.windowSizeX, this->properties.windowSizeY));
    customPlot = new QCustomPlot(this->centralWidget);
    customPlot->setGeometry(QRect(this->properties.windowPosX, this->properties.windowPosY, this->properties.windowSizeX, this->properties.windowSizeY));

//    this->setxLabel();
//    this->setyLabel();
//    this->setTitle();
//    this->setFont();
}

//template <typename Type>
//void plot<Type>::setPlotSize()
//{
//    this->properties.windowPosX = posX;
//    this->properties.windowPosY = posY;
//    this->properties.windowSizeX = sizeX;
//    this->properties.windowSizeY = sizeY;
//}

//template <typename Type>
//void plot<Type>::setVariablesNames()
//{
//    this->properties.variablesName = varNames;
//}

//template <typename Type>
//void plot<Type>::setLegend()
//{
//    customPlot->legend->setVisible(true);
//    customPlot->legend->setFont(QFont(this->properties.font.c_str(), 9));
//    customPlot->legend->setRowSpacing(-3);
//}

//template <typename Type>
//void plot<Type>::setTitle()
//{
//    this->properties.title = title;
//}

//template <typename Type>
//void plot<Type>::setxLabel()
//{
//    this->properties.xLabel = xLabel;
//}

//template <typename Type>
//void plot<Type>::setyLabel()
//{
//    this->properties.yLabel = yLabel;
//}

//template <typename Type>
//void plot<Type>::setFont()
//{
//    this->properties.font = font;
//}

template class plot <int>;
template class plot <float>;
template class plot <double>;
