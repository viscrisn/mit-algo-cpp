#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

double xmax=100;double ymax=100;
double xmin=-100;double ymin=-100;
double abs(double x)
{
    if(x>=0)return x;
    return -x;
}
void myInit(void)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-300,300,-300,300);

}

void writepixel(GLdouble x,GLdouble y)
{//glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void dda_line(double x1,double y3,double x2,double y2)
{
double length,xinc,yinc;
 double x=x1,y=y3;
double del_y=y2-y3;
double del_x=x2-x1;
if(abs(del_y)>abs(del_x))
length=abs(del_y);
else
length=abs(del_x);
xinc=del_x/length;
yinc=del_y/length;
writepixel(x,y);
for(int i=1;i<=length;i++)
{
x=x+xinc;
y=y+yinc;
writepixel(round(x),round(y));
}
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

void cohen_s_line(double x1,double y1,double x2,double y2)
{int c;double m=(y2-y1)/(x2-x1);double x,y;
int c1=code(x1,y1);
int c2=code(x2,y2);
while((c1|c2)>0)
{
if((c1&c2)>0)
break;
c=c1;
if(c1==0)
c=c2;
if((c&8)>0)
{
y=ymax;
x=x1+(1/m)*(ymax-y1);
}
else if((c&4)>0)
{
y=ymin;
x=x1+(1/m)*(ymin-y);
}
else if((c&2)>0)
{
x=xmax;
y=y1+m*(xmax-x1);
}
else if((c&1)>0)
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
dda_line(x1,y1,x2,y2);
}

void display()
{ glClear(GL_COLOR_BUFFER_BIT);
int a1=-100,a2=100,b1=100,b2=100,c1=100,c2=-100,d1=-100,d2=-100;
dda_line(a1,a2,b1,b2);
dda_line(b1,b2,c1,c2);
dda_line(c1,c2,d1,d2);
dda_line(d1,d2,a1,a2);
dda_line(120,120,-129,-72);



//glFlush();

}

void myKey(unsigned char key,int x,int y)
{
	if(key=='c')
	{
		glColor3f(0,0,0);
	dda_line(120,120,-129,-72);
	glColor3f(1,1,1);
cohen_s_line(120,120,-129,-72);
}


}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cohen-Sutherland Clipping");
	myInit();
	glutDisplayFunc(&display);
	glutKeyboardFunc(myKey);
	glutMainLoop();
	return 0;
}
