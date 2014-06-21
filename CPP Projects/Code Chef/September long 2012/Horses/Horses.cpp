#include<iostream>

int partition(long long a[], int left, int right, int pivotIndex)
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
void quicksort(long long a[], int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
}

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int n;
        cin>>n;
        long long a[n];
        for (int i=0;i<n;i++ )
        {
        	cin>>a[i];
        }

        quicksort(a,0,n);


        int min_diff=9999;
        for (int i=0;i<n-1;i++ )
        {
            if((a[i+1]-a[i])<min_diff)
            {
                min_diff = a[i+1] - a[i];
            }
        }
        cout<<min_diff<<"\n";


    }
}
