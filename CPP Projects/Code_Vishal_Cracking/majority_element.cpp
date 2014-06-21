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

int majority_element(int[], int);

int majority_element(int a[],int n)
{
    if(n==0)
        return -1;
    else if(n==1)
        return a[0];
    int count = 0, cur_ele = a[0];
    for(int i =1; i<n; i++)
    {
        if(cur_ele==a[i])
            count++;
        else
            count--;
        if(count<0)
        {
            cur_ele = a[i];
            count = 0;
        }
    }
    //cur_ele now has the most occuring element
    //Find if its occuring more than n/2 times
    count = 0;
    for(int i =0;i<n;i++)
    {
        if(cur_ele == a[i])
            count++;
    }
    if(count > n/2 )
        return cur_ele;
    else
        return -1;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++)
        cin>>a[i];
    int ans = majority_element(a,n);
    if(ans == -1)
        cout<<"No majority element is present\n";
    else
        cout<<ans;
}
