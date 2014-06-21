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

uint64_t pow_4(uint64_t n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 4;
    uint64_t temp = pow_4(n/2);
    if(n%2==0)
        return (temp*temp)%1000000007;
    return (temp*temp*4)%1000000007;
}

uint64_t dec_to_bin(int dec)
{
    bool rem;
    uint64_t i=1,sum=0;
    while(dec>0)
    {
        rem = dec%2;
        sum = sum + (i*rem);
        dec = dec/2;
        i = i*10;
    }
    return sum;
}
int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        uint64_t n;
        cin>>n;
        n = dec_to_bin(n);
        cout<<pow_4(n)<<"\n";
    }
}
