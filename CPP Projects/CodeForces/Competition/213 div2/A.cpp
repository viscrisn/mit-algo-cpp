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
	int k;
	int count = 0;
	cin>>k;
	for(int testno = 0; testno < test ; testno++ )
	{
		int num;
		cin>>num;

		int flag = 0;
		while(num)
		{
		    if((num%10)>k)
                flag = 1;
            num/=10;
		}
		if(flag == 0)
		{
		    count++;
		}
	}
	cout<<count;

}
