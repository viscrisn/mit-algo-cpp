#include <GL/glut.h>
#include <math.h>
#include <iostream>

void init(void)
{
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-200,200,-200,200);
  glLoadIdentity();
  }
  
  void lineSegment(int x1,int x2,int y1,int y2)
  {	
	int x=x1,y=y1;
	int d1,d2,d;
	int dx,dy;
	
	float m;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(dx!=0)
	m=(float)dy/dx;
	
	if(m>0 && fabs(m)<1)
	{dx=x2-x1;
	dy=y2-y1;
	d2=2*dy-dx;
	d1=2*dy;
	}
	
	else
		if(m>0 && fabs(m)>1)
		{
	d=2*dx-dy;
	d1=2*dx;
	d2=2*(dx-dy);			
			}
			else
				if(m<0 && fabs(m)<1 )
				{d=-2*dy-2*dx;
				d1=-2*dy;
				d2=-2*dy-2*dx;
					}
					else
						if(m<0 && fabs(m)>1)
							{
								d=2*dx+dy;
								d1=2*dx;
								d2=2*(dx+dy);
								}
								
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glLineWidth(5);
    glBegin(GL_POINTS);
    
    while(x<x2){
		if(d<=0){d=d+d1;x++;}
		
		else{d=d+d2;
		x++;y++;}
	glVertex2i(x,y);
		}
     
	glEnd();
    glFlush();
    }
    
    int main(int argc, char **argv)
    {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Implementing Bresanham's Line");
    init();
    //int x1,x2,y1,y2;
    lineSegment(0,0,50,50);
    glutMainLoop();
    return 0;
    }
