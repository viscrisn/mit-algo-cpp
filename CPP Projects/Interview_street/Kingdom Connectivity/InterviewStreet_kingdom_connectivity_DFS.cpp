#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<functional>

using namespace std;

long long kingdom(int **edges,int n);
int main()
{
	int n;
	int m;
	cin>>n>>m;
	int **edges;
	edges = (int**)(calloc(n,sizeof(int*)));
	for (int i=0;i<n;i++)
	{
		edges[i] = (int*)(calloc(1,sizeof(int)));
		//edges[i][0] = i;
	}
	int x,y;
	int size[n];
    for (int i=0;i<n;i++)
    {
    	size[i] = 1;
    }
	for (int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;y--;
		size[x]++;
		edges[x] = (int*)realloc(edges[x],(size[x]+1)*sizeof(int));
		edges[x][size[x]-1] = y;
	}
	for (int i=0;i<n;i++)
	{
		edges[i][0] = size[i]-1;
	}
	/*for (int i=0;i<n;i++)
	{
		for (int j=0;j<size[i];j++)
		{
			cout<<edges[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";*/
	long long ans;
	ans = kingdom(edges,n);
	if(ans!=-1)
        cout<<ans%1000000000;
    else
        cout<<"INFINITE PATHS";
}

long long kingdom(int **edges,int n)
{
    long long ans=0;
    stack<int> stk;
    stack<int> stk_pos;
    int flag[n];
    int top;
    int current[n];
    for (int i=0;i<n;i++)
    {
    	current[i] =0;
    }

    for (int i=0;i<n;i++)
    {
    	flag[i] = 1;
    }
    //not checking the case if graph does not has 1 as starting vertex
    stk.push(0);
    stk_pos.push(flag[0]);
    current[0] = 1;
    while(stk.empty()!= true)
    {
        top = stk.top();
        //flag[top] = stk_pos.top();
        if(top == n-1)
        {
            ans++;
            current[stk.top()] = 0;
            flag[stk.top()] = 1;
            stk.pop();
            stk_pos.pop();
        }
        if(flag[top]<=edges[top][0])
        {
            if(current[edges[top][flag[top]]] == 1)
                return -1;
            else
                current[edges[top][flag[top]]] = 1;

            stk.push(edges[top][flag[top]++]);
            stk_pos.push(flag[top]);
        }
        else
        {
            current[stk.top()] = 0;
            flag[stk.top()] = 1;
            stk.pop();
            stk_pos.pop();
        }
    }
    return ans;
}
