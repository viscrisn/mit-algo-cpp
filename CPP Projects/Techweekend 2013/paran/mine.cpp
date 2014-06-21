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

char c[100][100];

int cha(int t,int y)
{
    t--;
    y--;
    int count =0;
    for (int i=0;i<3;i++ )
    {
    	for (int j=0;j<3;j++ )
    	{
    		if(c[t+i][y+j]=='*')
    		{
    		    count++;
    		}
    	}

    }
    return count;

}
int main()
{
	int test;
	test = 100;
	for(int testno = 0; testno < test ; testno++ )
	{
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)
		{
		    return 0;
		}
		for (int i=0;i<100;i++ )
		{
			for (int j=0;j<100;j++ )
			{
				c[i][j]='0';
			}
		}
		for (int i=1;i<=n;i++ )
		{
			for (int j=1;j<=m;j++ )
			{
				cin>>c[i][j];
			}
		}

		/*for (int i=0;i<=n+1;i++ )
		{
			for (int j=0;j<=m+1;j++ )
			{
				cout<<c[i][j]<<" ";
			}
			cout<<"\n";
		}*/

		for (int i=1;i<n+1;i++ )
		{
			for (int j=1;j<m+1;j++ )
			{
				if(c[i][j]=='*')
				{
				    continue;
				}
				else if(c[i][j]=='.')
				{
				    c[i][j] = cha(i,j)+'0';
				}
			}

		}
		cout<<"Field #"<<testno+1<<":\n";
		for (int i=1;i<n+1;i++ )
		{
			for (int j=1;j<m+1;j++ )
			{
				cout<<c[i][j]<<" ";
			}
			cout<<"\n";
		}

	}
}
