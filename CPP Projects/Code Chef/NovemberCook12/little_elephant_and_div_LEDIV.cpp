#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

int gcd(int m,int n)
{
    if(n>m)
    {
        swap(n,m);
    }
    if(n==0)
    {
        return m;
    }
    return gcd(n,m%n);
}

int red_array(int a[],int n)
{
    int k = 0;
    for (int i=0; i<n; i=i+2 )
    {
        a[k++] = gcd(a[i],a[i+1]);
    }
    if(n%2!=0)
    {
        a[k-1] = a[n-1];
    }
    return k;
}
int main()
{
    int test;
    cin>>test;
    for (int test_no=0; test_no<test; test_no++ )
    {
        int n;
        cin>>n;
        int a[n];
        for (int i=0; i<n; i++ )
        {
            cin>>a[i];
        }
        int k = n;
        while(k>1)
        {
            k = red_array(a,k);
        }
        if(a[0]!=1)
        {
            cout<<a[0]<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }

}
