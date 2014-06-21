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
stack<int> stk;
stack<int> stk_pos;


int cycle(int **edges,int n,int k);
int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    int **edges;
    edges = (int**)(calloc(n,sizeof(int*)));
    for (int i=0; i<n; i++)
    {
        edges[i] = (int*)(calloc(1,sizeof(int)));
        //edges[i][0] = i;
    }
    int x,y;
    int size[n];
    for (int i=0; i<n; i++)
    {
        size[i] = 1;
    }
    for (int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--;
        y--;
        size[x]++;
        edges[x] = (int*)realloc(edges[x],(size[x]+1)*sizeof(int));
        edges[x][size[x]-1] = y;

        size[y]++;
        edges[y] = (int*)realloc(edges[y],(size[y]+1)*sizeof(int));
        edges[y][size[y]-1] = x;
    }
    for (int i=0; i<n; i++)
    {
        edges[i][0] = size[i]-1;
    }
    /*
    for (int i=0;i<n;i++)
    {
    	for (int j=0;j<size[i];j++)
    	{
    		cout<<edges[i][j]<<"\t";
    	}
    	cout<<"\n";
    }
    cout<<"\n";*/
    int c=0;
    c= cycle(edges,n,k);
    cout<<c<<"\n";
    while(!stk.empty())
    {
        cout<<stk.top()+1<<" ";
        stk.pop();
    }

}

int cycle(int **edges,int n,int k)
{

    int flag[n];
    int top;
    int counter;
    int current[n];
    for (int i=0; i<n; i++)
    {
        current[i] =0;
    }

    for (int i=0; i<n; i++)
    {
        flag[i] = 1;
    }
    for (int i=0; i<n; i++ )
    {
        while(stk.empty()!= true)
        {
            stk.pop();
        }
        for (int j=0; j<n; j++)
        {
            current[j] =0;
        }
        stk.push(i);
        stk_pos.push(flag[i]);
        current[i] = 1;
        counter = 1;
        while(stk.empty()!= true)
        {
            top = stk.top();
            if(counter>=k+1)
            {
                if(top==i)
                {
                    return counter;
                }
            }
label1:
            if(flag[top]<=edges[top][0])
            {
                if(current[edges[top][flag[top]]] == 1)
                {
                    flag[top]++;
                    goto label1;
                }
                else
                    current[edges[top][flag[top]]] = 1;

                stk.push(edges[top][flag[top]++]);
                stk_pos.push(flag[top]);

                counter++;
            }
            else
            {
                current[stk.top()] = 0;
                flag[stk.top()] = 1;
                stk.pop();
                stk_pos.pop();
                counter--;
            }

        }
    }
    return counter;

}
