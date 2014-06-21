#include<iostream>

#include<stack>

using namespace std;



int gr[10000][10000];

void printdfs(int n,int m)
{
    stack<int> s;
    bool visit[20]= {false};
    int i=0;
    int arr[20],k=0;
    int top,flag;

    visit[i]=true;
    s.push(i);
    while(s.empty()!=true)
    {
        flag = 0;
        top = s.top();
        for (int j=0;j<n;j++ )
        {
            if((gr[top][j]==1)&& (!visit[j]))
            {
                s.push(j);
                visit[j]=true;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            s.pop();
            arr[k++]=top;
        }
    }

    for (int i=k-1; i>=0; i--)
    {
        cout<<arr[i]+1<<" ";

    }

}





int main()
{
    int n,m,x,y;
    cin>>n>>m;

    //array arr[100];
    int pos=0;
    for (int i=0; i<m; i++)
    {
        cin>>x>>y;
        x--,y--;
        gr[x][y]=1;

    }

    printdfs(n,m);
}
