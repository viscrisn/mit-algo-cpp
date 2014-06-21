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

#define mod_no 1000000007

unsigned long long a[3];
unsigned long long ans;

int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		cin>>a[0]>>a[1]>>a[2];
		a[0] %= mod_no;
		a[1] %= mod_no;
		a[2] %= mod_no;

		sort(a,a+3);
		a[1] -= 1;
		a[2] -= 2;
		if(a[1] < 1 ||a[2] < 1)
        {
            cout<<"0\n";
            continue;
        }

        ans = (a[0]*a[2])%mod_no;
		ans = (ans*a[1])%mod_no;
		cout<<ans<<"\n";
	}
}
