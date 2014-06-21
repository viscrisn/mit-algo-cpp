#include <iostream>
#include <GL/glut.h>
//#include <math.h>

using namespace std;

int xmin=40,ymin=40,xmax=200,ymax=200;//Clip rectangle coordinates
int x1,x2,y1,y2;

float fabs(float x)
{
 	  if (x<0) return -x; 
	  return x;
	  }

void myInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0,400);
	}

void writePixel(int x,int y)
{
     glBegin(GL_POINTS);
     glVertex2i(x,y);
     glEnd();     
     //glFlush();
     }

void line(int x1,int y1,int x2,int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
	glFlush();
	}
	
void dda(float x1,float y1,float x2,float y2)
{
		float dy=y2-y1;
		float dx=x2-x1;
		float len;
		
		if(fabs(dy)>fabs(dx)) len=fabs(dy);
		else len=fabs(dx);
		
		float xi=dx/len;
		float yi=dy/len;
		float x=x1, y=y1;
		
		if(xmin<=x && x<=xmax && ymin<=y && y<=ymax)
		writePixel(x,y);
		
		for(int i=0;i<len;i++)
		{
			x=x+xi;
			y=y+yi;
			
			if(xmin<=x && x<=xmax && ymin<=y && y<=ymax)
			writePixel(int(x), int(y));
		
		}	glFlush();

}
	  	  
void myKeyboard(unsigned char key,int x,int y)
{cout<<"Inside MyKeyboard";
	glClear(GL_COLOR_BUFFER_BIT);
	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	if(key=='c')
		dda(x1,y1,x2,y2);
	}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	//glFlush();
	cout<<"Enter coordinates of the line:\nx1:";

	cin>>x1;
	cout<<"y1:";
	cin>>y1;
	cout<<"x2:";
	cin>>x2;
	cout<<"y2:";
	cin>>y2;
	line(x1,y1,x2,y2);
	
	}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("My Clipping Algorithm");
	myInit();
	glutDisplayFunc(&display);
	glutKeyboardFunc(&myKeyboard);
	glutMainLoop();
	return 0;
}
