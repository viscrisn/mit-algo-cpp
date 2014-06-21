#include<stdio.h>
#include<process.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

struct node
{
    char info;
    struct node* llink;
    struct node* rlink;
};

typedef node* NODEPTR;

NODEPTR create_exp_tree(char[]);
void inorder(NODEPTR);
NODEPTR getnode();


int main()
{
    NODEPTR root;
    char postfix[20];
    cout<<"Enter postfix expression\n";
    cin>>postfix;

    root=create_exp_tree(postfix);
    cout<<"Inorder traversal is:\n";
    inorder(root);

}

void inorder(NODEPTR root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        cout<<root->info;
        inorder(root->rlink);
    }
}

NODEPTR getnode()
{
    NODEPTR x;
    x= (NODEPTR)malloc(sizeof(node));
    return x;
}

NODEPTR create_exp_tree(char postfix[])
{
    NODEPTR temp;
    NODEPTR st[20];
    int top=-1;
    for(int i=0;postfix[i]!='\0';i++)
    {
        temp=getnode();
        temp->info=postfix[i];
        temp->llink=temp->rlink=NULL;
        if(isalnum(postfix[i]))
        {
            st[++top]=temp;
        }
        else
        {
            temp->rlink=st[top--];
            temp->llink=st[top--];
            st[++top]=temp;
        }
    }
    return st[top--];
}










