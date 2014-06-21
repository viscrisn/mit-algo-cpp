#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void myInit(void)
{
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
	
}	
int X1=0,Y1=0,X2=0,Y2=100,X3=100,Y3=100,X4=100,Y4=0;

void square(int n){
	if(n!=0){
		dda(X1,Y1,X2,Y2);
		dda(X2,Y2,X3,Y3);
		dda(X3,Y3,X4,Y4);
		dda(X4,Y4,X1,Y1);
		float temp=X1;
		X1=(X1+X2)/2;
		X2=(X3+X2)/2;
		X3=(X3+X4)/2;
		X4=(temp+X4)/2;
		
		temp=Y1;
		Y1=(Y1+Y2)/2;
		Y2=(Y3+Y2)/2;
		Y3=(Y3+Y4)/2;
		Y4=(temp+Y4)/2;
		
		
		square(n-1);
		}
	}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DAA line");
	myInit();
	
	int n=1;
	
	printf("Enter no. of squares:\t");
	scanf("%d",&n);
	square(n);
	
	glutMainLoop();
	return 0;
}
