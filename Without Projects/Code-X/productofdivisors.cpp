#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    while(1)
    {

    int n;
    size_t i=10;
    int * sum= (int *)malloc(i);
    //double sum=1;
    int j=0;
    cin>>n;
    int a[30];
    cout<<sizeof(sum);

    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            a[j]=i;
            j++;
        }
    }

    for(int i=0;i<j;i++)
    {
        (*sum)=(*sum)*a[i];
    }

    if((*sum)<9999)
    {

        cout<<(*sum);
    }
    else if((*sum)>9999)
    {
        int qw[4];
        int as=0;
        int t;
        for(int i=0;i<4;i++)
        {
            t=(int)(*sum)/10;
            qw[i]=(int)((*sum)-(t*10));
            (*sum)=(int)t;
        }

        for(int i=3;i>=0;i--)
        {
            cout<<qw[i];
        }

    }

    }

}



