#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;



bool isBST(struct node* root)
{
    if (root)
    {
        if(root.number_nodes>2)
        {
            return false;
        }

        if (!isBST(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}


