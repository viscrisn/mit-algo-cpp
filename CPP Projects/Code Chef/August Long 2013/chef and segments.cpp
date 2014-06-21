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
    long long a[n];
    long long left[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int t;
    left[0] = a[0];
    for(int i =1;i<n;i++)
    {
        left[i] = (left[i-1]*a[i]);
    }


    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
        int l,r;
        long long int mul=1,m;
        scanf("%d%d%lld",&l,&r,&m);
        l--;
        r--;
        if(l==0)
            mul =  left[r]%m;
        else if(left[r]/left[l-1] > 0)
            mul = (left[r]/left[l-1])%m;
        else
            mul = 0;
        printf("%lld\n",mul);
    }
}
