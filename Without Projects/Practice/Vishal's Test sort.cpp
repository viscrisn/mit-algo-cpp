#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
int vishal(int [],int);
int main()
{
    int a[100],n;

    cout<<"enter no. of elements\n";
    cin>>n;

    cout<<"enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vishal(a,n);
}

int vishal(int a[],int n)
{
    int b[100];

    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }

    for(int i=0;i<100;i++)
    {
        a[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        /*if(a[b[i]][0]==b[i])
        {
            for(int j=1;j<n;j++)
            {
                if(a[b[i]][j]!=b[i])
                {
                    a[b[i]][j]=b[i];
                }
            }
        }*/
        a[b[i]]=b[i];
    }


    for(int i=0;i<100;i++)
    {
        if(a[i]!=0)
        {
            cout<<a[i]<<" ";
        }
    }
}


