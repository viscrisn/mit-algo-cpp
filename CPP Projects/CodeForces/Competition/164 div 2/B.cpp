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
	int ans = n;

	for (int i=1;i<n;i++ )
	{
		ans += i*(n - i);
	}
	cout<<ans<<"\n";
	cout<<n*(n*n+5)/6;

}
