#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

struct node
{
    char val;
    struct node* link;
};

void LL_insert(char temp,node* head)
{
    node* temp_node = (node*)malloc(sizeof(node));
    temp_node->val = temp;
    temp_node->link = NULL;
    node* cur;
    cur = head;
    while(cur->link!=NULL)
        cur = cur->link;

    cur->link = temp_node;
}

void LL_display(node* head)
{
    node* cur = head;
    while(cur!=NULL)
    {
        cout<<cur->val<<"\t";
        cur = cur->link;
    }
}

node* LL_reverse_tail(node* head, node *prev)
{
    static node* start = NULL;
    if(head->link!=NULL)
    {
        LL_reverse_tail(head->link,head);
    }
    if(head->link == NULL)
    {
        start = head;
    }

    head->link = prev;
    return start;
}
node* LL_reverse(node* head)
{
    return LL_reverse_tail(head,NULL);
}

int main()
{
	node* head = (node*)malloc(sizeof(node));
	char temp;
	temp = '+';
	head->val = temp;
	head->link = NULL;
	temp = getchar();
	while(temp!='\n')
	{
	    LL_insert(temp,head);
	    temp = getchar();
	}
	LL_display(head);
    cout<<"\n";
	head = LL_reverse(head);
	LL_display(head);
}
