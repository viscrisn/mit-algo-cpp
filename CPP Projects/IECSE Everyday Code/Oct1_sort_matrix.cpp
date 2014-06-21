/*
First Question of The October <code> Nights:

"There is an NxN matrix is which each row alone is sorted, the column is not. Convert it to a 1-D sorted array."
*/

//Can be done very efficiently in linear time by using merge sort but done this way cause of laziness.

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

	int mat[n][n];
    int nsq=n*n;
	int ans[nsq];
	int count=0;

	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cin>>mat[i][j];
			ans[count++]=mat[i][j];
		}
	}

	quicksort(ans,0,nsq);

	for (int i=0;i<nsq;i++ )
	{
		cout<<ans[i]<<"\n";
	}


}
