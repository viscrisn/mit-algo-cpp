#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

int a,b;
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

void ellipsePoints(int x,int y,int x1,int y1)
{
	setPixel(x+x1,y+y1);
	setPixel(-x+x1,-y+y1);
	setPixel(-x+x1,y+y1);
	setPixel(x+x1,-y+y1);
}

void ellipse(int a,int b,int x1,int y1)
{
	double d1,d2;
	int x,y;
	x=0;
	y=b;
	d1=b*b-a*a*b+0.25*a*a;
	ellipsePoints(x,y,x1,y1);
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
		ellipsePoints(x,y,x1,y1);
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
		ellipsePoints(x,y,x1,y1);
	}
}

void Ellipse_Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	ellipse(a,b,100,100);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	cout<<"Enter a & b :- ";
	cin>>a>>b;
	glutCreateWindow("Ellipse");
	init();
	glutDisplayFunc(Ellipse_Display);
	glutMainLoop();
}
