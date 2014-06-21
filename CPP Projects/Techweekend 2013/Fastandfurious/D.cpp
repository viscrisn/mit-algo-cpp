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


//Not solved

int main()
{
	int n;
	cin>>n;

	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}

	sort(a,a+n);

	int neg =0,pos = 0;
	for (int i=0;i<n;i++ )
	{
		if(a[i]>0)
		{
		    neg = i;
		    pos = i+1;
		    break;
		}
	}
	if(neg==0)
	{
	    if(a[0]==0)
	    {
	        cout<<"0";
	        return 0;
	    }
	}

	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			if(a[neg] == a[pos])
		}

	}

	int cul[n]  = {0};
	int count=1;
	cul[0] = a[0];
	for (int i=pos;i<n-pos;i++ )
	{
		cul[count]+= cul[count-1] + a[i];
	}

	int cul1[n]  = {0};
	int count1=1;
	cul1[0] = a[0];
	for (int i=pos;i<n-pos;i++ )
	{
		cul1[count]+= cul1[count-1] + a[i];
	}
	for (int x=0;x<neg;x++ )
	{
		for (int y=pos;y<n-pos;y++ )
		{
			for (int i=0;i<n;i++ )
			{
				for (int i=0;i<y;i++ )
				{

				}

			}

		}

	}



}
