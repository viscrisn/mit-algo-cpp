#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
GLdouble xmin=2, ymin=1, xmax=55, ymax=95;
//double a1=-40, b1=-10, a2=90, b2=100;
double c1=10, d1=10, c2=20, d2=20;

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
}

void lines(float x1,float y1,float x2,float y2)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	glFlush();
}

int code(double x, double y)
{
	int c=0;
	if(y>ymax)
		c=c|8;
	else if(y<ymin)
		c=c|4;
	if(x>xmax)
		c=c|2;
	else if(x<xmin)
		c=c|1;
   return c;
}

void cohens(double x1, double y1, double x2, double y2)
{
		int c1= code(x1,y1);
		int c;
		double x,y;
		int c2= code(x2,y2);
		double m= (y2-y1)/(x2-x1);
		
		while((c1|c2)>0)
		{
			if((c1&c2)>0)
			{
			 cout<<"\nLine is completely outside the clip rectangle...";
			 break;
			}
			
			c=c1;
			if(c1==0)
			c=c2;
			
			if((c&8)>0)
			{
				y=ymax;
				x=x1+(1/m)*(ymax-y1);
			}
			
			
			 if((c&4)>0)
			{
				y=ymin;
				x=x1+(1/m)*(ymin-y);
			}
			
			 if((c&2)>0)
			{
				x=xmax;
				y=y1+m*(xmax-x1);
			}
			
			 if((c&1)>0)
			{
				x=xmin;
				y=y1+m*(xmin-x1);
			}
			
			if(c==c1)
			{
				x1=x;
				y1=y;
				c1=code(x1,y1);
			}
			
			if(c==c2)
			{
				x2=x;
				y2=y;
				c2=code(x2,y2);
		    }
       }
      
    glClear(GL_COLOR_BUFFER_BIT);
    lines(xmin,ymin,xmax,ymin);
	lines(xmax,ymin,xmax,ymax);
	lines(xmin,ymax,xmax,ymax);
	lines(xmin,ymin,xmin,ymax);
    lines(x1,y1,x2,y2);
   
}
	

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	lines(c1,d1,c2,d2);
	//lines(a1,b1,a2,b2);
	lines(xmin,ymin,xmax,ymin);
	lines(xmax,ymin,xmax,ymax);
	lines(xmin,ymax,xmax,ymax);
	lines(xmin,ymin,xmin,ymax);
}

void myKey(unsigned char key, int x, int y)
{
	if(key=='c')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		cohens(c1,d1,c2,d2);
		//cohens(a1,b1,a2,b2);
	}
	else
		cout<<"\nInvalid key pressed";
}
	
	
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,380);
	glutCreateWindow("Cohen-Sutherland Clipping");
	myInit();
	
	glutDisplayFunc(&display);
	glutKeyboardFunc(myKey);
	glutMainLoop();
	return 0;
}
