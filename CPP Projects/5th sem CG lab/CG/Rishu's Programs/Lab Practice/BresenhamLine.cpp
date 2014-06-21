#include<iostream>
#include<GL/glut.h>

using namespace std;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);
    glClearColor(1,1,0,0);
}

void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void bham()
{
    int x1,y1,x2,y2;
    cout<<"Enter the coordinates ";
    cin>>x1>>y1>>x2>>y2;

    int x=x1,y=y1;
    float d;
    setPixel(x,y);

    float m=float(y2-y1)/(x2-x1);
    float dx=x2-x1;
    float dy=y2-y1;
    cout<<"M: "<<m;

    if(m>0&&m<1)
    {
        d=2*dy-dx;
        while(x<=x2)
        {
            setPixel(x,y);
            if(d>0)
            {d=d+2*dy-2*dx;y++;}
            else
            d=d+2*dy;
            x++;
        }
    }
    else if(m>1)
    {
        d=2*dx-dy;
        while(y<=y2)
        {
            setPixel(x,y);
            if(d>0)
            {d=d+2*dx-2*dy;x++;}
            else
            d=d+2*dx;
            y++;
        }
    }
    else if(m<0 && m>-1)
    {
        d=-2*dy-dx;
        while(x<=x2)
        {
            setPixel(x,y);
            if(d>0)
            {d=d-2*dy-2*dx;y--;}
            else
            d=d-2*dy;
            x++;
        }
    }
    else if(m<-1)
    {
        d=2*dx+dy;
        while(y>=y2)
        {
            setPixel(x,y);
            if(d>0)
            {d=d+2*dx+2*dy;x++;}
            else
            d=d+2*dx;
            y--;
        }
    }
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    bham();
    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,400);
    glutCreateWindow("Bresenham Line");
    init();

    glutDisplayFunc(&display);

    glutMainLoop();
    return 0;
}
