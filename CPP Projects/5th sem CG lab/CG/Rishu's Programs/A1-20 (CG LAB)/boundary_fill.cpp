#include<iostream>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <unistd.h>
#include<stdio.h>

using namespace std;

float fillc[3]={1.0,0.0,0.0},boundary[3]={0,0,0};

void init()
{
    glClearColor(1.0,1.0,1.0,2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int aaa=0;

void boundaryfill(float x,float y,float fillc[3],float boundary[3])
{aaa++;
  cout<<"Inside boundary_fill()\n";
  //if(aaa%5==0)cin>>aaa;
float current[3];
glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);

cout<<"\nCurrent: "<<current[0]<<" "<<current[1]<<" "<<current[2];

//if(current[0]==boundary[0]&&current[1]==boundary[1]&&current[2]==boundary[2])cout<<"\nReached boundary!!!!!";

if(((current[0] != boundary[0])||(current[1] != boundary[1])||(current[2] != boundary[2]))&&((current[0] != fillc[0])||(current[1] != fillc[1])||(current[2] != fillc[2])))
{
glBegin(GL_POINTS);
glColor3fv(fillc);
glVertex2f(x,y);
glEnd();
usleep(5);
glFlush();

boundaryfill(x,y+1,fillc,boundary);
/*boundaryfill(x,y-1,fillc,boundary);
boundaryfill(x-1,y,fillc,boundary);
boundaryfill(x+1,y,fillc,boundary);*/
}
}


void myKey(unsigned char key, int x, int y)
{
    cout<<"\nEntered myKey()";
	if(key == 'f')
	{	for(int i=31;i<90;i++)
		boundaryfill(i,31,fillc,boundary);
        glFlush();}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

/*glColor3f(0,0,1.0);
glBegin(GL_POLYGON);
glVertex2i(30,30);
glVertex2i(90,30);
glVertex2i(90,90);
glVertex2i(30,90);
glEnd();
glFlush();*/


glColor3f(0,0,0);
glBegin(GL_LINE_LOOP);
glVertex2i(30,30);
glVertex2i(90,30);
glVertex2i(90,90);
glVertex2i(30,90);
glEnd();

glFlush();
}

int main(int argc,char *argv[])
{
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("Boundary Fill");
init();
glutDisplayFunc(display);
glutKeyboardFunc(myKey);
glutMainLoop();
return 0;
}
