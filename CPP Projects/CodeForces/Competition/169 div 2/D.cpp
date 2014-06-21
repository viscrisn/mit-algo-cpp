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

    long long l,m;
    cin>>l>>m;

    if(l==m)
    {
        cout<<0;
        return 0;
    }
    if(l>m)
        swap(l,m);

    long long k =1;
    long long power2[63];
    int t =63;
    for (int i=0; i<63; i++ )
    {

        power2[i] = k;
        k = k*2;
        if(power2[i]>m)
        {
            t =i;
            break;
        }
    }
    for (int i=t; i>=0; i-- )
    {
        if(((m>>i)%2) == 1)
        {
            continue;
        }
        if((l|power2[i]) <= m)
        {
            l = l|power2[i];
            cout<<l<<"\n";
        }
    }
    cout<<(l|m);



}
