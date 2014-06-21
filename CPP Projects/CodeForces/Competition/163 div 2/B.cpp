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
	int n,t;
	char a[100];
	cin>>n>>t;
	cin>>a;
	while(t)
	{
	    t--;
	    for (int i=0;i<n-1;i++ )
	    {
	    	if(a[i]=='B'&&a[i+1]=='G')
	    	{
	    	    swap(a[i],a[i+1]);
	    	    i++;
	    	}
	    }
	}
	cout<<a;

}
