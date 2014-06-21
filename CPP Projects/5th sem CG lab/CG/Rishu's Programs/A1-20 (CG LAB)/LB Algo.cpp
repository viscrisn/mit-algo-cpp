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
		
		if(fabs(dy)>fabs(dx))
							 len=fabs(dy);
		else 
			 				 len=fabs(dx);
		
		float xi=dx/len;
		float yi=dy/len;
		float x=x1, y=y1;
		
		writePixel(x,y);
		
		for(int i=0;i<len;i++)
		{
			x=x+xi;
			y=y+yi;
			
			writePixel(int(x), int(y));
		
		}	glFlush();

}

int pos(int x1,int y1)
{int val=0;

	  
	  if(y2>ymax)	//Top
	  val+=8;
	  
	  if(y1<ymin)	//Bottom
	  val+=4;
	  	  
	  if(x2>xmax)	//Right
	  val+=2;
	  
	  if(x1<xmin)	//Left
	  val+=1;
	  
	  return val;
 	  }

void CH(int x1,int y1,int x2,int y2)
{
 int val1,val2,val;
 val1=pos(x1,y1);	 
 val2=pos(x2,y2);
	 float m=(y2-y1)/(x2-x1);
	 float c=y1-m*x1;
	 
	 if(val1>=8)//8,9,10 indicate top
	 {	y1=ymax;
	 	x1=(y1-c)/m;cout<<"\ny1 changed (top)";
	 }
	 
	 if(val2>=8)//top
	 {	y2=ymax;
	 	x2=(y2-c)/m;cout<<"\ny2 changed (top)";
	 }
	 
	 
	 if(val1 > 2 && val1 < 8)//4,5,6 => bottom; 3 and 7 are not possible
	 {	y1=ymin;
	 	x1=(y1-c)/m;cout<<"\ny1 changed (bottom)";
	 }

	 if(val2 > 2 && val2 < 8)//bottom
	 {	y2=ymin;
	 	x2=(y2-c)/m;cout<<"\ny2 changed (bottom)";
	 }
	 
	 if(val1 % 4 == 2)//2,6,10 => right
	 {	x1=xmax;
	 	y1=(y1*m-c);cout<<"\nx1 changed (right)";
	 }
	 
	 
	 if(val2 % 4 == 2)//right
	 {	x2=xmax;
	 	y2=(y2*m-c);cout<<"\nx2 changed (right)";
	 }		
	 
	 if(val1 % 4 == 1)//1,5,9 => left
	 {	x1=xmin;
	 	y1=(y1*m-c);cout<<"\nx1 changed (left)";
	 }
	 
	 
	 if(val2 % 4 == 1)//left
	 {	x2=xmin;
	 	y2=(y2*m-c);cout<<"\nx2 changed (left)";
	 }		
	 
 	 if((val1 & val2)!=0) {cout<<"Line outside clip rectangle!";}//return;}
 	 
 	 line(x1,y1,x2,y2);
 	 }

void myKeyboard(unsigned char key,int x,int y)
{cout<<"Inside MyKeyboard";
	glClear(GL_COLOR_BUFFER_BIT);
	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	if(key=='c')
		CH(x1,y1,x2,y2);
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
