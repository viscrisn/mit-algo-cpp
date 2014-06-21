#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29
};
	int test;
	cin>>test;

	while(test)
	{
	    test--;
	    int n;
	    cin>>n;
	    int array[n];
	    for (int i=0;i<n;i++ )
	    {
	    	cin>>array[i];
	    }

        int n_prime = 0;
        for (int i=0;i<10;i++ )
        {
        	if(n == primes[i])
        	{
        	    n_prime = 1;
        	    break;
        	}
        }
        if(n_prime == 1)
        {
            cout<<n<<" ";
            for (int i=0;i<n;i++ )
            {
            	cout<<i+1<<" ";
            }
        }
        cout<<"\n";


	}
}
