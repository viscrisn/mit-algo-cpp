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

    cin>>a;
    int len = strlen(a);

    for (int i=0;i<len;i++ )
    {
    	a[i] = a[i] - '0';
    }

    for (int i=0;i<len-1;i++ )
    {
    	if(a[i]+a[i+1]==9)
    	{
    	    cout<<"Yes";
    	    return 0;
    	}
    }
    cout<<"NO";


}
