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
#include<set>
#include<queue>
#include<fstream>

using namespace std;

long long a[10000];
long long cul_sum[10000];

int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		long long n;
		cin>>n;
		for (int i=0;i<n;i++ )
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for (int i=0;i<=n;i++ )
		{
            cul_sum[i] = 0;
		}
        cul_sum[0] = a[0];
		for (int i=1;i<n;i++ )
		{
			cul_sum[i] = a[i] + cul_sum[i-1];
		}
		/*
		for (int i=0;i<n;i++ )
		{
			cout<<a[i]<<"\t";
		}
		cout<<endl;
		for (int i=0;i<n;i++ )
		{
			cout<<cul_sum[i]<<"\t";
		}
		cout<<endl;
		*/
		int flag = 0;
		long long i1 = 0;
		for ( i1=n-1;i1>=2;i1-- )
		{
			if(cul_sum[i1-1] > a[i1])
			{
			    flag = 1;
			    break;
			}
		}
		if(flag == 1)
        {
            cout<<i1+1<<"\n";
        }
        else
        {
            cout<<-1<<"\n";
        }

	}
	return 0;
}
