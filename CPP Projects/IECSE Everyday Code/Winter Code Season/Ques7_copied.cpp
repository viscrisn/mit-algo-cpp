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

int n, k = 300;
int go[100020], jump[100020], next[100020];

int L, R;

void cal_L_R( int i )
{
    L = (i / k) * k;
    R = min(n, L + k);
}

int main()
{
    int m, a, b, type, x;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        next[i] = min(n, i + a);
    }
    for (int i = 0; i < n; i += k)
    {
        cal_L_R(i);
        for (int i = R - 1; i >= L; i--)
        {
            if ((x = next[i]) >= R)
            {
                go[i] = x;
                jump[i] = 1;
            }

            else
            {
                go[i] = go[x];
                jump[i] = jump[x] + 1;
            }
        }
    }
    for (int move=0 ; move < m ; move++ )
    {
        cin>>type;
        if (type == 0)
        {
            cin>>a>>b;
            a--;
            next[a] = min(n, a + b);
            cal_L_R(a);
            for (int i = R - 1; i >= L; i--)
            {
                if ((x = next[i]) >= R)
                {
                    go[i] = x;
                    jump[i] = 1;
                }

                else
                {
                    go[i] = go[x];
                    jump[i] = jump[x] + 1;
                }

            }
        }
        else
        {
            int cnt = 0;
            cin>>a;
            a--;
            while (go[a] < n)
            {
                cnt += jump[a];
                a = go[a];
            }
            while (next[a] < n)
            {
                a = next[a];
                cnt++;
            }
            cout<<a+1<<" "<<cnt+1<<"\n";
        }
    }
    return 0;
}
