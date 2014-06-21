#include<iostream>
#include "Quicksort.h"

using namespace std;

int main()
{
    int no_of_ele,k;

    cin>>no_of_ele>>k;

    int num_array[no_of_ele];

    for (int i=0;i<no_of_ele;i++ )
    {
    	cin>>num_array[i];
    }

    quicksort(num_array,0,no_of_ele-1);

    int total=0;

    for (int i=0;i<no_of_ele;i++ )
    {
    	for (int j=i+1;j<i+k+1;j++ )
    	{
    		if(j>no_of_ele)
    		{
    		    break;
    		}
    		if(num_array[j]==num_array[i]+k)
    		{
    		    total++;
    		    break;
    		}
    	}

    }

    cout<<total;


}
