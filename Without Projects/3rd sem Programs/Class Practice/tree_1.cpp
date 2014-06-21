#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

struct node
{
    int info;
    struct node* llink;
    struct node* rlink;
};

typedef struct node* NODE;

NODE getnode()
{
    NODE x= (NODE)malloc(sizeof(node));
    if(!x)
        cout<<"Out of memory :(";
    return x;
}

NODE create_rec()
{
    int info;
    NODE t;
    scanf("%d",&info);
    if(info==-1)
        return NULL;
    t=getnode();
    t->info=info;
    printf("Enter left child for node %d\n",info);
    t->llink=create_rec();
    printf("Enter right child for node %d\n",info);
    t->rlink=create_rec();
    return t;
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\t",root->info);
        inorder(root->rlink);
    }
    else
        return;
}

int main()
{
    NODE root;
    printf("Enter root for the tree\n");
    root=create_rec();

    printf("Inorder traversal is:\n");
    inorder(root);
}







