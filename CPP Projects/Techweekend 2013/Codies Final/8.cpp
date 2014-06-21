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
#include<queue>\

using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}

	int zero =0;
	for (int i=0;i<n;i++ )
	{
		if(a[i]==0)
		{
		    zero++;
		}
	}
	int ab =0;
	for (int i=0;i<n;i++ )
	{
	    ab = i;
		if(a[i]==0)
		{
		    while(a[ab]==0 && ab <n)
		    {
		        ab++;
		    }
		}
		swap(a[ab],a[i]);
	}

	for (int i=n-zero;i<n;i++ )
	{
		a[i]=0;
	}

	for (int i=0;i<n;i++ )
	{
		cout<<a[i]<<"\t";
	}



}
