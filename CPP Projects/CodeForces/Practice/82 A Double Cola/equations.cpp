#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>

using namespace std;
//Working
int main()
{
	long long n;
	cin>>n;
	long long nby5 = n/5;
	long long round = log(nby5 + 1)/log(2);
	double remaining = n + 5 - 5*(1<<round);
	//round++;
	double turn = ceil(remaining / (1<<round));

	if(turn==1)
        cout<<"Sheldon";
    else if(turn==2)
        cout<<"Leonard";
    else if(turn==3)
        cout<<"Penny";
    else if(turn==4)
        cout<<"Rajesh";
    else if(turn==5||turn==0)
        cout<<"Howard";

    return 0;
}
