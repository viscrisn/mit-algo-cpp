/*Not working properly. Check Later*/

#include<iostream>

using namespace std;

void adjust(int [],int ,int);
void heapsort(int [],int);

int main()
{
    int size;
    cout<<"Enter no of elements\n";
    cin>>size;
    int a[size+1];
    cout<<"Enter the elements\n";

    for(int i=1;i<=size;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    heapsort(a,size);

    for(int i=1;i<=size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


}

void adjust(int a[],int r,int n)
{
    int child,rootkey;
    rootkey= a[n];
    child=2*r;
    while(child<=n)
    {
        if((child<n)&&a[child]<a[child+1])
            child++;

        if(rootkey>a[child])
            break;
        else
        {
            a[child/2]=a[child];
            child*=2;
        }
    }
    a[child/2]=rootkey;
}

void heapsort(int a[],int n)
{
    int i,j,temp;
    for(i=n/2;i>0;i--)
    {
        adjust(a,i,n);
    }
    for(i=n-1;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i+1];
        a[i+1]=temp;
        adjust(a,1,i);
    }
}
