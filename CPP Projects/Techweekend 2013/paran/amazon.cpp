#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
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
        cin>>n;

        for (int i = 0; i < n; i++ )
        {
                cin>>x[i]>>y[i];
                sh1[i]=1000;
                sh2[i]=1000;
                pt1[i]=-1;
                pt2[i]=-1;
                connect1[i]=-1;
                connect2[i]=-1;
        }
        int a,b;
        int d1,d2;
        for (int i = 0; i < n; i++ )
        {
                for(int j = 0 ; j< n ; j++)
                {
                        if(i==j)
                            continue;
                        d1=(x[i]-x[j])*(x[i]-x[j]);
                        d1+=(y[i]-y[j])*(y[i]-y[j]);
                        if(d1<sh1[i])
                        {
                                sh1[i]=d1;
                                pt1[i]=j;
                        }
                        else
                        if(d1<sh2[i])
                        {
                                sh2[i]=d1;
                                pt2[i]=j;
                        }
                }
        }
        for (int i = 0; i < n; i++ )
        {
                cout<<pt1[i]+1<<'\t'<<pt2[i]+1<<'\n';
        }
        reach(0);
        int res=check();
        if(res==-1)
                cout<<"UNREACHABLE";
        else
                cout<<"REACHABLE";

	return 0;
}
void reach(int x)
{
        int a,b;
        a=pt1[x];
        b=pt2[x];
        if((connect1[x]==-1))
        {
                if((connect1[a]==-1))
                {
                        connect1[x]=a;
                        connect1[a]=x;
                }
                else
                if(connect1[a]==)

        }
        else
        if((connect2[x]==-1))
        {
            if((connect1[a]==-1))
            {
                connect2[x]=a;
                connect1[a]=x;
            }
        }
        reach(a);
        reach(b);
}
/*int check()
{
        for (int i = 0; i < n; i++ )
        {

                {
                        return -1;
                }
        }
}

*/
