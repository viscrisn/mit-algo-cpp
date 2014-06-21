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
	cin>>n;

	int a[n][n];

	int count =1;
	int flag = 0;
	int left=0,top=0,right = n-1,bot = n-1;
	for (int i=0;i<n/2;i++ )
	{
		for (int j=i;j<n-(i*2);j++ )
		{
			a[i][j] = count++;
		}
		for (int j=i;j<n-(i*2);j++ )
		{
			a[j][n-i] = count++;
		}
		for (int j=n-(i*2)-1;j>i;j-- )
		{
			a[i][j] = count++;
		}
		for (int j=n-(i*2)-1;j>i;j-- )
		{
			a[n-j][i] = count++;
		}


	}
	if(n==3)
	{

	}
	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";

	}


}
