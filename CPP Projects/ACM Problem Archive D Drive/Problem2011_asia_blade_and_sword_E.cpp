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

int x_P, y_P,x_D,y_D;
char mat[203][203];
char star[203][2];
int star_count=0;
int m,n;
int ans = 0;
int flag = 0;

void solve(int x,int y)
{
    cout<<"\n";
    for (int i=0;i<m;i++ )
    {
    	for (int j=0;j<n;j++ )
    	{
    		cout<<mat[i][j]<<"\t";
    	}
    	cout<<"\n";
    }

    if(mat[x][y]=='D')
    {
        flag = 1;
        return;
    }
    if(flag == 1)
        return;
    ans++;
    if(mat[x][y]!='#'&&mat[x][y]!='P'&&mat[x][y]!='*')
    {
        mat[x][y]='P';
        solve(x+1,y);
        solve(x,y+1);
        solve(x-1,y);
        solve(x,y-1);
    }
    else if(mat[x][y]=='*')
    {
        for (int i=0;i<m;i++ )
        {
        	for (int j=0;j<n;j++ )
        	{
        		if(mat[i][j]=='*')
        		{
        		    mat[i][j]='P';
        		    star[star_count][0] = i;
        		    star[star_count][1] = j;
        		    star_count++;
        		}
        	}
        }
        for (int i=0;i<star_count;i++ )
        {
        	solve(star[i][0],star[i][0]);
        }
    }
}
int main()
{
	int test;
	cin>>test;
	for (int test_no=0;test_no<test;test_no++ )
	{
		cin>>m>>n;
		int x_P,y_P,x_D,y_D;
		for (int i=0;i<m;i++ )
		{
			for (int j=0;j<n;j++ )
			{
				cin>>mat[i][j];
				if(mat[i][j]=='P')
				{
				    x_P = i;
				    y_P = j;
				}
				if(mat[i][j]=='D')
				{
				    x_D = i;
				    y_D = j;
				}
			}
		}
		mat[x_P][y_P]='.';
		solve(x_P,y_P);
		cout<<ans<<"\n";

	}

}
