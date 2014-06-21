#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

long long **c = (long long **)(calloc(2,sizeof(long long)));
		c[0] = (long long *)(calloc(1000000000,sizeof(long long)));
		c[1] = (long long *)(calloc(1000000000,sizeof(long long)));

using namespace std;

int main()
{
    int test;
    cin>>test;
	for (int test_id=0;test_id<test;test_id++ )
	{
		int n,r;
		cin>>n>>r;

		//unsigned long long c[2][r+1];

		for (int i=0;i<=n;i++ )
		{
			for (int j=0;j<=min(i,r);j++ )
			{
				if(j==0 || j==i)
                    c[i%2][j] = 1;
                else
                    c[i%2][j] = c[(i-1)%2][j-1] + c[(i-1)%2][j];
			}
		}
		cout<<c[n%2][r]%142857<<"\n";

	}


}
