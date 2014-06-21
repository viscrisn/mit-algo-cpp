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

int gcd(int m,int n)
{
    if(n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
	int a,b,x,y;
	cin>>x>>y>>a>>b;
	int count =0;
	int lcm = (x*y)/gcd(x,y);
	int lcm2 = lcm;
	while(lcm2 <= b)
	{
	    if(lcm2 < a)
	    {
	        lcm2 += lcm;
	        continue;
	    }
	    lcm2 += lcm;
	    count++;
	}

	cout<<count;

}
