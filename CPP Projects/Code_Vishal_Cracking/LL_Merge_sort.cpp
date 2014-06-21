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

node* merge(node *LL1,node *LL2)
{
    if(LL1==NULL)  return LL2;
    if(LL2==NULL)  return LL1;

    display(LL1);
    display(LL2);

    node *temp,*prev=NULL,*start=NULL;
    while(LL1!=NULL && LL2!=NULL)
    {
        if(LL1->val < LL2->val)
        {
            temp = LL1;
            LL1 = LL1->link;
        }
        else
        {
            temp = LL2;
            LL2 = LL2->link;
        }
        if(start==NULL)
        {
            start = temp;
            prev = temp;
        }
        else
        {
            prev->link = temp;
            prev = temp;
        }
    }
    while(LL1!=NULL)
    {
        prev->link = LL1;
        prev = prev->link;
        LL1 = LL1->link;
    }
    while(LL2!=NULL)
    {
        prev->link = LL2;
        prev = prev->link;
        LL2 = LL2->link;
    }
    prev->link = NULL;
    return start;
}

uint32_t LL_length(node *head)
{
    uint32_t count =0;
    while(head!=NULL)
    {
        count++;
        head = head->link;
    }
    return count;
}

node* merge_sort(node *head)
{
    int len = LL_length(head);
    node *node_ptr[len+1];
    node *cur = head;
    for (int i=1;i<len+1;i++ )
    {
    	node_ptr[i] = cur;
    	cur = cur->link;
    	node_ptr[i]->link = NULL;
    }
    int index;
    while(len > 0)
    {
        len /=2;
        for (int i=1;i<len+1;i++ )
        {
            index = 2*(i-1) + 1;
        	node_ptr[i] =
        	merge(node_ptr[index],node_ptr[index+1]);
        }
    }
    return node_ptr[1];
}

int main()
{
    node *head = NULL;

    insert_front(&head,9);
    insert_front(&head,7);
    insert_front(&head,4);
    insert_front(&head,2);
    insert_front(&head,8);
    insert_front(&head,3);
    insert_front(&head,1);
    insert_front(&head,10);
    display(head);
    cout<<endl;

    //head = merge(head,head3);
    head = merge_sort(head);
    display(head);
}


