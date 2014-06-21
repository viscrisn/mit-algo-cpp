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

int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
    	uint64_t n,k;
        cin>>n>>k;
        if(k==0)
            cout<<"0 "<<n<<"\n";
        else if(n==0)
            cout<<"0 0\n";
        else
            cout<<n/k<<" "<<n%k<<"\n";
    }
}
