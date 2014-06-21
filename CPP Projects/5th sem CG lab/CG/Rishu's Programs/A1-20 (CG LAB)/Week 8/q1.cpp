//2D transformations
#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

int n=0;

struct Vertex
{
	int x,y;
	}*poly;

void translate(int tx,int ty)
{for(int i=0;i<n;i++)
	{
		poly[i].x+=tx;
		poly[i].y+=ty;
		}
}

void scale(int sx,int sy)
{
	for(int i=0;i<n;i++)
	{
		poly[i].x*=sx;
		poly[i].y*=sy;
		}
	}
	
void rotate(float angle)
{//cout<<"\nAngle (degrees): "<<angle;
	angle=angle*((float)3.1428/180);
//cout<<"\nAngle (radians): "<<angle;*/
//angle=-angle;
float temp;
for(int i=0;i<n;i++)
	{temp=poly[i].x;
		poly[i].x=poly[i].x*cos(angle)-poly[i].y*sin(angle);
		poly[i].y=temp*sin(angle)+poly[i].y*cos(angle);
		cout<<"\n"<<poly[i].x<<" "<<poly[i].y;
		}	
	}

void reflectX()
{
	for(int i=0;i<n;i++)
	{
		poly[i].y*=(-1);
	}
}

void reflectY()
{
	for(int i=0;i<n;i++)
	{
	poly[i].x*=(-1);	
	}
}

void shearX(float sh)
{
	for(int i=0;i<n;i++)
	{
	poly[i].x+=((float)sh*poly[i].y);	
	}
}

void shearY(float sh)
{
	for(int i=0;i<n;i++)
	{
	poly[i].y+=((float)sh*poly[i].x);	
	}
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
gluOrtho2D(-320,320,-240,240);
}

void display()
{
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(-320,0);
glVertex2i(320,0);
glVertex2i(0,-240);
glVertex2i(0,240);
glEnd();
glFlush();

cout<<"Enter the no. of points ";
cin>>n;
poly=new Vertex[n];

cout<<"Enter the coordinates\n";
for(int i=0;i<n;i++)
cin>>poly[i].x>>poly[i].y;

cout<<"\n";

/*for(int i=0;i<n;i++)
cout<<poly[i].x<<" "<<poly[i].y<<"\n";*/

glBegin(GL_LINE_LOOP);
for(int i=0;i<n;i++)
    glVertex2i(poly[i].x,poly[i].y);    
glEnd();
glFlush();

int c;
cout<<"1.Translate\n2.Scale\n3.Rotate\n4.Reflect about X-axis\n5.Reflect about Y-axis\n6.Shear along X-axis\n7.Shear along Y-axis\n8.Reflection about a line\n9.Exit";
cin>>c;

switch(c)
{
	case 1:
	int tx,ty;
	cout<<"Enter the x and y translation distances ";
	cin>>tx>>ty;
	translate(tx,ty);
	
	break;
	
	case 2:
	float sx,sy;
	int px,py;
	cout<<"Enter the x and y scale factors\n";
	cin>>sx>>sy;
	cout<<"Enter the point which is to be kept fixed\n";
	cin>>px>>py;
	translate(-px,-py);
	scale(sx,sy);
	translate(px,py);
	break;
	
	case 3:
	int angle;
	cout<<"Enter the rotation angle (in degrees)\n";
	cin>>angle;
	cout<<"Enter the point which is to be kept fixed\n";
	cin>>px>>py;
	translate(-px,-py);
	rotate(angle);
	translate(px,py);
	break;
	
	case 4:
	reflectX();
	break;
	
	case 5:
	reflectY();
	break;
	
	case 6:
	float sh;
	cout<<"\nEnter the shear factor ";
	cin>>sh;
	shearX(sh);
	break;
	
	case 7:
	cout<<"\nEnter the shear factor ";
	cin>>sh;
	shearY(sh);
	break;
	
	case 8:
	float m,intercept;
	cout<<"\nEnter the slope of the line ";
	cin>>m;
	cout<<"\nEnter the Y-intercept of the line ";
	cin>>intercept;
	
	translate(0,-intercept);
	rotate(-atan(m));
	reflectX();
	rotate(atan(m));
	translate(0,intercept);
	break;
	
	case 9:
	return;
	break;
	
	default:
	break;
	}
	glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++)
    glVertex2i(poly[i].x,poly[i].y);    
	glEnd();
	glFlush();
	glColor3f(0,0,0);
}

int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("2D Transformations");
init();
glutDisplayFunc(&display);

glutMainLoop();
return 0;
}
