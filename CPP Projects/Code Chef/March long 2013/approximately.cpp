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

using namespace std;

int len(int n)
{
    int t = 0;
    while(n!=0)
    {
        t++;
        n/=10;
    }
    return t;
}
int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int k;
		cin>>k;
		if(k==0)
		{
		    cout<<"3\n";
		    continue;
		}
		cout<<"3.";
		long long num = 103993;
		long long den = 33102;
		long long quo = num/den;
		long long rem = num%den;
		int flag  = 0;
		while(k>0)
		{
		    rem*=10;
		    while(rem<=den)
		    {
		        cout<<"0";
		        rem*=10;
		        k--;
		        if(k<=0)
                {
                    flag = 1;
                    break;
                }
		    }
            if(flag ==1)
            {
                break;
            }
            quo = rem / den;
            cout<<quo;
            rem = rem % den;
            k -= len(quo);

		}
		cout<<"\n";
	}
}
