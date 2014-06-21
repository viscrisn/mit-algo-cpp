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
		int n,k;
		cin>>n>>k;
		if(n<k)
		{
		    cout<<"0\n";
		    continue;
		}
		else
		{
            if(k<=100)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"0\n";
            }
		}
	}
}
