#include<iostream>
#include<GL/glut.h>

using namespace std;
float xmin=-70,ymin=-50,xmax=70,ymax=50;
float a,b,c,d;
void init()
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

bool clipTest(float p,float q,float &u1,float &u2)
{cout<<"\nCliptest p: "<<p<<" q: "<<q<<" u1: "<<u1<<" u2: "<<u2;
    float r;

    if(p<0)
    {
        r=q/p;cout<<" r: "<<r;
        if(r>u2) return false;
        if(r>u1) u1=r;cout<<"\nu1 = "<<u1;
    }
    else if(p>0)
    {
        r=q/p;cout<<" r: "<<r;
        if(r<u1)return false;
        if(r<u2)u2=r;cout<<"\nu2 = "<<u2;
    }
    else if(q<0)return false;
    return true;
}

void clip(float x1,float y1,float x2,float y2)
{
    float u1=0,u2=1;
    float newx1,newx2,newy1,newy2;
    if(clipTest(x1-x2,x1-xmin,u1,u2))
        if(clipTest(x2-x1,xmax-x1,u1,u2))
            if(clipTest(y1-y2,y1-ymin,u1,u2))
                (clipTest(y2-y1,ymax-y1,u1,u2));

                    newx1=x1+u1*(x2-x1);
                    newx2=x1+u2*(x2-x1);
                    newy1=y1+u1*(y2-y1);
                    newy2=y1+u2*(y2-y1);

                glBegin(GL_LINES);
                glVertex2i(newx1,newy1);
                glVertex2i(newx2,newy2);
                glEnd();
                glFlush();
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


    cout<<"Enter the coordinates ";cin>>a>>b>>c>>d;
    glBegin(GL_LINES);
    glVertex2i(a,b);
    glVertex2i(c,d);
    glEnd();
    glFlush();
}

void myKey(unsigned char key,int x,int y)
{
    if(key=='c')
    {glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();
    glColor3f(1,0,1);
    clip(a,b,c,d);
    glFlush();
    }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Liang-Barsky Line Clipping");
    init();
    glutDisplayFunc(&display);
    glutKeyboardFunc(&myKey);
    glutMainLoop();
    return 0;
}
