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
#include<set>
#include<queue>
#include<fstream>

using namespace std;

bool is_sorted_queue(queue<int> qu)
{
    int n;
    n = qu.size();
    int temp;
    for (int i=0;i<n-1;i++ )
    {
    	temp = qu.front();
    	qu.pop();
    	qu.push(temp);
    	if(temp > qu.front())
    	{
    	    return false;
    	}

    }
    return true;

}

int main()
{
	queue<int> qu;
	int n;
	cout<<"Enter number of elements to be inserted\n";
	cin>>n;

	int temp;
	cout<<"Enter the elements\n";
	for (int i=0;i<n;i++ )
	{
		cin>>temp;
		qu.push(temp);
	}

	if(is_sorted_queue(qu)==true)
	{
	    cout<<"It is sorted\n";
	}
	else
	{
	    cout<<"It is not sorted\n";
	}
	return 0;
}
