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
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        int d1,d2,d3;
        cin>>d1>>d2>>d3;
        int d4;
        if(d1+d2 >= d3)
        {
            d4 = min(d1,d2) + d3;
            if(d4 >= max(d1,d2))
            {
                cout<<0<<"\n";
            }
            else
            {
                cout<<(max(d1,d2) - d4)<<"\n";
            }
        }
        else
        {
            cout<<(d3-(d1+d2))<<"\n";
        }
    }
}
