#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;

void bestfit(int h[],int n,int p[],int m)
{
    int temp[n];
    for (int i=0;i<m;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    		temp[j] = h[j] - p[i];
    	}
    	int min=99999,min_index;
    	for (int j=0;j<n;j++ )
    	{
    		if(temp[j] < min && temp[j]>0)
    		{
    		    min = temp[j];
    		    min_index = j;
    		}
    	}
    	cout<<"Process"<<i<<"to hole:"<<min_index<<"\n";
    	h[min_index] -= p[i];

    }


}

int main()
{
    int h_size,p_size;
    cout<<"Enter total no of holes:\t";
    cin>>h_size;
    cout<<"Enter total no of processes:\t";
    cin>>p_size;
    int hole[h_size],process[p_size];
    cout<<"Enter holes\n";
    for (int i=0;i<h_size;i++ )
    {
    	cin>>hole[i];
    }
    cout<<"Enter processes\n";
    for (int i=0;i<p_size;i++ )
    {
    	cin>>process[i];
    }

    //firstfit(hole,h_size,process,p_size);
    bestfit(hole,h_size,process,p_size);
    //worstfit(hole,h_size,process,p_size);

    return 0;
}
