//D:\Artifacts\Computer Programming\Problems\ACM Problems\problems (2)

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int f(int);

int main()
{
	int test =0;
	while(1)
	{
	    cin>>test;
	    if(test == -1)
	    {
	        break;
	    }
	    cout<<f(test)<<endl;
	}
}

int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n%2==0)
    {
        return n/2;
    }
    else
    {
        return (f((n-1)/2) + f((n+1)/2));
    }
}
