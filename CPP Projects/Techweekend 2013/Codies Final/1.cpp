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
	int a[n][m],b[m][n];

	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<m;j++ )
		{
			cin>>a[i][j];
		}
	}

	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cin>>b[i][j];
		}
	}

	int c[100][100];
	for (int k=0;k<n;k++ )
	{
		for (int i=0;i<n;i++ )
		{
			for (int j=0;j<m;j++ )
			{
				c[k][i] += a[i][j] * b[j][i];
			}

		}
	}
	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<m;j++ )
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}



}
