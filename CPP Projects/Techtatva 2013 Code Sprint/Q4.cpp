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
	int n;
	cin>>n;
	int a[100][100];
	for (int i=0;i<n;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cin>>a[i][j];
		}
	}
	int cl;
	cin>>cl;
	int r,c;
	r = cl/10;
	c = cl%10;
	//r--;
	//c--;
	while(1)
	{
	    //if(a[r][c] == ((r+1)*10 + (c+1)))
	    if(a[r-1][c-1] == ((r)*10 + (c)))
	    {
	        cout<<"\nTresure found at "<<r<<","<<c;
	        break;
	    }
	    //cout<<a[r][c]<<"\n";
	    //cin>>cl;
	    //cout<<"\n "<<r<<","<<c;
	    r = a[r-1][c-1]/10;
	    c = a[r-1][c-1]%10;


	    //r--;
	    //c--;
	}

}
