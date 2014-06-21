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
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
        sum+= a[i];
    }
    int s = a[0];
    int ind = n;
    while(sum>0)
    {
        ind--;
        sum -= 2*a[ind];

    }
    if(sum+(2*a[ind]) < s)
    {
        ind++;
        for (int i=0; i<ind; i++ )
        {
            cout<<"+";
        }
        for (int i=ind; i<n; i++ )
        {
            cout<<"-";
        }
        return 0;
    }
    sum += 2*a[ind];
    ind++;
    int frnt_ind=0;
    while(sum>s)
    {
        sum -= 2*a[frnt_ind];
        frnt_ind++;
        cout<<"-";
    }
    for (int i=frnt_ind; i<ind; i++ )
    {
        cout<<"+";
    }
    for (int i=ind; i<n; i++ )
    {
        cout<<"-";
    }
    return 0;


}
