#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head = head->link;
    }

    cout<<'\n';
}

void insert_front(node **head,int ele)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = ele;
    temp->link =NULL;
    if(*head != NULL);
        temp->link = *head;
    *head = temp;
}

void create_circular_mid(node **head)
{
    int len = 0;
    node *cur = *head;
    if((*head)->link == NULL)
    {
        (*head)->link = *head;
        return;
    }

    while(cur->link!=NULL)
    {
        len++;
        cur = cur->link;
    }
    node *mid = *head;
    for(int i=0;i<len/2;i++)
    {
        mid = mid->link;
    }
    cur->link = mid;
}

void delete_mid(node **head)
{
    if(*head->link==NULL)
    {
        free(*head);
        return NULL;
    }

    node *slow=*head,*fast=*head->link;
    while(slow!=fast)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    slow = *head;
    while(slow->link!=fast->link)
    {
        slow = slow->link;
        fast = fast->link;
    }
}
int main()
{
    node *head = NULL;
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,6);
    insert_front(&head,5);
    insert_front(&head,1);

    display(head);

    create_circular_mid(&head);

}
