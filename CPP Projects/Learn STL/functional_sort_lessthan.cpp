#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    vector<int> array;
    vector<int>::iterator i;
    int n;
    cin>>n;
    array.resize(n);

    for (i=array.begin();i<array.end();i++ )
    {
    	cin>>*i;
    }

    for (i=array.begin();i<array.end();i++ )
    {
    	cout<<*i<<"\t";
    }
    cout<<"\n";

    sort(array.begin(),array.end(),greater<int> ());

    for (i=array.begin();i<array.end();i++ )
    {
    	cout<<*i<<"\t";
    }
    cout<<"\n";
}
