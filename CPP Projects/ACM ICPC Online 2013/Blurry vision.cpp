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

int a[11][11];
int big1[32][32];
int big2[32][32];

int main()
{
	int test;
	cin>>test;

	for(int testno = 0; testno < test ; testno++ )
	{
		int n,m;
		cin>>n>>m;
		char buf[11];
		for (int i=0;i<n;i++ )
		{
			cin>>buf;
			for (int j=0;j<m;j++ )
			{
				a[i][j] = buf[j] - 'a' + 10;
			}
		}
		/*
		for (int i=0;i<n;i++ )
		{
			for (int j=0;j<m;j++ )
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
        */


		for (int i=10;i<10+n;i++ )
		{
			for (int j=10;j<10+m;j++ )
			{
				big1[i][j] = a[i-10][j-10];
			}
		}
		/*for (int i=5;i<n+15;i++ )
		{
			for (int j=5;j<15;j++ )
			{
				cout<<big1[i][j]<<"\t";
			}
			cout<<"\n";
		}*/
		int total_max =-1;
		for (int i=0;i<32-n;i++ )
		{
			for (int j=0;j<32-m;j++ )
			{
			    int total = 0;
			    int total_max_int = -1;
			    for (int k=0;k<n;k++ )
				{
					for (int o=0;o<m;o++ )
					{
						big2[k][o] = 0;
					}
				}
				for (int k=0;k<n;k++ )
				{
					for (int o=0;o<m;o++ )
					{
						if((big1[k+i][o+j] == a[k][o]) &&
                        (big1[k+i][o+j]!=0))
                        {
                            big2[k][o] = 1;
                            total++;
                            if((total > total_max))
                                total_max_int = total;
                        }
					}
				}
				if(total_max_int!=n*m && total_max_int >                    total_max)
				{
				    total_max = total_max_int;
				}

			}

		}
		cout<<total_max<<"\n";



	}
}
