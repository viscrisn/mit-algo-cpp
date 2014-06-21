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

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    int sum=0;
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(n%2==0)
    {
        if(sum%2==1)
        {
            cout<<"2";
        }
        else
        {
            cout<<"3";
        }
    }
    else
    {
        if(sum%2==0)
        {
            cout<<"2";
        }
        else
        {
            cout<<"3";
        }
    }

}
