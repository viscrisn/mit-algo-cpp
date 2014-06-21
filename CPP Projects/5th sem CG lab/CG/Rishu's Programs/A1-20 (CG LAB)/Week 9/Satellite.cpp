//Satellite using 2D transformations
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
using namespace std;

struct Vertex
{
	float x,y;
	};
	Vertex sat,rect1[4],rect2[4],l1[2],l2[2];


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-320,320,-240,240);
}

void line(int x1,int y1,int x2,int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
}

void writePixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	//glFlush();
	}
void circlePts(int x,int y,int x_offset,int y_offset)
{
		writePixel(x+x_offset,y+y_offset);
		writePixel(x+x_offset,-y+y_offset);
		writePixel(-x+x_offset,-y+y_offset);
		writePixel(-x+x_offset,y+y_offset);
		
		writePixel(y+x_offset,x+y_offset);
		writePixel(y+x_offset,-x+y_offset);
		writePixel(-y+x_offset,-x+y_offset);
		writePixel(-y+x_offset,x+y_offset);
	}

void circle(int r, int x_offset,int y_offset)
{
	int x=0,y=r;
	int d=1-r;
	circlePts(x,y,x_offset,y_offset);
	
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
		circlePts(x,y,x_offset,y_offset);
		}
	}

void translate(int tx,int ty,Vertex * poly, int n)
{for(int i=0;i<n;i++)
	{
		poly[i].x+=tx;
		poly[i].y+=ty;
		}
}

void rotate(float angle, Vertex * poly, int n)
{	angle=angle*((float)3.1428/180);
float temp;
for(int i=0;i<n;i++)
	{temp=poly[i].x;
		poly[i].x=poly[i].x*cos(angle)-poly[i].y*sin(angle);
		poly[i].y=temp*sin(angle)+poly[i].y*cos(angle);
		}	
	}

void display()
{
glClearColor(1,1,1,1);
int i;
for(;;)
{i=0;
for( i=0;i<90;i++)
{usleep(500000);

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);

circle(100,0,0);

rotate(i,&sat,1);
circle(20,sat.x,sat.y);

rotate(i,l1,2);
line(l1[0].x,l1[0].y,l1[1].x,l1[1].y);

rotate(i,l2,2);
line(l2[0].x,l2[0].y,l2[1].x,l2[1].y);

rotate(i,rect1,4);
line(rect1[0].x,rect1[0].y,rect1[1].x,rect1[1].y);
line(rect1[1].x,rect1[1].y,rect1[2].x,rect1[2].y);
line(rect1[2].x,rect1[2].y,rect1[3].x,rect1[3].y);
line(rect1[3].x,rect1[3].y,rect1[0].x,rect1[0].y);

rotate(i,rect2,4);
line(rect2[0].x,rect2[0].y,rect2[1].x,rect2[1].y);
line(rect2[1].x,rect2[1].y,rect2[2].x,rect2[2].y);
line(rect2[2].x,rect2[2].y,rect2[3].x,rect2[3].y);
line(rect2[3].x,rect2[3].y,rect2[0].x,rect2[0].y);
glFlush();	
glColor3f(1.0,0.0,0.0);

	
}
}
}

int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("2D Transformations");
init();

sat.x=0;
sat.y=170;

l1[0].x=0;
l1[0].y=200;
l1[1].x=0;
l1[1].y=190;

l2[0].x=0;
l2[0].y=150;
l2[1].x=0;
l2[1].y=140;

rect1[0].x=-20;
rect1[0].y=130;
rect1[1].x=20;
rect1[1].y=130;
rect1[2].x=20;
rect1[2].y=140;
rect1[3].x=-20;
rect1[3].y=140;

rect2[0].x=-20;
rect2[0].y=200;
rect2[1].x=20;
rect2[1].y=200;
rect2[2].x=20;
rect2[2].y=210;
rect2[3].x=-20;
rect2[3].y=210;

glutDisplayFunc(&display);

glutMainLoop();
return 0;
}
