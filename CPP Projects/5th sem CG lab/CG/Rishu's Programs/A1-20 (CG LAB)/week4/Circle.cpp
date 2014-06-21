#include<GL/glut.h>
#include<iostream>

using namespace std;
void myInit(void)
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
	
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<"Enter radius";
	int n;
	cin>>n;
	circle(n);
	glFlush();
	}
	
int main(int argc, char **argv)
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
