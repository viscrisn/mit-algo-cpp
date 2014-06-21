
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
    int x_LLink[1000];
    int x_RLink[1000];
    int total;
};

int table[1000][2];
node bal[1000];
int n;

int solve(int i)
{
    if(bal[i].total == -1 )
    {
        for (int j=1; j <= bal[i].x_LLink[0]; j++ )
        {
            bal[i].x_L += solve(bal[i].x_LLink[j]);
        }
        for (int j=1; j <= bal[i].x_RLink[0]; j++ )
        {
            bal[i].x_R += solve(bal[i].x_RLink[j]);
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

int main()
{
// take inputs
    scanf("%d\n", &n);

    for(int i=0; i<n; i++)
    {
        int value, is_weight_l=0, is_weight_r=0, j=0;
        stringstream left;
        string line;
        getline(cin, line); // left
        left<<line; // put ss's first value into s.
        while(left>>value) // put each of left's stuff into `value`, for as long as left has values in it
        {
            if(is_weight_l == 0) //it's the weight on the balance
            {
                bal[i].x_L = value;
                is_weight_l = 1;
                j=1;
            }
            else
            {
                bal[i].x_LLink[j++] = value;
            }
        }
        bal[i].x_LLink[0] = j-1;


        stringstream right;
        getline(cin, line);
        right<<line;
        while(right>>value) // put each of right's stuff into `value`, for as long as right has values in it
        {
            if(is_weight_r == 0) // it's the weight on the balance
            {
                bal[i].x_R = value;
                is_weight_r = 1;
                j=1;
            }
            else
            {
                bal[i].x_RLink[j++] = value;
            }
        }
        bal[i].x_RLink[0] = j-1;

        bal[i].total = -1;
    }

    for (int i=0; i<n; i++ )
    {
        if(bal[i].total == -1)
            solve(i);
    }

    for (int i=0; i<n; i++ )
    {
        cout<<i<<": "<<table[i][0]<<" "<<table[i][1]<<'\n';
    }

    return 0;
}
