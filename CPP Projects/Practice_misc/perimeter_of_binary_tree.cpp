#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}

void insert(node *root,int val_temp)
{
    node *temp = getnode();
    temp->val = val_temp;
    temp->left = NULL;
    temp->right = NULL;
    node *cur = root;
    while(1)
    {
        if(cur->left==NULL&&cur->right==NULL)
        {
            break;
        }
        if(val_temp > cur->val)
        {
            if(cur->right!=NULL)
            {
                cur = cur->right;
            }
            else
            {
                break;
            }
        }
        else if(val_temp < cur->val)
        {
            if(cur->left!=NULL)
            {
                cur = cur->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout<<"Error inserting values\n";
            exit(0);
        }
    }
    if(val_temp > cur->val)
    {
        cur->right = temp;
    }
    else
    {
        cur->left = temp;
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->val<<"\t";
        inorder(root->right);
    }
}

void perimeter_left(node *root)
{
    node *cur = root;
    while(cur->left!=NULL||cur->right!=NULL)
    {
        if(!(cur->left==NULL&&cur->right==NULL))
            cout<<cur->val<<"\t";
        if(cur->left != NULL)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}

void perimeter_leaf(node *root)
{
    if(root!=NULL)
    {
        perimeter_leaf(root->left);
        if(root->left==NULL&&root->right==NULL)
            cout<<root->val<<"\t";
        perimeter_leaf(root->right);
    }
}

void perimeter_right(node *root)
{
    node *cur = root;
    stack<int> stk;
    while(cur->left!=NULL||cur->right!=NULL)
    {
        if(!(cur->left==NULL&&cur->right==NULL)&&cur!=root)
            stk.push(cur->val);
        if(cur->right != NULL)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    while(stk.empty()!=true)
    {
        cout<<stk.top()<<"\t";
        stk.pop();
    }
}

void perimeter(node *root)
{
    perimeter_left(root);
    perimeter_leaf(root);
    perimeter_right(root);
}

int main()
{
	node *root = getnode();
	int val_temp;
	cout<<"Enter root value\n";
	cin>>val_temp;
	root->val = val_temp;
	root->left = NULL;
	root->right = NULL;
	cout<<"Enter nodes, -1 to terminate\n";
	cin>>val_temp;
	while(val_temp!=-1)
	{
	    insert(root,val_temp);
	    cin>>val_temp;
	}
	inorder(root);
    cout<<"\n";
    perimeter(root);
}

