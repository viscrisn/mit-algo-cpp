#include<stdio.h>
#include<conio.h>
#include<process.h>

#define TRUE 1
#define FALSE 0
short int visited_dfs[26],visited_bfs[26];

struct GNode
{
	char vertex;
	struct GNode *next;
};
typedef struct GNode *GNODEPTR;

void dfs(char c,GNODEPTR *graph)
{
	GNODEPTR w;
	int v;
	v=((int)c)-97;
	visited_dfs[v]=TRUE;
	printf("%c\t",c);
	for(w=graph[v];w;w=w->next)
	{
		v=((int)(w->vertex))-97;
		if(!visited_dfs[v])
		{
			dfs(w->vertex,graph);
		}
	}
}

void addq(int *r,GNODEPTR q[],GNODEPTR g)
{
	q[++(*r)]=g;
}
GNODEPTR deleteq(int *f,int *r,GNODEPTR q[])
{
	GNODEPTR t;
	if(*f>*r)
	{
		printf("\nNo Element");
		return NULL;
	}
	t=q[(*f)++];
	if(*f>*r)
	{
		*f=0;
		*r=-1;
	}
	return t;
}
void bfs(char c,GNODEPTR *graph)
{
	GNODEPTR q[26],w;
	int f,r,v;
	f=0;
	r=-1;
	v=((int)c)-97;
	printf("%c\t",c);
	visited_bfs[v]=TRUE;
	addq(&r,q,graph[v]);
	while(f<=r)
	{
		w=deleteq(&f,&r,q);
		for(;w;w=w->next)
		{
			v=((int)(w->vertex))-97;
			if(!visited_bfs[v])
			{
				printf("%c\t",w->vertex);
				addq(&r,q,graph[v]);
				visited_bfs[v]=TRUE;
			}
		}
	}
}

void main()
{
	int n,i;
	char v,a[100];
	GNODEPTR *graph,temp,tail;
	clrscr();
	printf("\nEnter the no. of vertices :-\t");
	scanf("%d",&n);
	flushall();
	if(n>0)
	{
		printf("\nEnter all the vertices :-\n");
		for(i=0;i<n;i++)
		{
			scanf("%c",&a[i]);
			flushall();
		}
		graph=(GNODEPTR*)calloc(n,sizeof(GNODEPTR));
		for(i=0;i<n;i++)
		{
			flushall();
			printf("\nEnter the adjacent vertices of %c (Please enter '0' to exit) :-\n",a[i]);
			while(1)
			{
				scanf("%c",&v);
				flushall();
				if(v=='0')
					break;
				temp=(GNODEPTR)malloc(sizeof(struct GNode));
				temp->vertex=v;
				temp->next=NULL;
				if(graph[i]==NULL)
					graph[i]=temp;
				else
					tail->next=temp;
				tail=temp;
			}
		}
		printf("\nEnter the vertex from which you want to start DFS & BFS :-\t");
		scanf("%c",&v);
		flushall();
		printf("\nD.F.S. :-\t");
		dfs(v,graph);
		printf("\nB.F.S. :-\t");
		bfs(v,graph);
	}
	printf("\nPress 'Enter' to exit...");
	getch();
}
