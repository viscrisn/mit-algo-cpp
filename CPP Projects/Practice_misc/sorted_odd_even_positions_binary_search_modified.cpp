/*we have a array where odd elements has odd position and even elements has even position both are sorted at their positions eg. 4 1 8 3 16 5. Find efficient function to search an element.*/

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

int mod_bin_search(int a[],int n,int ele)
{
    int position = -1;
    int first = 0;
    int last = n/2;
    int mid,index;
    while(first < last)
    {
        mid = (first+last)/2;
        if(ele%2==0)
            index = mid*2;
        else
            index = mid*2 + 1;
        if(a[index] == ele)
        {
            position = index;
            break;
        }
        else if(a[index] > ele)
            last = mid;
        else
            first = mid;
    }
    return position;
}

int main()
{
	int n;
	cout<<"Enter number of elements\n";
	cin>>n;
	int a[n];
	cout<<"Enter elements\n";
	for (int i=0;i<n;i++ )
	{
		cin>>a[i];
	}
	cout<<"Enter element to be searched\n";
	int ele;
	cin>>ele;
	int position = mod_bin_search(a,n,ele);
	if(position >=0)
        cout<<"Element found at postion: "<<position<<"\n";
    else
        cout<<"Not found\n";

    return 0;
}
