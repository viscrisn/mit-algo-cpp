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

struct Edge
{
    int sourceV, destV, cost;
};

long long matrix(Edge **edges,int n,int *machines,int k);

int main()
{
    int n;
    int k;
    cin>>n>>k;
    int m = n-1;
    Edge **edges;
    edges = (Edge**)(calloc(n,sizeof(Edge*)));
    for (int i=0; i<n; i++)
    {
        edges[i] = (Edge*)(calloc(1,sizeof(Edge)));
        //edges[i][0] = i;
    }
    int x,y,c;
    int size[n];
    for (int i=0; i<n; i++)
    {
        size[i] = 1;
    }
    for (int i=0; i<m; i++)
    {
        cin>>x>>y>>c;
        size[x]++;
        edges[x] = (Edge*)realloc(edges[x],(size[x]+1)*sizeof(Edge));
        edges[x][size[x]-1].sourceV = x;
        edges[x][size[x]-1].destV = y;
        edges[x][size[x]-1].cost = c;

        //bidirectional
        size[y]++;
        edges[y] = (Edge*)realloc(edges[y],(size[y]+1)*sizeof(Edge));
        edges[y][size[y]-1].sourceV = y;
        edges[y][size[y]-1].destV = x;
        edges[y][size[y]-1].cost = c;
    }
    for (int i=0; i<n; i++)
    {
        edges[i][0].sourceV = size[i]-1;
        edges[i][0].destV = -1;
        edges[i][0].cost = -1;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<size[i]; j++)
        {
            cout<<edges[i][j].sourceV<<" "<<edges[i][j].destV<<" "<<edges[i][j].cost<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";

    int machines[k];
    for (int i=0; i<k; i++ )
    {
        cin>>machines[i];
    }

    long long ans;
    sort(machines);
    matrix(edges,n,machines,k);

}

long long matrix(Edge **edges,int n,int *machines,int k)
{
    for (int i=0; i<k; i++ )
    {
        stack<int> stk;
        stack<int> stk_pos;
        int flag[n];
        int top;
        for (int i=0; i<n; i++)
        {
            flag[i] = 1;
        }
        int cur_machine = machines[i];
        stk.push(cur_machine);
        stk_pos.push(flag[cur_machine]);
        while(stk.empty()!= true)
        {
            top = stk.top();
            //flag[top] = stk_pos.top();
            if(binary_search(machines,machines+k,top))
            {

                flag[stk.top()] = 1;
                stk.pop();
                stk_pos.pop();
            }
            if(flag[top]<=edges[top][0])
            {
                stk.push(edges[top][flag[top]++]);
                stk_pos.push(flag[top]);
            }
            else
            {
                flag[stk.top()] = 1;
                stk.pop();
                stk_pos.pop();
            }
        }
    }

}


