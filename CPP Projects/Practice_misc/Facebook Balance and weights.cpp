#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include <sstream>
using namespace std;

struct node
{
    int x_L;
    int x_R;
    int *x_LLink;
    int *x_RLink;
    int total;
};

int solve(int i, node bal[], int table[][2], int n)
{
    if(bal[i].total == -1 )
    {
        for (int j=1; j <= bal[i].x_LLink[0]; j++ )
        {
            bal[i].x_L += solve(bal[i].x_LLink[j], bal, table, n);
        }
        for (int j=1; j <= bal[i].x_RLink[0]; j++ )
        {
            bal[i].x_R += solve(bal[i].x_RLink[j], bal, table, n);
        }
    }
    int temp = 0;
    if(bal[i].x_L > bal[i].x_R)
        temp = table[i][1] = bal[i].x_L - bal[i].x_R;
    else
        temp = table[i][0] = bal[i].x_R - bal[i].x_L;
    bal[i].total = (10 + 2*temp);
    return bal[i].total;
}

int table[10000][2];
int main()
{
    int n;
    scanf("%d\n", &n);
    node bal[n];


    for(int i=0; i<n; i++)
    {
        int value, is_weight_l=0, is_weight_r=0, j=0;
        stringstream left;
        string line;
        getline(cin, line);
        left<<line;

        bal[i].x_LLink = (int*)malloc(sizeof(int));

        while(left>>value)
        {
            if(is_weight_l == 0)
            {
                bal[i].x_L = value;
                is_weight_l = 1;
                j=1;
            }
            else
            {
                bal[i].x_LLink = (int*)realloc(bal[i].x_LLink,sizeof(int)*(j+2));
                bal[i].x_LLink[j++] = value;
            }
        }
        bal[i].x_LLink[0] = j-1;


        stringstream right;
        getline(cin, line);
        right<<line;
        j = 0;
        bal[i].x_RLink = (int*)malloc(sizeof(int));

        while(right>>value)
        {
            if(is_weight_r == 0)
            {
                bal[i].x_R = value;
                is_weight_r = 1;
                j=1;
            }
            else
            {
                bal[i].x_RLink = (int*)realloc(bal[i].x_RLink,sizeof(int)*(j+2));
                bal[i].x_RLink[j++] = value;
            }
        }
        bal[i].x_RLink[0] = j-1;

        bal[i].total = -1;
    }

    for (int i=0; i<n; i++ )
    {
        if(bal[i].total == -1)
            solve(i,bal,table,n);
    }

    for (int i=0; i<n; i++ )
    {
        cout<<i<<": "<<table[i][0]<<" "<<table[i][1]<<'\n';
    }

    return 0;
}
