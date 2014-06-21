#include<iostream>
#include<GL/glut.h>

using namespace std;

float fillc[3]={1,0,0},boundary[3]={0,0,0};

void init()
{
    glClearColor(1,1,1,2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,400,0,400);
}

void boundaryfill(int x,int y, float fillc[3],float boundary[3])
{
    float current[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);
    if(((current[0] != boundary[0])||(current[1] != boundary[1])||(current[2] != boundary[2]))&&((current[0] != fillc[0])||(current[1] != fillc[1])||(current[2] != fillc[2])))
    {
        glBegin(GL_POINTS);
        glColor3fv(fillc);
        glVertex2f(x,y);
        glEnd();
        //usleep(5);
        glFlush();

        boundaryfill(x,y+1,fillc,boundary);
        boundaryfill(x,y-1,fillc,boundary);
        boundaryfill(x-1,y,fillc,boundary);
        boundaryfill(x+1,y,fillc,boundary);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20,20);
    glVertex2i(70,20);
    glVertex2i(70,70);
    glVertex2i(20,70);
    glEnd();
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='f')
    boundaryfill(43,25,fillc,boundary);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Boundary Fill");
    init();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
}
