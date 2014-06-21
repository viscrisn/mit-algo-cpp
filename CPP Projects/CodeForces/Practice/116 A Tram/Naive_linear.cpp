#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<functional>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int max = b[0];
	for (int i=1;i<n;i++)
	{
		b[i-1] -= a[i];
		b[i] += b[i-1];
		if(b[i] > max)
            max = b[i];
	}
	cout<<max;

}
