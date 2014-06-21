#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Element
{
    int data;
    struct Element *prev;
    struct Element *next;
    struct Element *child;
};

bool insert_front(Element **head,int data)
{
    Element *temp = new Element;
    if(!temp)
        return false;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    temp->child = NULL;
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
    temp->child = NULL;
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

void flaten_DLL(Element **head)
{
    Element *cur, *ahd, *itr;//ahd is not needed
    //cur->next gives ahd directly
    cur = *head;
    while(cur!=NULL)
    {
        if(cur->child!=NULL)
        {
            ahd = cur->next;
            itr = cur->child;
            while(itr->next!=NULL)
                itr = itr->next;
            itr ->next = ahd;
            if(ahd!=NULL)
                ahd->prev = itr;
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        cur = cur->next;
    }
}
int main()
{
    Element *head = NULL;
    insert_rear(&head,4);
    insert_rear(&head,5);
    insert_front(&head,3);
    insert_rear(&head,6);
    insert_front(&head,2);
    insert_front(&head,1);

    display(head);
    cout<<endl;

    delete_front(&head);
    delete_rear(&head);
    display(head);
    cout<<endl;

    Element *head2 = NULL;
    insert_rear(&head2,41);
    insert_rear(&head2,51);
    insert_front(&head2,31);
    insert_rear(&head2,61);
    insert_front(&head2,21);
    insert_front(&head2,11);
    display(head2);
    cout<<endl;

    Element *head3 = NULL;
    insert_rear(&head3,411);
    insert_rear(&head3,511);
    insert_front(&head3,311);
    insert_rear(&head3,611);
    insert_front(&head3,211);
    insert_front(&head3,111);
    display(head3);
    cout<<endl;

    head->next->next->child = head2;
    head2->next->child = head3;

    flaten_DLL(&head);
    display(head);
}

