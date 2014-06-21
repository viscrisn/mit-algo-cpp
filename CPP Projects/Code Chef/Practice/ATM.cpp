#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	float bal;
	int with;
	float ans;

	cin>>with>>bal;
	if((with%5 != 0) || (bal == with))
	{
	    cout<<bal;
	    return 0;
	}
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ans = (bal - with) - 0.5;
	cout<<ans;

}
