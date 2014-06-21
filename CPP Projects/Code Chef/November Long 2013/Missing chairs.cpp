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

uint64_t pow_2(uint64_t n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 2;
    uint64_t temp = pow_2(n/2);
    if(n%2==0)
        return (temp*temp)%1000000007;
    return (temp*temp*2)%1000000007;
}

int main()
{
	int test;
	cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
    	uint64_t n;
    	cin>>n;
    	cout<<(pow_2(n) - 1)<<"\n";
    }
}
