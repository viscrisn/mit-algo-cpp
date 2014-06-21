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

node* add_2_ll(node* l1,node* l2)
{
    node *l3=NULL;
    int carry = 0;
    int quo = 0;
    while(l1!=NULL && l2!=NULL)
    {
        quo = (l1->val + l2->val)%10 + carry;
        carry = (l1->val + l2->val)/10;
        insert_rear(&l3,quo);
        l1 = l1->link;
        l2 = l2->link;
    }
    while(l1!=NULL)
    {
        insert_rear(&l3,l1->val + carry);
        carry = (l1->val)/10;
        l1 = l1->link;
    }
    while(l2!=NULL)
    {
        insert_rear(&l3,l2->val + carry);
        carry = (l2->val)/10;
        l2 = l2->link;
    }
    if(carry>0)
        insert_rear(&l3,carry);
    return l3;
}

node* reverse_ll_tail(node* cur, node* prev)
{
    static node* start = NULL;
    if(cur->link!=NULL)
    {
        reverse_ll_tail(cur->link,cur);
    }
    else if(start==NULL)
    {
        start = cur;
    }
    cur->link = prev;
    return start;
}

void reverse_ll(node **head)
{
    *head = reverse_ll_tail((*head),NULL);
}

void reverse_ll_iterative(node **head)
{
    node *cur, *prev;
    cur = (*head)->link;
    prev = (*head);
    (*head) = cur->link;
    prev ->link = NULL;
    while((*head)!=NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = (*head);
        (*head) = (*head)->link;
    }
    cur->link = prev;
    (*head) = cur;
}

int main()
{
    node *l1=NULL;
    node *l2=NULL;
    node *l3 = NULL;
    insert_rear(&l1,4);
    insert_rear(&l1,5);
    insert_front(&l1,3);
    insert_rear(&l2,6);
    insert_front(&l2,2);
    insert_front(&l2,1);
    insert_front(&l2,8);
    insert_front(&l2,7);

    display(l1);
    display(l2);
    l3 = add_2_ll(l1,l2);
    display(l3);

    reverse_ll(&l3);
    display(l3);

    reverse_ll_iterative(&l3);
    display(l3);


}

