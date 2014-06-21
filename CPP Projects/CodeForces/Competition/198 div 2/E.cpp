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
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int minusone = 0;
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
		if(a[i]==-1)
            minusone++;
        else
            a[i]--;
	}
	int minusfixed = n - minusone;
	for (int i=0;i<n;i++ )
	{
		if(a[i]!=-1)
		{
		    if(a[a[i]]!=-1)
                minusfixed--;
		}
	}
	int count = 1;
	for (int i=0;i<minusfixed;i++ )
	{
		count = (count*minusone)%1000000007;
		minusone--;
	}
	minusone--;
	if(minusone>0)
	{
	    while(minusone > 0)
        {
            count = (count*minusone)%1000000007;
            minusone--;
        }
	}
    cout<<count;
}
