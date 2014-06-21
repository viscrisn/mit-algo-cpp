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
	char a[100];
	char b[100];

	int k[200] = {0};

	cin.getline(a,100,'\n');
	cin.getline(b,100,'\n');

	int len_a = strlen(a);
	int len_b = strlen(b);

	for (int i=0;i<len_b;i++ )
	{
		k[b[i]] = 1;
	}

	for (int i=0;i<len_a;i++ )
	{
		if(k[a[i]]==1)
		{
		    continue;
		}
		else
		{
		    cout<<a[i];
		}
	}



}
