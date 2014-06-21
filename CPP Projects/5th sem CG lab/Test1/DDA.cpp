#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0,200.0,-500.0,500.0);
}

void setpixel(int x, int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
    glFlush();
}
void DDA(int x1,int y1,int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    int xinc, yinc, x, y;
    int steps=0;
    int length;
    x = x1;
    y = y1;
    if(abs(dy)>abs(dx))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }
    xinc = dx/length;
    yinc = dy/length;
    while(steps<=length)
    {
        setpixel(x,y);
        x = x+xinc;
        y = y+yinc;
        steps++;
    }
}
void disp1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    DDA(00,200,200,200);
    glFlush();
}

int main(int argc,char * argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("DDA Algorithm");
    init();
    glutDisplayFunc(&disp1);
    glutMainLoop();
}

