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

char a[100][100];
int main()
{
	int test;
	test  =100;

	for(int testno = 0; testno < test ; testno++ )
	{
		int r,c,s;
		cin>>r>>c>>s;
		if(r==0&&c==0&&s==0)
		{
		    return 0;
		}
		for (int i=0;i<r;i++ )
		{
			for (int j=0;j<c;j++ )
			{
			    cin>>a[i][j];
			}
		}
		for (int i=0;i<r;i++ )
		{
			for (int j=0;j<c+1;j++ )
			{
			    cout<<a[i][j];
			}
			cout<<"\n";
		}
		int sx,sy;
		s--;
		sx = 0;
		sy = s;
		int count=0;
		while(sx>=0&&sy>=0 && sx <=r&&sy<=c)
		{
		    //cout<<a[sx][sy];
		    if(a[sx][sy]=='N')
		    {
		        a[sx][sy]='*';
		        sx--;

		    }
		    else if(a[sx][sy]=='S')
		    {
		        a[sx][sy]='*';
		        sx++;

		    }
		    else if(a[sx][sy]=='E')
		    {
		        a[sx][sy]='*';
		        sy++;

		    }
		    else if(a[sx][sy]=='W')
		    {
		        a[sx][sy]='*';
		        sy--;

		    }
		    else if(a[sx][sy]=='*')
		    {
		        cout<<count<<" Steps infinite";
		        return 0;
		    }

		    for (int i=0;i<r;i++ )
		    {
		    	for (int j=0;j<c;j++ )
		    	{
		    		cout<<a[i][j]<<" ";
		    	}
                cout<<"\n";
		    }

		    count++;
		    cout<<count<<"\n";
		}
		cout<<"Exit in: "<<count<<"\n";

	}
}
