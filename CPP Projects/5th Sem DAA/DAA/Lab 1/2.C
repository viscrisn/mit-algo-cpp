#include<stdio.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
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

NODE insert(int key,NODE root)
{
	NODE temp,cur,par;
	temp=getnode();
	temp->info=key;
	temp->llink=temp->rlink=NULL;
	if(!root)
		return temp;
	cur=root;
	par=NULL;
	while(cur!=NULL)
	{
		par=cur;
		if(cur->info==key)
		{
			printf("Duplicate Key...");
			return root;
		}
		cur=key>cur->info?cur->rlink:cur->llink;
	}
	if(key>par->info)
		par->rlink=temp;
	else
		par->llink=temp;
	return root;
}

void search(NODE cur,int num)
{
	if(cur->info==num)
	{
		printf("Element Found in the Tree...");
		return;
	}
	else if(num>cur->info)
		search(cur->rlink,num);
	else if(num<cur->info)
		search(cur->llink,num);
	else
		insert(num,cur);
}

void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}

void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);
}

void main()
{
	int key,ch;
	NODE root=NULL;
	clrscr();
	printf("     MENU\n");
	printf("1) Insert into BST\n2) Search for an element\n");
	printf("3) Display using PREORDER Traversal\n");
	printf("4) Display using INORDER Traversal\n");
	printf("5) Display using POSTORDER Traversal\n");
	printf("6) Exit\n");
	while(1)
	{
		printf("\nEnter choice :- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the element to inserted :- ");
				scanf("%d",&key);
				root=insert(key,root);
				break;
			case 2: if(root==NULL)
				{
					printf("\nTree Empty...");
					break;
				}
				printf("Enter the element to be searched :- ");
				scanf("%d",&key);
				search(root,key);
				break;
			case 3:	printf("Displaying using PREORDER Traversal :-  ");
				preorder(root);
				break;
			case 4:	printf("Displaying using INORDER Traversal :-  ");
				inorder(root);
				break;
			case 5:	printf("Displaying using POSTORDER Traversal :-  ");
				postorder(root);
				break;
			case 6:	exit(0);
		}
	}
}