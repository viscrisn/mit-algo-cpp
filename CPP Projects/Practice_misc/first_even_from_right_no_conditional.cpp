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
	cin>>test;
    int testno = 0;

	for(; testno < test ; testno++ )
	{

		int n;
		cin>>n;

		int flag = 0;
		int k = 1;
		while(k==1)
		{
		    while(n%2==0)
		    {
		        cout<<"Case # "<<testno+1<<": "<<n%10<<"\n";
		        k = 0;
		        n++;
		    }
		    n/=10;
		    while(n==0)
		    {
		        n++;
		        k=2;
		    }
		}
		while(k==2)
		{
		    cout<<"Case # "<<testno+1<<": "<<"-1\n";
		    k=0;
		}

	}
}
