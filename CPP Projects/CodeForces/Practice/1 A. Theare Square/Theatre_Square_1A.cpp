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
	double n,m,a;
	cin>>n>>m>>a;
	double c,d;
	c = ceil(n/a);
	d = ceil(m/a);
    cout<<c*d;
}
