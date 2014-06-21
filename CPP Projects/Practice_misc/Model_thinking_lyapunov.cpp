#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int main()
{
	cout<<"Enter number:\n";
	long long t;
	cin>>t;
	long long count=0;
	while(t!=1)
	{
	    t = t%2==0?(t/2):(t*3 +1);
	    cout<<t<<"\t";
	    count++;
	}
	cout<<"\nNo of loops:\t"<<count;
}
