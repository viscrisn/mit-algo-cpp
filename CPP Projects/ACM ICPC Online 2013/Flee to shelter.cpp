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
		int n,m,t;
		cin>>n>>m>>t;
		int total_trips = n/m;
		if(n%m!=0)
            total_trips++;
        cout<<total_trips*t*2<<"\n";
	}
}
