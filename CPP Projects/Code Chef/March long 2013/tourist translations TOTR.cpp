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
	int test;
	cin>>test;

	char a[30];
	cin>>a;

	for(int testno = 0; testno < test ; testno++ )
	{
		char t[110];
		cin>>t;
		int len = strlen(t);
		for (int i=0;i<len;i++ )
		{
			if(isalpha(t[i]))
			{
			    if(islower(t[i]))
			    {
			        cout<<char(a[t[i]-'a']);
			    }
			    else
			    {
			        cout<<char(toupper(a[t[i]-'A']));
			    }
			}
			else if(t[i]=='_')
			{
			    cout<<' ';
			}
			else
			{
			    cout<<t[i];
			}
		}
		cout<<"\n";

	}
}
