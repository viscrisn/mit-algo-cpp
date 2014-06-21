#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<sstream>
#include<queue>
#include<cstdlib>
#include<map>
#include<set>

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


class ColorfulChocolates
{
    public:
    int maximumSpread(string mem, int maxSwaps)
    {
        int n = mem.size();
        int array[n];

        for (int i=0;i<n;i++ )
        {
        	array[i] = mem[i] - 'A' + 1;
        }

        int count=1;
        int index_prev = 0;
        int count_max = 1;
        for (int i=0;i<n;i++ )
        {
        	if(array[i]==array[i+1])
        	{
        	    count++;
        	}
        	else
        	{
        	    if(count>count_max)
        	    {
        	        count_max = count;
                    index_prev =i;
        	    }
        	    count =1;
        	}
        }
        //cout<<count_max;
        int index_last = index_prev + count_max-1;
        int number = array[index_prev];
        int count_number_max=0;
        for (int i=0;i<n;i++ )
        {
        	if(number == array[i])
        	{
        	    count_number_max = 0;
        	}
        }
        int maxed_number[count_number_max];
        int counter =0;
        for (int i=0;i<n;i++ )
        {
        	if(number == array[i])
        	{
        	    maxed_number[counter++] = i;
        	}
        }
        int difference[count_number_max*2];
        for(int i=0;i<counter;i++)
        {
            difference[i] = maxed_number[i] - index_prev;
        }
        for(int i=counter;i<count_number_max*2;i++)
        {
            difference[i] = index_last - maxed_number[i];
        }

        quicksort(difference,0,count_number_max*2);

        int ans = count_max;
        for (int i=0;i<count_number_max*2;i++ )
        {
        	if(difference[i] < maxSwaps)
        	{
        	    ans++;
        	    maxSwaps = maxSwaps - difference[i];
        	}
        }
        return ans;

    }
};

int main()
{
    ColorfulChocolates a;
    a.maximumSpread("ABBBCCAAAAA",2);
}



