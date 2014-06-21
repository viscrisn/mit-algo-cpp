#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test)
	{
	    test--;
	    int notes;
	    int sweets;
	    cin>>notes>>sweets;
	    int notes_arr[notes];
	    int total =0;
	    for (int i=0;i<notes;i++ )
	    {
	    	cin>>notes_arr[i];
	    	total += notes_arr[i];
	    }

	    int residual = total%sweets;

	    int flag =0;
	    for (int i=0;i<notes;i++ )
	    {
	    	if(notes_arr[i] <= residual)
	    	{
	    	    flag = 1;
	    	    break;
	    	}
	    }
	    if(flag == 1)
	    {
	        cout<<"-1\n";
	    }
	    else
	    {
	        cout<<total/sweets<<"\n";
	    }


	}
}
