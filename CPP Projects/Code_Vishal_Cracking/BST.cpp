#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

node *getnode()
{
    return (node*)(malloc(sizeof(node)));
}

node *insert(node *root, int val)
{
    node *temp = getnode();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    if(root==NULL)
    {
        return temp;
    }
    node *cur = root;
    while(cur->left!=NULL||cur->right!=NULL)
    {
        if(cur->val > val)
        {
            if(cur->left==NULL)
            {
                break;
            }
            cur = cur->left;
        }
        else if(cur->val <val)
        {
            if(cur->right==NULL)
            {
                break;
            }
            cur = cur->right;
        }
        else
        {
            cout<<"Duplicate value inserted";
            return root;
        }
    }
    if(cur->val < val)
        cur->right = temp;
    else
        cur->left = temp;

    return root;
}

int height(node *root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right)) + 1;
}

bool isBalanced(node *root)
{
    static bool val = true;
    if(root!=NULL)
    {
        if(abs((height(root->left) - height(root->right))) > 1)
        {
            val  = false;
        }
        isBalanced(root->left);
        isBalanced(root->right);
    }
    return val;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->val<<"\t";
        inorder(root->right);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->val<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        cout<<root->val<<"\t";
        postorder(root->right);
    }
}


void iter_preorder(node *root)
{
    stack<node*> stk;
    stk.push(NULL);
    while(root!=NULL)
    {
        cout<<root->val<<"\t";

        if(root->right!=NULL)    stk.push(root->right);
        if(root->left!=NULL)     stk.push(root->left);
        root = stk.top();
        stk.pop();

    }
}

void levelorder(node *root)
{
    queue<node*> q;
    while(root!=NULL)
    {
        cout<<root->val<<"\t";
        if(root->left!=NULL)    q.push(root->left);
        if(root->right!=NULL)   q.push(root->right);
        root = q.front();
        q.pop();
    }
}

int main()
{
    node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 6);
    /*
                       5
                    /     \
                  3          7
               /    \       /  \
              1      4     6    8
                                 \
                                  9
    */
    cout<<"Inorder:\t";
    inorder(root);
    cout<<"\nPreorder:\t";
    preorder(root);
    cout<<"\nPostorder:\t";
    postorder(root);

    cout<<"\nIter preorder:\t";
    iter_preorder(root);

    cout<<"\nLevelorder:\t";
    levelorder(root);


    cout<<"\nHeight:\t";
    cout<<height(root)<<"\n";
    if(isBalanced(root))
        cout<<"Balanced\n";
    else
        cout<<"Not balanced\n";


}
