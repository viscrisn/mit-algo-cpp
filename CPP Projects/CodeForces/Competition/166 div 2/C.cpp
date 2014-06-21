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
    int n,k;
    cin>>n>>k;
    if(n<3*k)
    {
        cout<<"-1";
        return 0;
    }
    int group =0;
    group = n/k;
    if(n%k!=0)  group++;

    int a[k],b[k];
    for (int i=0; i<k; i++ )
    {
        a[i] = i+1;
    }

    int temp = a[0];
    for (int t=0; t<k-1; t++ )
    {
        b[t] = a[t+1];
    }
    b[k-1] = temp;

    int count1 = 0;
    int flag = 0;
    for (int i=0; i<group; i++ )
    {
        if(flag<2)
        {
            flag++;
            for (int j=0; j<k; j++ )
            {
                cout<<a[j]<<" ";
                count1++;
                if(count1==n)
                {
                    return 0;
                }
            }
        }
        else
        {
            flag++;
            for (int j=0; j<k; j++ )
            {
                cout<<b[j]<<" ";
                count1++;
                if(count1==n)
                {
                    return 0;
                }
            }
            if(flag==4)
            {
                flag = 0;
            }
        }

    }

}
