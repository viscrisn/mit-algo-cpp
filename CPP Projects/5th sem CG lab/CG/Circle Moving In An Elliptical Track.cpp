#include<iostream>
#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include <unistd.h>
using namespace std;

int a,b,c,d,e,f,cp,r;
float arr[10000][2];
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600.0,800.0,-600.0,800.0);
}

void setPixel(int x, int y)
{ glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2f(x,y);
  glEnd();
}

void circlePoints(float x,float y,float x1,float y1)
{
    setPixel(x+x1,y+y1);
    setPixel(-x+x1,-y+y1);
    setPixel(-x+x1,y+y1);
    setPixel(x+x1,-y+y1);
    setPixel(y+x1,x+y1);
    setPixel(-y+x1,-x+y1);
    setPixel(-y+x1,x+y1);
    setPixel(y+x1,-x+y1);
}

void circle(int r,float x1,float y1)
{
	float x,y;
	x=0;
	y=r;
	double d=1.25-r;
	circlePoints(x,y,x1,y1);
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
		circlePoints(x,y,x1,y1);
	}
}

void ellipsePoints(int x,int y)
{
	setPixel(x,y);
	setPixel(x,-y);
	setPixel(-x,-y);
	setPixel(-x,y);

}

void ellipse(int a,int b,int flag)
{
	double d1,d2;
	int x,y;
	x=0;
	y=b;
	d1=b*b-a*a*b+0.25*a*a;
	if(flag==0)
        ellipsePoints(x,y);
    else
    {
        arr[cp][0]=x;
        arr[cp][1]=y;
        cp++;
    }
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
		if(flag==0)
            ellipsePoints(x,y);
        else
        {
            arr[cp][0]=x;
            arr[cp][1]=y;
            cp++;
        }
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
		if(flag==0)
            ellipsePoints(x,y);
        else
        {
            arr[cp][0]=x;
            arr[cp][1]=y;
            cp++;
        }
	}
}

void Ellipse_Display(void)
{
	int i=cp=0;
	glClear(GL_COLOR_BUFFER_BIT);
	ellipse(c,d,1);
	for(;;)
	{
	    glClear(GL_COLOR_BUFFER_BIT);
	    ellipse(a,b,0);
	    ellipse(e,f,0);
	    for(i=0;i<cp;i++)
	    {
	        glClear(GL_COLOR_BUFFER_BIT);
	        ellipse(a,b,0);
            ellipse(e,f,0);
	        circle(r,arr[i][0],arr[i][1]);
	        usleep(100);
	        glFlush();
	    }
	    for(i=cp-1;i>=0;i--)
	    {
	        glClear(GL_COLOR_BUFFER_BIT);
	        ellipse(a,b,0);
            ellipse(e,f,0);
	        circle(r,arr[i][0],-arr[i][1]);
	        usleep(100);
	        glFlush();
	    }
	    for(i=0;i<cp;i++)
	    {
	        glClear(GL_COLOR_BUFFER_BIT);
	        ellipse(a,b,0);
            ellipse(e,f,0);
	        circle(r,-arr[i][0],-arr[i][1]);
	        usleep(100);
	        glFlush();
	    }
	    for(i=cp-1;i>=0;i--)
	    {
	        glClear(GL_COLOR_BUFFER_BIT);
	        ellipse(a,b,0);
            ellipse(e,f,0);
	        circle(r,-arr[i][0],arr[i][1]);
	        usleep(100);
	        glFlush();
	    }
	}
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,500);
	a=50;
	b=100;
	c=100;
	d=200;
	e=150;
	f=250;
	r=20;
	glutCreateWindow("Ellipse");
	init();
	glutDisplayFunc(Ellipse_Display);
	glutMainLoop();
}
