#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;

    int steps[n+2];
	for (int i=0;i<n+2;i++ )
	{
		steps[i] = i;
	}

	for (int i=2;i<=n+1;i++ )
	{
		steps[i] = steps[i-1] + steps[i-2];
	}


	cout<<steps[n+1];

}
