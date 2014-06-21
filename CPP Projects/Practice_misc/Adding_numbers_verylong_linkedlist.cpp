#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<conio.h>

using namespace std;

struct node
{
    char val;
    struct node* link;
};

node* getnode()
{
    return (node*)(malloc(sizeof(node)));
}
node* insert(node* head, char value)
{
    node* temp = getnode();
    temp->val = value;
    temp->link = NULL;
    if(head==NULL)
    {
        head = temp;
        return head;
    }

    temp->link = head;
    head = temp;

    return head;
}

node* add_no(node* head)
{
    cout<<"Enter number";
    char c;
    c = getche();
    while((c!= '\0')&&(c!= '\n')&&(c!= '\r'))
    {
        head = insert(head,c-'0');
        c = getche();
    }
    return head;
}

void display(node* head)
{
    node* cur= head;
    while(cur!=NULL)
    {
        cout<<(int)cur->val<<" ";
        cur= cur->link;
    }
    cout<<"\n";
}

/*//No idea why this is not working properly :(
void display_reversed(node* head)
{
    if(head->link!=NULL)
    {
        display_reversed(head->link);
    }
    cout<<(int)head->val<<" ";
}*/

node* reverse_ll(node* head,node* prev)
{
    static node* new_head = NULL;
    if(head->link!=NULL)
    {
        reverse_ll(head->link,head);
    }
    if(head->link == NULL)
    {
        new_head = head;
    }
    head -> link = prev;

    return new_head;
}

node* reverse_ll(node* head)
{
    return reverse_ll(head,NULL);
}

node* sum(node* num1,node* num2)
{
    node* temp,*ptr1 = num1,*ptr2 = num2;
    int tmp_carry = 0;
    int tmp_sum = 0;
    while((ptr1!=NULL)&&(ptr2!=NULL))
    {
        tmp_sum = ptr1->val + ptr2->val + tmp_carry;
        tmp_carry = tmp_sum/10;
        tmp_sum %= 10;
        temp = insert(temp,tmp_sum);
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
    while((ptr1!=NULL))
    {
        tmp_sum = ptr1->val + tmp_carry;
        tmp_carry = tmp_sum/10;
        tmp_sum %= 10;
        temp = insert(temp,tmp_sum);
        ptr1 = ptr1->link;
    }
    while((ptr2!=NULL))
    {
        tmp_sum = ptr2->val + tmp_carry;
        tmp_carry = tmp_sum/10;
        tmp_sum %= 10;
        temp = insert(temp,tmp_sum);
        ptr2 = ptr2->link;
    }
    if(tmp_carry!=0)
    {
        temp = insert(temp,tmp_carry);
    }

    temp = reverse_ll(temp);
    return temp;
}
int main()
{
	node* num1 = NULL;
	node* num2 = NULL;

	num1 = add_no(num1);
	num2 = add_no(num2);

	display(num1);
	display(num2);

	node* sum_no = NULL;
	sum_no = sum(num1,num2);

	display(sum_no);
}
