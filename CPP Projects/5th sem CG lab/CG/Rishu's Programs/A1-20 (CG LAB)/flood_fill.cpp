#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <unistd.h>
#include<stdio.h>

float fill[3]={1.0,0.0,0.0},old[3]={0.0,1.0,0.0};
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,640.0,0.0,480.0);
}

void display()
{
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);

glBegin(GL_POLYGON);
    glVertex2i(200,250);
	glVertex2i(250,250);
  	glVertex2i(250,200);
	glVertex2i(200,200);
glEnd();
glFlush();
}

void floodfill(float x,float y,float fill[3],float old[3])
{//printf("X: %f\tY:%f",x,y);
float pix[3];
glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pix);
//printf("%f ,%f ,%f ",pix[0],pix[1],pix[2]);

if(pix[0]==old[0]&&pix[1]==old[1]&&pix[2]==old[2])
{
glBegin(GL_POINTS);
glColor3fv(fill);
glVertex2f(x,y);
glEnd();
glFlush();
//usleep(1000);
floodfill(x+1,y,fill,old);

/*floodfill(x+1,y+1,fill,old);
floodfill(x+1,y-1,fill,old);
floodfill(x-1,y+1,fill,old);
floodfill(x-1,y-1,fill,old);*/
}
}

void myKey(unsigned char key, int x, int y)
{
	if(key == 'f')
	for(int i=200;i<250;i++)
		{floodfill(200,i,fill,old);
        glFlush();}
}


int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("flood");
glutDisplayFunc(display);
glutKeyboardFunc(myKey);
init();
glutMainLoop();
return 0;
}
