#include<iostream>
#include<GL/glut.h>

using namespace std;

double xmin=40,ymin=40,xmax=200,ymax=200;//Clip rectangle coordinates
double x1,x2,y1,y2;

void myInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0,400);
	}
		

void line(double x1,double y1,double x2,double y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
	glFlush();
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

int code(double x,double y)
{
int c=0;
if(y>ymax)
c=8;
else if(y<ymin)
c=4;
if(x>xmax)
c=c|2;
else if(x<xmin)
c=c|1;
return (c);
}	
	void CSClip(double x1,double y1,double x2,double y2)
{double c;double m=(y2-y1)/(x2-x1);double x,y;
int c1=code(x1,y1);
int c2=code(x2,y2);
while((c1|c2)>0)
{
if((c1&c2)>0)
break;
c=c1;
if(c1==0)
c=c2;
if(((int)c&2)>0)
{
y=ymax;;
x=x1+(1/m)*(ymax-y1);
}
else if(((int)c&4)>0)
{
y=ymin;
x=x1+(1/m)*(ymin-y);
}
else if(((int)c&2)>0)
{
x=xmax;
y=y1+m*(xmax-x1);
}
else if(((int)c&1)>0)
{
	x=xmin;
	y=y1+m*(xmin-x1);
}
if(c==c1)
{
	x1=x;y1=y;
	c1=code(x1,y1);
}
if(c==c2)
{
	x2=x;y2=y;
	c2=code(x2,y2);
}
}
//end of while
cout<<x1;
cout<<y1;
cout<<x2;
cout<<y2;
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
		CSClip(x1,x2,y1,y2);
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
