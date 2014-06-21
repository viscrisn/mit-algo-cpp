#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

//WRONG ANSWER

int main()
{
    unsigned long long a =0;
    cout<<sizeof(a);
	int test;
	//cin>>test;
	test =10;
	while(test)
	{
	    test--;
	    int n;
	    cin>>n;
	    int num = n;
	    int power=0;
	    while(n%12 == 0)
	    {
	        power++;
	        n/=12;
	    }
	    for (int i=0;i<power;i++ )
	    {
	    	num /= 12;
	    	num *=13;
	    }

	    cout<<num<<endl;
	}
}
