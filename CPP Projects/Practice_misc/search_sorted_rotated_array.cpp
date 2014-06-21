//Started 10:43pm 25-08-2012
//Doing only for general cases.
//Not considering Extreme cases
//Finished 11:13pm
//Debugging took 15-20 mins
//Working

#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter in sorted, rotated fashion:\n";
    for (int i=0;i<n;i++ )
    {
    	cin>>a[i];
    }

    cout<<"Enter number to be searched\n";
    int key;
    cin>>key;

    /*
    //Sample test case
    int key = 6;
    int a[] = {4,5,6,7,8,9,10,1,2,3};
    int n = 10;
    */

    int start =0;
    while((a[start] < a[start+1])&&(start<n))
    {
        start++;
    }
    start++;

    if(start == n-1)
    {
        start = 0;
    }

    int last = n + start - 1;
    int mid=(start + last)/2;
    int flag =0;
    while(last>start)
    {
    	mid = mid%n;
    	if(a[mid] == key)
    	{
    	    flag = 1;
    	    break;
    	}
    	else if(a[mid] > key)
    	{
    	    if(mid < start)
                last = mid + n;
            else
                last = mid;

    	    mid=(start + last)/2;
    	}
    	else
    	{
    	    if(mid < start)
                start = mid + n;
            else
                start = mid;

    	    mid=(start + last)/2;
    	}

    }

    if(flag ==1)
    {
        cout<<"Element found at:  "<<mid;
    }
    else
    {
        cout<<"Element not found\n";
    }

}
