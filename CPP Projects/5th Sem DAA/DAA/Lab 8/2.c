#include <stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node* next;
};
typedef node* nodeptr;

void addtoTable (nodeptr, int);

nodeptr createnode (int i)
{
	nodeptr temp = new node();
	if (temp == NULL)
	{
		printf("Memory Error\n");
		exit(0);
	}
	temp->data=i;
	temp->next=NULL;
	return temp;
}

nodeptr* hashing (int* list, int n, int hf)
{
	int i,k;
	nodeptr* table;
	table = new nodeptr [hf];
	for (i=0; i<hf; i++)
		table[i] = createnode(0);
	for (i=0; i<n; i++)
	{
	    k = list[i] % hf;
	    addtoTable(table[list[i]%hf], list[i]);
	}
	return table;
}

void addtoTable (nodeptr temp, int data)
{
    nodeptr cur = temp, prev;
    cur->data++;
    while (cur!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next = createnode(data);
}

void display (nodeptr* table, int hf)
{
    int i;
    nodeptr temp;
    for (i=0; i<hf; i++)
    {
        temp = table[i];
        while (temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search (nodeptr* table, int hf)
{
    int j,k,comparison=0;
    nodeptr temp;
    printf("Enter key to search for : ");
    scanf("%d",&k);
    temp = table [k%hf];
    temp=temp->next;
    while (temp != NULL)
    {
        comparison++;
        if (temp->data == k)
        {
            j=1; break;
        }
        temp=temp->next;
    }
    if (j==1)
    {
        printf("FOUND...\nNo. of Comparisons = %d",comparison);
    }
    else
        printf("NOT FOUND...\nNo. of Comparisons = %d",comparison);
}

int main ()
{
    int hf, *list, n, i;
    nodeptr* table;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    list = new int [n];
    printf("Enter the elements\n");
    for (i=0;i<n;i++)
        scanf("%d",&list[i]);
	printf("Enter hash function value : ");
	scanf("%d",&hf);
    table = hashing (list,n,hf);
    display (table, hf);
    search (table, hf);
    return 0;
}

