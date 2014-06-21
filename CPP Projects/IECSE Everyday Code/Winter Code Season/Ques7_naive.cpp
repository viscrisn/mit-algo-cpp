#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<queue>

using namespace std;

//Naive solution. O(n^2)
//Using dynamic programming by storing number of counts and jumps in an array.
//Solution of O(nlogn) is possible, but didn't code that as time complexity doesn't count it seems.
//This will also give correct output.
//100% sure that most participants sent this solution :P

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];
	for (int i=0;i<n;i++ )
	{
		cin>>arr[i];
	}
	for (int test=0;test<m;test++ )
	{
		int type;
		cin>>type;
		int count=0, last;
		if(type==1)
		{
		    int pos;
		    cin>>pos, pos--;
            while(pos<=n-1)
            {
                count++;
                last = pos;
                pos+=arr[pos];
            }
            cout<<last+1<<" "<<count<<"\n";
		}
		else
		{
		    int a, b;
		    cin>>a>>b, a--;
		    arr[a] = b;
		}

	}


}
