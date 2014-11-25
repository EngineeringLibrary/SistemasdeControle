#include "glview.h"

GlView *GlView::instance = 0;
void GlView::setInstance(GlView *Img)
{
    instance = Img;
}

//void GlView::init()
//{
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}

void GlView::startFramework(int argv, char *argc[])
{
    // Initialize GLUT
    glutInit(&argv, argc);                                   	//initializes the GLUT framework
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   //sets up the display mode
    glutCreateWindow("Tituto do grafico");

    glutDisplayFunc(displayWrapper);
    glutMouseFunc(MouseFuncWrapper);
    glutMotionFunc(MotionFuncWrapper);
    glutPassiveMotionFunc(PassiveMotionFuncWrapper);

    glMatrixMode(GL_PROJECTION);   //changes the current matrix to the projection matrix

    //sets up the projection matrix for a perspective transform
    gluPerspective(45, 	//view angle
                1.0,    //aspect ratio
                10.0,   //near clip
                200.0); //far clip

    glMatrixMode(GL_MODELVIEW);   //changes the current matrix to the modelview matrix

    glutMainLoop();				// Start the main GLUT thread
}

void GlView::displayWrapper(void)
{
    instance->display(); // calls display(float) with time delta
}

void GlView::MouseFuncWrapper(int button, int state, int x, int y)
{
    instance->MouseClickProcess(button, state, x, y);
}

void GlView::MotionFuncWrapper(int x, int y)
{
    instance->MotionFunc(x,y);
}
void GlView::PassiveMotionFuncWrapper(int x, int y)
{
    instance->PassiveMotionFunc(x,y);
}

//void GlView::runWrapper() {
//    instance->run();
//}
//void GlView::keyboardWrapper(unsigned char key, int x, int y) {
//    instance->keyboard(key,x,y);
//}
//void GlView::keyboardUpWrapper(unsigned char key, int x, int y) {
//    instance->keyboardUp(key,x,y);
//}
//void GlView::specialKeyboardWrapper(int key, int x, int y) {
//    instance->specialKeyboard(key,x,y);
//}
//void GlView::specialKeyboardUpWrapper(int key, int x, int y) {
//    instance->specialKeyboardUp(key,x,y);
//}
