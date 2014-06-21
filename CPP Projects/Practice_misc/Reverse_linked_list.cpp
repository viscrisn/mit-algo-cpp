#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

struct node
{
    int val;
    struct node* link;
};

typedef node* nodeptr;

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}
void add(nodeptr head,int value)
{
    nodeptr temp;
    temp = getnode();
    temp->val = value;
    temp->link = NULL;

    if(head->link == NULL)
    {
        head->link = temp;
        return;
    }
    else
    {
        nodeptr next;
        next = head -> link;
        head->link = temp;
        temp->link =next;
        return;
    }

}

void display(nodeptr head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"\t";
        head = head->link;
    }
}

nodeptr reverse1(nodeptr head,nodeptr prev)
{
    static nodeptr start = NULL;

    if(head->link!=NULL)
    {
        reverse1(head->link,head);
    }
    if(head->link == NULL)
    {
        start = head;
    }
    head->link = prev;
    return start;
}

nodeptr reverse(nodeptr head)
{
    return reverse1(head,NULL);
}

int main()
{
    node* linked_list;
    linked_list = getnode();
    linked_list->val = 1;
    linked_list->link = NULL;
    add(linked_list,2);
    add(linked_list,3);
    add(linked_list,4);
    add(linked_list,5);
    display(linked_list);
    cout<<endl;
    linked_list = reverse(linked_list);
    display(linked_list);
}
