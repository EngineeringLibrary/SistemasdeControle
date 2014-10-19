#ifndef GRAFICS_H
#define GRAFICS_H
#include <src/graphicLibs/glview.h>
#include <math.h>
#include <src/primitiveLibs/matrix.h>

class grafics : public GlView
{
private:
    double (*FunctionToCall)(double),
           lMin,
           lMax,
           step,
           MinOutputValue,
           MaxOutputValue,
           GraphicDataSize,
           GraphicXposition,
           GraphicYposition,
           LastMotionXPosition,
           LastMotionYPosition;

    Matrix<double> input, output, XClicks, YClicks;
    int NumberOfClicks, GraphicXLimit_Left, GraphicXLimit_Rigth
                      , GraphicYLimit_Down, GraphicYLimit_Up;
    bool grid, MotionOcurrency;


    double FunctionCalculation(double input);
    double normalize(double input, double xUp, double xDown, double yUp, double yDown);
    bool isInGraphicRegion(double in, double out);
    bool isInXLimit(double in);
    bool isInYLimit(double out);
    void clearDraw();
    void DrawAxis(double ZeroXPosition = -40, double ZeroYPosition = 0);
    void DrawGrid();
    void DrawData();
    void DrawGraphic();
    void GenerateDataFunction();
//    void ZoomIn();
//    void ZoomOut();
    void DrawFunction();

public:
    grafics();
    grafics(double (*FunctionToCall)(double), double lMin, double lMax, double step);
    void setGraphicPosition(int GraphicXLimit_Left,
                            int GraphicXLimit_Rigth,
                            int GraphicYLimit_Down,
                            int GraphicYLimit_Up);
    void display();
    void MouseClickProcess(int button, int state, int x, int y);
    void MotionFunc(int x, int y);
    void PassiveMotionFunc(int x, int y);
};

#endif // GRAFICS_H
