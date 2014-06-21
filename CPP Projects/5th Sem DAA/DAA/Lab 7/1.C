#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Tree23
{
	int a,b;
	int count,count_child;
	struct Tree23 *l,*r,*m;
};
typedef struct Tree23 *tree;
tree getnode(int item)
{
	tree temp=(tree)malloc(sizeof(struct Tree23));
	if(temp==NULL)
	{
		printf("\nmemory Error...");
		exit(0);
	}
	temp->a=item;
	temp->count=1;
	temp->count_child=0;
	temp->l=temp->r=temp->m=NULL;
	return temp;
}

tree insert(int item,tree root)
{
	tree temp1,temp2;
	if(root==NULL)
	{
		temp1=getnode(item);
		return temp1;
	}
	 else if(root->count==1 && root->count_child==0)
	{
		if(item<root->a)
		{
			root->b=root->a;
			root->a=item;
		}
		else
			root->b=item;
		root->count++;
		return root;
	}
	else if(root->count==2 && root->count_child==0)
	{
		root->count--;
		root->count_child+=2;
		if(item>root->b)
		{
			temp1=getnode(root->a);
			temp2=getnode(item);
			root->a=root->b;
			root->l=temp1;
			root->r=temp2;
		}
		else if(item<root->a)
		{
			temp1=getnode(item);
			temp2=getnode(root->b);
			root->l=temp1;
			root->r=temp2;
		}
		else
		{
			temp1=getnode(root->a);
			temp2=getnode(root->b);
			root->a=item;
			root->l=temp1;
			root->r=temp2;
		}
		return root;
	}
	else 
	{
		if(root->count==1)
		{
			if(item<root->a)
			{
				root->l=insert(item,root->l);
			}
			else
			{
				root->r=insert(item,root->r);
			}
			
			if(root->l->count==1 && root->l->count_child>0)
		{			
			temp1=root->l;
			root->b=root->a;
			root->a=root->l->a;
			root->m=root->l->r;
			root->l=root->l->l;
			free(temp1);
			root->count=2;
			root->count_child=3;
		}
			
			
			else if(root->r->count==1 && root->r->count_child>0)
		{
			temp2=root->r;
			root->b=root->r->a;
			root->m=root->r->l;
			root->r=root->r->r;
			free(temp2);
			root->count=2;
			root->count_child=3;
		}
			
			
			
			
		}
		else if(root->count==2)
		{
			if(item<root->a)
				root->l=insert(item,root->l);
			else if(item>root->b)
				root->r=insert(item,root->r);
			else
				root->m=insert(item,root->m);

		/*if(root->l->count==1 && root->l->count_child>0)
		{
			temp1=root->l;
			root->b=root->a;
			root->a=root->l->a;
			root->m=root->l->r;
			root->l=root->l->l;
			free(temp1);
			root->count=2;
			root->count_child=3;
		}*/

		if(root->m->count==1 && root->m->count_child>0)
		{
			temp1=getnode(root->a);
			temp2=getnode(root->b);
			root->a=root->m->a;
			temp1->l=root->l;
			temp1->r=root->m->l;
			temp2->l=root->m->r;
			temp2->r=root->r;
			root->l=temp1;
			root->r=temp2;
			root->count=1;
			root->count_child=2;
			free(root->m);
			root->m=NULL;
		}
		
		/*else if(root->r->count==1 && root->r->count_child>0)
		{
			temp2=root->r;
			root->b=root->r->a;
			root->m=root->r->l;
			root->r=root->r->r;
			free(temp2);
			root->count=2;
			root->count_child=3;
		}*/
	}
		return root;
	}
}

void display(tree root)
{
	if(root==NULL)
		return;
	printf("_");
	display(root->l);
	if(root->count==1)
	{
		printf("%d",root->a);
	}
	else
	{
		printf("%d->",root->a);
		display(root->m);
		printf("<-%d",root->b);
	}
	display(root->r);
	printf("_");
}

void main()
{
	int item;
	char ch;
	tree root;
	clrscr();
	root=NULL;
	while(1)
	{
		printf("\nEnter the item to be inserted :-  ");
		scanf("%d",&item);
		root=insert(item,root);
		display(root);
		flushall();
		printf("\nWant to insert more (y/n) ?   ");
		scanf("%c",&ch);
		flushall();
		if(ch=='n')
			break;
	}
	getch();
}
