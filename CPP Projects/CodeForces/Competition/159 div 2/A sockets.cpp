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
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
    }
    sort(a,a+n);

    int ans =0;
    int cur = n-1;
    while(1)
    {
        if(m<=k)
        {
            cout<<ans;
            return 0;
        }
        if(cur > -1)
        {
            k+= a[cur] - 1;
            ans++;
            cur--;
        }
        else
        {
            ans = -1;
            m = -1;
        }
    }

}
