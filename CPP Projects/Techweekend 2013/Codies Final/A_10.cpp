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

    n+=2;
    int count = 1;
    for (int i=1;i<=n;i++ )
    {
        count = 1;
    	for (int j=1;j<n-i;j++ )
    	{
    		cout<<(count++)*i<<" ";
    	}
        cout<<"\n";
    }

}
