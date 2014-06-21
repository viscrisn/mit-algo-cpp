#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,150.0);
}

void Boat(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//BOAT
	glColor3f(1.0,0.0,0.5);
	glLineWidth(15);
	
	glBegin(GL_LINES);
		glVertex2i(10,50);
		glVertex2i(30,30);

		glVertex2i(30,30);
		glVertex2i(130,30);

		glVertex2i(130,30);
		glVertex2i(150,50);

		glVertex2i(150,50);
		glVertex2i(130,0);

		glVertex2i(130,0);
		glVertex2i(30,0);
		
		glVertex2i(30,0);
		glVertex2i(10,50);
		
		glVertex2i(10,50);
		glVertex2i(53,70);
		
		glVertex2i(30,30);
		glVertex2i(50,40);
		
		glVertex2i(150,50);
		glVertex2i(110,50);
		
		glVertex2i(100,50);
		glVertex2i(90,50);
	glEnd();
	
	//FLAG
	glColor3f(0.0,1.0,0.0);
	glLineWidth(20);
	glBegin(GL_LINES);
		glVertex2i(100,30);
		glVertex2i(100,100);

		glVertex2i(110,30);
		glVertex2i(110,100);

		glVertex2i(100,100);
		glVertex2i(130,100);

		glVertex2i(130,100);
		glVertex2i(130,80);

		glVertex2i(130,80);
		glVertex2i(110,80);
		
		glVertex2i(110,90);
		glVertex2i(130,90);
	glEnd();
	
	
	//HOUSE
	glColor3f(1.0,0.0,0.0);
	glLineWidth(1);
	glBegin(GL_LINES);
	
		glVertex2i(50,30);
		glVertex2i(50,60);

		glVertex2i(50,60);
		glVertex2i(60,90);
		
		glVertex2i(50,60);
		glVertex2i(70,60);
		
		glVertex2i(60,90);
		glVertex2i(70,60);
		
		glVertex2i(70,60);
		glVertex2i(70,30);

		glVertex2i(70,30);
		glVertex2i(90,40);
		
		glVertex2i(90,40);
		glVertex2i(90,70);
		
		glVertex2i(70,60);
		glVertex2i(90,70);
		
		glVertex2i(90,70);
		glVertex2i(80,100);
		
		glVertex2i(60,90);
		glVertex2i(80,100);
		
		glVertex2i(57,30);
		glVertex2i(57,50);
		
		glVertex2i(63,30);
		glVertex2i(63,50);
		
		glVertex2i(60,30);
		glVertex2i(60,50);
		
		glVertex2i(57,40);
		glVertex2i(63,40);
		
		glVertex2i(57,50);
		glVertex2i(63,50);
		
		glVertex2i(52,40);
		glVertex2i(52,50);
		
		glVertex2i(52,50);
		glVertex2i(55,50);
		
		glVertex2i(55,50);
		glVertex2i(55,40);
		
		glVertex2i(55,40);
		glVertex2i(52,40);
		
		glVertex2i(52,45);
		glVertex2i(55,45);
		
		glVertex2i(53,40);
		glVertex2i(53,50);
		
		glVertex2i(54,40);
		glVertex2i(54,50);
		
		glVertex2i(65,40);
		glVertex2i(65,50);
		
		glVertex2i(65,50);
		glVertex2i(68,50);
		
		glVertex2i(68,50);
		glVertex2i(68,40);
		
		glVertex2i(68,40);
		glVertex2i(65,40);
		
		glVertex2i(65,45);
		glVertex2i(68,45);
		
		glVertex2i(66,40);
		glVertex2i(66,50);
		
		glVertex2i(67,40);
		glVertex2i(67,50);
		
		glVertex2i(75,42);
		glVertex2i(85,48);
		
		
		glVertex2i(75,52);
		glVertex2i(85,58);
		
		
		glVertex2i(75,47);
		glVertex2i(85,53);
		
		glVertex2i(78,54);
		glVertex2i(78,44);
		
		glVertex2i(83,57);
		glVertex2i(83,47);
		
		glVertex2i(75,52);
		glVertex2i(75,42);
		
		glVertex2i(85,58);
		glVertex2i(85,48);
		
		glVertex2i(62,84);
		glVertex2i(82,94);
		
		glVertex2i(64,78);
		glVertex2i(84,88);
		
		glVertex2i(66,72);
		glVertex2i(86,82);
		
		glVertex2i(68,66);
		glVertex2i(88,76);
		
		glVertex2i(64,92);
		glVertex2i(74,62);
		
		glVertex2i(68,94);
		glVertex2i(78,64);
		
		glVertex2i(72,96);
		glVertex2i(82,66);
		
		glVertex2i(76,98);
		glVertex2i(86,68);
		
	glEnd();
	glFlush();
}



int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1300,715);
	glutCreateWindow("HOUSE BOAT FLAG");
	init();
	glutDisplayFunc(Boat);
	glutMainLoop();
}
