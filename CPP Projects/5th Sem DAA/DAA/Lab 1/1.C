#include<stdio.h>

struct node
{
	int info;
	struct node *next;
	struct node *prev;
};

typedef struct node *NODEPTR;

NODEPTR getnode()
{
	NODEPTR x;
	x=(NODEPTR)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Memory Error...");
		exit(0);
	}
	return x;
}

NODEPTR insert_front(int item,NODEPTR head)
{
	NODEPTR temp=getnode();
	temp->info=item;
	temp->next=head->next;
	temp->prev=head;
	head->next->prev=temp;
	head->next=temp;
	return head;
}

NODEPTR insert_in_between(int ele,int item,NODEPTR head)
{
	NODEPTR t,temp;
	temp=getnode();
	temp->info=item;
	t=head->next;
	do
	{
		if(t->info==ele)
		{
			temp->prev=t->prev;
			temp->next=t;
			t->prev->next=temp;
			t->prev=temp;
			return head;
		}
		t=t->next;
	}while(t!=NULL);
	printf("Element %d NOT FOUND... %d cannot be inserted...",ele,item);
	free(temp);
	return head;
}

void display(NODEPTR head)		
{
	NODEPTR t=head->next;
	if(t==NULL)
	{
		printf("Empty List...");
		return;
	}
	while(t!=NULL)
	{
		printf("%d  ",t->info);
		t=t->next;
	}
}

NODEPTR delete_item(int item,NODEPTR head)
{
	NODEPTR t,cur;
	t=head->next;
	do
	{
		if(t->info==item)
		{
			cur=t->prev;
			t->prev->next=t->next;
			t->next->prev=t->prev;
			free(t);
			t=cur;
		}
		t=t->next;
	}while(t!=NULL);
	return head;
}
		

void search(int item,NODEPTR head)
{
	NODEPTR t=head->next;
	if(t==NULL)
	{
		printf("List Empty... Element Not Found...");
		return;
	}
	while(t!=NULL)
	{
		if(t->info==item)
		{
			printf("Element Found...");
			return;
		}
		t=t->next;
	}
	printf("Element Not Found...");
}

void main()
{
	int item,ch,ele;
	NODEPTR head=getnode();
	clrscr();
	head->next=head->prev=NULL;
	printf("   MENU\n");
	printf("1) Add element to the FRONT...\n2) Insert an element before an element\n");
	printf("3) Delete an element\n4) Search for an element\n5) Display...\n6) Exit...");
	do
	{
		printf("\nEnter choice :- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the item :- ");
				scanf("%d",&item);
				head=insert_front(item,head);
				break;
			case 2:	printf("Enter the no. before which the item is to be inserted :- ");
				scanf("%d",&ele);
				printf("Enter the element to be inserted before %d :- ",ele);
				scanf("%d",&item);
				head=insert_in_between(ele,item,head);
				break;
			case 3:	printf("Enter the element to be deleted :- ");
				scanf("%d",&item);
				head=delete_item(item,head);
				break;
			case 4:	printf("Enter an element to be searched for :- ");
				scanf("%d",&item);
				search(item,head);
				break;
			case 5:	display(head);
				break;
			case 6:	exit(0);
		}
	}while(1);
}