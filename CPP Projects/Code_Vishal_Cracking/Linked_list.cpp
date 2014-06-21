#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node* link;
};

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}

void insert_front(node **head,int val)
{
    if((*head)==NULL)
    {
        (*head) = getnode();
        (*head)->val = val;
        (*head)->link = NULL;
        return;
    }
    node *temp = getnode();
    temp->val = val;
    temp->link = (*head);
    (*head) = temp;
}

void insert_rear(node **head,int val)
{
    if((*head)==NULL)
    {
        (*head) = getnode();
        (*head)->val = val;
        (*head)->link = NULL;
        return;
    }
    node *cur = (*head);
    while(cur->link!=NULL)
        cur = cur->link;
    node *temp = getnode();
    temp->val = val;
    temp->link = NULL;
    cur->link = temp;
}

void delete_val(node **head,int val)
{
    if((*head)==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    node *cur = (*head);
    node *prev;
    while((cur->link!=NULL) && cur->val != val)
    {
        prev = cur;
        cur = cur->link;

    }
    if(cur==NULL)
    {
        cout<<"Element is not present\n";
        return;
    }
    else if(cur->val == val)
    {
        prev->link = cur->link;
        free(cur);
    }
}

void delete_front(node **head)
{
    if((*head)==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    node *cur = (*head)->link;
    free(*head);
    (*head) = cur;
}

void delete_rear(node **head)
{
    if((*head)==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    node *cur = (*head);
    node *prev;
    while(cur->link!=NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    free(cur);
    prev->link = NULL;
}

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->link;
    }
    cout<<"\n";
}

int main()
{
    node *head=NULL;
    insert_rear(&head,4);
    insert_rear(&head,5);
    insert_front(&head,3);
    insert_rear(&head,6);
    insert_front(&head,2);
    insert_front(&head,1);

    display(head);

    delete_front(&head);
    delete_rear(&head);
    delete_val(&head,3);
    display(head);
}
