/*
ID: viscris1
PROB: ride
LANG: C++
*/

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
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
	char a[2][10];
	cin>>a[0]>>a[1];
	int n = strlen(a[0]);
	int m = strlen(a[1]);
	int mul1=1, mul2=1;
	for (int i=0;i<n;i++ )
	{
		mul1 *= a[0][i] - 'A' + 1;
	}
	for (int i=0;i<m;i++ )
	{
		mul2 *= a[1][i] - 'A' + 1;
	}
	mul1 %= 47;
	mul2 %= 47;
	mul1==mul2?cout<<"GO\n":cout<<"STAY\n";
    return 0;
}
