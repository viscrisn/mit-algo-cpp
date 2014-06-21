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
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int cnt = 1;
    int par = 1;
    for (int i=0; i<n; i++ )
    {
        if(par == 1)
        {
            for (int j=0; j<n; j++ )
            {
                a[j][i] = cnt++;
            }
            par = 2;
        }
        else
        {
            for (int j=n-1; j>=0; j-- )
            {
                a[j][i] = cnt++;
            }
            par = 1;
        }
    }
    for (int i=0;i<n;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    		cout<<a[i][j]<<" ";
    	}
    	cout<<'\n';

    }



}
