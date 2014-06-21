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

struct node
{
    int i,x;
};

bool cmp(node c, node d)
{
    return c.x < d.x;
}

int main()
{
    node a[700000];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n;
	cin>>n;
	for (int i=0;i<n*2;i++ )
	{
		cin>>a[i].x;
		a[i].i = i;
	}
	sort(a,a+ 2*n,cmp);
    /*for (int i=1;i<=2*n;i++ )
    {
    	cout<<a[i].x<<" ";
    }*/

	for (int i=0;i< 2*n;i++ )
	{
		if(i%2==0)
		{
		    if(a[i].x != a[i+1].x)
		    {
		        cout<<-1;
		        return 0;
		    }
		}
	}
	for (int i=0;i< 2*n;i++ )
	{
		if(i%2==0)
		{
		    cout<<a[i].i+1<<" "<<a[i+1].i+1<<"\n";
		}
	}
	return 0;
}
