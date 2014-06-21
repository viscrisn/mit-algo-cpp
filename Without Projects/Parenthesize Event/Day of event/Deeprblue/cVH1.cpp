#include<iostream>
#include<cstdio>
using namespace std;

int checkVerticalHorizontal(char **,int,int,int,int);

int main()
{
	int i,m,n;

	cin>>m;
	cin>>n;

	char **arr=new char*[m];
	for(i=0;i<m;i++)
		arr[i]=new char[n];

	for(i=0;i<=m;i++)
		gets(arr[i]);

	for(i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]=='E')
				continue;
			cout<<i<<","<<j<<" "<<checkVerticalHorizontal(arr,i,j,m,n)<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

int checkVerticalHorizontal(char **arr,int x,int y,int m,int n)
{
	int i,count=0;

	for(i=x-1;i>=0;i--)
		if(arr[i][y]!='E')
			count++;

	for(i=x+1;i<m;i++)
		if(arr[i][y]!='E')
			count++;

	for(i=y-1;i>=0;i--)
		if(arr[x][i]!='E')
			count++;

	for(i=y+1;i<n;i++)
		if(arr[x][i]!='E')
			count++;

	return count;
}
