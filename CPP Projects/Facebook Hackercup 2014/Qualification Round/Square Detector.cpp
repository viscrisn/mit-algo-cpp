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

bool grid[25][25];

int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int n;
		cin>>n;
		char temp;
		for (int i=0;i<n;i++ )
		{
			for (int j=0;j<n;j++ )
			{
				cin>>temp;
				grid[i][j] = (temp=='.')?0:1;
			}
		}

	}
}
