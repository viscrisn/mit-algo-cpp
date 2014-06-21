#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int main()
{
	int test;
	cin>>test;

	while(test)
	{
	    test--;
	    unsigned long long fact = 1;
	    int n;
	    cin>>n;

	    for (int i=1;i<=n;i++ )
	    {
	    	fact = fact * i;
	    	if(fact%10 == 0)
	    	{
	    	    fact/=10;
	    	}
	    }
	    long long sum=0;
	    while(fact)
	    {
	        sum += fact%10;
	        fact/=10;
	    }
	    cout<<sum<<"\n";

	}
}

