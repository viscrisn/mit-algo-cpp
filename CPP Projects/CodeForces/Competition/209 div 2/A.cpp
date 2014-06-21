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
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int flag = 0;
	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<m;j++ )
		{
			cin>>a[i][j];
		}
	}
	for (int i=0;i<n;i++ )
	{
		if(a[i][0] == 1 || a[i][m-1]==1)
            flag = 1;
	}
	for (int i=0;i<m;i++ )
	{
		if(a[0][i] == 1 || a[n-1][i]==1)
            flag = 1;
	}
	if(flag == 1)
        cout<<2;
    else
        cout<<4;
    return 0;
}
