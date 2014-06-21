#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
	int bf;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nMemory Error...");
		exit(0);
	}
	return x;
}

int max(int a,int b)
{
	return((a>b?a:b));
}

int height(NODE root)
{
	if(root==NULL)
		return 0;
	return (1+max(height(root->llink),height(root->rlink)));
}

NODE rotate(NODE root,char rot1)
{
	NODE temp,temp2,temp3,temp4;
	char rot2;
	if(rot1=='R')
	{
		if(root->rlink->bf>0)	//(height(root->rlink->llink)-height(root->rlink->rlink))>0)
		{
			rot2='L';
		}
		else
		{
			rot2='R';
		}
	}
	else
	{
		if(root->llink->bf>=0)	//(height(root->llink->llink)-height(root->llink->rlink))>=0)
		{
			rot2='L';
		}
		else
		{
			rot2='R';
		}
	}

	if(rot1=='L' && rot2=='L')
	{
		temp=root;
		root=root->llink;
		temp->llink=root->rlink;
		root->rlink=temp;
	}

	else if(rot1=='L' && rot2=='R')
	{
		temp=root;
		temp2=root->llink;
		root=temp2->rlink;
		temp3=root->llink;
		temp4=root->rlink;
		root->llink=temp2;
		root->rlink=temp;
		temp2->rlink=temp3;
		temp->llink=temp4;

	}

	if(rot1=='R' && rot2=='L')
	{
		temp=root;
		temp2=root->rlink;
		root=temp2->llink;
		temp3=root->rlink;
		temp4=root->llink;
		root->rlink=temp2;
		root->llink=temp;
		temp2->llink=temp3;
		temp->rlink=temp4;
	}

	else if(rot1=='R' && rot2=='R')
	{
		temp=root;
		root=root->rlink;
		temp->rlink=root->llink;
		root->llink=temp;
	}

	return root;
}

NODE insert(NODE root,int key)
{
	if(root==NULL)
	{
		root=getnode();
		root->llink=root->rlink=NULL;
		root->info=key;
		root->bf=0;
		return root;
	}
	else if(key<root->info)
	{
		root->llink=insert(root->llink,key);
		root->bf=height(root->llink)-height(root->rlink);
		if(root->bf<-1)
		{
			root=rotate(root,'R');
		}
		else if(root->bf>1)
		{
			root=rotate(root,'L');
		}
	}
	else if(key>root->info)
	{
		root->rlink=insert(root->rlink,key);
		root->bf=height(root->llink)-height(root->rlink);
		if(root->bf<-1)
		{
			root=rotate(root,'R');
		}
		else if(root->bf>1)
		{
			root=rotate(root,'L');
		}
	}
	else
		printf("\nDuplicate key...");
	return root;
}

/*int check_bf(NODE root)
{
	if(root==NULL)
		return 0;
	return check_bf(root->llink)+1;
	return check_bf(root->rlink)+1;
}*/

void inorder_display(NODE root)
{
	if(root==NULL)
		return;
	inorder_display(root->llink);
	printf("%d\t",root->info);
	inorder_display(root->rlink);
}

void postorder_display(NODE root)
{
	if(root==NULL)
		return;
	postorder_display(root->llink);
	postorder_display(root->rlink);
	printf("%d\t",root->info);
}

void preorder_display(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder_display(root->llink);
	preorder_display(root->rlink);
}

int main()
{
	int key;
	char ch='y';
	NODE root=NULL;
	while(ch=='y')
	{
		printf("Enter the element to inserted :- ");
		scanf("%d",&key);
		root=insert(root,key);
		printf("\n\nInorder :-\n");
		inorder_display(root);
		printf("\nPre-Order :-\n");
		preorder_display(root);
		printf("\nPost-Order :-\n");
		postorder_display(root);
		printf("\n\n");
		printf("Want to insert more (y/n)???\t");
		scanf("%c",&ch);
	}
	getch();
}
