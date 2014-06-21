#include<iostream>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>

using namespace std;

int n=0;
int tx,ty,sx,sy;

void myInit()
{	
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400,400,-400,400);	
}

class Vertex
{ 
	public: 
	int x;
	int y;

};
Vertex v[10],temp[10];

Vertex translate (Vertex old,int tx,int ty) 
{ 
	Vertex now;
	now.x=old.x+tx;
	now.y=old.y+ty;
	return now;
}

Vertex reflectx(Vertex old)
{
	Vertex now;
	now.x=old.x;
	now.y=-old.y;
	return now;
}

Vertex reflecty(Vertex old)
{
	Vertex now;
	now.x=-old.x;
	now.y=old.y;
	return now;
}


Vertex scale (Vertex old,int sx,int sy)
{
	Vertex now;
	now.x=old.x*sx;
	now.y=old.y*sy;
	return now;
}

void output()
{
	glClear(GL_COLOR_BUFFER_BIT);
//Cartesian Axis
	glBegin(GL_LINES);
	glVertex2i(-300,0);
	glVertex2i(300,0);
	glVertex2i(0,-300);
	glVertex2i(0,300);
	glEnd();
//Initial polygon in blue
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<n; i++)
		glVertex2i(v[i].x,v[i].y);
	glEnd();
	glFlush(); 
}

void initialize()
{
	for(int i=0; i<n; i++)
	{
		v[i].x=temp[i].x;
		v[i].y=temp[i].y;
	}

	output();
}

Vertex Rotation(float a,Vertex old)
{
	Vertex now;

	int tmp=old.x;
	now.x=old.x*cos(a)-old.y*sin(a);
	now.y=tmp*sin(a)+old.y*cos(a);

	return now;
}

void disp()
{
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<n;i++)
		glVertex2i(v[i].x,v[i].y);
	glEnd();
}

void myKey(unsigned char key, int x, int y)
{

	if(key=='s')
	{

		cout<<"\n \n Enter Scaling Factors Sx and Sy :-  ";
		cin>>sx>>sy;
		for(int i=0;i<n;i++)
			v[i]=scale(v[i],sx,sy);
		glColor3f(0.0,1.0,0.0);
		disp(); 
	}

	else if (key=='t')
	{
		cout<<"Enter tx and ty :-  ";
		cin>>tx>>ty;
		for(int i=0;i<n;i++)
			v[i]=translate(v[i],tx,ty);
		glColor3f(1.0,0.0,0.0);
		disp(); 
	}
	
	else if(key=='i')
	{
		initialize();
	}

	else if(key=='x')
	{
		for(int i=0;i<n;i++) 
			v[i]=reflectx(v[i]);
		glColor3f(0.0,1.0,0.0);
		disp(); 
	}
	
	else if(key=='z')
	{

		for(int i=0;i<n;i++)
			v[i]=Rotation(-45*3.14/180,v[i]);


		for(int i=0;i<n;i++)
			v[i]=reflecty(v[i]);

		for(int i=0;i<n;i++)
			v[i]=Rotation(45*3.14/180,v[i]);

		glColor3f(0.0,1.0,1.0); 
		disp();

	}
	
	else if(key=='y')
	{
		for(int i=0;i<n;i++) 
			v[i]=reflecty(v[i]);
		glColor3f(0.0,1.0,0.0); 
		disp(); 
	}
	
	else if(key=='h')
	{
		int shx,shy,tmp;
		cout<<"Enter Shearing Factor :-  ";
		cin>>shx>>shy;
		for(int i=0;i<n;i++)
		{
			tmp=v[i].x;
			v[i].x=v[i].x+(shx*v[i].y);
			v[i].y=(shy*tmp)+v[i].y;
		}
		glColor3f(0.0,1.0,1.0); 
		disp();
	}
	
	else if(key=='r')
	{
		float a;	
		cout<<"Enter Degree :-  ";
		cin>>a;
		a=(a*3.14)/180;
		for(int i=0;i<n;i++) 
			v[i]=Rotation(a,v[i]);
		glColor3f(0.0,1.0,1.0); 
		disp(); 

	}
	
	else if(key=='o')
	{
		int px,py;
		cout<<"Enter Pivot :-  ";
		cin>>px>>py;
		float a;
		cout<<"Enter Degree :-  ";
		cin>>a;
		a=(a*3.14)/180;

		//translate to origin
		for(int i=0;i<n;i++) 
			v[i]=translate(v[i],-px,-py);

		for(int i=0;i<n;i++) 
			v[i]=Rotation(a,v[i]);

		//translate back
		for(int i=0;i<n;i++) 
			v[i]=translate(v[i],px,py);

		glColor3f(0.0,1.0,1.0); 
		disp(); 

	}
	
	else if(key=='p')
	{
		int px,py;
		cout<<"\nEnter Pivot :-  ";
		cin>>px>>py;
		cout<<"\n\nEnter Scaling Factors Sx and Sy :-  ";
		cin>>sx>>sy;

		for(int i=0;i<n;i++) //translate to origin
			v[i]=translate(v[i],-px,-py);
	
		for(int i=0;i<n;i++)
			v[i]=scale(v[i],sx,sy);
	
		for(int i=0;i<n;i++) // translate back to point
			v[i]=translate(v[i],px,py);


		glColor3f(0.0,1.0,0.0); 
		disp(); 

	}
	glFlush();
}

void display()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	output();
	glFlush(); 
}

int main(int argc, char** argv)
{ 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);	
	glutCreateWindow("Transform");	

	cout<<"Enter no. of vertices ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter x and y coordinate for vertex "<<i+1<<" : ";
		cin>>v[i].x>>v[i].y;
		temp[i].x=v[i].x;
		temp[i].y=v[i].y;
	}
	
	cout<<"\n'i':Initialize\n't':Translation\t's':Scaling(Origin)\t'p':Scaling(Pivot)\n'x':Reflect(x)\t'y':Reflect(y)\t\t'z':Reflect(x=-y)\n'h':Shearing\t'r':Rotation(Origin)\t'o':Rotation(pivot)";
	cout<<"\n";

	myInit();
	glutDisplayFunc(&display);
	glutKeyboardFunc(myKey);
	glFlush();
	glutMainLoop();
	return 0;
}
