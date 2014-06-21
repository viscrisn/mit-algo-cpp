//3-D Transformation
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<iostream>

using namespace std;

struct Vertex
{
	int x,y,z;
}*Obj;

void translation(int tx,int ty,int tz)
{
	for(int i=0;i<10;i++)
	{
		Obj[i].x+=tx;
		Obj[i].y+=ty;
		Obj[i].z+=tz;
	}
}

void scaling(int sx,int sy,int sz)
{
	for(int i=0;i<10;i++)
	{
		Obj[i].x*=sx;
		Obj[i].y*=sy;
		Obj[i].z*=sz;
	}
}

void rotation(float angle,char ch)
{
	int tmp;
	for(int i=0;i<10;i++)
	{
		switch(ch)
		{
			case 'Z':   tmp=Obj[i].x;
						Obj[i].x=Obj[i].x*cos(angle)-Obj[i].y*sin(angle);
						Obj[i].y=tmp*sin(angle)+Obj[i].y*cos(angle);
						break;
						
			case 'Y':   tmp=Obj[i].z;
						Obj[i].z=Obj[i].z*cos(angle)-Obj[i].x*sin(angle);
						Obj[i].x=tmp*sin(angle)+Obj[i].x*cos(angle);
						break;
							
			case 'X':   tmp=Obj[i].y;
						Obj[i].y=Obj[i].y*cos(angle)-Obj[i].z*sin(angle);
						Obj[i].z=tmp*sin(angle)+Obj[i].z*cos(angle);
						break;
		}
	}	
}

void reflect(char code)
{
	for(int i=0;i<10;i++)
	{
		if(code == 'Z')
			Obj[i].z*=(-1);
		else if(code == 'X')
			Obj[i].x*=(-1);	
		else
			Obj[i].y*=(-1);
	}
}

void shear(float sh1,float sh2,char code)
{
	for(int i=0;i<10;i++)
	{
		if(code == 'Z')
		{
			Obj[i].x+=((float)sh1*Obj[i].z);
			Obj[i].y+=((float)sh2*Obj[i].z);
		}
		else if(code == 'X')
		{
			Obj[i].x+=((float)sh1*Obj[i].y);
			Obj[i].z+=((float)sh2*Obj[i].y);
		}
		else
		{
			Obj[i].y+=((float)sh1*Obj[i].x);
			Obj[i].z+=((float)sh2*Obj[i].x);
		}
	}
}

void drawLine(Vertex A,Vertex B)
{
	int x1 = A.x + A.z*(tan(63.5)*cos(45));
	int y1 = A.y + A.z*(tan(63.5)*sin(45));
	
	int x2 = B.x + B.z*(tan(63.5)*cos(45));
	int y2 = B.y + B.z*(tan(63.5)*sin(45));
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
	glFlush();
}

void drawHome(Vertex Obj[])
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-320,0);
	glVertex2i(320,0);
	glVertex2i(0,-240);
	glVertex2i(0,240);
	glEnd();
	glFlush();
	
	
	drawLine(Obj[0],Obj[1]);
	drawLine(Obj[1],Obj[5]);
	drawLine(Obj[5],Obj[4]);
	drawLine(Obj[4],Obj[0]);
	drawLine(Obj[2],Obj[3]);
	drawLine(Obj[3],Obj[7]);
	drawLine(Obj[7],Obj[6]);
	drawLine(Obj[6],Obj[2]);
	drawLine(Obj[2],Obj[0]);
	drawLine(Obj[3],Obj[1]);
	drawLine(Obj[7],Obj[5]);
	drawLine(Obj[6],Obj[4]);
	drawLine(Obj[2],Obj[8]);
	drawLine(Obj[6],Obj[8]);
	drawLine(Obj[3],Obj[9]);
	drawLine(Obj[7],Obj[9]);
	drawLine(Obj[8],Obj[9]);
}

void display()
{
	int c;
	while(true)
	{		
		cout<<"\n1.Translate\n2.Scale\n3.Rotate\n4.Reflection \n5.Shear \n6.Exit\n";
		cin>>c;
		char code;
		switch(c)
		{
			case 1:
					int tx,ty,tz;
					cout<<"Enter the x,y and z translation distances ";
					cin>>tx>>ty>>tz;
					translation(tx,ty,tz);
						
					glColor3f(1,0,0);
					drawHome(Obj);
					break;
				
			case 2:
					int sx,sy,sz,px,py,pz;
					cout<<"Enter the x,y and zscale factors\n";
					cin>>sx>>sy>>sz;
					cout<<"Enter the point which is to be kept fixed\n";
					cin>>px>>py>>pz;
					translation(-px,-py,-pz);
					scaling(sx,sy,sz);
					translation(px,py,pz);
					drawHome(Obj);
					break;
			
			case 3:
					int angle;
					
					cout<<"Enter the rotation angle (in degrees)\n";
					cin>>angle;
					cout<<"Enter The rotation axis 1.Z 2.Y 3.X\n";
					cin>>code;
					if(code == '1'|| code == '2'|| code =='3')
						code+=39;
					else if(code == 'x' ||code == 'y'||code == 'z')
						code-=32;
					
					rotation(angle,code);
					drawHome(Obj);
					break;
			
			case 4: 
					cout<<"Enter the Reflection Axis 1.Y 2.X 3.Z\n";
					cin>>code;
					if(code == '1'|| code == '2'|| code =='3')
						code+=39;
					else if(code == 'x' ||code == 'y'||code == 'z')
						code-=32;
					
					reflect(code);
					drawHome(Obj);
					break;
			
			case 5:
					float sh1,sh2;
					cout<<"Enter Shear Axis 1.X 2.Y 3.Z\n";
					cin>>code;
					if(code == '1'|| code == '2'|| code =='3')
						code+=39;
					else if(code == 'x' ||code == 'y'||code == 'z')
						code-=32;
					
					cout<<"\nEnter the shear factors ";
					cin>>sh1>>sh2;
					
					shear(sh1,sh2,code);
					drawHome(Obj);
					break;
			case 6: return;				
			
			default:
					break;
		}
	}
}


void Home()
{
	Obj = new Vertex[10];
	for(int m = 0;m<10;)
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++)
				{
					Obj[m].x = i*100;
					Obj[m].y = j*100;
					Obj[m].z = k*100;
					m++;
				}
	
	Obj[8].x=50;
	Obj[8].y=150;
	Obj[8].z=25;
	Obj[9].x=50;
	Obj[9].y=150;
	Obj[9].z=75;
	drawHome(Obj);
	display();
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300,300,-300,300);
}

int main(int argC, char **argv)
{
	glutInit(&argC,argv);
	glutInitWindowSize(600,600);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("3D - Transformation");
	init();
	glutDisplayFunc(&Home);
	glutMainLoop();
	return 0;
}
