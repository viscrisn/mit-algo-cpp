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
	int test;
	test =100;
	for(int testno = 0; testno < test ; testno++ )
	{
		long long n;
		cin>>n;

		if(n==0)
		{
		    return 0;
		}
		long long a[1000];
		int len =0;
		int t;
		int k =0;
		int count =1;
		for (int i=0;i<1000;i++ )
		{
		    count++;
			t = n*n;
			while(t!=0)
			{
			    len++;
			    t/=10;
			}
			t = n*n;
			t/=100;
			t%=10000;
			n= t;
			a[i] = t;
			int flag = 0;
			for (int j=0;j<i;j++ )
			{
				if(a[j]==t)
				{
				    k = i;
				    flag = 1;
				    count--;
				    break;
				}
			}

		}
		for (int i=0;i<=1000;i++ )
		{
			//cout<<a[i]<<"\n";
		}
        cout<<count;

	}
}
