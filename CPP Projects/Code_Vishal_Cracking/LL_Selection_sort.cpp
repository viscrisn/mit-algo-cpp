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

void selection_sort(node **head)
{
    node *index_i, *index_j, *temp, *prev;
    int node_sorted = 0;
    index_i = *head;
    while(index_i->link != NULL)
    {
        index_j = *head;
        int flag =0;
        int min = 999999999;
        for (int i=0;i<node_sorted;i++ )
        {
            index_j = index_j->link;
            if(index_j->link==NULL)
                return;
        }
        //Won't work for 1 node. Add special condition
        while(index_j->link!=NULL)
        {
            if(min > index_j->link->val)
            {
                prev = index_j;
                temp = index_j->link;
                min = index_j->link->val;
            }
            index_j = index_j->link;
        }
        index_j = *head;
        for (int i=0;i<node_sorted;i++ )
        {
            if(index_j->link->val > min)
                break;
        	index_j = index_j->link;
        }
        prev->link = temp->link;
        if(node_sorted==0 && (*head)->val > min)
        {
            temp->link = *head;
            *head = temp;
        }
        else
        {
            temp->link = index_j->link;
            index_j->link = temp;
        }
        node_sorted++;
        //display(*head);
    }
}

int main()
{
    node *head=NULL;
    insert_rear(&head,1);
    insert_rear(&head,5);
    insert_front(&head,6);
    insert_rear(&head,3);
    insert_front(&head,2);
    insert_front(&head,4);
    display(head);

    selection_sort(&head);
    display(head);
}

