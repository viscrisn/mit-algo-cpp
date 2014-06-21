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

int gcd(int n,int m)
{
    if(m==0)
    {
        return n;
    }
    return gcd(m,n%m);
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
}
