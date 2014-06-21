#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

void insert(node* head, int value);
int height(node* head);
int bal_fac(node * head);
void rl(node* head);
void lr(node* head);
void drl(node* head);
void dlr(node* head);
node* getnode();

int main()
{

}

node* getnode()
{
    return (node*)malloc(sizeof(node));
}

int height(node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    return max(height(head->left, head->right) + 1);
}
