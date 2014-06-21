#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

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
    int a[] = {1,2,3,4,5,6,7,8,9};
    quicksort(a,0,8);
    for (int i=0;i<9;i++ )
    {
    	cout<<a[i]<<"\t";
    }

}
