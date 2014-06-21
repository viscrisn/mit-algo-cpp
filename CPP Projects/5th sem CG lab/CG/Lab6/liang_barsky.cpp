#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float xmin=-40, ymin=40, xmax=100, ymax=150;
float a1=-60,b1=40,a2=140,b2=130;

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

bool clipTest(float p, float q, float *u1, float *u2)
{ 
	float r;
	bool returnval=true;
	if(p<0)
	{
		r=q/p;
		if(r>*u2)
			returnval=false;
		else if(r>*u1)
			*u1=r;
	}
	
	else if(p>0)
	{
		r=q/p;
		if(r<*u1)
			returnval=false;
		else if(r<*u2)
			*u2=r;
	}
	
	else if(q<0)
		returnval=false;
	
	return returnval;		
}

void clipLine(float x1, float y1, float x2, float y2)
{
	float u1=0, u2=1;
    float dx=x2-x1, dy=y2-y1;
    //float x,y,xc,yc;
    
	if(clipTest(-dx,(x1-xmin),&u1,&u2))
		if(clipTest(dx,(xmax-x1),&u1,&u2))
			if(clipTest(-dy,(y1-ymin),&u1,&u2))
				if(clipTest(dy,(ymax-y1),&u1,&u2))
				{
					/*x=x1+u1*dx;
					y=y1+u1*dy;
					xc=x1+u2*dx;
					yc=y1+u2*dy;*/
					if(u2<1)
					{
						x2=x1+u2*dx;
						y2=y1+u2*dy;
					}
					if(u1>0)
					{
						x1=x1+u1*dx;
						y1=y1+u1*dy;
					}
					
					lines(xmin,ymin,xmax,ymin);
					lines(xmax,ymin,xmax,ymax);
					lines(xmin,ymax,xmax,ymax);
					lines(xmin,ymin,xmin,ymax);
					lines(x1,y1,x2,y2);
				}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	lines(a1,b1,a2,b2);
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
		clipLine(a1,b1,a2,b2);
	}
	else
		cout<<"Invalid key pressed";
}

int main(int argc, char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(850,0);
	glutCreateWindow("Liang Barsky Clipping");
	myInit();
	
	glutDisplayFunc(&display);
	glutKeyboardFunc(myKey);
	glutMainLoop();
	return 0;
}
	
