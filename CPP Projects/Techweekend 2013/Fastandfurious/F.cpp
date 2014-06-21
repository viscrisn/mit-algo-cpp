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

	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	int lar =0;
	int max = 0;
	int cmax =0;
	for (int i=0;i<n;i++ )
	{
		if(a[i]==(a[i+1]-1))
		{
		    max++;
		}
		else
		{
		    if(max>cmax)
		    {
		        cmax = max;
		    }
		    max = 0;
		}
	}
	cout<<n-cmax-1;

}
