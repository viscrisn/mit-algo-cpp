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

using namespace std;

//Time Complexity :O(n)
struct node
{
    int val;
    struct node* left;
    struct node* right;
    struct node* next;
};

node* getnode()
{
    node* temp = (node*)malloc(sizeof(node));
    return temp;
}

void insert(node* root, int value)
{
    node * temp = getnode();
    temp->val = value;
    temp->left = NULL;
    temp-> right = NULL;
    temp->next = NULL;

    node * cur = root;

    while(1)
    {
        if(value < cur->val)
        {
            if(cur->left!=NULL)
            {
                cur = cur->left;
            }
            else
            {
                break;
            }
        }
        else if(value >= cur->val)
        {
            if(cur->right!=NULL)
            {
                cur = cur->right;
            }
            else
            {
                break;
            }
        }
    }

    if(value < cur->val)
    {
        cur->left = temp;
    }
    else
    {
        cur->right = temp;
    }
    cout<<"Inserted Successfully\n";
}

node* level_link(node* root,int lvl)
{
    stack<node*> stk;
    stack<int> level;
    //instead of modifing the node structure, taken another stack which keeps track of depth

    node *current = root;
    bool done = false;
    node* cur = NULL;
    node* head_ll = NULL;

    int counter = 0;
    while (done==false)
    {
        if (current!=NULL)
        {
            stk.push(current);
            level.push(counter++);
            current = current->left;
        }
        else
        {
            if (stk.empty())
            {
                done = true;
            }
            else
            {
                current = stk.top();
                stk.pop();
                counter = level.top();
                level.pop();
                if(counter == lvl)
                {
                    if(cur==NULL)
                    {
                        cur = current;
                        head_ll = cur;
                    }
                    else
                    {
                        node* temp = cur;
                        cur = current;
                        temp->next = cur;
                    }
                }
                counter++;
                current = current->right;
            }
        }
    }
    return head_ll;
}

//Could have done more easily if we would have used system stack.
//Just use inorder traversal and keep track of depth using a counter.

void disp_lvl(node* head)
{
    while(head!=NULL)
    {
        cout<<head->val<<"\t";
        head = head->next;
    }
    cout<<"\n";
}
void disp_inorder(node* root)
{
    if(root!=NULL)
    {
        disp_inorder(root->left);
        cout<<root->val<<"\t";
        disp_inorder(root->right);
    }
}
void disp_preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->val<<"\t";
        disp_preorder(root->left);
        disp_preorder(root->right);
    }
}

int main()
{
    int value;
    node * root = getnode();

    cout<<"Enter root node value\n";
    cin>>value;
    root->val = value;
    root->left = NULL;
    root-> right = NULL;
    root->next = NULL;
    node* head_ll = NULL;

    while(1)
    {
        cout<<" 1. Insert\n 2. link levels\n 3.Display linked nodes\n 4.Display whole tree\n 5. Exit\n";
        int menu;
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout<<"Enter value to enter: ";
            cin>>value;
            insert(root,value);
            break;
        case 2:
            cout<<"Enter level to be linked(root node is lvl 0):";
            int lvl;
            cin>>lvl;
            head_ll = level_link(root,lvl);
            break;
        case 3:
            cout<<"The linked nodes are\n";
            disp_lvl(head_ll);
            break;
        case 4:
            cout<<"\nTree is (inorder)\n";
            disp_inorder(root);
            cout<<"\nTree is (preorder)\n";
            disp_preorder(root);
            break;
        case 5:
            cout<<"Exiting\n";
            exit(0);
            break;
        default:
            cout<<"Wrong option selected\n";
        }
    }
}
