#include <GL/glut.h>
#include <math.h>
#include <iostream>


void myInit()
{	glClearColor (0.1,0.1,0.1, 0.2);		//background color
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0,639,0,479);
}

void writepixel (double x, double y)
{	glBegin (GL_POINTS);
		glVertex2i (x,y);
	glEnd();
	glFlush();
}

void BLA (int x1, int y1, int x2, int y2)
{
  int x,y;
  int dn,dne,de,d;
  int dx,dy;

  x=x1;
  y=y1;

  dx=abs(x1-x2);
  dy=abs(y1-y2);
  if(dy>dx)
  {
  d=2*dx-dy;
  dn = 2*dx;
  dne= 2*(dx-dy);

  writepixel(x,y);

 while(y<y2)
 {   if(d<=0)
      { d=d+dn;
        y++;
      }
      else
      if(d>0)
      { d=d+dne;
        x++;
        y++;
      }
   writepixel(x,y);
  }
}


else
{
  d=2*dy-dx;
  de = 2*dy;
  dne= 2*(dy-dx);

  writepixel(x,y);

 while(x<x2)
 {   if(d<=0)
      { d=d+de;
        x++;
      }
      else
      if(d>0)
      { d=d+dne;
        x++;
        y++;
      }
   writepixel(x,y);
  }
}

}

void drawpattern()
{   int a=0;
	BLA(50,50,250,50);
	BLA(150,50,150,250);
	int x1=120,y1=50,x2=150,y2=80,i,j;
	for(i=x1,j=y2;j>=50;i--,j--)
	{	if(j>=0)
		{
		BLA(50,50,250,50);
		BLA(150,50,150,250);
		BLA(i,y1,x2,j);
		glClear (GL_COLOR_BUFFER_BIT);
		for(int m=0;m<=20000;m++)
			for(int n=0;n<20000;n++)
				a++;
		}
	}
}

void display()
{	glClear (GL_COLOR_BUFFER_BIT);
	drawpattern();
}

int main (int argc, char **argv)
{	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow ("Graphics");

	glutDisplayFunc (display);
	myInit();
	glutMainLoop();

	return 0;
}

