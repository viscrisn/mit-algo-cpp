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

/*
//passing head by reference
void insert_front(node* &head,int val)
{
    if(head==NULL)
    {
        head = getnode();
        head->val = val;
        head->link = NULL;
        return;
    }
    node *temp = getnode();
    temp->val = val;
    temp->link = head;
    head = temp;
}
*/

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

void create_cycle(node *head,int pos)
{
    node *cur = head;
    while(head!=NULL && pos!=0)
    {
        head = head->link;
        pos--;
    }
    while(cur->link!=NULL)
        cur = cur->link;
    cur->link = head;
}

int detect_cycle(node *head)
{
    if(head==NULL)
        return -1;
    if(head->link==NULL)
        return -1;
    if(head->link->link == NULL)
        return -1;

    //Detect Cycle
    node *fast = head->link->link, *slow = head;
    bool flag = false;
    while(fast!=NULL&&fast->link!=NULL)
    {
        if(slow == fast || slow->link == fast)
        {
            flag = true;
            break;
        }
        fast = fast->link->link;
        slow = slow->link;
    }
    if(flag == false)
        return -1;

    //Cycle Found, now find length of cycle
    int len = 1;
    slow = fast;
    fast = fast->link;
    while(fast != slow)
    {
        len++;
        fast = fast->link;
    }

    //Length found, now find position of cycle
    fast = head;
    slow = head;
    for(int i = 0; i<len; i++)
        fast = fast->link;
    int pos = 0;
    while(slow!=fast)
    {
        slow = slow->link;
        fast = fast->link;
        pos++;
    }
    return pos;
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

    display(head);

    create_cycle(head,3);
    int pos = detect_cycle(head);
    if(pos != -1)
        cout<<"There is a cycle starting at position: "<<pos<<"\n";
    else
        cout<<"There is no cycle\n";
}

