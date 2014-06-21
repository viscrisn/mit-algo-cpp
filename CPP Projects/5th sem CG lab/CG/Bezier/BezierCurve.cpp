#include<GL/glut.h>
#include<unistd.h>
#include<math.h>
#include<iostream>
using namespace std;

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-350,350,-350,350);
}

class Vertex
{
	public:
	float x, y;
} p[4];

Vertex getPt(double t)
{
	Vertex v;
	v.x = pow((1-t),3)*p[0].x + 3*t*pow((1-t),2)*p[1].x + 3*t*t*(1-t)*p[2].x + pow(t,3)*p[3].x;
	v.y = pow((1-t),3)*p[0].y + 3*t*pow((1-t),2)*p[1].y + 3*t*t*(1-t)*p[2].y + pow(t,3)*p[3].y;
	return v;
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Curve");
	myInit();
	
	glClear(GL_COLOR_BUFFER_BIT);
	cout << "Enter the 4 control pts: ";
	for(int i=0; i<4; i++)
		cin >> p[i].x >> p[i].y;
		
	Vertex v;
	for(double t=0; t<=1; t+=0.001)
	{
		v = getPt(t);
		glBegin(GL_POINTS);
			glVertex2i(v.x,v.y);
		glEnd();
	}
	glFlush();
		
	glutMainLoop();
	return 0;
}
