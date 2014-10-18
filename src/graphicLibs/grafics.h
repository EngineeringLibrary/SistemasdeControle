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
    int NumberOfClicks;
    bool grid, MotionOcurrency;


    double FunctionCalculation(double input);
    void clearDraw();
    void DrawAxis(int ZeroXPosition = -40, int ZeroYPosition = 0);
    void DrawGrid();
    void DrawData();
    void GenerateDataFunction();
//    void ZoomIn();
//    void ZoomOut();
    void DrawFunction();

public:
    grafics();
    grafics(double (*FunctionToCall)(double), double lMin, double lMax, double step);
    void display();
    void MouseClickProcess(int button, int state, int x, int y);
    void MotionFunc(int x, int y);
    void PassiveMotionFunc(int x, int y);
};

#endif // GRAFICS_H
