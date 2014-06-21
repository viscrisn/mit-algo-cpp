#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int a;
    struct node *left;
    struct node *right;
};

node* getnode()
{
    node* temp = (node*)malloc(sizeof(node));
    return temp;
}

void search(node*,int);
void insert(node*,int);

int main()
{
    int value;
    node * root = getnode();

    cout<<"Enter root node value\n";
    cin>>value;
    root->a = value;
    root->left = NULL;
    root-> right = NULL;

    while(1)
    {
        cout<<"1. Insert\n2. Search\n3. Exit\n";
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
            cout<<"Enter key to search: ";
            cin>>value;
            search(root,value);
            break;
        case 3:
            cout<<"Exiting\n";
            exit(0);
            break;
        default:
            cout<<"Wrong option selected\n";
        }
    }
}

void insert(node* root, int value)
{
    node * temp = getnode();
    temp->a = value;
    temp->left = NULL;
    temp-> right = NULL;

    node * cur = root;

    while(1)
    {
        if(value < cur->a)
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
        else if(value >= cur->a)
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

    if(value < cur->a)
    {
        cur->left = temp;
    }
    else
    {
        cur->right = temp;
    }
    cout<<"Inserted Successfully\n";
}

void search(node* root, int value)
{
    node * cur = root;
    int flag = 0;

    while(1)
    {
        if(cur->a == value)
        {
            flag = 1;
            break;
        }
        else if(value < cur->a)
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
        else if(value > cur->a)
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

    if(flag == 1)
    {
        cout<<"Key is present\n";
    }
    else
    {
        cout<<"Key is not present\n";
    }
}


