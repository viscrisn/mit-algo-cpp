#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

//NOT WORKING
int find_element(int *array,int n,int ele)
{
    int start = 0;
    int end = n-1;
    int mid;
    while(start < end)
    {
        mid = (start + end)/2;
        if(array[mid]==ele)
            return mid;
        else if(ele < array[mid])
            end = mid-1;
        else if(ele > array[mid])
            start = mid+1;
    }
    return -1;

}
int main()
{
    int len;
    cout<<"Enter number of elements and rotated array\n";
    cin>>len;
    int array[len];
    for (int i=0;i<len;i++ )
    {
    	cin>>array[i];
    }
    cout<<"Enter element to be searched\n";
    int ele;
    cin>>ele;
    int pos = find_element(array,len,ele);
    if(pos==-1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at index: "<<pos<<"\n";
    return 0;
}
