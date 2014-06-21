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

const int maxn = 200001;

int n,m;
int A[maxn];
int S[maxn];

int main()
{
    int i,j;
    int x,y,ans = 0,sum;
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {


        cin>>n;
        for (i = 1; i <= n; ++i)
        {
            cin>>A[i];
        }
        sort(A+1,A+n+1);
        for (i = n; i >= 1; --i) ans += A[i]*(n-i);
        for (i = 1; i <= n; ++i) S[i] = S[i-1]+A[i];
        cin>>m;
        while (m--)
        {
            cin>>x;
            if (x == 1)
                cout<<ans<<" ";
            else
            {
                sum = 0;
                for (i = n,y = 1,j = 0; i >= 1; i -= y,y *= x,++j)
                    sum += (S[i]-S[max(i-y,0)])*j;
                cout<<sum<<" ";
            }
        }
        cout<<"\n";
    }
}
