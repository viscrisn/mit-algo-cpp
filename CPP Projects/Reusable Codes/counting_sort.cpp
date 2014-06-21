//CONSTRAINT:- NUMBERS MUST BE POSITIVE INTEGERS
//Working fine.
// 04-08-2012 started 6:59pm, finished 7:08pm
#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter no of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    int a[n];
    int k=0;
    for (int i=0;i<n;i++ )
    {
    	cin>>a[i];
    	if(a[i]>k)
    	{
    	    k = a[i];
    	}
    }
    k++;

    int c[k];
    for (int i=0;i<k;i++ )
    {
    	c[i] = 0;
    }

    for (int i=0;i<n;i++ )
    {
    	c[a[i]]++;
    }
    for (int i=2;i<k;i++ )
    {
    	c[i]+=c[i-1];
    }

    int final[n];
    for (int i=0;i<n;i++ )
    {
    	final[--c[a[i]]] = a[i];
    }
    for (int i=0;i<n;i++ )
    {
    	cout<<final[i]<<"\t";
    }






}
