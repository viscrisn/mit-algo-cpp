#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
    int total_case;
    cin>>total_case;
	for (int test_case=0;test_case<total_case;test_case++ )
	{
		int G;
		cin>>G;
		for (int G_case=0;G_case<G;G_case++ )
		{
			int I,N,Q;
			cin>>I>>N>>Q;
			if(N%2==0)
			    cout<<N/2<<"\n";
            else
                cout<<(N/2 + !(I&Q))<<"\n";
		}
	}

}
