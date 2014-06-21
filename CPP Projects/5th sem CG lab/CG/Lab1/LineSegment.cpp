#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(180,15);
		glVertex2i(0,0);
	glEnd();
	glLineWidth(10);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(15,165);
		glVertex2i(110,40);
	glEnd();
	glLineWidth(3);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1300,715);
	glutCreateWindow("Creating LINES using openGL");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
