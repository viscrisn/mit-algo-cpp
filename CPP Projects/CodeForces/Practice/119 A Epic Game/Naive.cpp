#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int gcd(int m,int n)
{
    if(n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	int turn = 0;
	while(1)
	{
	    if(n<=0)
            break;
	    if(turn % 2 == 0)
	    {
	        n -= gcd(n,a);
	        turn = 1;
	    }
	    else
	    {
	        n -= gcd(n,b);
	        turn = 0;
	    }
	}
	if(turn==1)
        cout<<0;
    else
        cout<<1;
}
