#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <unistd.h>
using namespace std;

int r,ang;

struct vertices
{
    float x,y;
}v[4];

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0,500.0,-600.0,500.0);
}

void setPixel(int x, int y)
{ glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2f(x,y);
  glEnd();
}

void lines()
{
    for(int i=0;i<4;i++)
    {
        glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(v[i].x,v[i].y);
        glEnd();
        glFlush();
    }
}

void base()
{
    glBegin(GL_LINES);
        glVertex2f(-100,-180);
        glVertex2f(-150,-500);
        glVertex2f(100,-180);
        glVertex2f(150,-500);
        glVertex2f(-150,-500);
        glVertex2f(150,-500);
    glEnd();
    glFlush();
}

vertices rotate(vertices t,float radian)
{
    float tmp=t.x;
    t.x=t.x*cos(radian)-t.y*sin(radian);
    t.y=t.x*sin(radian)+t.y*cos(radian);
    return t;
}

void circlePoints(float x,float y)
{
    setPixel(x,y);
    setPixel(-x,-y);
    setPixel(-x,y);
    setPixel(x,-y);
    setPixel(y,x);
    setPixel(-y,-x);
    setPixel(-y,x);
    setPixel(y,-x);
}

void circle(int r)
{
	float x,y;
	x=0;
	y=r;
	double d=1.25-r;
	circlePoints(x,y);
	while(y>x)
	{
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			y--;
		}
		x++;
		circlePoints(x,y);
	}
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    circle(r);
    lines();
    base();
    glFlush();
    usleep(100);
    for(;;)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        for(int i=0;i<4;i++)
        {
            v[i]=rotate(v[i],ang*3.14/180);
        }
        circle(r);
        lines();
        base();
        usleep(100);
        glFlush();
    }
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	glutCreateWindow("WindMill");
	r=200;
	ang=-10;
	v[0].x=0;
	v[0].y=r;
	v[1].x=r;
	v[1].y=0;
	v[2].x=0;
	v[2].y=-r;
	v[3].x=-r;
	v[3].y=0;
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
