#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

GLdouble xmin=-100, ymin=-100, xmax=100, ymax=100;
int in=0, out=0;
int n=8;

class Vertex
{
	public:
	double x,y;


	Vertex()
	{
	}
	
	Vertex(double xi, double yi)
	{
		x=xi;
		y=yi;
	}
};

Vertex inv[8],outv[8],tempv[8];
int i;

Vertex c1(xmin,ymin);
Vertex c2(xmax,ymin);
Vertex c3(xmax,ymax);
Vertex c4(xmin,ymax);

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300,300,-300,300);
}

void setpixel(GLdouble x, GLdouble y)
{

	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

}

void DDALine(double x1, double y1, double x2, double y2)
{
	GLdouble x,y,dx,dy,length,xinc,yinc,i;
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;

	if(abs(dy)>abs(dx))
	 length=abs(dy);
	else
	 length=abs(dx);

	xinc=dx/length;
	yinc=dy/length;
	setpixel(x,y);

	for(i=1; i<length; i++)
	{
		x+=xinc;
		y+=yinc;
		setpixel(round(x),round(y));
	}
}

bool inside(Vertex v, Vertex c1, Vertex c2)
{
	if(c1.y==ymin && c2.y==ymin)
	{
		if(v.y>ymin)
		return true;
	}

	if(c1.y==ymax && c2.y==ymax)
	{
		if(v.y<ymax)
		return true;
	}

	if(c1.x==xmax && c2.x==xmax)
	{
		if(v.x<xmax)
		return true;
	}

	if(c1.x==xmin && c2.x==xmin)
	{
		if(v.x>xmin)
		return true;
	}

    return false;
}

void output(Vertex v, Vertex outv[])
{
	outv[out++]=v;
}

Vertex intersect(Vertex P, Vertex S, Vertex c1, Vertex c2)
{
	Vertex i;
	
	if (P.x-S.x==0)
	{
		i.x=P.x;
		i.y=c1.y;
	}
	else
	{
		double m=(P.y-S.y)/(P.x-S.x);
	
		if(c1.y==c2.y)
		{
			i.y=c1.y;
			i.x = (P.x*m - P.y + c1.y)/m;
		}


		if(c1.x==c2.x)
		{
			i.x=c1.x;
			i.y=P.y-m*(P.x-c1.x);
		}
	}
	return i;
}

void SHPCA(Vertex inv[], int inc, Vertex outv[], Vertex c1, Vertex c2)
{
	out=0;
	int j;
	Vertex S,P,i;
	S=inv[inc-1];
	for(j=0; j<inc; j++)
	{
		P=inv[j];
		if(inside(P,c1,c2))
		{
			if(inside(S,c1,c2))
			output(P,outv);

			else
			{
				i=intersect(S,P,c1,c2);
				output(i,outv);
				output(P,outv);
			}
		}

		else if(inside(S,c1,c2))
		{
			i=intersect(S,P,c1,c2);
			output(i,outv);
		}

		S=P;
		n=out;
	}
}



void myKey(unsigned char key, int x, int y)
{
	if(key=='c')
	{
		SHPCA(inv,n,outv,c1,c2);
		SHPCA(outv,n,inv,c2,c3);
		SHPCA(inv,n,outv,c4,c3);
		SHPCA(outv,n,inv,c1,c4);

		glClear(GL_COLOR_BUFFER_BIT);
		DDALine(xmin,ymin,xmax,ymin);
		DDALine(xmax,ymin,xmax,ymax);
		DDALine(xmin,ymax,xmax,ymax);
		DDALine(xmin,ymin,xmin,ymax);

		for(i=0; i<n-1; i++)
		{
			DDALine(inv[i].x,inv[i].y,inv[i+1].x,inv[i+1].y);
		}

		DDALine(inv[0].x,inv[0].y,inv[n-1].x,inv[n-1].y);
	}
	else
	cout<<"\n Wrong key pressed";
	glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	DDALine(xmin,ymin,xmax,ymin);
	DDALine(xmax,ymin,xmax,ymax);
	DDALine(xmin,ymax,xmax,ymax);
	DDALine(xmin,ymin,xmin,ymax);

	for(i=0; i<n-1; i++)
	{
		DDALine(inv[i].x,inv[i].y,inv[i+1].x,inv[i+1].y);
	}

	DDALine(inv[0].x,inv[0].y,inv[n-1].x,inv[n-1].y);
	  glFlush();
	glutKeyboardFunc(myKey);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(30,30);


	cout<<"\nEnter no. of vertices: ";
	cin>>n;

	cout<<"\nEnter the vertices: ";
	for(i=0; i<n; i++)
	{
	 cin>>inv[i].x>>inv[i].y;

	}

	glutCreateWindow("Polygon Clipping");
	myInit();

	glutDisplayFunc(&display);


	glutMainLoop();
	return 0;
}
