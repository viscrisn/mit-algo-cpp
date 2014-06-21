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
	

void ellipsePts(int x,int y)
{
	writePixel(x,y);
	writePixel(x,-y);
	writePixel(-x,y);
	writePixel(-x,-y);
	}


void ellipse(int a,int b)
{
	double d1,d2;
	int x=0; int y=b;
	
	d1=b*b-a*a*b+0.25*a*a;
	
	ellipsePts(x,y);
	
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
	ellipsePts(x,y);
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
			ellipsePts(x,y);
 	}
 	
	}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int a,b;
	cout<<"Enter major axis length";
	cin>>a;
	cout<<"Enter minor axis length";
	cin>>b;
	
	ellipse(a,b);
	}
	
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Ellipse");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	}

