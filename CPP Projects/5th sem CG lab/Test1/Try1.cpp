#include<iostream>
#include<GL/glut.h>
#include<cmath>
#include<unistd.h>

using namespace std;

struct line_str
{
    float x,y;
} v[4];

int rad_g = 200,center_x = 0,center_y = 100;
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-600.0,500.0,-600.0,500.0);
}

void setpixel(int x, int y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void circlepoints(int x, int y,int cx,int cy)
{
    setpixel(x+cx,y+cy);
    setpixel(-x+cx,y+cy);
    setpixel(x+cx,-y+cy);
    setpixel(-x+cx,-y+cy);
    setpixel(y+cx,x+cy);
    setpixel(-y+cx,x+cy);
    setpixel(y+cx,-x+cy);
    setpixel(-y+cx,-x+cy);
}

void circle(int rad,int center_x,int center_y)
{
    float x=0,y=rad;
    double d= 1.25 - rad;
    circlepoints(x,y,center_x,center_y);
    while(y>x)
    {
        if(d<0)
        {
            d += 2*x + 3;
            x++;
        }
        else
        {
            d += 2*(x-y) + 5;
            x++;
            y--;
        }
        circlepoints(x,y,center_x,center_y);
    }
}

void dda(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
    glFlush();
    /*
    double dx = x2-x1, dy = y2 - y1,length, steps = 0;
    double x = x1, y = y1,xinc,yinc;
    if(abs(dy)>abs(dx))
    {
        length = abs(dy);
    }
    else
    {
        length = abs(dx);
    }
    xinc = dx/length;
    yinc = dy/length;
    while(steps<length)
    {
        setpixel(round(x),round(y));
        x += xinc;
        y += yinc;
        steps++;
    }

    glFlush();*/
}

void line_disp()
{
    for(int i=0; i<4; i++)
    {
        dda(0 + center_x,0+ center_y,v[i].x+ center_x,v[i].y+ center_y);
        dda(10 + center_x,10+ center_y,10+v[i].x+ center_x,10+v[i].y+ center_y);
    }

}

void rotate_line(float radian)
{
    for (int i=0; i<4; i++ )
    {
        v[i].x = v[i].x * cos(radian) - v[i].y * sin(radian);
        v[i].y = v[i].x * sin(radian) + v[i].y * cos(radian);
    }

}

void translate_line()
{

}
void disp1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    circle(rad_g,0,100);
    //circle(rad_g+10,0,100);
    line_disp();
    float radian = 0;
    int ang = 10;
    for (int i=0; i<300; i++ )
    {
        if(i%7==0)
        {
            v[0].x = 0,v[0].y = rad_g;
            v[1].x = 0,v[1].y = -rad_g;
            v[2].x = rad_g,v[2].y = 0;
            v[3].x = -rad_g,v[3].y = 0;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        circle(rad_g,0,100);
      //  circle(rad_g+10,0,100);
        radian = (3.14/180)*ang;
        rotate_line(radian);
        line_disp();
        usleep(1000);
    }

}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Try1");
    init();
    v[0].x = 0,v[0].y = rad_g;
    v[1].x = 0,v[1].y = -rad_g;
    v[2].x = rad_g,v[2].y = 0;
    v[3].x = -rad_g,v[3].y = 0;
    glutDisplayFunc(&disp1);
    glutMainLoop();
}
