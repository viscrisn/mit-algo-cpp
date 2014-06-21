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

void LL_sort(node **head)
{
    node *cur = *head;
    int vals[3] = {};
    while(cur!=NULL)
    {
        vals[cur->val]++;
        cur = cur->link;
    }
    cur = *head;
    int vals_index;
    if(vals[0]!=0)
        vals_index = 0;
    else
        vals_index = 1;
    while(cur!=NULL)
    {
        if(vals[vals_index]==0)
            vals_index++;
        cur->val = vals_index;
        vals[vals_index]--;
        cur = cur->link;
    }
}
int main()
{
    node *head=NULL;
    insert_rear(&head,1);
    insert_rear(&head,0);
    insert_front(&head,2);
    insert_rear(&head,2);
    insert_front(&head,2);
    insert_front(&head,1);

    display(head);

    LL_sort(&head);

    display(head);
}

