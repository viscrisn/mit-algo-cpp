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
	int n,c;

	cin>>n>>c;
	int a[n];
    c--;
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}

	int t = a[c];

	for (int i=0;i<n;i++)
	{
		a[i] = a[i] - t;
	}
	a[c] = t*n;
    for (int i=0;i<n;i++ )
    {
    	cout<<a[i]<<" ";
    }

}
