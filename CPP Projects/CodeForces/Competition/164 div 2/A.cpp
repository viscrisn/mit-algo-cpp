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
    int a[n][2];
    for (int i=0; i<n; i++ )
    {
        cin>>a[i][0]>>a[i][1];
    }

    int ans = 0;
    for (int i=0; i<n; i++ )
    {
        for (int j=0; j<n; j++ )
        {
            if(a[i][0]==a[j][1])
            {
                ans++;
            }
        }


    }
    cout<<ans;

}
