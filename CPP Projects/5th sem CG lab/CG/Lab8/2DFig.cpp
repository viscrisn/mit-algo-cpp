#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

struct points
{
	float x;
	float y;
};
struct points P[100];
int n,dx=1,dy=1,deg,px=0,py=0;
float degree=0;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void lines(struct points P1,struct points P2)
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
		glVertex2i(P1.x,P1.y);
		glVertex2i(P2.x,P2.y);
	glEnd();
	glFlush();
}


void display_polygon()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
			lines(P[i],P[i+1]);
		else
			lines(P[i],P[0]);
	}
}

void myKey(unsigned char key, int x, int y)
{
	int i;
	
	if(key=='p')
	{
		//glClear(GL_COLOR_BUFFER_BIT);
		for(i=0;i<n;i++)
		{
			P[i].x-=px;
			P[i].y-=py;
		}
		//display_polygon();
		
		for(i=0;i<n;i++)
		{
			P[i].x=P[i].x*cos(degree)-P[i].y*sin(degree);
			P[i].y=P[i].x*sin(degree)+P[i].y*cos(degree);
		}
		//display_polygon();
		
		for(i=0;i<n;i++)
		{
			P[i].x+=px;
			P[i].y+=py;
		}
		display_polygon();
	}
	else
		cout<<"\nInvalid Key Pressed";
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(800,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Translation");
	init();
	
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<"\nEnter the no of vertices of the polygon :-   ";
	cin>>n;
	cout<<"\nEnter the (x,y) co-ordinates of the polygon in order :-\n";
	for(i=0;i<n;i++)
	{
		cin>>P[i].x>>P[i].y;
	}
	display_polygon();
	cout<<"\nPress\n't' to translate the polygon\n";
	cout<<"'s' to scale the polygon\n";
	cout<<"'r' to rotate the polygon\nafter entering the following details :-\n";
	cout<<"\nEnter the points about which the operations are to be performed :- \nx = ";
	cin>>px;
	cout<<"y = ";
	cin>>py;
	
	cout<<"\nEnter the scaling factors :-\nx = ";
	cin>>dx;
	cout<<"y = ";
	cin>>dy;
	
	cout<<"\nEnter the rotation factors :-\ndegree = ";
	cin>>deg;
	
	degree=(float) deg/180;
	glFlush();
	glutKeyboardFunc(myKey);
	
	glFlush();
	glutMainLoop();
	return 0;
}
