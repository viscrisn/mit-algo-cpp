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

	int d;
	cin>>d;

	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}

	int b[n];

	int count = 0;
	for (int i=0;i<n-d;i++ )
	{
		b[count++] = a[i+d];
	}
	for (int i=0;i<d;i++ )
	{
		b[count++] = a[i];
	}
	for (int i=0;i<n;i++ )
	{
		a[i] = b[i];
	}
	for (int i=0;i<n;i++ )
	{
		cout<<a[i]<<"\t";
	}



}
