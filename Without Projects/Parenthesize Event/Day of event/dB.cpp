#include<iostream>
#include<cstdio>
using namespace std;

int checkdiagonal(char **arr,int m, int n, int x,int y)
{
    int c=x;
    int k=y;
    int c1=x;
    int k1=y;
    int flag=0;


    for (int i=0;i<x;i++)
    {
        {
        c--;
        k--;
        if(arr[c][k]!='E')
        {
            flag+=1;
        }
        }


       {
        c1--;
        k1++;
        if(arr[c1][k1]!='E')
        {
            flag+=1;
        }
         }
          }


    for (int i=x;i<n;i++)
    {
        {
        c++;
        k--;
        if(arr[c][k]!='E')
        {
            flag+=1;
        }
        }


       {
        c1++;
        k1++;
        if(arr[c1][k1]!='E')
        {
            flag+=1;
        }
         }
          }
            return flag;
    }


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
			cout<<i<<","<<j<<" "<<checkdiagonal(arr,i,j,m,n)<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
