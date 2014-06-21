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

struct array
{
    int i,v;
} a[1010];

int n,L,H;
int test;

bool cmp(array c, array d)
{
    return c.v < d.v;
}
int main()
{
    cin>>test;
    for(int testno = 0; testno < test ; testno++ )
    {
        cin>>n>>L>>H;
        for (int i=0; i<n; i++ )
        {
            cin>>a[i].v;
            a[i].i = i;
        }
        sort(a,a+n,cmp);
        int I = 0, J = n-1, K = J -1;
        int sum,counter = 0;
label1:
        while(I<n-2)
        {
            for (J = n-1; J>I+1; J-- )
            {
                for (K = J-1; K>I; K-- )
                {
                    sum = a[I].v + a[J].v + a[K].v;
                    if(sum > H)
                        break;
                    else if(sum >= L && a[I].i < a[K].i
                            && a[K].i < a[J].i)
                    {
                        counter++;
                    }
                    else if(sum < L)
                    {
                        I++;
                        goto label1;
                    }
                }

            }
            I++;

        }
        cout<<counter<<"\n";

    }
}
