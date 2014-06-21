#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<set>

using namespace std;

int main()
{
	set<int> ele;
	int k,size_ele;
	cin>>size_ele>>k;
	int temp;
	for (int i=0;i<size_ele;i++ )
	{
		cin>>temp;
		ele.insert(temp);
	}

    int total=0;
	set<int>::iterator itr;
	for ( itr=ele.begin() ; itr != ele.end() ;++itr )
	{
		if(ele.find((*itr)+k) != ele.end())
		{
		    total++;
		}
	}
    cout<<total;



}
