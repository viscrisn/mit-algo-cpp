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
	char a[100];
	char b[100];
	cin>>a>>b;
	int len1,len2;
	len1 = strlen(a);
	len2 = strlen(b);

    sort(a,a+len1);
    sort(b,b+len2);
    int arr1[256] = {0};
    int arr2[256] = {0};

    for (int i=0;i<len1;i++ )
    {
    	arr1[a[i]]++;
    }
    for (int i=0;i<len2;i++ )
    {
    	arr2[b[i]]++;
    }
    for (int i=0;i<256;i++ )
    {
    	arr1[i] = abs(arr1[i] - arr2[i]);
    }
    int sum =0;
    for (int i=0;i<256;i++ )
    {
    	sum+=arr1[i];
    }
    sum+=abs(len1-len2);

    sum-=3;

    cout<<sum;


}
