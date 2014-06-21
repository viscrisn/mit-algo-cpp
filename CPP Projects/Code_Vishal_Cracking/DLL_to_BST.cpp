#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

bool insert_front(node **head,int val)
{
    node *temp = new node;
    if(!temp)
        return false;
    temp->val = val;
    temp->prev = NULL;
    temp->next = NULL;
    if(*head == NULL)
    {
        *head = temp;
        return true;
    }
    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
    return true;
}

bool insert_rear(node **head,int val)
{
    node *temp = new node;
    if(!temp)
        return false;
    temp->val = val;
    temp->prev = NULL;
    temp->next = NULL;
    if(*head==NULL)
    {
        *head = temp;
        return true;
    }
    node *cur = *head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return true;
}

bool delete_front(node **head)
{
    if(*head == NULL)
        return false;
    node *cur = *head;
    *head = (*head)->next;
    if(*head!=NULL)
        (*head)->prev = NULL;
    delete cur;
    return true;
}

bool delete_rear(node **head)
{
    if(*head==NULL)
        return false;
    node *cur = *head;
    while(cur->next!=NULL)
        cur = cur->next;
    if(cur == *head)
    {
        *head = NULL;
        delete cur;
        return true;
    }
    cur->prev->next = NULL;
    delete cur;
    return true;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"\t";
        head = head->next;
    }
}

node *DLL_to_BST(node *head)
{
    if(head==NULL)
        return NULL;
    int len = 1;
    node *cur = head;
    while(cur->next!=NULL)
    {
        len++;
        cur = cur->next;
    }
    cur = head;
    for(int i =0;i<len/2;i++)
    {
        cur = cur->next;
    }
    if(cur->prev!=NULL)
        cur->prev->next = NULL;
    if(cur->next!=NULL)
        cur->next->prev = NULL;
    if(len>1)
    {
        cur->prev = DLL_to_BST(head);
        cur->next = DLL_to_BST(cur->next);
    }
    return cur;
}

void inorder(node *head)
{
    if(head!=NULL)
    {
        inorder(head->prev);
        cout<<head->val<<"\t";
        inorder(head->next);
    }
}

void preorder(node *head)
{
    if(head!=NULL)
    {
        cout<<head->val<<"\t";
        preorder(head->prev);
        preorder(head->next);
    }
}

int main()
{
    node *head=NULL;
    insert_rear(&head,4);
    insert_rear(&head,5);
    insert_front(&head,3);
    //insert_front(head,3);//To pass head by reference
    insert_rear(&head,6);
    insert_front(&head,2);
    insert_front(&head,1);
    insert_rear(&head,7);

    display(head);
    cout<<endl;

    head = DLL_to_BST(head);
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
}

