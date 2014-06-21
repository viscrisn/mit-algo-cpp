#include<GL/glut.h>
#include <unistd.h>

void floodfill(float,float,float[],float[]);

float fill[3]={1.0,0.0,0.0},old[3]={0.0,1.0,0.0};

void init()
{
	glOrtho(0.0,640.0,0.0,480.0,1.0,-1.0);
}

void display()
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);

	glVertex2i(100,150);
	glVertex2i(150,150);
	glVertex2i(150,200);
	glVertex2i(100,200);
	glEnd();
	floodfill(125.0,175.0,fill,old);
	glFlush();
}

void floodfill(float x,float y,float fill[3],float old[3])
{
	float pix[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pix);

	if( pix[0]==old[0] &&
		pix[1]==old[1] &&
		pix[2]==old[2]
	  )
		{
			glBegin(GL_POINTS);
			glColor3fv(fill);
			glVertex2f(x,y);
			glEnd();
			usleep(5);
			glFlush();
	
			floodfill(x-1,y,fill,old);usleep(30000);
			floodfill(x+1,y,fill,old);usleep(30000);
			floodfill(x,y+1,fill,old);usleep(30000);
			floodfill(x,y-1,fill,old);usleep(30000);
		}
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Flood Filling Rectangle (4 connected pixels) ");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
