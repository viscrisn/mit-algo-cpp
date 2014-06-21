#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
using namespace std;

struct Vertex
{
    float x,y;
};
Vertex c1,c2,sp1[2],sp2[2],sp3[2],sp4[2];
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400,400,-200,200);
}

void rotate(float angle,Vertex *poly,int n)
{
    angle=angle*(22.0/7.0)/180.0;
    for(int i=0;i<n;i++)
    {
        float temp=poly[i].x;
        poly[i].x=temp*cos(angle)-poly[i].y*sin(angle);
        poly[i].y=temp*sin(angle)+poly[i].y*cos(angle);
    }
}

void translate(int tx,int ty,Vertex *poly,int n)
{
    for(int i=0;i<n;i++)
    {
        poly[i].x+=tx;
        poly[i].y+=ty;
    }
}
void setPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void line(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}

void circlePts(int x,int y,int xc,int yc)
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
    setPixel(x,y);

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
    while(c2.x-c1.x>0)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,0);
        circle(50,c1.x,c1.y);
        circle(50,c2.x,c2.y);
        line(-150,-51,150,-51);//base

        line(sp1[0].x,sp1[0].y,sp1[1].x,sp1[1].y);//spokes
        line(sp2[0].x,sp2[0].y,sp2[1].x,sp2[1].y);
        line(sp3[0].x,sp3[0].y,sp3[1].x,sp3[1].y);
        line(sp4[0].x,sp4[0].y,sp4[1].x,sp4[1].y);
        glFlush();

        translate(-c1.x,-c1.y,sp1,2);
        rotate(1,sp1,2);
        translate(c1.x,c1.y,sp1,2);
        translate(-c1.x,-c1.y,sp2,2);
        rotate(1,sp2,2);
        translate(c1.x,c1.y,sp2,2);
        translate(-c2.x,-c2.y,sp3,2);
        rotate(1,sp3,2);
        translate(c2.x,c2.y,sp3,2);
        translate(-c2.x,-c2.y,sp4,2);
        rotate(1,sp4,2);
        translate(c2.x,c2.y,sp4,2);

    }
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='s')
    {
        display();
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,400);
    glutCreateWindow("Wheels");
    init();
    c1.x=-100;
    c1.y=0;

    c2.x=100;
    c2.y=0;

    sp1[0].x=-100;
    sp1[0].y=50;
    sp1[1].x=-100;
    sp1[1].y=-50;
    sp2[0].x=-150;
    sp2[0].y=0;
    sp2[1].x=-50;
    sp2[1].y=0;

    sp3[0].x=100;
    sp3[0].y=50;
    sp3[1].x=100;
    sp3[1].y=-50;
    sp4[0].x=150;
    sp4[0].y=0;
    sp4[1].x=50;
    sp4[1].y=0;

    //glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
}
