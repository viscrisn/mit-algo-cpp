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
    int arr[10],lim[10];
    int n,i,j;
    char val[]="FT";
    cout<<"enter n";
    cin>>n;
    for(i=0; i<n; i++)
    {
        arr[i]=0;
        lim[i]=pow(2,i);
    }

    for(i=0; i<pow(2,n); i++)
    {
        for(j=n-1; j>=0; j--)
        {
            cout<<val[arr[j]]<<"\t";
            lim[j]--;
            if(lim[j]==0)
            {
                lim[j]=pow(2,j);
                arr[j]=!arr[j];
            }
        }
        cout<<endl;
    }
}
