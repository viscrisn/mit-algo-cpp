#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>

void myInit(void)
{	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
}

void writepixel(float x, float y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	
	glFlush();
}


void dda(float x1,float y1,float x2,float y2)
{
		float dy=y2-y1;
		float dx=x2-x1;
		float len;
		
		if(abs(dy)>abs(dx)) len=abs(dy);
		else len=abs(dx);
		
		float xi=dx/len;
		float yi=dy/len;
		float x=x1, y=y1;
		writepixel(x,y);
		
		for(int i=0;i<len;i++)
		{
			x=x+xi;
			y=y+yi;
			//writepixel(x,y);
			writepixel(round(x), round(y));
		}
		glFlush();
}	

void draw()
{printf("Draw");
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glLineWidth(20);
	
	dda(350,350,650,300);	//m<0&&abs(m)<1
	dda(350,350,500,650);	//m>1
	dda(200,650,350,350);	//m<0&&abs(m)>1
	dda(350,350,650,550);	//m>0 && m<1
	
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DAA line");
	myInit();
	
	//float x1, y1, x2,y2;
	/*printf("Input 4 coordinates:\t");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	dda(x1,y1,x2,y2);
	*/
	glutDisplayFunc(&draw);
	glutMainLoop();
}
