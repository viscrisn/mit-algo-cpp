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
	int n,k;
	cin>>n>>k;
	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int k_arr[k];
	for (int i=0,ind = k-1; i<k ;i++,ind-- )
	{
		k_arr[i] = ind - i;
	}
	uint64_t min_total = -1;
    for (int i=0;i<=n-k;i++ )
    {
        uint64_t min = 0;
    	for (int j=0;j<k;j++ )
    	{
    		min += a[i+j]*(-k_arr[j]);
    	}
    	if(min_total > min)
            min_total = min;
    }
    cout<<min_total;

}
