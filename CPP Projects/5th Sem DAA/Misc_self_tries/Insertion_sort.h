#include<iostream>

using namespace std;

void i_sort(int a[],int len)
{
    for (int i=1;i<len;i++ )
    {
        int item = a[i];
        int iHole = i;
    	while((iHole > 0) && (a[iHole - 1]>item))
    	{
    	    a[iHole] = a[iHole - 1];
    	    iHole = iHole - 1;
    	}
        a[iHole] = item;
    }

}
