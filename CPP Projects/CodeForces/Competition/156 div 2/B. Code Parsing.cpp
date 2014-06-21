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
	char s[1000001];
	cin>>s;
	int len = strlen(s);
	int x=0,y=0;
	for (int i=0;i<len;i++ )
	{
		if(s[i]=='x')   x++;
		if(s[i]=='y')   y++;
	}
	int diff = abs(x-y);
	if(x>y)
	{
	    for (int i=0;i<diff;i++ )
	    {
	    	cout<<'x';
	    }
	}
	else
	{
	    for (int i=0;i<diff;i++ )
	    {
	    	cout<<'y';
	    }
	}

}
