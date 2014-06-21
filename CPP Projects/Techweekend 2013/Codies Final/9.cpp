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

int main()
{
    int a,b;
    cin>>a>>b;
    if(b>a)
    {
        swap(a,b);
    }
    int sum =0;
    if(a==0)
    {
        cout<<b;
        return 0;
    }
    if(b==0)
    {
        cout<<a;
        return 0;
    }
    if(a>0 && b>0)
    {
        for (int i=0; i<b; i++ )
        {
            a++;
        }
    }
    if(a>0 && b<0)
    {
        for (int i=0; i<abs(a); i++ )
        {
            b++;
        }
        sum = b;
        cout<<sum;
        return 0;
    }
    if(a<0 && b>0)
    {
        for (int i=0; i<abs(a); i++ )
        {
            b--;
        }
        sum = b;
        cout<<sum;
        return 0;
    }
    if(a<0 && b<0)
    {
        for (int i=0; i<abs(b); i++ )
        {
            a--;
        }
    }

    sum = a;
    cout<<sum;
}
