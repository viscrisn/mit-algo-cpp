#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
typedef struct node* nodeptr;

void depthfirstsearch (nodeptr*,nodeptr, int* );

int count=0,pos=0;
int topo[20];
nodeptr createnode (int info)
{
	nodeptr temp;
	temp=(nodeptr) malloc (sizeof (struct node));
	temp->data=info;
	temp->next=NULL;
	return temp;
}

nodeptr addtolist (nodeptr head, int data)
{
	nodeptr temp = createnode (data), cur=head;
	while (cur->next != NULL)
		cur=cur->next;
	cur->next=temp;
	return head;
}

nodeptr* creategraph (int v)
{
	int i,k;
	nodeptr* adjlist = (nodeptr*) malloc (sizeof (nodeptr)*v);
	printf("Enter the Verticies\n");
	for (i=0;i<v;i++)
	{
		scanf("%d",&k);
		adjlist[i] = createnode (k);
	}
	for (i=0;i<v;i++)
	{
		printf("Enter the connections for %d \n",adjlist[i]->data);
		printf("Enter -1 to stop\n");
		while (1)
		{
			scanf("%d",&k);
			if (k==-1)
				break;
			adjlist[i]=addtolist(adjlist[i],k);
		}
	}
	return adjlist;
}

void display (nodeptr* adjlist, int v)
{
	nodeptr cur;
	int i;
	for (i=0;i<v;i++)
	{
		cur=adjlist[i];
		while (cur!=NULL)
		{
			printf("%d ->  ",cur->data);
			cur=cur->next;
		}
		printf("\n");
	}
}

void dfs (nodeptr* adjlist, int visited[], int v)
{
	count=0;  int i,key;
	printf("Enter node to start from \n");
	scanf("%d",&key);
	for (i=0;i<v;i++)
	{
		if (visited[adjlist[key]->data] == 0)
			depthfirstsearch(adjlist, adjlist[key], visited);
		key++;
		if (key>=v)
			key=0;
	}
}

void depthfirstsearch (nodeptr* adjlist,nodeptr temp, int visited[])
{
	count=1;
	visited[temp->data]=count;
	printf("%d   ",temp->data);
	nodeptr prev=temp;
	while (temp!=NULL)
	{
		if (visited[temp->data]==0)
			depthfirstsearch(adjlist, adjlist[temp->data], visited);
		temp=temp->next;
	}
	topo[pos++] = prev->data;
}



int main ()
{
	nodeptr* adjlist;
	int v,i;
	topo[0] = -1;
	printf("Enter number of verticies : ");
	scanf("%d",&v);
	adjlist = creategraph (v);
	display(adjlist, v);
	int *visited=(int*) malloc (sizeof(int)*v);
	for (i=0;i<v;i++)
		visited[i]=0;
	dfs (adjlist, visited, v);
	printf("\nTopological Order : ");
	for (i=v-1;i>=0;i--)
		printf("%d  ",topo[i]);
	printf("\n");
	return 0;
}
