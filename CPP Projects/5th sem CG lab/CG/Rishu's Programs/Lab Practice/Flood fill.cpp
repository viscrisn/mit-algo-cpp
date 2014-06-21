#include<iostream>
#include<GL/glut.h>

using namespace std;

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,400,0,400);//do NOT give a negative value
}

float fillc[3]={1,0,0},old[3]={1,1,1};

void floodFill(int x,int y,float fillc[3],float old[3])
{
    float current[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,current);
    if(current[0]!=old[0] && current[1]!=old[1] && current[2]!=old[2])
    {
        glColor3fv(fillc);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();

        floodFill(x,y+1,fillc,old);
        floodFill(x+1,y,fillc,old);
        floodFill(x,y-1,fillc,old);
        floodFill(x-1,y,fillc,old);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(30,30);
    glVertex2i(90,30);
    glVertex2i(90,90);
    glVertex2i(30,90);
    glEnd();
glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(50,50);
    glVertex2i(70,50);
    glVertex2i(70,70);
    glVertex2i(50,70);
    glEnd();

    glFlush();
}
void myKey(unsigned char key,int x,int y)
{
    if(key=='f')
    floodFill(43,50,fillc,old);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);//Give the exact difference of the values passed in gluOrtho2D(), i.e., 200-(-200),200-(-200)
    glutCreateWindow("Boundary Fill");
    init();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
}
