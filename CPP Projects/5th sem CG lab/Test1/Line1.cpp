#include<iostream>
#include<GL/glut.h>

void init()
{
    glClearColor(0.0,0.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(100);
    glBegin(GL_LINES);
        glVertex2i(0,0);
        glVertex2i(500,500);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glLineWidth(10);
    glBegin(GL_POLYGON);
        glVertex2i(200,0);
        glVertex2i(0,200);
        glVertex2i(0,0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(800,600);
    glutCreateWindow("An example openGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
