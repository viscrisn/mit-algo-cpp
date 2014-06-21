#include<iostream>
#include<GL/glut.h>

using namespace std;

int xmin=40,ymin=40,xmax=200,ymax=200;//Clip rectangle coordinates
int x1,x2,y1,y2;

void myInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0,400);
	}
		
void writePixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	}
	
void line(int x1,int y1,int x2,int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
	glFlush();
	}

bool ClipTest(float p,float q, float &u1,float &u2)
{float r;

if(p<0)
{r=q/p;
	if(r>u2) return false;
	else 	if(r>u1)u1=r;
}
	if(p>0)
	{
		r=q/p;
		if(r<u1)return false;
		else if(r<u2)u2=r;
		}

return true;
}


void LBClip(int x1,int y1,int x2,int y2)
{int p1,p2,p3,p4,q1,q2,q3,q4;
p1=x1-x2;
p2=x2-x1;
p3=y1-y2;
p4=y2-y1;

q1=x1-xmin;
q2=xmax-x1;
q3=y1-ymin;
q4=ymax-y1;

float u1=0,u2=1;
if(ClipTest(p1,q1,u1,u2))
	if(ClipTest(p2,q2,u1,u2))
		if(ClipTest(p3,q3,u1,u2))
			if(ClipTest(p4,q4,u1,u2))
			{}
			x1=x1+u1*p2;
			y1=y1+u1*p4;
			x2=x1+u2*p2;
			y2=x1+u2*p4;
			
							line(x1,y1,x2,y2);


	}
	
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	glFlush();
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

void myKeyboard(unsigned char key,int x,int y)
{cout<<"Inside MyKeyboard";
	glClear(GL_COLOR_BUFFER_BIT);
	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	if(key=='c')
		LBClip(x1,x2,y1,y2);
	}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Liang-Barsky Clipping");
	myInit();
	glutDisplayFunc(&display);
	glutKeyboardFunc(&myKeyboard);
	glutMainLoop();
	return 0;
}

