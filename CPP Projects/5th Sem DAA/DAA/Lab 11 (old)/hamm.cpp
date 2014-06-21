#include<iostream>
using namespace std;
int mat[10][10],n,ne;

void input()
{
    int i,j;
    cout<<"\nEnter the number of vertices : ";
    cin>>n;
    cout<<"\nNo. of edges : ";
    cin>>ne;
    cout<<"Input the edges (VERTEX VERTEX) \n";
    int tmp2,tmp1;
    for(i=0;i<ne;i++)
    {
        cin>>tmp1>>tmp2;
        mat[tmp2][tmp1]=1;
        mat[tmp1][tmp2]=1;
    }
}

void hamiltonian(int c,int v[10],bool visited[10])
{
    int i=0;
    if(mat[v[c-1]][0]==1 && c==n)
    {
        for(i=0;i<c;i++)
            cout<<v[i]<<" ";
        cout<<"\n"; 
        return;
    }
    for(i=0;i<n;i++)
    {
        if(mat[v[c-1]][i]==1 && !visited[i])
        {
            visited[i]=true;
            v[c++]=i;
            hamiltonian(c,v,visited);
            visited[i]=false;c--;
        }
    }
}

int main()
{
    input();
    int v[10];bool visited[10];
    for (int i = 0; i < n; ++i)
        visited[i]=false;
    v[0]=0;
    visited[0]=true;
    cout<<"Possible solutions : \n";
    hamiltonian(1,v,visited);
}
/*
Enter the number of vertices : 6

No. of edges : 9
Input the edges (VERTEX VERTEX) 
0 1
0 2
0 3
1 2
1 5
2 3
2 4
3 4
4 5
0 1 1 1 0 0 
1 0 1 0 0 1 
1 1 0 1 1 0 
1 0 1 0 1 0 
0 0 1 1 0 1 
0 1 0 0 1 0 
 */