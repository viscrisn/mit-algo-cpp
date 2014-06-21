#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}
float alpha=60.0*(22.0/7.0)/180.0,fi=30*(22.0/7.0)/180.0;

struct Vertex
{
    float x,y,z;
};
Vertex poly[8]={{0,0,0},{100,0,0},{100,100,0},{0,100,0},{0,0,100},{100,0,100},{100,100,100},{0,100,100}},temp[8];

void cavalier()
{
    for(int i=0;i<8;i++)
    {
        temp[i].x=poly[i].x+poly[i].z*cos(fi)/tan(alpha);
        temp[i].y=poly[i].y+poly[i].z*sin(fi)/tan(alpha);
    }
}

void draw()
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++)
    glVertex2i(temp[i].x,temp[i].y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    for(int i=4;i<8;i++)
    glVertex2i(temp[i].x,temp[i].y);
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<4;i++)
    {
        glVertex2i(temp[i].x,temp[i].y);
        glVertex2i(temp[i+4].x,temp[i+4].y);
    }
    glEnd();
}

void rotateZ(float angle)
{
    angle*=(22.0/7.0)/180.0;
    float temp2;
    for(int i=0;i<8;i++)
    {
        temp2=poly[i].x;
        poly[i].x=temp2*cos(angle)-poly[i].y*sin(angle);
        poly[i].y=temp2*sin(angle)+poly[i].y*cos(angle);
    }
}

void rotateX(float angle)
{
    angle*=(22.0/7.0)/180.0;
    float temp2;
    for(int i=0;i<8;i++)
    {
        temp2=poly[i].y;
        poly[i].y=temp2*cos(angle)-poly[i].z*sin(angle);
        poly[i].z=temp2*sin(angle)+poly[i].z*cos(angle);
    }
}

void rotateY(float angle)
{
    angle*=(22.0/7.0)/180.0;
    float temp2;
    for(int i=0;i<8;i++)
    {
        temp2=poly[i].z;
        poly[i].z=temp2*cos(angle)-poly[i].x*sin(angle);
        poly[i].x=temp2*sin(angle)+poly[i].x*cos(angle);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    draw();
    glColor3f(1,0,1);
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='z'||key=='a')
    {
        if(key=='z')
        rotateZ(30);
        else rotateZ(-30);
        cavalier();
        glClear(GL_COLOR_BUFFER_BIT);
        draw();
        glFlush();
    }
    else
    if(key=='y'||key=='t')
    {
        if(key=='y')
        rotateY(30);
        else rotateY(-30);
        cavalier();
        glClear(GL_COLOR_BUFFER_BIT);
        draw();
        glFlush();
    }
    else
    if(key=='x'||key=='c')
    {
        if(key=='x')
        rotateX(30);
        else rotateX(-30);
        cavalier();
        glClear(GL_COLOR_BUFFER_BIT);
        draw();
        glFlush();
    }
}
int main(int argc,char ** c)
{
    glutInit(&argc,c);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("sdf");
    init();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
}
