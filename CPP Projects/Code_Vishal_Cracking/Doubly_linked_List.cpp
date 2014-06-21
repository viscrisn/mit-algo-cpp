#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Element
{
    int data;
    struct Element *prev;
    struct Element *next;
};

bool insert_front(Element **head,int data)
{
    Element *temp = new Element;
    if(!temp)
        return false;
    temp->data = data;
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

bool insert_rear(Element **head,int data)
{
    Element *temp = new Element;
    if(!temp)
        return false;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(*head==NULL)
    {
        *head = temp;
        return true;
    }
    Element *cur = *head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return true;
}

bool delete_front(Element **head)
{
    if(*head == NULL)
        return false;
    Element *cur = *head;
    *head = (*head)->next;
    if(*head!=NULL)
        (*head)->prev = NULL;
    delete cur;
    return true;
}

bool delete_rear(Element **head)
{
    if(*head==NULL)
        return false;
    Element *cur = *head;
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

void display(Element *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head = head->next;
    }
}
int main()
{
    Element *head=NULL;
    insert_rear(&head,4);
    insert_rear(&head,5);
    insert_front(&head,3);
    //insert_front(head,3);//To pass head by reference
    insert_rear(&head,6);
    insert_front(&head,2);
    insert_front(&head,1);

    display(head);
    cout<<endl;

    delete_front(&head);
    delete_rear(&head);
    display(head);
}
