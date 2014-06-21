//Cohen-Sutherland clipping
#include<iostream>
#include<GL/glut.h>

using namespace std;

int xmin=-70,ymin=-50,xmax=70,ymax=50;
int a,b,c,d;
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

int code(int x,int y)
{
    int c=0;
    if(y>ymax)c=8;
    else if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    else if(x<xmin)c=c|1;
    return c;
}

void clip(int x1,int y1,int x2,int y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(float)(y2-y1)/(x2-x1);cout<<"\nm: "<<m<<" c1 "<<c1<<" c2 "<<c2;
    int x,y;
    while((c1|c2)>0)
    {cout<<"\nWhile";
        if((c1&c2)>0)break;

        if(c1==0)c=c2;
        else c=c1;

        if((c & 8) > 0)
        {
            y=ymax;
            x=x1+(float)(ymax-y1)/m;cout<<"\nTop x: "<<x<<"y: "<<y;
        }
        else
            if((c&4)>0)
            {
                y=ymin;
                x=x1+(float)(ymin-y1)/m;cout<<"\nBottom x: "<<x<<"y: "<<y;
            }
        if((c&2)>0)
        {
            x=xmax;
            y=(float)y1+m*(xmax-x1);cout<<"\nRight x: "<<x<<"y: "<<y;
        }
        else
            if((c&1)>0)
            {
                x=xmin;
                y=(float)y1+m*(xmin-x1);cout<<"\nLeft x: "<<x<<"y: "<<y;
            }
        if(c==c1)
        {
            x1=x;y1=y;
            c1=code(x1,y1);cout<<"\nx1: "<<x1<<" y1: "<<y1<<" c1: "<<c1<<" c2: "<<c2;;
        }
        else
        {
            x2=x;y2=y;
            c2=code(x2,y2);cout<<"\nx2: "<<x2<<" y2: "<<y2<<" c2: "<<c2<<" c1: "<<c1;
        }
    }
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}

void display()
{


}

void mykey(unsigned char key,int x,int y)
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
        clip(a,b,c,d);
        glFlush();
    }
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Cohen-Sutherland Clipping");
    init();
glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,1);
    cout<<"Enter the coordinates\n";
    cin>>a>>b>>c>>d;
    glBegin(GL_LINES);
    glVertex2i(a,b);
    glVertex2i(c,d);
    glEnd();
    glFlush();
    cout<<a<<" "<<b<<" "<<c<<" "<<d;

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();
    glFlush();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&mykey);
    glutMainLoop();
}
