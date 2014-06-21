#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>


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

bool LL_palin(node *head);

int main()
{
    node *head=NULL;
    insert_rear(&head,4);
    insert_rear(&head,2);
    insert_front(&head,3);

    insert_front(&head,4);
    insert_rear(&head,1);
    insert_front(&head,2);
    insert_front(&head,1);
    display(head);

    if(LL_palin(head))
        cout<<"Yes, its a palindrome\n";
    else
        cout<<"No, Its not a palindrome\n";
}


bool LL_palin(node *head)
{
    stack<node*> stk;
    int len = 0;
    node *cur = head;
    while(cur!=NULL)
    {
        cur = cur->link;
        len++;
    }
    cur = head;
    for(int i=0;i<len/2;i++)
    {
        stk.push(cur);
        cur = cur->link;
    }

    if(len%2==1)
        cur = cur->link;
        //Because middle node should not be checked

    node *temp;
    for(int i =0;i<len/2;i++)
    {
        temp = stk.top();
        stk.pop();
        if(cur->val != temp->val)
            return false;
        cur = cur->link;
    }
    return true;
}
