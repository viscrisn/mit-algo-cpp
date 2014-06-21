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
	int n,k;
	cin>>n>>k;
	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	if(n<k)
	{
	    cout<<-1;
	    return 0;
	}
	sort(a,a+n);
    reverse(a,a+n);
    cout<<a[k-1]<<" "<<a[k-1];

}
