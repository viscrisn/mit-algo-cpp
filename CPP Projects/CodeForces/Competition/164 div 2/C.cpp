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
	int n,m;
	int k;
	cin>>n>>m;
	k = min(n,m)+1;
	int x = 0,y = 1;

	cout<<k<<"\n";
	for (int i=0;i<k;i++ )
	{
		cout<<x<<" "<<y<<"\n";
		if(y==m)
		{
		    y = -1;
		}
		x++;
		y++;

	}

}
