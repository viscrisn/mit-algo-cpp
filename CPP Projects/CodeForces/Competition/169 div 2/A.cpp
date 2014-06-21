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

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][2];

	for (int i=0;i<n;i++ )
	{
		cin>>a[i][0]>>a[i][1];
		a[i][1] = -a[i][1] + m;
	}
	int max = -999999999;
	for (int i=0;i<n;i++ )
	{
		if(a[i][1]<0)
		{
		    a[i][0] = a[i][1] + a[i][0];
		}
	}
	for (int i=0;i<n;i++ )
	{
		if(a[i][0]>max)
		{
		    max = a[i][0];
		}
	}

	cout<<max;


}
