#include<GL/glut.h>
#include<iostream>

using namespace std;

double xmin=40,ymin=40,xmax=200,ymax=200;//Clip rectangle coordinates
int n;
struct Vertex
{int x,y;
	};

Vertex* v;

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


	for(int i=0;i<n-1;i++)
	{line(v[i].x,v[i].y,v[i+1].x,v[i+1].y);
		}
		line(v[n-1].x,v[n-1].y,v[0].x,v[0].y);
	}

void clip(Vertex v[],int clipEdge)
{

	}

void myKeyboard(unsigned char key,int x,int y)
{cout<<"Inside MyKeyboard";
	glClear(GL_COLOR_BUFFER_BIT);
	line(xmin,ymin,xmax,ymin);//Clipping rectangle
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	if(key=='c')
		clip(v,5);
	}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,640);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cohen-sutherland Polygon Clipping");
	myInit();
	glutDisplayFunc(&display);

	cout<<"Enter the no. of points ";cin>>n;
	v=new Vertex[n];
	cout<<"Enter the coordinates (in a cyclic order)\n";

	for(int i=0;i<n;i++)
		{cout<<"\nx"<<i+1<<":";
			cin>>v[i].x;
			cout<<"y"<<i+1<<":";
			cin>>v[i].y;}

	glutKeyboardFunc(&myKeyboard);

	glutMainLoop();
	return 0;
}

