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

//Not working

int fact(int n)
{
    int k =1;
	for (int i=1;i<=n;i++ )
	{
		k*=i;
	}
	return k;
}

int main()
{
	int n;
	cin>>n;

	int a[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
	int b[14] ={0};
	int len = 14;
	int ans =0;
	for (int i=0;i<len;i++ )
	{
		if(n%a[i]==0)
		{
		    ans++;
		    n/=a[i];
		    i--;
		    b[i]++;
		}

	}

	int k = fact(ans);
	for (int i=0;i<14;i++ )
	{
		if(b[i]>0)
		{
		    k/=fact(b[i]);
		}
	}



	cout<<k;

}
