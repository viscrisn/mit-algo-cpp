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
	int a[3][3];
	int index = -1;
	for (int i=0;i<3;i++ )
	{
		for (int j=0;j<3;j++ )
		{
			cin>>a[i][j];
		}
		if(a[i][i]!=0)
		{
		    index = i;
		}
	}
	int sum =0;
	if(index!=-1)
	{
	    for (int i=0;i<3;i++ )
	    {
	    	sum+= a[index][i];
	    }
	    for (int i=0;i<3;i++ )
	    {
	    	if(a[i][i]==0)
	    	{
	    	    if(i == 0)
                    a[i][i] = sum - (a[i][1] + a[i][2]);
	    	    if(i == 1)
                    a[i][i] = sum - (a[i][0] + a[i][2]);
	    	    if(i == 2)
                    a[i][i] = sum - (a[i][1] + a[i][0]);
	    	}
	    }
	}
	else
	{
        a[0][0] = ((a[2][1] + a[2][0]) +
                   (a[1][0] + a[1][2]) -
                   (a[0][1] + a[0][2]))/2;

        a[1][1] = ((a[0][1] + a[0][2]) +
                   (a[2][0] + a[2][1]) -
                   (a[1][0] + a[1][2]))/2;

        a[2][2] = ((a[0][1] + a[0][2]) +
                   (a[1][0] + a[1][2]) -
                   (a[2][1] + a[2][0]))/2;
	}
	for (int i=0;i<3;i++ )
	{
		for (int j=0;j<3;j++ )
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
    }

}
