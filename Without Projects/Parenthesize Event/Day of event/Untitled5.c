#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
   cin>>n;
  int count=0;
  int *a=new int[n];
  int *b=new int[n];

  for(int i=0;i<n;i++)
  {
    cin>>a[i];
}
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    int *u=new int[n+n];
    for(int i=0;i<n;i++)
        u[i]=a[i];
    int pos=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<pos;j++)
        {
            if(b[i]==u[j])
                break;
        }
        if(j==pos)
        u[pos++]=b[i];
    }
    int *x=new int[n];
    int posx=0
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
                break;
        }
        if(j==n)
            x[posx++]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<u[i]<<" ";
    }
    for(int j=0;j<n;j++)
    {
        cout<<u[j]<<" ";
    }
    }

