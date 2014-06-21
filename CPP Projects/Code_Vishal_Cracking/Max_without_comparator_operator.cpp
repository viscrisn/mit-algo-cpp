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

bool greater1(int a,int b)
{
    return (bool)((b-a) & (1<<31));
}
int max(int a[],int n)
{
    int max = a[0];
    for (int i=1;i<n;i++ )
    {
    	if(greater1(a[i],max))
            max = a[i];
    }
    return max;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++ )
	{
		cin>>arr[i];
	}
	cout<<max(arr,n);
}
