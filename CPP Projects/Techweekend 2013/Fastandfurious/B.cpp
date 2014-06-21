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
	int n,m;
	cin>>n>>m;

	int a[n][m];
	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<m;j++ )
		{
			cin>>a[i][j];
		}
	}

	int first = a[0][0];
	int t[10000] = {0};
	int flag = 0;
	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<m;j++ )
		{
			if(i==j && a[i][j]== first)
			{
			    continue;
			}
			else if(i==j && a[i][j]!= first)
			{
			    cout<<"NOt a cross matrix";
			    return 0;
			}
			if(i!=j && a[i][j]==first)
			{
			    cout<<"NOt a cross matrix";
			    return 0;
			}

		}
	}
	cout<<"YES, its a cross matrix";


}
