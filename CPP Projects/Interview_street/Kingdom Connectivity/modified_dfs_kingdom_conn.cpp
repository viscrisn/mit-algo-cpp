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

int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    int **a;
    a = (int**)(calloc(n,sizeof(int*)));
    int x,y;
    int cal[n];
    for (int i=0;i<n;i++ )
    {
    	cal[i] = 1;
    }

    for (int i=0;i<n;i++ )
    {
    	a[i] = (int*)(calloc(1,sizeof(int)));
    }

    for (int i=0; i<m; i++ )
    {
        cin>>x>>y;
        x--;y--;cal[x]++;
        a[x] = (int*)realloc(a[x],cal[x]*sizeof(int));
        a[x][cal[x]-1] = y;

    }
    for (int i=0;i<n;i++ )
    {
    	for (int j=0;j<cal[i];j++ )
    	{
    		cout<<a[i][j]<<"\t";
    	}
    	cout<<"\n";
    }


    for (int i=0; i<m; i++ )
    {
        cin>>x>>y;
        x--;
        y--;
        a[x][y] = 1;
    }
    /*for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }*/
    for (int k=0; k<n; k++ )
    {
        for (int i=0; i<n; i++ )
        {
            for (int j=0; j<n; j++ )
            {
                if(a[i][j]!= 0 && (a[i][k]==1 && a[k][j]==1))
                {
                    a[i][j] += 1;
                }
                else if(a[i][k]>=1 && a[k][j]>=1)
                {
                    a[i][j] += a[i][k] *a[k][j];
                }
            }
        }
        /*cout<<"\n";
        for (int i1=0; i1<n; i1++ )
        {
            for (int j1=0; j1<n; j1++ )
            {
                cout<<a[i1][j1]<<"\t";
            }
            cout<<"\n";
        }*/
    }
    int ans = a[0][n-1];
    cout<<ans;

}

