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
#include<queue>

using namespace std;

//Space complexity : no extra space required. O(1)
//time complexity: O(no_ele in smaller_mat X (dim_lar_mat - row X dim_lar_mat - col))
//Linear time complexity beause you have to atleast see the elements once. So its optimal.
//Reduced Space Naive method

int main()
{
    cout<<"Enter dimention of larger square matrix\t";
    int dim;
    cin>>dim;
    cout<<"Enter contents\n";
    int larger[dim][dim];
    for (int i=0; i<dim; i++ )
    {
        for (int j=0; j<dim; j++ )
        {
            cin>>larger[i][j];
        }
    }
    cout<<"Enter no. of rows and columns of smaller matrix\t";
    int n,m;
    cin>>n>>m;
    int ans = 0;
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<m; j++ )
        {
            ans = 0;
            for (int k=i; k<=dim - n + i; k++ )
            {
                for (int l=j; l<=dim - m + j; l++ )
                {
                    ans += larger[k][l];
                }
            }
            cout<<ans<<"\t";
        }
        cout<<"\n";
    }
}
