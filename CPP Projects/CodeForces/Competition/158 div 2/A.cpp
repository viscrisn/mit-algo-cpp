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
	long long a,b,n;
	cin>>a>>b>>n;

	long long temp;
	long long temp2,ans;

    temp  = a;
	for (int i=0;i<n;i++ )
	{
	    temp = temp*10;
		for (int j=0;j<=10;j++ )
		{
			if(temp%b == 0)
			{
			    break;
			}
			else
			{
			    temp++;
			    if(j==10)
			    {
			        cout<<"-1";
			        return 0;
			    }
			}
		}

	}

	if(temp%b!=0)
        cout<<"-1";
    else
	cout<<temp;




}
