#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
GLsizei winwidth=600,winheight=500;
GLfloat xwcmin=-50.0,ywcmin=-50.0,xwcmax=50.0,ywcmax=50.0;
class wcpt3d
{
	public:
		GLfloat x,y,z;
};
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
}
void plotpoint(wcpt3d bezcurvept)
{
	glBegin(GL_POINTS);
		glVertex2f(bezcurvept.x,bezcurvept.y);
	glEnd();
}
void binomial(GLint n,GLint *c)
{
	GLint k,j;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
		for(j=n;j>=k+1;j--)
			c[k]*=j;
		for(j=n-k;j>=2;j--)
			c[k]/=j;
	}
}
void compute(GLfloat u,wcpt3d *bezpt,GLint nctrlpts,wcpt3d *ctrlpts,GLint *c)
{
	GLint k,n=nctrlpts-1;
	GLfloat bezblendfnc;
	bezpt->x=bezpt->y=bezpt->z=0.0;
	for(k=0;k<nctrlpts;k++)
	{
		bezblendfnc=c[k]*pow(u,k)*pow(1-u,n-k);
		bezpt->x+=ctrlpts[k].x*bezblendfnc;
		bezpt->y+=ctrlpts[k].y*bezblendfnc;
		bezpt->z+=ctrlpts[k].z*bezblendfnc;
	}
}
void bezier(wcpt3d *ctrlpts,GLint nctrlpts,GLint nbezcurvepts)
{
	wcpt3d bezcurvept;
	GLfloat u;
	GLint *c,k;
	c=new GLint[nctrlpts];
	binomial(nctrlpts-1,c);
	for(k=0;k<=nbezcurvepts;k++)
	{
		u=GLfloat(k)/GLfloat(nbezcurvepts);
		compute(u,&bezcurvept,nctrlpts,ctrlpts,c);
		plotpoint(bezcurvept);
	}
	delete [] c;
}
void displayfnc(void)
{
	GLint nctrlpts=4,nbezcurvepts=1000;
	wcpt3d ctrlpts[4]={{-40.0,-40.0,0.0},{-10.0,200.0,0.0},{10.0,-200.0,0.0},{40.0,40.0,0.0}};
	//wcpt3d ctrlpts[4]={{20.0,20.0,0.0},{40.0,40.0,0.0},{60.0,60.0,0.0},{10.0,10.0,0.0}};
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4);
	glColor3f(1.0,0.0,0.0);
	bezier(ctrlpts,nctrlpts,nbezcurvepts);
	glFlush();
}
void winreshapefnc(GLint newwidth,GLint newheight)
{
	glViewport(0,0,newheight,newheight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xwcmin,xwcmax,ywcmin,ywcmax);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(winwidth,winheight);
	glutInitWindowPosition(50,50);
	glutCreateWindow("BAZIER");
	init();
	glutDisplayFunc(displayfnc);
	glutReshapeFunc(winreshapefnc);
	glutMainLoop();
	return 0;
}
