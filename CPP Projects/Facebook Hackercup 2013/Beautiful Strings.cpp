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
    //freopen("beautiful_stringstxt","r",stdin);
    //freopen("beautiful","w",stdout);
	int test;
	cin>>test;

    getchar();
	for(int testno = 0; testno < test ; testno++ )
	{
	    char s[510];
		int freq[27] = {0};
		cin.getline(s,510,'\n');
		int len = strlen(s);
		char temp;
		for (int i=0;i<len;i++ )
		{
		    temp = s[i];
			if(isalpha(temp))
			{
			    if(isupper(temp))
			    {
			        freq[temp - 65]++;
			    }
			    else
			    {
			        freq[temp - 97]++;
			    }
			}
		}
		sort(freq,freq+27);
		reverse(freq,freq+27);
		int ans = 0;
        for (int i=0;i<26;i++ )
        {
        	ans += freq[i]*(26-i);
        }
        cout<<"Case #"<<testno+1<<": "<<ans<<"\n";

	}
}
