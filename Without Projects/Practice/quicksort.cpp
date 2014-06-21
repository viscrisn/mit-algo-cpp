#include<iostream>
#include<stdio.h>

using namespace std;
int partition(int a[], int left, int right, int pivotIndex)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left < right && a[left] != a[right])
        {
           // swap(a[left], a[right]);
           int temp = a[left];
           a[left] = a[right];
           a[right]  = temp;
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}
void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
}
int main()
{
    int a[32],t,n,p=0;
    cout<<"enter the no. of elements\n";
    cin>>n;
    cout<<"enter the elements now\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
