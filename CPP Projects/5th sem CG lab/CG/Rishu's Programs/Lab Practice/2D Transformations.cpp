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

struct Vertex
{
    float x,y;
}*poly;
int n;

void translate(float tx,float ty, Vertex *poly,int n)
{
    for(int i=0;i<n;i++)
    {
        poly[i].x+=tx;
        poly[i].y+=ty;
    }
}

void rotate(float angle,Vertex * poly, int n)
{
    angle=angle*((22.0/7.0)/180.0);// give a .0, otherwise nos. will be treated as integers
    for(int i=0;i<n;i++)
    {
        float temp=poly[i].x;
        poly[i].x=poly[i].x*cos(angle)-poly[i].y*sin(angle);
        poly[i].y=temp*sin(angle)+poly[i].y*cos(angle);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
    glVertex2i(poly[i].x,poly[i].y);
    glEnd();
    glFlush();

    glColor3f(1,0,1);
    rotate(30,poly,n);

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
    glVertex2i(poly[i].x,poly[i].y);
    glEnd();
    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("2D Transformations");
    init();
    cout<<"No. of vertices? ";cin>>n;
    poly=new Vertex[n];
    cout<<"Coordinates:\n";
    for(int i=0;i<n;i++)
    cin>>poly[i].x>>poly[i].y;

    glutDisplayFunc(&display);
    glutMainLoop();
}
