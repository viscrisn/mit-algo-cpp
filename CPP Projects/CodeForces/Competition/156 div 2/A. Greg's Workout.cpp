#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int max = 0;
	int cyc[3]={0};
	int temp;
	for (int i=0;i<n;i++ )
	{
	    cin>>temp;
	    if(i%3==0)
            cyc[0]+= temp;
        else if(i%3==1)
            cyc[1]+= temp;
        else
            cyc[2]+= temp;
	}
	int index=0;
	for (int i=0;i<3;i++ )
	{
	    //cout<<cyc[i]<<"\t";
		if(cyc[i]>max)
		{
		    max = cyc[i];
		    index =i;
		}

	}
	if(index==0)
	{
        cout<<"chest";
	}
	else if(index==1)
	{
	    cout<<"biceps";
	}
	else
	{
	    cout<<"back" ;
	}



}
