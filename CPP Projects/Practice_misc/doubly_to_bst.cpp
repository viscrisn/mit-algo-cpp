#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

// 42 mins to code the algo. Thinking for the algo took 35 mins.

//working awesome!
//1-11-2012 09:59- started
//1-11-2012 10:43- finished
using namespace std;

struct node
{
    int value;
    struct node* left;
    struct node* right;
};

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}

void add(node* head,int val)
{
    node* cur=head;
    node* temp = getnode();
    temp->value = val;

    while(cur->right!=NULL)
    {
        cur = cur->right;
    }
    temp->left = cur;
    temp->right = NULL;
    cur->right = temp;
}
void display(node* head)
{
    node* cur = head;
    while(cur!=NULL)
    {
        cout<<cur->value<<"\t";
        cur= cur->right;
    }
}

void inorder(node* head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        cout<<head->value<<"\t";
        inorder(head->right);
    }
}
void preorder(node* head)
{
    if(head!=NULL)
    {
        cout<<head->value<<"\t";
        preorder(head->left);
        preorder(head->right);
    }
}

void fill_array(node* head, int array[],int len)
{
    int i=0;
    node* cur = head;
    while(cur!=NULL)
    {
        array[i++] = cur->value;
        cur = cur-> right;
    }
}

void inorder_sort(node* head, int array[],int len)
{
    if(head!=NULL)
    {
        inorder_sort(head->left,array,len);
        int min=999;
        int min_index=0;
        for (int i=0; i<len; i++ )
        {
            if(min>array[i])
            {
                min = array[i];
                min_index = i;
            }
        }
        //If array was already sorted, just take next element.
        //Time complexity in that case = O(n)
        //Current complexity: O(nlogn)
        array[min_index] = 999;
        if(head->value!=min)
        {
            head->value = min;
        }
        inorder_sort(head->right,array,len);
    }
}
node* double_to_BST(node* head)
{
    node* cur = head;
    int len=0;
    while(cur!=NULL)
    {
        len++;
        cur= cur->right;
    }
    int array[len];
    fill_array(head,array,len);
    node * index[len+1];
    cur = head;
    for (int i=1; i<=len; i++ )
    {
        index[i] = cur;
        cur = cur->right;
    }
    for (int i=1; i<=len; i++ )
    {
        if(i>len/2)
        {
            index[i]->left = NULL;
            index[i]->right = NULL;
        }
        else
        {
            index[i]->left = index[2*i];
            index[i]->right = index[2*i+1];
        }
    }
    cout<<"Converted to a complete Binary tree:\n";
    inorder(index[1]);
    cout<<endl;
    inorder_sort(index[1],array,len);
    return index[1];
}
int main()
{
    node *head = getnode();
    head->value = 10;
    head->left = NULL;
    head->right = NULL;

    add(head,4);
    add(head,7);
    add(head,2);
    add(head,9);
    add(head,8);
    add(head,3);

    cout<<"Doubly Linked list:\n";
    display(head);
    cout<<endl;
    head = double_to_BST(head);
    cout<<"Converted to a complete Binary Search tree:\n";
    cout<<"Inorder:\n";
    inorder(head);
    cout<<endl;
    cout<<"Preorder:\n";
    preorder(head);
}
