#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <unistd.h>
using namespace std;

int ss,ab,ang;

struct vertices
{
    float x,y;
}s[4],a[4],b[4];

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0,600.0,-600.0,600.0);
}

void setPixel(int x, int y)
{ glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2f(x,y);
  glEnd();
}

vertices translate(vertices t,int tx,int ty)
{
    t.x+=tx;
    t.y+=ty;
    return t;
}

vertices rotate(vertices t,float radian)
{
    int tmp=t.x;
    t.x=t.x*cos(radian)-t.y*sin(radian);
    t.y=tmp*sin(radian)+t.y*cos(radian);
    return t;
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<4;i++)
        {
            glVertex2f(s[i].x,s[i].y);
        }
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<4;i++)
        {
            glVertex2f(a[i].x,a[i].y);
        }
    glEnd();
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<4;i++)
        {
            glVertex2f(b[i].x,b[i].y);
        }
    glEnd();
    glFlush();
}

void move()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(int tr=0;tr<ss;tr+=25)
    {
        for(int i=0;i<4;i++)
        {
            a[i]=translate(a[i],0,25);
            b[i]=translate(b[i],25,0);
        }


        for(int i=0;i<4;i++)
        {
            a[i]=translate(a[i],0,-tr);
            a[i]=rotate(a[i],ang*3.14/180);
            a[i]=translate(a[i],0,tr);
        }
        for(int i=0;i<4;i++)
        {
            b[i]=translate(b[i],-tr,0);
            b[i]=rotate(b[i],ang*3.14/180);
            b[i]=translate(b[i],tr,0);
        }
        glClear(GL_COLOR_BUFFER_BIT);
        usleep(100000);
        Display();
    }
    for(int tr=0;tr<ss;tr+=25)
    {
        for(int i=0;i<4;i++)
        {
            a[i]=translate(a[i],25,0);
            b[i]=translate(b[i],0,25);
        }
        for(int i=0;i<4;i++)
        {
            a[i]=translate(a[i],-tr,-ss);
            a[i]=rotate(a[i],ang*3.14/180);
            a[i]=translate(a[i],tr,ss);
        }
        for(int i=0;i<4;i++)
        {
            b[i]=translate(b[i],-ss,-tr);
            b[i]=rotate(b[i],ang*3.14/180);
            b[i]=translate(b[i],ss,tr);
        }
        glClear(GL_COLOR_BUFFER_BIT);
        usleep(100000);
        Display();
    }
}

void display()
{
    Display();
    usleep(500);
    move();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	glutCreateWindow("SQUARE");
	ss=500;
	ab=50;
	ang=2;
	s[0].x=s[0].y=s[1].x=s[3].y=ab/2;
	s[1].y=s[2].x=s[2].y=s[3].x=ss+ab/2;
	a[0].x=a[0].y=a[1].x=a[3].y=ab/2;
	a[1].y=a[2].x=a[2].y=a[3].x=-ab/2;
	b[0].x=b[0].y=b[1].x=b[3].y=ab/2;
	b[1].y=b[2].x=b[2].y=b[3].x=-ab/2;
	init();
	glutDisplayFunc(&display);
	glutMainLoop();
}
