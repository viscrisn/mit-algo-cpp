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

void reach(int);
int check();
int n;
int x[100],y[100];
int sh1[100],sh2[100],pt1[100],pt2[100];
int connect1[100]={-1};
int connect2[100]={-1};

int main()
{
	int n;
	cin>>n;

        for (int i = 0; i < n; i++ )
        {
                cin>>x[i]>>y[i];
                x[i] = abs(x[i]);
                y[i] = abs(y[i]);
                sh1[i]=1000;
                sh2[i]=1000;
                pt1[i]=-1;
                pt2[i]=-1;
                connect1[i]=-1;
                connect2[i]=-1;
        }
        int d1[n];
        for (int i = 0; i < n; i++ )
        {
                for(int j = 0 ; j< n ; j++)
                {
                        if(i==j)
                            continue;
                        d1[i]=(x[i]-x[j])*(x[i]-x[j]);
                        d1[i]+=(y[i]-y[j])*(y[i]-y[j]);
                }
        }
        int b1[n];

        for (int i=0;i<n-1;i++ )
        {
        	b1[i] = d1[i] - d1[i+1];
        	b1[i] = abs(b1[i]);
        }
        int min=999;
        for (int i=0;i<n-1;i++ )
        {
        	//cout<<b1[i]<<"\t";
        	if(b1[i]<min&&b1[i]!=0)
        	{
        	    min = b1[i];
        	}
        }
        for (int i=0;i<n-1;i++ )
        {
        	if(b1[i]>min)
        	{
        	   cout<<"NOT POSSIBLE\n";
        	   return 0;
        	}

        }

        cout<<"POSSIBLE\n";

}
