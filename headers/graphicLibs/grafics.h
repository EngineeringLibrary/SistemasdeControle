#ifndef GRAFICS_H
#define GRAFICS_H
#include <src/graphicLibs/glview.h>
#include <math.h>
#include <src/primitiveLibs/matrix.h>
#include <src/graphicLibs/graphicproperties.h>
#include <src/simulationLibs/simfunction.h>

class grafics : public GlView
{
private:
    graphicProperties prop;
    simFunction func;
    void clearDraw();
    void DrawTitle();
    void DrawXLabel();
    void DrawYLabel();
    void DrawAxis(double ZeroXPosition = -40,
                  double ZeroYPosition =  0);
    void DrawGrid();
    void DrawData();
    void DrawGraphic();
//    void ZoomIn();
//    void ZoomOut();
    void DrawFunction();

public:
    grafics();
    grafics(simFunction func);
    grafics(graphicProperties prop);
    grafics(graphicProperties prop, simFunction func);

    void display();
    void MouseClickProcess(int button, int state, int x, int y);
    void MotionFunc(int x, int y);
    void PassiveMotionFunc(int x, int y);
};

#endif // GRAFICS_H
