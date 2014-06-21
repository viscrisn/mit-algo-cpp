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

using namespace std;

int main()
{
	string a = "";
	cin>>a;

	int len = a.length();
	int freq[26] = {0};

	for (int i=0;i<len;i++ )
	{
		freq[a[i]-'a']++;
	}
	int ans =0;
	for (int i=0;i<26;i++ )
	{
		if(freq[i]%2==0)
		{
		    freq[i] = 0;
		}
		else
		{
		    ans++;
		}
	}
	if(ans==0)
	{
	    cout<<"First";
        return 0;
	}
	ans -=1;

	if(ans%2==0)
	{
	    cout<<"First";
	    return 0;
	}
	else
	{
	    cout<<"Second";
	    return 0;
	}

}
