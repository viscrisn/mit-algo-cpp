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
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for (int i=0;i<m;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    		cin>>a[i][j];
    	}
    }
    for (int i=0;i<m;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
               // b[i][j]=a[]
    	}
    }
    cout<<a[0][0]<<"\n";
    cout<<a[0][1]<<" "<<a[1][0]<<"\n";
    cout<<a[0][2]<<" "<<a[1][1]<<" "<<a[2][0]<<"\n";
    cout<<a[0][3]<<" "<<a[1][2]<<"\n";
    cout<<a[0][0]<<" "<<a[0][0]<<"\n";

}
