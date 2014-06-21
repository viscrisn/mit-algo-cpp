#include<iostream>
#include<GL/glut.h>

using namespace std;

struct Vertex
{
    float x,y;
}inV[20];
Vertex outV[20];
int n,xmin=-50,ymin=-50,xmax=50,ymax=50,len=0;

void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

bool inside(Vertex v, int clipEdge)
{
    switch(clipEdge)
    {
        case 1://top
        if(v.y<ymax)return true;
        return false;
        break;

        case 2://bottom
        if(v.y>ymin)return true;
        return false;
        break;

        case 3://right
        if(v.x<xmax)return true;
        return false;
        break;

        case 4://left
        if(v.x>xmin)return true;
        return false;
        break;
    }
}

void output(Vertex v,Vertex outV[])
{
    outV[len++]=v;
    //cout<<"\noutV: "<<v.x<<","<<v.y;
}

Vertex intersect(Vertex s,Vertex p,int clipEdge)
{
    float m=(s.y-p.y)/(s.x-p.x);
    Vertex i;
    switch(clipEdge)
    {
        case 1://top
        i.y=ymax;
        i.x=s.x+(ymax-s.y)/m;
        break;

        case 2://bottom
        i.y=ymin;
        i.x=s.x+(ymin-s.y)/m;
        break;

        case 3://right
        i.x=xmax;
        i.y=s.y+(xmax-s.x)*m;
        break;

        case 4://left
        i.x=xmin;
        i.y=s.y+(xmin-s.x)*m;
        break;
    }
    return i;
}

void clip(Vertex inV[], Vertex outV[],int clipEdge)
{
    Vertex s,p,i;
    s=inV[n-1];
    len=0;
    for(int j=0;j<n;j++)
    {
        p=inV[j];
        if(inside(p,clipEdge))
            if(inside(s,clipEdge))
            {
                output(p,outV);
            }
            else
            {
                i=intersect(s,p,clipEdge);
                output(i,outV);
                output(p,outV);
            }
        else if(inside(s,clipEdge))
            {
                i=intersect(s,p,clipEdge);
                output(i,outV);
            }
        s=p;
    }
    n=len;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();

    glColor3f(1,0,1);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<n;i++)
    glVertex2i(inV[i].x,inV[i].y);
    glEnd();
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='c')
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(xmin,ymin);
        glVertex2i(xmax,ymin);
        glVertex2i(xmax,ymax);
        glVertex2i(xmin,ymax);
        glEnd();

        clip(inV,outV,1);
        clip(outV,inV,2);
        clip(inV,outV,3);
        clip(outV,inV,4);

        glColor3f(0,1,1);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<len;i++)
        glVertex2i(outV[i].x,outV[i].y);

        glEnd();
        glFlush();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Polygon Cliping");
    init();
    cout<<"Enter the no. of vertices ";
    cin>>n;

    cout<<"Enter the coordinates (in a cyclic order)\n";
    for(int i=0;i<n;i++)
    cin>>inV[i].x>>inV[i].y;

    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
    return 0;
}
