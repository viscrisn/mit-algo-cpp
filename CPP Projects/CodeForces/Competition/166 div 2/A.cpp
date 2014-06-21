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
	cin>>n;
	t=n;
	int a[4];

    n++;
    label1:
    t=n;
	for (int i=0;i<4;i++ )
	{
		a[i] = t%10;
		t/=10;
	}
	//reverse(a,a+4);

	for (int i=0;i<4;i++ )
	{
	    for (int j=i+1;j<4;j++ )
	    {
	    	if(a[i]==a[j])
	    	{
	    	    n++;
	    	    goto label1;
	    	}
	    }
	}
    cout<<n;


}
