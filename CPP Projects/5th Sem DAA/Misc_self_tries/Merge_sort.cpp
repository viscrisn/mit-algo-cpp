//INCOMPLETE DUE TO SLEEPiNESS
#include<iostream>

using namespace std;

void mergesort(int [],int);
void merge(int[],int[],int, int);

int main()
{
    int n;
    cout<<"Enter no of elements\n";
    cin>>n;

    int a[n];
    cout<<"Enter the elements\n";
    for (int i=0;i<n;i++ )
    {
    	cin>>a[i];
    }

    mergesort(a,n);

    for (int i=0;i<n;i++ )
    {
    	cout<<a[i]<<"\t";
    }

}

int[] mergesort(int a[],int n)
{
    if(n<=1)
    {
    	return;
    }
    int mid = n/2;
    int left[mid];
    int right[mid];

    for (int i=0;i<mid;i++ )
    {
    	left[i]=a[i];
    }
    int index=0;
    for (int i=mid;i<n;i++ )
    {
    	right[index++]=a[i];
    }

    mergesort(left,mid);
    mergesort(right,index);

    return merge(left,right,mid,index);
}

int[] merge(int left[],int right[],int lsize,int rsize)
{
    int result[lsize+rsize];
    while ((lsize > 0) || (rsize > 0))
    {
        if ((lsize > 0) && (rsize > 0))
        {
            if first(left) <= first(right)
                append first(left) to result
                left = rest(left)
            else
                append first(right) to result
                right = rest(right)
        }
        else if length(left) > 0
            append first(left) to result
            left = rest(left)
        else if length(right) > 0
            append first(right) to result
            right = rest(right)
    }
    return result
}
