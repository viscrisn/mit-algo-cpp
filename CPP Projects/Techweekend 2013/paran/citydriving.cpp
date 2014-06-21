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

int b[1000][1000];
int a[1000][2];

int main()
{
    int test;
    test = 100;

    for(int testno = 0; testno < test ; testno++ )
    {
        int n;
        cin>>n;
        if(n==0)
        {
            return 0;
        }
        for (int i=0; i<1000; i++ )
        {
            for (int j=0; j<1000; j++ )
            {
                b[i][j]=999;
            }
        }
        int x,y,w;
        for (int i=0; i<n; i++ )
        {
            cin>>x>>y>>w;
            b[x][y] = w;
            b[y][x] = w;
        }
        /*for (int i=0; i<n; i++ )
        {
            for (int j=0; j<n; j++ )
            {
                cout<<b[i][j]<<" ";
            }
            cout<<"\n";
        }*/

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    b[i][j]=min(b[i][j],b[i][k]+b[k][j]);

/*
        for (int i=0; i<n; i++ )
        {
            for (int j=0; j<n; j++ )
            {
                cout<<b[i][j]<<" ";
            }
            cout<<"\n";
        }
*/
        int q;
        cin>>q;
        for (int i=0;i<q;i++ )
        {
        	cin>>a[i][0]>>a[i][1];
        }
        for (int i=0;i<q;i++ )
        {
        	cout<<b[a[i][0]][a[i][1]]<<"\n";
        }

    }
}
