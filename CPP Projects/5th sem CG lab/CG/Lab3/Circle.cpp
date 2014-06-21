#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

int r,arc;
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

void Circle_Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	circle(r,arc);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	cout<<"Enter r :- ";
	cin>>r;
	cout<<"\n0) Full Circle\n1) 1st quadrant\n2) 2nd quadrant\n3) 3rd quadrant\n4) 4th quadrant\n5) 1st & 2nd quadrant\n6) 2nd & 3rd quadrant\n7) 3rd & 4th quadrant\n8) 4th & 1st quadrant\n";
	cout<<"In which quadrant do you want the arc :- ";
	cin>>arc;
	glutCreateWindow("Circle");
	init();
	glutDisplayFunc(Circle_Display);
	glutMainLoop();
}
