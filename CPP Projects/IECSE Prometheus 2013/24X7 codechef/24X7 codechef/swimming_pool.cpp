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
		int a;
		cin>>a;
		int flag = 0;
		for (int i=3;i<100000;i++ )
		{
			if(((((i-2)*180)%i)==0)&&((((i-2)*180)/i)==a))
			{
                cout<<"YES\n";
                flag = 1;
                break;
			}
		}
		if(flag==0)
            cout<<"NO\n";

	}
}
