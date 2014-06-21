#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int first;
    cin>>first;
    int n;
    cin>>n;

    n++;

    int *a = (int *)calloc(n,sizeof(int));
    int j;

    for(int i=2;i<n;i++)
    {
        a[i]=i;
    }

    for(int i=2;i<sqrt(n);i++ )
    {
    	if(a[i]!=0)
    	{
    	    j=i*i;
    	    while(j<=n)
    	    {
    	        a[j]=0;
    	        j=j+i;
    	    }
    	}
    }

    int final[n];
    j=0;
    for (int i=2;i<n;i++ )
    {
    	if(a[i]!=0)
    	{
    	    final[j]=a[i];
    	    j++;
    	}
    }

    for (int i=0;i<j;i++ )
    {
        if(final[i]>=first)
    	cout<<final[i]<<"\t";
    }



}
