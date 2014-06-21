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

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        int x= 0;
        for (int i=1; i<=n; i++ )
        {
            if(n%i==0)
            {
                if(x==0)
                {
                    x=1;
                }
                else
                {
                    x=0;
                }
            }
        }
        if(x==0)
            cout<<"no";
        else
            cout<<"yes";
    }


}
