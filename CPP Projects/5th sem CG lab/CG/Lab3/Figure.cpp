#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;


void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0,600.0,-500.0,500.0);
}


void setPixel(int x, int y)
{ glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

void circlePoints(int x,int y,int arc)
{
	if(arc==0)
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
	else if(arc==1)
	{	
		setPixel(x,y);
		setPixel(y,x);
	}
	else if(arc==2)
	{	
		setPixel(x,-y);
		setPixel(y,-x);
	}
	else if(arc==3)
	{	
		setPixel(-x,-y);
		setPixel(-y,-x);
	}
	else if(arc==4)
	{	
		setPixel(-x,y);
		setPixel(-y,x);
	}
	else if(arc==5)
	{	
		setPixel(x,y);
		setPixel(y,x);
		setPixel(x,-y);
		setPixel(y,-x);
	}
	else if(arc==6)
	{	
		setPixel(x,-y);
		setPixel(y,-x);
		setPixel(-x,-y);
		setPixel(-y,-x);
	}
	else if(arc==7)
	{	
		setPixel(-x,-y);
		setPixel(-y,-x);
		setPixel(-x,y);
		setPixel(-y,x);
	}
	else
	{	
		setPixel(-x,y);
		setPixel(-y,x);
		setPixel(x,y);
		setPixel(y,x);
	}
}

void circle(int r,int arc)
{
	int x,y;
	x=0;
	y=r;
	double d=1.25-r;
	circlePoints(x,y,arc);
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
		circlePoints(x,y,arc);
	}
}

void ellipsePoints(int x,int y,int x1,int y1,int arc=0)
{
	if(arc==0)
	{
		setPixel(x+x1,y+y1);
		setPixel(-x+x1,-y+y1);
		setPixel(-x+x1,y+y1);
		setPixel(x+x1,-y+y1);
	}
	else
	{
		setPixel(-x+x1,-y+y1);
		setPixel(x+x1,-y+y1);
	}
}

void ellipse(int a,int b,int x1,int y1,int arc=0)
{
	double d1,d2;
	int x,y;
	x=0;
	y=b;
	d1=b*b-a*a*b+0.25*a*a;
	ellipsePoints(x,y,x1,y1,arc);
	while(a*a*(y-0.5)>b*b*(x+1))
	{
		if(d1<0)
			d1+=b*b*(2*x+3);
		else
		{
			d1+=b*b*(2*x+3)+a*a*(-2*y+2);
			y--;
		}
		x++;
		ellipsePoints(x,y,x1,y1,arc);
	}
	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
	while(y>0)
	{
		if(d2<0)
		{
			d2+=b*b*(2*x+2)+a*a*(-2*y+3);
			x++;
		}
		else
			d2+=a*a*(-2*y+3);
		y--;
		ellipsePoints(x,y,x1,y1,arc);
	}
}

void lines()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-150,-200);
	glVertex2i(150,-200);
	
	glVertex2i(150,-200);
	glVertex2i(200,-350);
	
	glVertex2i(200,-350);
	glVertex2i(-200,-350);
	
	glVertex2i(-200,-350);
	glVertex2i(-150,-200);
	
	glVertex2i(70,-350);
	glVertex2i(70,-400);
	
	glVertex2i(70,-400);
	glVertex2i(50,-400);
	
	glVertex2i(50,-400);
	glVertex2i(50,-350);
	
	glVertex2i(-70,-350);
	glVertex2i(-70,-400);
	
	glVertex2i(-70,-400);
	glVertex2i(-50,-400);
	
	glVertex2i(-50,-400);
	glVertex2i(-50,-350);
	
	glVertex2i(50,-140);
	glVertex2i(50,-200);
	
	glVertex2i(-50,-140);
	glVertex2i(-50,-200);
	
	glVertex2i(10,10);
	glVertex2i(-10,-20);
	
	glVertex2i(-10,-20);
	glVertex2i(20,-20);
	glEnd();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	circle(150,0);
	ellipse(30,15,-50,50);
	ellipse(30,15,50,50);
	ellipse(30,15,0,-80,1);
	lines();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	glutCreateWindow("Man");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
}
