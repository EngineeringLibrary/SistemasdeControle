#include "graphicproperties.h"

graphicProperties::graphicProperties()
{
    this->title = "Titulo do Grafico";
    this->GraphicDataSize = 1;
    this->GraphicXposition = 0;
    this->GraphicYposition = 0;
    this->NumberOfClicks = 0;
    this->LastMotionXPosition = 0;
    this->LastMotionYPosition = 0;
    this->GraphicXLimit_Left = 0;
    this->GraphicXLimit_Right = 40;
    this->GraphicYLimit_Down = 0;
    this->GraphicYLimit_Up = 40;
    this->MotionOcurrency = false;
}

bool graphicProperties::isInGraphicRegion(double in, double out)
{
    return (in >= this->GraphicXLimit_Left  &&
            in <= this->GraphicXLimit_Right &&
            out >= this->GraphicYLimit_Down &&
            out <= this->GraphicYLimit_Up);
}

bool graphicProperties::isInXLimit(double in)
{
    return (in >= this->GraphicXLimit_Left  &&
            in <= this->GraphicXLimit_Right);
}

bool graphicProperties::isInYLimit(double out)
{
    return (out >= this->GraphicYLimit_Down &&
            out <= this->GraphicYLimit_Up);
}

double graphicProperties::getGraphicXposition()
{
    return this->GraphicXposition;
}

double graphicProperties::getGraphicYposition()
{
    return this->GraphicYposition;
}

void graphicProperties::setMotionOcurrency(bool MotionOcurrency)
{
    this->MotionOcurrency = MotionOcurrency;
}

void graphicProperties::setGridStatus(bool GridStatus)
{
    this->GridStatus = GridStatus;
}

void graphicProperties::setHoldStatus(bool HoldStatus)
{
    this->HoldStatus = HoldStatus;
}

void graphicProperties::setLastMotionPosition(double LastMotionXPosition,
                                              double LastMotionYPosition)
{
    this->LastMotionXPosition = LastMotionXPosition;
    this->LastMotionYPosition = LastMotionYPosition;
}

void graphicProperties::setNumberOfClicks(int NumberOfClicks)
{
    this->NumberOfClicks = NumberOfClicks;
}

void graphicProperties::setXLabel(std::string xLabel)
{
    this->xLabel = xLabel;
}

void graphicProperties::setYLabel(std::string yLabel)
{
    this->yLabel = yLabel;
}

void graphicProperties::setTitle (std::string title)
{
    this->title = title;
}

void graphicProperties::setLimits(double GraphicXLimit_Left,
                                  double GraphicXLimit_Right,
                                  double GraphicYLimit_Down,
                                  double GraphicYLimit_Up)
{
    this->GraphicXLimit_Left  = GraphicXLimit_Left;
    this->GraphicXLimit_Right = GraphicXLimit_Right;
    this->GraphicYLimit_Down  = GraphicYLimit_Down;
    this->GraphicYLimit_Up    = GraphicYLimit_Up;
}

void graphicProperties::setXClicks(int i, int j, double number)
{
    this->XClicks(i,j,number);
}

void graphicProperties::setYClicks(int i, int j, double number)
{
    this->YClicks(i,j,number);
}

void graphicProperties::setGraphicDataSize(double GraphicDataSize)
{
    this->GraphicDataSize = GraphicDataSize;
}

bool graphicProperties::getMotionOcurrency()
{
    return this->MotionOcurrency;
}

bool graphicProperties::getHoldStatus()
{
    return this->HoldStatus;
}

bool graphicProperties::getGridStatus()
{
    return this->GridStatus;
}

double graphicProperties::getLastXMotionPosition()
{
    return this->LastMotionXPosition;
}

double graphicProperties::getLastYMotionPosition()
{
    return this->LastMotionYPosition;
}

int graphicProperties::getNumberOfClicks()
{
    return this->NumberOfClicks;
}

std::string graphicProperties::getXLabel()
{
    return this->xLabel;
}

std::string graphicProperties::getYLabel()
{
    return this->yLabel;
}

std::string graphicProperties::getTitle ()
{
    return this->title;
}

double graphicProperties::getXLimitLeft()
{
    return this->GraphicXLimit_Left;
}

double graphicProperties::getXLimitRight()
{
    return this->GraphicXLimit_Right;
}

double graphicProperties::getYLimitDown()
{
    return GraphicYLimit_Down;
}

double graphicProperties::getYLimitUp()
{
    return this->GraphicYLimit_Up;
}

Matrix<double> graphicProperties::getXClicks()
{
    return this->XClicks;
}

Matrix<double> graphicProperties::getYClicks()
{
    return this->YClicks;
}

void graphicProperties::setGraphicXposition(double GraphicXposition)
{
    this->GraphicXposition = GraphicXposition;
}

void graphicProperties::setGraphicYposition(double GraphicYposition)
{
    this->GraphicYposition = GraphicYposition;
}

double graphicProperties::getGraphicDataSize()
{
    return this->GraphicDataSize;
}
