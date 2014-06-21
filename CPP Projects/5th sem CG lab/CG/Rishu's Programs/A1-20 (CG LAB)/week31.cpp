#include <iostream>
#include <GL/glut.h>
#include <math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 700.00, 0.0, 700.00);
} 

void Bresenhamline(int x1, int y1, int x2, int y2)
{
	float dx=x2-x1;
	float dy=y2-y1;
	float m=dy/dx;
	int x=x1;
	int y=y1;
	int inc1, inc2, d;
	
	if(m>0 && m<1)
	{
		inc1=2*dy;
		inc2=2*(dx-dy);
		d=2*dy-dx;
		glVertex2i(x,y);
		while(x<x2)
		{
			if(d<=0)
			{
				d=d+inc1;
				x++;
			}
			else
			{
				d+=inc2;
				x++;
				y++;
			}
		glVertex2i(x,y);
		}
	}
	if(m>1)
	{
		inc1=2*dx;
		inc2=2*(dx-dy);
		d=2*dx-dy;
		glVertex2i(x,y);
		while(y<y2)
		{
			if(d<=0)
			{
				d=d+inc1;
				y++;
			}
			else
			{
				d=d+inc2;
				x++;
				y++;
			}
		glVertex2i(x,y);
		}
	}
	
	if(m<0 && abs(m)>1)
	{
		inc1=2*dx;
		inc2=2*(dx+dy);
		d=2*dx + dy;
		glVertex2i(x,y);
		while(y2<y)
		{
			if(d<=0)
			{
				d+=inc1;
				y--;
			}
			else
			{
				d+=inc2;
				x++;
				y--;
			}
			glVertex2i(x,y);
		}
	}
	
	if(m<0 && abs(m)<1)
	{
		inc1=-2*dy;
		inc2=-2*(dy+dx);
		d=(-(2*dy+dx));
		glVertex2i(x,y);
		while(x<x2)
		{
			if(d<=0)
			{
				d=d+inc1;
				x++;
			}
			else
			{
				d=d+inc2;
				x++;
				y--;
			}
			glVertex2i(x,y);
		}
	}
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_POINTS);
	Bresenhamline(350,350,650,300);	//m<0&&abs(m)<1
	Bresenhamline(350,350,500,650);	//m>1
	Bresenhamline(200,650,350,350);	//m<0&&abs(m)>1
	Bresenhamline(350,350,650,550);	//m>0 && m<1
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 1;
}
