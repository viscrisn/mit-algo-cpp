#include<iostream>
#include<stdio.h>
#include<cmath>
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
{ glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}


void DDA(int x1,int y1,int x2,int y2)
{
	double dx,dy,steps,length;
	float xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-y1;
	steps=0;
	x=x1;y=y1;
	if(abs(dy)>abs(dx))
		length=abs(dy);
	else
		length=abs(dx);
	xinc=(float)dx/length;
	yinc=(float)dy/length;
	while(steps<length)
	{
		setPixel(round(x),round(y));
		x+=xinc;
		y+=yinc;
		steps++;
	}
}

void DDA_Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	DDA(p,q,r,s);
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
	glutCreateWindow("DDA Lines");
	init();
	glutDisplayFunc(DDA_Display);
	glutMainLoop();
}
