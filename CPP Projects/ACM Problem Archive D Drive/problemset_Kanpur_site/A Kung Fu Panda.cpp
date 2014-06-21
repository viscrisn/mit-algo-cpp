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

int row_arr[510];
int col_arr[510];
int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int row,col;
		cin>>row;
		for (int i=0;i<row;i++ )
		{
			cin>>row_arr[i];
		}
		sort(row_arr,row_arr+row);
		cin>>col;
		for (int i=0;i<col;i++ )
		{
			cin>>col_arr[i];
		}
		sort(col_arr,col_arr+col);
		cout<<"Case"<<testno+1<<":\n";
		cout<<row<<"\n";
		for (int i=0;i<row;i++ )
		{
			cout<<row_arr[i]<<" ,"<<col_arr[i]<<"\n";
		}
	}
}
