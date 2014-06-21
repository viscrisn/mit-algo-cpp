#include<iostream>

using namespace std;

void merge(int[],int,int,int);
void merge_sort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
    else
        return;
}
void merge(int a[],int low,int mid,int high)
{
    int h,i,j,b[50],k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++ )
    {
        cin>>a[i];
    }

    for (int i=0; i<n; i++ )
    {
        cout<<a[i]<<"\t";
    }

    merge_sort(a,0,n);

    cout<<"After sorting\n";
    for (int i=0; i<n; i++ )
    {
        cout<<a[i]<<"\t";
    }


}
