#include "grafics.h"

grafics::grafics()
{
    this->GraphicDataSize = 1;
    this->GraphicXposition = 0;
    this->GraphicYposition = 0;
    this->NumberOfClicks = 0;
    this->LastMotionXPosition = 0;
    this->LastMotionYPosition = 0;
    this->GraphicXLimit_Left = -40;
    this->GraphicXLimit_Rigth = 40;
    this->GraphicYLimit_Down = -40;
    this->GraphicYLimit_Up = 40;
    this->MotionOcurrency = false;
    this->FunctionToCall = NULL;
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
    this->GraphicXLimit_Left = 0;
    this->GraphicXLimit_Rigth = 40;
    this->GraphicYLimit_Down = 0;
    this->GraphicYLimit_Up = 40;
    this->MotionOcurrency = false;
}

double grafics::FunctionCalculation(double input)
{
    input = ((*this->FunctionToCall)(input));
    return (input);
}

double grafics::normalize(double input, double xUp, double xDown, double yUp, double yDown)
{
    return ((input - xDown)/(xUp - xDown))*(yUp - yDown) + yDown;
}

bool grafics::isInGraphicRegion(double in, double out)
{
    return (in > this->GraphicXLimit_Left  &&
            in < this->GraphicXLimit_Rigth &&
            out > this->GraphicYLimit_Down &&
            out < this->GraphicYLimit_Up);

}

bool grafics::isInXLimit(double in)
{
    return (in > this->GraphicXLimit_Left  &&
            in < this->GraphicXLimit_Rigth);
}

bool grafics::isInYLimit(double out)
{
    return (out > this->GraphicYLimit_Down &&
            out < this->GraphicYLimit_Up);
}

void grafics::clearDraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clears the colour and depth buffers
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glPushMatrix();     	//saves the current matrix on the top of the matrix stack
    glTranslatef(0,0,-100); //translates the current matrix 0 in x, 0 in y and -100 in z

    glColor3f(0.0,0.0,0.0);
}

void grafics::DrawAxis(double ZeroXPosition, double ZeroYPosition)
{
    if(isInXLimit(ZeroXPosition))
    {
        glBegin(GL_LINES);
            glVertex2f(ZeroXPosition, this->GraphicYLimit_Down);
            glVertex2f(ZeroXPosition, this->GraphicYLimit_Up);
        glEnd();
    }
    if(isInYLimit(ZeroYPosition))
    {
        glBegin(GL_LINES);
            glVertex2f(this->GraphicXLimit_Left, ZeroYPosition);
            glVertex2f(this->GraphicXLimit_Rigth, ZeroYPosition);
        glEnd();
    }


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
        cont++;
    }
}

void grafics::DrawGraphic()
{
    double ZeroXFunction = this->GraphicXLimit_Left,
           ZeroYFunction = ((this->GraphicXLimit_Rigth + this->GraphicXLimit_Left)/2);
    Matrix<double> NormInput, NormOutput;

    NormInput  = this->GraphicDataSize*input.normalize(this->GraphicXLimit_Rigth, this->GraphicXLimit_Left) - this->GraphicXposition;
    NormOutput = this->GraphicDataSize*output.normalize(this->GraphicYLimit_Up, this->GraphicYLimit_Down) + this->GraphicYposition;

    glBegin(GL_LINE_STRIP);
        for (int i = 1; i <= input.getRows(); i++)
            for(int j = 1; j <= input.getCols(); j++)
            {
                if((input(i,j) > 0 && input(i,j) < this->step) || (input(i,j) < 0 && input(i,j) > -this->step))
                    ZeroXFunction = NormInput(i,j);
                if((output(i,j) > 0 && output(i,j) < this->step) || (output(i,j) < 0 && output(i,j) > -this->step))
                    ZeroYFunction = NormOutput(i,j);
                if(isInGraphicRegion(NormInput(i,j), NormOutput(i,j)))
                    glVertex2f(NormInput(i,j), NormOutput(i,j));
            }
    glEnd();

    this->DrawAxis(ZeroXFunction, ZeroYFunction);
}

void grafics::DrawFunction()
{
    GenerateDataFunction();
    DrawGraphic();
}

void grafics::DrawGrid()
{
    double GridXDistance = (abs(this->GraphicXLimit_Rigth - this->GraphicXLimit_Left)/abs(this->GraphicXLimit_Rigth));
    double GridYDistance = (abs(this->GraphicYLimit_Up    - this->GraphicYLimit_Down)/abs(this->GraphicYLimit_Up));

    glPointSize(1.0);
    glBegin(GL_POINTS);
        for (double i = this->GraphicXLimit_Left; i <= this->GraphicXLimit_Rigth; i += GridXDistance)
            for (double j = this->GraphicYLimit_Down; j <= this->GraphicYLimit_Up ; j += GridYDistance)
                glVertex2f(i, j);
    glEnd();
    glPointSize(3.0);
}

void grafics::display()
{
    this->clearDraw();
    if((this->FunctionToCall == NULL))
        this->DrawGraphic();
    else
        this->DrawFunction();

    this->DrawGrid();

    glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
    glutSwapBuffers();      //swaps the front and back buffers
}

void grafics::MouseClickProcess(int button, int state, int x, int y)
{
    double XDistance = (this->GraphicXLimit_Rigth - this->GraphicXLimit_Left)/2;
    double YDistance = (this->GraphicYLimit_Up    - this->GraphicYLimit_Down)/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

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
    double XDistance = (this->GraphicXLimit_Rigth - this->GraphicXLimit_Left)/2;
    double YDistance = (this->GraphicYLimit_Up    - this->GraphicYLimit_Down)/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

    this->GraphicXposition += (this->LastMotionXPosition - a)/XDistance;
    this->GraphicYposition += (this->LastMotionYPosition - b)/YDistance;
    this->MotionOcurrency = true;
}

void grafics::PassiveMotionFunc(int x, int y)
{
    double XDistance = (this->GraphicXLimit_Rigth - this->GraphicXLimit_Left)/2;
    double YDistance = (this->GraphicYLimit_Up    - this->GraphicYLimit_Down)/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

    this->LastMotionXPosition = a;
    this->LastMotionYPosition = b;

//    double a = (x/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*40;
//    double b = (y/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*40;
//    this->LastMotionXPosition = a;
//    this->LastMotionYPosition = b;
}
