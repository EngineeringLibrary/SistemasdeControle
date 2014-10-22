#ifndef GRAPHICPROPERTIES_H
#define GRAPHICPROPERTIES_H
#include <src/primitiveLibs/matrix.h>

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
    graphicProperties();
    bool isInGraphicRegion(double in, double out);
    bool isInXLimit       (double in);
    bool isInYLimit       (double out);

    void setXClicks(int i, int j, double number);
    void setYClicks(int i, int j, double number);

    void setGraphicXposition   (double GraphicXposition);
    void setGraphicYposition   (double GraphicYposition);
    void setMotionOcurrency    (bool MotionOcurrency);
    void setGridStatus         (bool GridStatus);
    void setHoldStatus         (bool HoldStatus);
    void setGraphicDataSize    (double GraphicDataSize);
    void setNumberOfClicks     (int NumberOfClicks);
    void setXLabel             (std::string xLabel);
    void setYLabel             (std::string yLabel);
    void setTitle              (std::string title);
    void setLastMotionPosition (double LastMotionXPosition,
                                double LastMotionYPosition);
    void setLimits             (double GraphicXLimit_Left,
                                double GraphicXLimit_Rigth,
                                double GraphicYLimit_Down,
                                double GraphicYLimit_Up);

    int            getNumberOfClicks();
    bool           getMotionOcurrency();
    bool           getHoldStatus();
    bool           getGridStatus();
    double         getGraphicXposition();
    double         getGraphicYposition();
    double         getXLimitLeft();
    double         getXLimitRight();
    double         getYLimitDown();
    double         getYLimitUp();
    double         getLastXMotionPosition();
    double         getLastYMotionPosition();
    double         getGraphicDataSize();
    std::string    getXLabel();
    std::string    getYLabel();
    std::string    getTitle ();
    Matrix<double> getXClicks();
    Matrix<double> getYClicks();
};

#endif // GRAPHICPROPERTIES_H
