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
    int n;
    cin>>n;
    int count =1;
    for (int i=1;i<=n;i++ )
    {
    	for (int j=0;j<n-i;j++ )
    	{
    		cout<<" ";
    	}
    	for (int j=0;j<i;j++ )
    	{
    		cout<<count++<<" ";
    	}
    	cout<<"\n";


    }

}

