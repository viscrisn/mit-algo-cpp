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
	    char ch;
	    char l2;
	    while((ch=getche())!=13)
	    {
	        l2 = ch;
	    }
        ch = l2;
	    ch = ch - '0';
	    if(ch==0)
	    {
	        cout<<"Sakib Number\n";
	    }
	    else if(ch%2 == 0)
	    {
	        cout<<"Yes\n";
	    }
	    else if(ch%5 == 0)
	    {
	        cout<<"Yes\n";
	    }
	    else
	    {
	        cout<<"No\n";
	    }
	}
}
