#include<iostream>

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
    int n;
    cin>>n;
    int a[n];

    cin>>a[0]>>a[1]>>a[2]>>a[3];
    quicksort(a,0,3);
    int first =a[3],second=a[2],third=a[1],fourth=a[0];
    for (int i=4;i<n;i++ )
    {
    	cin>>a[i];
    	if(a[i]>first)
    	{
    	    fourth = third;
    	    third = second;
    	    second = first;
    	    first =a[i];
    	}
    	else if(a[i]>second)
    	{
    	    fourth = third;
    	    third = second;
    	    second = a[i];
    	}
    	else if(a[i]>third)
    	{
    	    fourth = third;
    	    third = a[i];
    	}
    	else if(a[i]>fourth)
    	{
    	    fourth = a[i];
    	}
    }
    //Input complete

    cout<<first<<"\n";
    cout<<second<<"\n";
    cout<<third<<"\n";
    cout<<fourth<<"\n";


}
