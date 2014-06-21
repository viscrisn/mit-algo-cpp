#include<GL/glut.h>
#include<iostream>
#include<unistd.h>

using namespace std;

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
	}

void writePixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	}
	

void ellipsePts(int x,int y, int x_offset,int y_offset)
{
	writePixel(x+x_offset,y+y_offset);
	writePixel(x+x_offset,-y+y_offset);
	writePixel(-x+x_offset,y+y_offset);
	writePixel(-x+x_offset,-y+y_offset);
	}


void ellipse(int a,int b, int x_offset,int y_offset)
{
	double d1,d2;
	int x=0; int y=b;
	
	d1=b*b-a*a*b+0.25*a*a;
	
	ellipsePts(x,y,x_offset,y_offset);
	
	while((a*a*(y-0.5))>(b*b*(x+1)))
	{
		if(d1<0)
		{
			d1+= b*b*(2*x+3);
		}	
		else
		{
			d1+=(b*b*(2*x+3)+a*a*(-2*y+2));
			y--;
		}	

	x++;	
	ellipsePts(x,y,x_offset,y_offset);
	}	

	d2=(b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b);
	
	while(y>0)
	{
		if(d2<0)
		{
			d2+=b*b*2*(x+1)+a*a*(-2*y+3);
			x++;
		}
		else
		{	
			d2+=a*a*(-2*y+3);
		}
		
			y--;
			ellipsePts(x,y,x_offset,y_offset);
 	}
 	
	}
	
void circlePts(int x,int y)
{
		writePixel(x,y);
		writePixel(x,-y);
		writePixel(-x,-y);
		writePixel(-x,y);
		
		writePixel(y,x);
		writePixel(y,-x);
		writePixel(-y,-x);
		writePixel(-y,x);
	}

void circle(int r)
{
	int x=0,y=r;
	int d=1-r;
	circlePts(x,y);
	
	while(y>x)
	{
		if(d<0)
		{
			d=d+2*x+3;
			x++;
			}
		else
		{
			d=d+2*x-2*y+5;
			x++;
			y--;
			}
		circlePts(x,y);
		}
	}

void face()
{circle(130);
ellipse(30,20,35,23);
ellipse(30,20,-35,23);
ellipse(40,20,0,-47);

while(1){
	glColor3f(0,0,0);
	ellipse(15,15,30,23);
	ellipse(15,15,-40,23);
	
	glColor3f(1,1,1);
ellipse(15,15,40,23);
ellipse(15,15,-30,23);
usleep(200000);
glColor3f(0,0,0);
ellipse(15,15,40,23);
ellipse(15,15,-30,23);

	glColor3f(1,1,1);
	ellipse(15,15,30,23);
	ellipse(15,15,-40,23);
}
	}
	
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	face();
	}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple");
	myInit();
	glutDisplayFunc(&display);
	glutMainLoop();
	return 0;
	}
