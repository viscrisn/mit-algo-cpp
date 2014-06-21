#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

void rotate(int a[100][100],int m,int n)
{
    int b[m][n];
    for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			b[i][j] = a[j][n-i-1];
		}
	}
	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			a[i][j] = b[i][j];
		}
	}
}
int main()
{
    int m,n;
    cin>>m>>n;
	int a[100][100];
	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cin>>a[i][j];
		}
	}

	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}

	rotate(a,m,n);

	for (int i=0;i<m;i++ )
	{
		for (int j=0;j<n;j++ )
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}

}
