#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

int p,q,r,s;
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,350.0,0.0,250.0);
}

void setPixel(int x, int y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


void BresL1(int x1,int y1,int x2,int y2)
{
    int dx,dy,ince,incne,x,y,d;
    dx=x2-x1;
    dy=y2-y1;
    ince=2*dy;
    incne=2*(dy-dx);
    d=2*dy-dx;
    x=x1;
    y=y1;
    setPixel(x,y);
    while(x<=x2)
    {
        if(d<=0)
        {
            d+=ince;
            x++;
        }
        else
        {
            d+=incne;
            x++;
            y++;
        }
        setPixel(x,y);
    }
    glFlush();
}

void BresG1(int x1,int y1,int x2,int y2)
{
    int dx,dy,incn,incne,x,y,d;
    dx=x2-x1;
    dy=y2-y1;
    incn=2*dx;
    incne=2*(dx-dy);
    d=2*dx-dy;
    x=x1;
    y=y1;
    setPixel(x,y);
    while(y<=y2)
    {
        if(d<=0)
        {
            d+=incn;
            y++;
        }
        else
        {
            d+=incne;
            x++;
            y++;
        }
        setPixel(x,y);
    }
    glFlush();
}


void Bres_Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    float m=(float)(s-q)/(float)(r-p);
    if(m<1)
        BresL1(p,q,r,s);
    else
        BresG1(p,q,r,s);
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,300);
    cout<<"Enter the 1st co-ordinates (x1,y1) :- ";
    cin>>p>>q;
    cout<<"Enter the 2nd co-ordinates (x2,y2) :- ";
    cin>>r>>s;
    glutCreateWindow("Bresenhan Lines");
    init();
    glutDisplayFunc(Bres_Display);
    glutMainLoop();
}
