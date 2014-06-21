//D:\Artifacts\Computer Programming\Problems\ACM Problems\problems (2)

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int M(int);

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
	    cout<<"M("<<test<<") = "<<M(test)<<endl;
	}
}

int M(int n)
{
    if(n==1)
    {
        return 1;
    }
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int count =0;
    for (int i=0;i<sizeof(primes)/sizeof(int);i++ )
    {
    	if(n%primes[i]==0)
    	{
    	    if((n/primes[i])%primes[i] ==0)
    	    {
    	        return 0;
    	    }
    	    count ++;
    	}
    }
    if(count%2==0)
    {
        return 1;
    }
    return -1;

}
