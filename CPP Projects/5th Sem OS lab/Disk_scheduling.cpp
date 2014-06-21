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

void sstf(int req[],int n,int cur)
{
    int mov =0;
    int req1[n];
    for (int i=0;i<n;i++ )
    {
        req1[i] = req[i];
    }

    sort(req1,req1+n);
    int temp[n];
    for (int i=0;i<n;i++ )
    {
    	cout<<"Head is now at:\t"<<cur<<endl;
    	for (int j=0;j<n;j++ )
    	{
    		temp[j] = abs(req1[j] - cur);
    	}
    	int min = 99999,min_index;
    	for (int j=0;j<n;j++ )
    	{
    		if(min > temp[j])
    		{
    		    min = temp[j];
    		    min_index = j;
    		}
    	}



    	mov += abs(req1[min_index] - cur);
    	cur = req1[min_index];
    	req1[min_index] = 99999;
    }

}
void fcfs(int req[],int n,int cur)
{
    int mov =0;
    for (int i=0;i<n;i++ )
    {
    	cout<<"Head is now at:\t"<<cur<<endl;
    	mov += abs(req[i] - cur);
    	cur = req[i];
    }
    cout<<"\ntotal disk arm movement:\t"<<mov;

}
int main()
{
	cout<<"Enter number of requests\n";
	int n;
	cin>>n;
	int req[n];
	cout<<"Enter requests\n";
	for (int i=0;i<n;i++ )
	{
		cin>>req[i];
	}
	cout<<"Enter current head position\n";
	int cur;
	cin>>cur;
	fcfs(req,n,cur);
	sstf(req,n,cur);

}
