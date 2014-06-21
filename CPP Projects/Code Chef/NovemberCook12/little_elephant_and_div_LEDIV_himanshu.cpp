#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<set>

using namespace std;

int main()
{
    int test;
    cin>>test;
    for (int test_no=0; test_no<test; test_no++ )
    {
        int n;
        int fl=0;
        int min=0;
        cin>>n;
        vector<int> a;
        a.resize(n);
        sort(a.begin(),a.end());
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        min = a[0];

        while(min>1)
        {
            fl=0;
            for(int i=0; i<n; i++)
            {
                if(a[i]%min!=0)
                {
                    fl=1;
                }
            }
            if(fl==0)
                break;

            min--;
        }
        if(min==1)
            cout<<"-1\n";
        else if(fl==0)
            cout<<min<<"\n";
        else
            cout<<"-1\n";
    }
}
