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

int a[1001][1001];
int n,m;

int sum_row(int r)
{
    int temp = 0;
    for (int i=1;i<n;i++ )
    {
    	temp+=a[r][i];
    }
    return temp;
}
int sum_col(int c)
{
    int temp = 0;
    for (int i=1;i<n;i++ )
    {
    	temp+=a[i][c];
    }
    return temp;
}

int main()
{
	cin>>n;
	cin>>m;
	int x,y;
	for (int i=0;i<m;i++ )
	{
		cin>>x>>y;
		a[x][y] = 1;
	}
	a[1][1] = 1;
	a[n][n] = 1;
	a[1][n] = 1;
	a[n][1] = 1;

    int ans = 0;
    int row[1001];
    int index = 0;
    for (int i=1;i<=n;i++ )
    {
    	int t = sum_row(i);
    	if(t == 0)
        {
            row[index++] = i;
        }
    }
    ans = index;
    for (int i=1;i<=n;i++ )
    {
    	int t = sum_col(i);
    	if(t == 0)
        {
            int flag = 1;
            for (int i2=0;i2<index;i2++ )
            {
            	if(i == row[i2])
                    flag = 0;
            }
            if(flag == 1)
            {
                ans++;
            }
        }
    }

    if(n%2==0)
        ans /= 2;
    cout<<ans;

}
