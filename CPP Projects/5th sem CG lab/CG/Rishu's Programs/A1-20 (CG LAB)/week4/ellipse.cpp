#inlcude<GL/glut.h>
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

void ellipsePts(int x,int y)
{
	writePixel(x,y);
	writePixel(x,-y);
	writePixel(-x,y);
	writePixel(-x,-y);
	}

void ellipse(int a,int b)
{
	int x=0,y=b,d1,d2;
	int d1=b*b+a*a(.25-b);
	ellipsePts(x,y);
	
	while(a*a*y<b*b*x)
	{
		if(d1<0)
			{
				d1+=b*b(2*x+3);
				x++;
				}
		else
			{
				d1+=b*b*(2*x+3)+a*a(-2*y+2);
				x++;
				y--;
				}
		ellipsePts(x,y);
			}
	}
	
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	int a,b;
	cout<<"Enter major axis length";
	cin>>a;
	cout<<"Enter minor axis length";
	cin>>b;
	
	ellipse(a,b);
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
