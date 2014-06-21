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
		int n,m,k;
		cin>>n>>m>>k;
		if(n>1 && m>1 && k>1)
            cout<<k/2<<"\n";
        else
            cout<<k<<"\n";
	}
}
