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
