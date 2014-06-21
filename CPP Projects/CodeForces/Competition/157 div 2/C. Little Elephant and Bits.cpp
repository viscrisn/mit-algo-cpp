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

char a[100010];

int main()
{
	cin>>a;
	int len = strlen(a);
	int flag =0;
	for (int i=0;i<len-1;i++ )
	{
		if(flag == 0)
		{
		    if(a[i] == '0')
		    {
		        flag =1;
		        continue;
		    }
		    else
		    {
		        cout<<a[i];
		    }
		}
		else
		{
		    cout<<a[i];
		}
	}
	if(flag == 1)
        cout<<a[len -1];

}
