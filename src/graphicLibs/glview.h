#ifndef GLVIEW_H
#define GLVIEW_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

class GlView
{
private:
    static GlView *instance;

public:
    static void setInstance(GlView *Img);

    static void displayWrapper(void);
    static void MouseFuncWrapper(int button, int state, int x, int y);
    static void MotionFuncWrapper(int x, int y);
    static void PassiveMotionFuncWrapper(int x, int y);

    void startFramework(int argv, char *argc[]);

    virtual void display()=0;
    virtual void MouseClickProcess(int button, int state, int x, int y)=0;
    virtual void MotionFunc(int x,int y)=0;
    virtual void PassiveMotionFunc(int x, int y)=0;
};

#endif // GLVIEW_H
