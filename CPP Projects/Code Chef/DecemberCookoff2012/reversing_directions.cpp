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

        int n;
        cin>>n;
        string a[n];
        for (int i=0; i<n; i++ )
        {
            getline(cin,a[i]);
            if(i==0)
            {
                getline(cin,a[i]);
            }
        }

        int r,l,b;
        r = a[n-1].find_first_of("Right");
        l = a[n-1].find_first_of("Left");
        b = a[n-1].find_first_of("Begin");
        for (int i=n-1; i>=0; i-- )
        {


            r = a[i].find_first_of("Right");
            l = a[i].find_first_of("Left");
            b = a[i].find_first_of("Begin");
        }


        /*
        for (int i=0;i<n;i++ )
        {
        	cout<<i<<" "<<a[i]<<"\n";
        }
        */



    }
}
