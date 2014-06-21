#include <GL/glut.h>
#include <iostream>

using namespace std;

struct vertex
{
	float x,y;
};

vertex v1, v2, v3, v4;
float t=0;

void myinit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (-250, 250, -250, 250);
}

void draw()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glColor3f(1.0, 1.0, 1.0);
	float computex, computey;
	while (t <= 1)
	{
		computex = (1-t)*(1-t)*(1-t)*v1.x + 3*t*(1-t)*(1-t)*v2.x + 3*t*t*(1-t)*v3.x + t*t*t*v4.x;
		computey = (1-t)*(1-t)*(1-t)*v1.y + 3*t*(1-t)*(1-t)*v2.y + 3*t*t*(1-t)*v3.y + t*t*t*v4.y;
		cout << computex << " \t" << computey << endl;
		glBegin (GL_POINTS);
		glVertex2f (computex, computey);
		glEnd();
		t=t+0.005;
	}
	glutSwapBuffers();

}

int main (int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480); 
	
	//myinit();	//glClearColor(0.0,0.0,0.0,0.0);
	cout<<"\nEnter the verticies : ";
	cin >> v1.x >> v1.y >> v2.x >> v2.y >> v3.x >> v3.y >> v4.x >> v4.y;
	glutCreateWindow("Bezier Curve");
	myinit();
	glClear(GL_COLOR_BUFFER_BIT);
	//glutDisplayFunc(draw);
	glColor3f(1.0,0.0,0.0);
	draw();
	glFlush();
	glutMainLoop();
	glutSwapBuffers();
	return 0;
}
	
	
	
	
