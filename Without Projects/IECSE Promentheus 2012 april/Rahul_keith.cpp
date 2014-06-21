#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int get(int arr[],int dig,int p)
{
    int sum=0;
    for(int q=1;q<=dig;q++)
    sum+=arr[--p];

    return sum;
}


int keith(int x)
{
    int y=x;
    int ar[30];int i=0;int d=0;

    while(y>0)
    {
        ar[i]=y%10;
        i++;
        y=y/10;
    }

    d=i;
    int l=d-1;int tmp;

    for(int c=0;c<d/2;c++)
    {
        tmp=ar[l];
        ar[l]=ar[c];
        ar[c]=tmp;
        l--;
    }

     int j=i;
     do
     {
        ar[j]=get(ar,d,j);

        if(ar[j]>=x)
            break;
    }while(ar[j++]<=x);

    return ar[j];
}


int main()
{
    int num;
    cin>>num;
    int a=1;
    for(int n=11;n<=100000;n++)
    {
    if(n==keith(n) && a<=num)
    {
        cout<<n<<endl;a++;
    }
    }
}

