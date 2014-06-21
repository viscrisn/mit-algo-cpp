#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	vector<int> array;
	int n;
    cin>>n;
    array.resize(n);
    for (int i=0;i<n;i++ )
    {
    	cin>>array.at(i);
    }

    for (int i=0;i<n;i++ )
    {
    	cout<<array[i]<<"\t";
    }
    cout<<"\n";
    sort(array.begin(),array.end());

    for (int i=0;i<n;i++ )
    {
    	cout<<array[i]<<"\t";
    }
    cout<<"\n";

}
