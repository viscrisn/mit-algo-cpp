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
int sec_largest(int a[],int n)
{
    int lar = a[0], sec_lar = a[1];
    if(lar < sec_lar)
        swap(lar,sec_lar);
    for (int i=2;i<n;i++ )
    {
    	if(a[i] > lar)
    	{
    	    sec_lar = lar;
    	    lar = a[i];
    	}
    }
    return sec_lar;
}
int main()
{
	int n;
	cin>>n;

	int a[n];
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	cout<<sec_largest(a,n);

}
