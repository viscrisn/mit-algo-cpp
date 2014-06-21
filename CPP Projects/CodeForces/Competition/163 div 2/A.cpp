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
	int len;
	char a[100];
	cin>>len;
	cin>>a;
	int ans =0;
	for (int i=1;i<len;i++ )
	{
		if(a[i]==a[i-1])
            ans++;
	}

    cout<<ans;
}
