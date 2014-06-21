#include<iostream>
#include<math.h>

using namespace std;

int mf(int);
int main()
{

    int i=0,n;
    cin>>n;
    cout<<mf(n);

 /*  int n[30];
     while(n[i]!=-1)
        cin>>n[i];

    for(int t=0;t<=i;t++)
        cout<<mf(n[t]);*/
}

int mf(int n)
{
    if(n==1)
        return 1;

    float a;
    register int t=0;
    int g[20];
    int y;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            g[t]=i;
            t++;
        }
    }

    int h=1;

    for(int i=0;i<=t;i++)
    {
        h*=g[i];
    }
    if
    if(h==n)
    {
        return pow(-1,t);

    }
    else
        return 0;
}




















