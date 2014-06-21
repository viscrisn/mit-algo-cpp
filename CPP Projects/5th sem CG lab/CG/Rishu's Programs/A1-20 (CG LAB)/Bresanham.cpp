#include <GL/glut.h>
#include <math.h>
#include <time.h>
void init(void)
{
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,150.0);
  }
  
  
void writepixel(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	
	glFlush();
}
  
  void lineSegment(int x1=0,int y1=0,int x2=80,int y2=80)
  {
  
	int x=x1,y=y1;
	int d1,d2,d;
	int dx,dy;
	
	dx=x2-x1;
	dy=y2-y1;
	d2=2*(dy-dx);
	d1=2*dy;
	d=2*dy-dx;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(5);
    
    while(x<x2){
		if(d<=0){d=d+d1;x++;}
		
		else{d=d+d2;
		x++;y++;}
		
	writepixel(x,y);
		}
     
   }
    
    int main(int argc, char **argv)
    {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("An example openGl program");
    init();
    //glutDisplayFunc(lineSegment);
	int x1=20,y1=0,x2=100,y2=80;
	
	while(y2>y1)
    {lineSegment(x1,y1,x2,y2);
    x1--;
    y2--;
    while(int i=0;i<9999;i++){}
    }
    
    glutMainLoop();
    return 0;
    }
