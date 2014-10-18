#include "grafics.h"

grafics::grafics()
{
    this->GraphicDataSize = 1;
    this->GraphicXposition = 0;
    this->GraphicYposition = 0;
    this->NumberOfClicks = 0;
    this->LastMotionXPosition = 0;
    this->LastMotionYPosition = 0;
    MotionOcurrency = false;
}

grafics::grafics(double (*FunctionToCall)(double), double lMin, double lMax, double step)
{
    this->FunctionToCall = FunctionToCall;
    this->lMax = lMax;
    this->lMin = lMin;
    this->step = step;
    this->GraphicDataSize = 1;
    this->GraphicXposition = 0;
    this->GraphicYposition = 0;
    this->NumberOfClicks = 0;
    this->LastMotionXPosition = 0;
    this->LastMotionYPosition = 0;
    MotionOcurrency = false;
}

double grafics::FunctionCalculation(double input)
{
    input = ((*this->FunctionToCall)(input));
    return (input);
}

void grafics::clearDraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clears the colour and depth buffers
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glPushMatrix();     	//saves the current matrix on the top of the matrix stack
    glTranslatef(0,0,-100); //translates the current matrix 0 in x, 0 in y and -100 in z

    glColor3f(0.0,0.0,0.0);
}

void grafics::DrawAxis(int ZeroXPosition, int ZeroYPosition)
{
    glBegin(GL_LINES);
        glVertex2d(ZeroXPosition, -40);
        glVertex2d(ZeroXPosition, 40);
    glEnd();

    glBegin(GL_LINES);
        glVertex2d(-40, ZeroYPosition);
        glVertex2d(40, ZeroYPosition);
    glEnd();


}

void grafics::GenerateDataFunction()
{
    int tam = (int)((this->lMax - this->lMin)/this->step);
    int cont = 1;
    this->input.init(1,tam);

    for (double i = this->lMin; i < this->lMax; i += this->step)
    {

        this->input(1,cont,i);
        this->output(1,cont,this->FunctionCalculation(i));

        if(i == this->lMin)
        {
            this->MaxOutputValue = this->output(1,cont);
            this->MinOutputValue = this->output(1,cont);
        }
        else
        {
            if(this->MaxOutputValue < this->output(1,cont))
                this->MaxOutputValue = this->output(1,cont);

            if(this->MinOutputValue > this->output(1,cont))
                this->MinOutputValue = this->output(1,cont);
        }
        cont++;
    }
}

void grafics::DrawFunction()
{
    int tam = (int)((this->lMax - this->lMin)/this->step),
              ZeroXFunction = -40, ZeroYFunction = 0;
    GenerateDataFunction();

    glBegin(GL_POINTS);
        glVertex2f(this->GraphicDataSize*(80*(input(1,1)  - this->lMin)    /(this->lMax     - this->lMin)     - 40) - this->GraphicXposition,
                   this->GraphicDataSize*(80*(output(1,2) - MinOutputValue)/(MaxOutputValue - MinOutputValue) - 40) + this->GraphicYposition);
    glEnd();

    glBegin(GL_LINE_STRIP);
        for (int i = 1; i <= tam; i++)
        {
            if((input(1,i) > 0 && input(1,i) < this->step) || (input(1,i) < 0 && input(1,i) > -this->step))
                ZeroXFunction = this->GraphicDataSize*(80*(input(1,i)  - this->lMin)    /(this->lMax     - this->lMin)     - 40) - this->GraphicXposition;
            if((output(1,i) > 0 && output(1,i) < this->step) || (output(1,i) < 0 && output(1,i) > -this->step))
                ZeroYFunction = this->GraphicDataSize*(80*(output(1,i) - MinOutputValue)/(MaxOutputValue - MinOutputValue) - 40) + this->GraphicYposition;

            glVertex2f(this->GraphicDataSize*(80*(input(1,i)  - this->lMin)    /(this->lMax     - this->lMin)     - 40) - this->GraphicXposition,
                       this->GraphicDataSize*(80*(output(1,i) - MinOutputValue)/(MaxOutputValue - MinOutputValue) - 40) + this->GraphicYposition);
        }

    glEnd();

    this->DrawAxis(ZeroXFunction, ZeroYFunction);
}

void grafics::DrawGrid()
{
    glBegin(GL_POINTS);
        for (int i = -40; i <= 40; i += 2)
            for (int j = -40; j <= 40; j += 2)
            {
                glVertex2f(i, j);
            }

    glEnd();
}

void grafics::display()
{
    this->clearDraw();

    glPointSize(1.0);

//    this->DrawAxis();
    this->DrawFunction();
    this->DrawGrid();

    glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
    glutSwapBuffers();      //swaps the front and back buffers
}

void grafics::MouseClickProcess(int button, int state, int x, int y)
{
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*40;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*40;

    if(this->MotionOcurrency == false)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            this->XClicks(1, this->NumberOfClicks + 1, a);
            this->YClicks(1, this->NumberOfClicks + 1, b);

            this->GraphicDataSize  += 0.2;
            this->GraphicXposition += this->XClicks(1, this->NumberOfClicks + 1);
            this->GraphicYposition += this->YClicks(1, this->NumberOfClicks + 1);
            this->NumberOfClicks++;
        }
        else if (button == GLUT_RIGHT_BUTTON && this->NumberOfClicks > 0 && state == GLUT_UP)
        {
            this->GraphicDataSize  -= 0.2;
            this->NumberOfClicks--;
            this->GraphicXposition -= this->XClicks(1, this->NumberOfClicks + 1);
            this->GraphicYposition -= this->YClicks(1, this->NumberOfClicks + 1);
        }
        else if(button == GLUT_RIGHT_BUTTON && this->NumberOfClicks == 0)
        {
            this->GraphicXposition = 0;
            this->GraphicYposition = 0;
        }
    }

    else
        this->MotionOcurrency = false;
}

void grafics::MotionFunc(int x, int y)
{
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*40;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*40;

    this->GraphicXposition += (this->LastMotionXPosition - a)/40;
    this->GraphicYposition += (this->LastMotionYPosition - b)/40;
    this->MotionOcurrency = true;
}

void grafics::PassiveMotionFunc(int x, int y)
{
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*40;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*40;

    this->LastMotionXPosition = a;
    this->LastMotionYPosition = b;

//    double a = (x/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*40;
//    double b = (y/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*40;
//    this->LastMotionXPosition = a;
//    this->LastMotionYPosition = b;
}
