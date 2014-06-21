#include<iostream>
#include<stdio.h>

using namespace std;

int median(int [],int,int [], int);

void gnome_sort(int a[],int n)
{
    int pos = 1;
    while(pos<n)
    {
        if(a[pos]>=a[pos-1])
            pos++;
        else
        {
            swap(a[pos],a[pos-1]);
            if(pos>1)
                pos--;
        }
    }
}

int median(int a1[],int n1,int a2[], int n2)
{
    gnome_sort(a1,n1);
    gnome_sort(a2,n2);
    int median_pos = (n1+n2)/2;
    bool last_update = false;
    int i=0,j=0,count = 0;
    int result =0;
    while( count <= median_pos)
    {
        if (a1[i] > a2[j])
        {
            j++;
            result = a2[j];
        }
        else
        {
            i++;
            result = a1[i];
        }
        count++;
        if(i > n1)
        {
            j+= median_pos - count;
            break;
        }
    }
    if ((n1+n2) % 2 == 0)
    {
        result = (a1[i] + a2[j]) / 2;
    }
    return result;

}

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int array1[n1],array2[n2];
    for(int i =0; i<n1; i++)
    {
        cin>>array1[i];
    }
    for(int i =0; i<n2; i++)
    {
        cin>>array2[i];
    }
    cout<<median(array1,n1,array2,n2);
}
