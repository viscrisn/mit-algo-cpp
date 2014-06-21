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

int main()
{
    int n;
    cin>>n;
    int a[100];
    int count =0;
    while(n!=0)
    {
        a[count++] = n%2;
        n/=2;
    }
    for (int i=count-1;i>=0;i-- )
    {
    	cout<<a[i];
    }

}
