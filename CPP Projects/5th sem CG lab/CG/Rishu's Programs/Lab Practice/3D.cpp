#include<iostream>
#include<GL/glut.h>
#include<math.h>

using namespace std;

void init()
{
    glClearColor(1,1,.5,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

struct Vertex
{
    float x,y,z;
};

Vertex poly[8]={{0,0,0},{100,0,0},{100,100,0},{0,100,0},{0,0,100},{100,0,100},{100,100,100},{0,100,100}},temp[8];
float alpha=70*((22.0/7.0)/180.0),fi=40*((22.0/7.0)/180.0);

void rotateZ(float angle)
{cout<<"Rotate";
    angle*=((22/7)/180.0);
    cout<<" "<<angle<<" degrees. ";
    for(int i=0;i<8;i++)
    {
        float temp2=poly[i].x;
        poly[i].x=poly[i].x*cos(angle)-poly[i].y*sin(angle);cout<<poly[i].x<<" ";
        poly[i].y=temp2*sin(angle)+poly[i].y*cos(angle);cout<<poly[i].y<<"\n";
    }
}
void cavalier(Vertex poly[],int n=8)
{
    for(int i=0;i<n;i++)
    {
        temp[i].x=poly[i].x+poly[i].z*cos(fi)/tan(alpha);
        temp[i].y=poly[i].y+poly[i].z*sin(fi)/tan(alpha);
    }
}

void draw()
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<4;i++)
    {glVertex2i(temp[i].x,temp[i].y);}
    glEnd();

    glBegin(GL_LINE_LOOP);
    for(int i=4;i<8;i++)
    {glVertex2i(temp[i].x,temp[i].y);}
    glEnd();

    glBegin(GL_LINES);
    for(int i=0;i<4;i++)
    {
        glVertex2i(temp[i].x,temp[i].y);
        glVertex2i(temp[i+4].x,temp[i+4].y);
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);

    cavalier(poly);
    draw();
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='r')
    {
    glColor3f(1,0,1);
    rotateZ(45);
    cavalier(poly);
    draw();
    glFlush();
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutCreateWindow("3D Transformations");
    init();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
    return 0;
}
