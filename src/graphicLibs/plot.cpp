#include "SistemasdeControle/headers/graphicLibs/plot.h"

template<typename Type>
plot<Type>::plot(LinAlg::Matrix<Type> X, LinAlg::Matrix<Type> Y, QMainWindow *MainWindow)
{
    this->setPlotSize();
    this->initPlot(MainWindow);
    this->setxLabel("Matriz X de Dados");
    this->setyLabel("Matriz Y de Dados");
    this->setTitle("Primeiro teste com Grafico");
    this->setFont();

    // add title layout element:
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(this->customPlot, this->title.c_str()));

    if(X.getNumberOfColumns() == Y.getNumberOfColumns() && X.getNumberOfRows() == Y.getNumberOfRows())
    {
        this->rows = X.getNumberOfRows();
        this->columns = X.getNumberOfColumns();
        this->setLegend();

        QPen pen;
        // add graphs with different scatter styles:
        for (unsigned i = 0; i < this->rows; ++i)
        {
          customPlot->addGraph();
          pen.setColor(QColor(qSin(i*0.3)*100+100, qSin(i*0.6+0.7)*100+100, qSin(i*0.4+0.6)*100+100));
          // generate data:
          QVector<double> x(this->columns), y(this->columns);
          for (unsigned k = 0; k < this->columns; ++k)
          {
            x[k] = X(i+1,k+1);
            y[k] = Y(i+1,k+1);
          }
          customPlot->graph()->setData(x, y);
          customPlot->graph()->rescaleAxes(true);
          customPlot->graph()->setPen(pen);
          customPlot->graph()->setName("Grafico" + QString::number(i+1));
          customPlot->graph()->setLineStyle(QCPGraph::lsLine);
          customPlot->xAxis->setLabel(this->xLabel.c_str());
          customPlot->yAxis->setLabel(this->yLabel.c_str());
          // set scatter style:
        }
     }
    customPlot->rescaleAxes();
}

template <typename Type>
void plot<Type>::initPlot(QMainWindow *MainWindow)
{
    centralWidget = new QWidget(MainWindow);
    centralWidget->setGeometry(QRect(this->windowPosX, this->windowPosY, this->windowSizeX, this->windowSizeY));
    customPlot = new QCustomPlot(centralWidget);
    customPlot->setGeometry(QRect(this->windowPosX, this->windowPosY, this->windowSizeX, this->windowSizeY));
}

template <typename Type>
void plot<Type>::setPlotSize(unsigned posX, unsigned posY, unsigned sizeX, unsigned sizeY)
{
    this->windowPosX = posX;
    this->windowPosY = posY;
    this->windowSizeX = sizeX;
    this->windowSizeY = sizeY;
}

template <typename Type>
void plot<Type>::setVariablesNames(std::string *varNames)
{
    this->variablesName = varNames;
}

template <typename Type>
void plot<Type>::setLegend()
{
    customPlot->legend->setVisible(true);
    customPlot->legend->setFont(QFont(this->font.c_str(), 9));
    customPlot->legend->setRowSpacing(-3);
}

template <typename Type>
void plot<Type>::setTitle(std::string title)
{
    this->title = title;
}

template <typename Type>
void plot<Type>::setxLabel(std::string xLabel)
{
    this->xLabel = xLabel;
}

template <typename Type>
void plot<Type>::setyLabel(std::string yLabel)
{
    this->yLabel = yLabel;
}

template <typename Type>
void plot<Type>::setFont(std::string font)
{
    this->font = font;
}

template class plot <int>;
template class plot <float>;
template class plot <double>;
