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

//finds number of such triplets who are in AP
int ap_3sum_cont(int a[],int n)
{
    int ans=0;
    for (int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(a[j]-a[i]==a[k]-a[j])
                    ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n][2];
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
    }
    int ans = ap_3sum_cont(a,n);
    cout<<ans<<"\n";

}
