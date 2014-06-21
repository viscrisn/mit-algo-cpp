#include<GL/glu.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#define WINDOW_HEIGHT 300
using namespace std;


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,400.0,0.0,300.0);
}

void setPixel(int x, int y){
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}

typedef struct tEdge
{
	int yUpper;
	float xIntersect,dxPerScan;
	struct tEdge * next;
}Edge;

struct dcPt
{
	int x, y;
};

void insertEdge(Edge *list,Edge *edge)
{
	Edge *p,*q=list;
	p=q->next;
	while(p!=NULL)
	{
		if(edge->xIntersect<p->xIntersect)
		p=NULL;
		else
		{
			q=p;
			p=p->next;
		}
	}
	edge->next=q->next;
	q->next=edge;
}

int yNext(int k,int cnt,dcPt *pts)
{
	int j;
	if((k+1)>(cnt-1))
	j=0;
	else
	j=k+1;
	while(pts[k].y==pts[j].y)
		if((j+1)>(cnt-1))
		j=0;
		else
		j++;
	return(pts[j].y);
}

void makeEdgeRec(dcPt lower,dcPt upper,int yComp,Edge *edge,Edge *edges[])
{
	edge->dxPerScan=(float) (upper.x-lower.x)/(upper.y-lower.y);
	edge->xIntersect=lower.x;
	if(upper.y<yComp)
		edge->yUpper=upper.y-1;
	else
		edge->yUpper=upper.y;
	insertEdge(edges[lower.y],edge);
}

void buildEdgeList(int cnt,dcPt *pts,Edge *edges[])
{
	Edge *edge;
	dcPt v1,v2;
	int i,yPrev=pts[cnt-2].y;
	
	v1.x=pts[cnt-1].x;
	v1.y=pts[cnt-1].y;
	for(i=0;i<cnt;i++)
	{
		v2=pts[i];
		if(v1.y!=v2.y)
		{
			edge=(Edge *) malloc (sizeof (Edge));
			if(v1.y<v2.y)
			makeEdgeRec(v1,v2,yNext(i,cnt,pts),edge,edges);
			else
			makeEdgeRec(v2,v1,yPrev,edge,edges);
		}
		yPrev=v1.y;
		v1=v2;
	}
}
void buildActiveList(int scan,Edge *active,Edge *edges[])
{
	Edge *p,*q;
	p=edges[scan]->next;
	while(p)
	{
		q=p->next;
		insertEdge(active,p);
		p=q;
	}
}

void fillScan(int scan,Edge *active)
{
	Edge *p1,*p2;
	int i;
	p1=active->next;
	while(p1)
	{
		p2=p1->next;
		for(i=p1->xIntersect;i<p2->xIntersect;i++)
		setPixel((int) i,scan);
		p1=p2->next;
	}
}

void deleteAfter(Edge *q){
	Edge *p = q->next;
	q->next = p->next;
	delete p;
}

void updateActiveList(int scan,Edge *active)
{
	Edge *q=active,*p=active->next;
	while(p)
		if(scan >=p->yUpper)
		{
			p=p->next;
			deleteAfter(q);
		}
		else
		{
			p->xIntersect=p->xIntersect+p->dxPerScan;
			q=p;
			p=p->next;
		}
}

void resortActiveList(Edge *active)
{
	Edge *q,*p=active->next;
	active->next=NULL;
	while(p)
	{
		q=p->next;
		insertEdge(active,p);
		p=q;
	}
}

void scanFill(int cnt,dcPt *pts)
{
	Edge *edges[WINDOW_HEIGHT],*active;
	int i,scan;
	for(i=0;i<WINDOW_HEIGHT;i++)
	{
		edges[i]=new Edge;
		edges[i]->next=NULL;
	}
	buildEdgeList(cnt,pts,edges);
	active=(Edge *)malloc(sizeof(Edge));
	active->next=NULL;
	
	for(scan=0;scan<WINDOW_HEIGHT;scan++)
	{
		buildActiveList(scan,active,edges);
		if(active->next)
		{
			fillScan(scan,active);
			updateActiveList(scan,active);
			resortActiveList(active);
		}
	}
}

void display(){
	int cnt;
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<"Enter no. of vertices: ";
	cin>>cnt;
	dcPt* pts = new dcPt[cnt];
	cout<<"Enter value of vertices: ";
	int x,y;
	for(int i=0;i<cnt;i++)
	{
		cout<<"x=";
		cin>>x;
		cout<<"y=";
		cin>>y;
		pts[i].x = x;
		pts[i].y = y;
	}
	scanFill(cnt,pts);
	usleep(5);
	glEnd();
	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,300);
	glutCreateWindow("ScanFill");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
