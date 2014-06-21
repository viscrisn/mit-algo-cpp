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

int gcd(int m,int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int n;
		cin>>n;

		int m = n/2 +1;
		cout<<m<<"\n";


	}
}
