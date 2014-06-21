#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;
struct Color
{
    float red, green, blue;
};

Color getPixel(int x, int y){                   // gets the color of the pixel at (x,y) 
    Color c;
    float color[4];
    glReadPixels(x,y,1,1,GL_RGB, GL_FLOAT, color);
    c.red = color[0];   
    c.green = color[1];         
    c.blue = color[2];  
    //cout<<c.red<<c.green<<c.blue<<"\n";
    return c;
}
/*struct fill getpixcol(int x,int y)
{
    struct fill gotpixel;
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,pick_col);
    gotpixel.r =(float) pick_col[0]/255.0;
    gotpixel.g =(float) pick_col[1]/255.0;
    gotpixel.b =(float) pick_col[2]/255.0;
    return(gotpixel);
}*/
void setPixel(int x, int y, Color c){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glColor3f(c.red, c.green, c.blue);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glPopAttrib();
    glFlush();
}

void init()
     {
        glClearColor(1.0,0.0,0.0,0.0);
        gluOrtho2D(0.0,400.0,0.0,400.0);
     }

void drawPixel(int x,int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

void Boundary_fill(int x,int y,Color thisColor){
    Color boundary_color;
    boundary_color.red=0.0;
    boundary_color.green=1.0;
    boundary_color.blue=0.0;
    //cout<<"boundary"<<boundary_color.red<<"\n";
    Color nextpixel=getPixel(x,y);
    if((nextpixel.red!=boundary_color.red)&&(nextpixel.blue!=boundary_color.blue)&&(nextpixel.green!=boundary_color.green) && (nextpixel.red!=thisColor.red)&& (nextpixel.blue!=thisColor.blue)&& (nextpixel.green!=thisColor.green))
    {  
        setPixel(x,y,thisColor);
        //cout<<"fill color\n";
        Boundary_fill((x+1),y,thisColor);
        Boundary_fill((x-1),y,thisColor);
        Boundary_fill(x,(y+1),thisColor);
        Boundary_fill(x,(y-1),thisColor);
    }

}

void draw(int x1,int y1, int x, int y){
    drawPixel(x1+x,y1+y);//quadrant1
    drawPixel(x1+x,y1-y);//quadrant2
    drawPixel(x1-x,y1+y);//quadrant3
    drawPixel(x1-x,y1-y);//quadrant4
    drawPixel(x1+y,y1+x);//quadrant5
    drawPixel(x1+y,y1-x);//quadrant6
    drawPixel(x1-y,y1+x);//quadrant7
    drawPixel(x1-y,y1-x);//quadrant8
}

void circle(int px,int py,int r){
    int a,b;
    float p;
    a=0;
    b=r;
    p=(5/4)-r;

    while(a<=b){
        draw(px,py,a,b);
        if(p<0){
            p=p+(2*a)+1;
        }
        else{
            b=b-1;
            p=p+(2*a)+1-(2*b);
        }
        a=a+1;
    }
}


void Circle(void)
{
    Color thisColor;
    thisColor.red=1.0;
    thisColor.blue=1.0;
    thisColor.green=1.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glPointSize(2.0);
    int x0 = 100;
    int y0 = 150;
    circle(x0,y0,50);
    usleep(10);
    glColor3f(thisColor.red,thisColor.blue,thisColor.green);
    Boundary_fill(x0,y0,thisColor);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Boundary fill in a circle");
    init();
    glutDisplayFunc(Circle);
    glutMainLoop();
    return 0;
}
