#include<iostream>
#include<stdlib.h>

using namespace std;

int lsearch(int *,int , int);
int print(int);
int main()
{
    int t,n,k;
    cout<<"Enter no. of elements\n";
    cin>>t;
    int *ptr=(int *)calloc(t,sizeof(int));

    cout<<"Enter the elements\n";
    for(int i=0;i<t;i++)
    {
        cin>>*(ptr+i);
    }

    int key;
    cout<<"Enter the elements to be seached\n";

    cin>>key;
    /*for(int i=0;i<t;i++)
    {
        cout<<"\t"<<*(ptr+i);
    }*/
    k=lsearch(ptr,t,key);
    print(k);
}

int lsearch(int *p,int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(*(p+i)==key)
        {
            return 1;
            break;
        }
        else if(*(p+i)!=key)
        {
            return -1;
        }

    }

}

int print(int k)
{
    if(k==1)
    {
        cout<<"The number is found :)";
    }
    else if(k==-1)
    {
        cout<<"The number is not present.";
    }
    return 0;
}







