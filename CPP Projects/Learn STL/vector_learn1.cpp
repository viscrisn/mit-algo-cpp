#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	vector<int> array;
    int n;
    cin>>n;
    array.resize(n);
    for (int i=0;i<array.size();i++ )
    {
    	cin>>array.at(i);
    }

    vector<int>::iterator cur;
    cur = array.begin();

//Finds out largest number in the array
    int high = *cur;
    cur++;
    while(cur!=array.end())
    {
        if(*cur > high)
        {
            high = *cur;
        }
        cur++;
    }
    cout<<high<<"\n";

    for (int i=0;i<array.size();i++ )
    {
    	cout<<array.at(i)<<"\t";
    }

    cout<<endl;
//Alternate way to print
    for (cur=array.begin();cur<array.end();cur++ )
    {
    	cout<<*cur<<"\t";
    }

}
