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
#include<fstream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int total = pow(2,n);
    for (int i=0;i<total;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    	    if(((i>>j)&1)==1)
                cout<<'t';
    		else
                cout<<'h';
    	}
    	cout<<"\n";
    }


}
