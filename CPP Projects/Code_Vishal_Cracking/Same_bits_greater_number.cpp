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

int greater_same_bits(int n)
{
    int i = 0,count = 0;
    bool flag = false;
    for (i=0;i<32;i++ )
    {
    	if((n & (1<<i))>0)
    	    flag = true;
    	else
    	{
    	    count++;
            if(flag == true)
                break;
    	}
    }
    n = n | (1<<i);
    i--;
    for (int j=0;j<count;j++ )
    {
    	n = n & (~(1<<i));
    	i--;
    }
    while(i >= 0)
    {
        n = n | (1<<i);
        i--;
    }
    return n;
}

int main()
{
    int n;
    cin>>n;
    cout<<greater_same_bits(n);

}
