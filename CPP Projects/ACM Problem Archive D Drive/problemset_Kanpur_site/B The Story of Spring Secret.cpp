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
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int n;
		cin>>n;
		char str1[110];
		int m =0,count = 0;
		for (int i=0;i<n;i++ )
		{
			cin>>str1;
			m = strlen(str1);
			if(m==6 && strcmp(str1,"hilsha")==0)
                count++;
		}
		cout<<count<<"\n";
	}
}
