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

//Beautiful application of dfs
//Read my code to improve your graph traversal skills
//Thank you
//-Vishal Krishna

void clear(int done[][10], int counter);
void solve(int** edges, int size[],int n);
int next_edge(int **edges,int done[][10], int counter, int top,int *size);
void display(stack<int> stk);
int count(int done[][10], int counter);

int total =0;

int main()
{
	int n;
	n=10;
	//int edges[n][n] =;

    int size[10];
	int **edges=(int **)calloc(n,sizeof(int*));
	edges[0] = (int*)calloc(3,sizeof(int));
	size[0] = 3;
	edges[0][0]=2;edges[0][1]=5;edges[0][2]=8;
	edges[1] = (int*)calloc(4,sizeof(int));
	edges[1][0]=2;edges[1][1]=3;edges[1][2]=4;edges[1][3]=7;
	size[1] = 4;
	edges[2] = (int*)calloc(5,sizeof(int));
	edges[2][0]=1;edges[2][1]=3;edges[2][2]=5;edges[2][3]=8;edges[2][4]=0;
	size[2] = 5;
	edges[3] = (int*)calloc(4,sizeof(int));
	edges[3][0]=1;edges[3][1]=2;edges[3][2]=6;edges[3][3]=9;
	size[3] = 4;
	edges[4] = (int*)calloc(4,sizeof(int));
	edges[4][0]=1;edges[4][1]=5;edges[4][2]=6;edges[4][3]=7;
	size[4] = 4;
	edges[5] = (int*)calloc(5,sizeof(int));
	edges[5][0]=2;edges[5][1]=8;edges[5][2]=0;edges[5][3]=6;edges[5][4]=4;
	size[5] = 5;
	edges[6] = (int*)calloc(4,sizeof(int));
	edges[6][0]=3;edges[6][1]=4;edges[6][2]=5;edges[6][3]=9;
	size[6] = 4;
	edges[7] = (int*)calloc(4,sizeof(int));
	edges[7][0]=1;edges[7][1]=4;edges[7][2]=8;edges[7][3]=9;
	size[7] = 4;
	edges[8] = (int*)calloc(5,sizeof(int));
	edges[8][0]=2;edges[8][1]=0;edges[8][2]=5;edges[8][3]=9;edges[8][4]=7;
	size[8] = 5;
	edges[9] = (int*)calloc(4,sizeof(int));
	edges[9][0]=3;edges[9][1]=6;edges[9][2]=8;edges[9][3]=7;
	size[9] = 4;

    int m;
    cin>>m;
    if(m==0)
    {
        cout<<"Number cannot start with 0\n";
        return 0;
    }
    solve(edges,size,m);
    //cout<<"Total Number of numbers: "<<total<<"\n";
}
void solve(int** edges, int size[],int m)
{
    stack<int> stk;
    stk.push(m);
    int top;
    int done[6][10];
    for (int i=0;i<6;i++ )
    {
    	for (int j=0;j<10;j++ )
    	{
    		done[i][j] = 0;
    	}
    }
    int counter = 0,cnt;
    int nxt_edge;
    while(stk.empty()!=true)
    {
        top = stk.top();
        if(counter == 5)
        {
            display(stk);
            //total++;//Just for reference
            clear(done,counter);
            stk.pop();
            counter--;
            continue;
        }
        cnt = count(done,counter);
        if(cnt < size[top])
        {
            nxt_edge = next_edge(edges,done,counter,top,size);
            if(nxt_edge==-1)
            {
                goto label1;
            }
            stk.push(edges[top][nxt_edge]);
            counter++;
        }
        else
        {
            label1:
            clear(done,counter);
            stk.pop();
            counter--;
        }
    }
}
int next_edge(int **edges,int done[][10], int counter, int top,int *size)
{
    for (int i=0;i<size[top];i++ )
    {
    	if(done[counter][edges[top][i]]==0)
    	{
    	    done[counter][edges[top][i]]=1;
    	    return i;
    	}
    }
    return -1;
}
void clear(int done[][10], int counter)
{
    for (int i=0;i<10;i++ )
    {
        done[counter][i]=0;
    }
}
int count(int done[][10], int counter)
{
    int cnt=0;
    for (int i=0;i<10;i++ )
    {
        if(done[counter][i]==1)
            cnt++;
    }
    return cnt;
}

void display(stack<int> stk)
{
    int array[7];
    for (int i=0;i<6;i++ )
    {
        array[i]=stk.top();
        stk.pop();

    }
    for (int i=5;i>=0;i--)
    {
        cout<<array[i];
    	stk.push(array[i]);
    }
    cout<<'\n';
}
