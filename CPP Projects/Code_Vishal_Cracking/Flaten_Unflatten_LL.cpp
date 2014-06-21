#include<iostream>
#include<stack>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node* link;
    struct node* child;
};

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}

//insert_front takes O(1) time, thus insert_rear not used
void insert_front(node **head,int val)
{
    node *temp = getnode();
    temp->val = val;
    temp->link = (*head);
    temp->child = NULL;
    (*head) = temp;
}

//Displays the singly list
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->link;
    }
    cout<<"\n";
}

void flaten_LL(node *head)
{
    if(head==NULL)
        return;
    node *end = head;
    //end will always point to last node
    while(end->link!=NULL)
        end = end->link;
    while(head!=NULL)
    {
        //If current node has a child, link it to end
        if(head->child!=NULL)
        {
            end->link = head->child;
            while(end->link!=NULL)
                end = end->link;
            //head->child = NULL can be done
            //But then this process will be irreversible
        }
        head = head->link;
    }
}

void unflatten_LL(node *head, stack<node*> &stk1)
{
    if(head==NULL)
        return;
    node *cur = head,*prev;
    stack<node*> stk;
    stk1.push(head);
    while(cur!=NULL)
    {
        if(cur->child!=NULL)
        {
            stk.push(cur);
            stk1.push(cur->child);
        }
        cur = cur->link;
    }
    prev = head;
    while(stk.size()>0)
    {
        cur = stk.top(),stk.pop();
        prev = cur;
        while(prev->link != cur->child && prev->link!=NULL)
            prev = prev->link;
        prev->link = NULL;
    }
}

int main()
{
    //Create all the linked lists as individual linked list
    //Child pointer set to NULL

    node *head = NULL;
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,1);
    display(head);
    //cout<<endl;
    //Since insert_front is used, values are reversed
    //so add in reverse order

    node *head2 = NULL;
    insert_front(&head2,5);
    display(head2);
    //cout<<endl;

    node *head3 = NULL;
    insert_front(&head3,8);
    insert_front(&head3,7);
    insert_front(&head3,6);
    display(head3);
    //cout<<endl;

    node *head4 = NULL;
    insert_front(&head4,11);
    insert_front(&head4,10);
    insert_front(&head4,9);
    display(head4);
    //cout<<endl;

    node *head5 = NULL;
    insert_front(&head5,13);
    insert_front(&head5,12);
    display(head5);
    //cout<<endl;

    node *head6 = NULL;
    insert_front(&head6,14);
    display(head6);


    node *head7 = NULL;
    insert_front(&head7,15);
    display(head7);
    //cout<<endl;

    //Link the child pointer with linked list
    head->child = head2;
    head->link->link->child = head3;
    head2->child = head4;
    head3->link->child = head5;
    head4->link->child = head6;
    head5->child = head7;

    cout<<"Flattened Linked list is:\n";
    flaten_LL(head);
    display(head);

    cout<<"Unflattened Linked list is:\n";

    stack<node*> stk1;
    stack<node*> stk2;

    unflatten_LL(head,stk1);

    while(stk1.size()>0)
    {
        stk2.push(stk1.top());
        stk1.pop();
    }
    while(stk2.size()>0)
    {
        head = stk2.top();
        stk2.pop();
        display(head);
    }

}
