#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

int main()
{
	int test;
	cin>>test;
	for (int test_no=0;test_no<test;test_no++ )
	{
		int n,k,temp,flag =0,m=0;
		cin>>n>>k;
		int array[n];
		for (int i=0;i<n;i++ )
		{
			cin>>temp;
			if(temp==k)
			{
			    flag = 1;
			}
			if(temp<k)
			{
			    array[m++] = temp;
			}
		}
		if(flag == 1)
		{
		    cout<<"1\n";
		    continue;
		}
		if(m == 0)
		{
		    cout<<"0\n";
		    continue;
		}
		sort(array,array+m);


	}

}
