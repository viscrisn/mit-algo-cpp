#include<iostream>
#include<stdio.h>
using namespace std;
//This is actually Linear sort. This program is wrong. Make it right, right now.
int binarysort(int [],int);
int main()
{
    int a[32],n;
    cout<<"enter no of elements";
    cin>>n;
    cout<<"enter the elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    binarysort(a,n);
}

int binarysort(int b[],int n)
{
    int temp;

    for(int j=0;j<n;j++)
    {
        for(int i=j+1;i<n;i++)
        {
            if(b[i+1]<b[j])
            {
                temp = b[i+1];
                b[i+1] = b[j];
                b[j] = temp;
            }
        }
    }

    //Linear search hai kya???????
    /*Chalo linear seach bhi lik ke dekte hai
    temp = b[0];
    for(int j=0;j<n;j++)
    {
        for(int i=j+1;i<n;i++)
            {
                if(b[i]<temp)
                {
                    swap temp and b[i];
                }
            }
    }
    */

    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}















