#include<iostream>
#include<GL/glut.h>

using namespace std;

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
}

void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void circlePts(int x,int y, int xc,int yc)
{
    setPixel(x+xc,y+yc);
    setPixel(-x+xc,y+yc);
    setPixel(-x+xc,-y+yc);
    setPixel(x+xc,-y+yc);

    setPixel(y+xc,x+yc);
    setPixel(-y+xc,x+yc);
    setPixel(-y+xc,-x+yc);
    setPixel(y+xc,-x+yc);
}

void circle(int r,int xc,int yc)
{
    float d=1.25-r;
    int x=0,y=r;
    circlePts(x,y,xc,yc);

    while(x<=y)
    {
        if(d<0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=2*x-2*y+5;
            y--;
        }
        x++;
        circlePts(x,y,xc,yc);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    circle(50,0,0);
    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(&display);
    glutMainLoop();
}
