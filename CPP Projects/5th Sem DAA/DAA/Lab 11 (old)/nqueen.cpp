  #include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int mat[10][10],n;
bool isValid(int r,int c)
{
    int i=0,j=0,d1,d2;
    for(i=0;i<n;i++)
    {
        if(mat[r][i]==1 && i!=c)
            return false;
        if(mat[i][c]==1 && i!=r)
            return false;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            d1=abs(r-i);d2=abs(c-j);
            if(d1!=0 && d1==d2 && mat[i][j]==1)
                return false;
        }
    return true;
}

int nqueen(int q,int c)
{
    int i,j;
    if(q==0)
    {
        int f=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(mat[i][j]==1)
                f++;
        if(f==n)
        {
            for(i=0;i<n;i++)
                {
                    cout<<"\n";
                    for(j=0;j<n;j++)
                        cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
        }
        return -1;

    }
    for(i=n-q;i<n;i++)
        for(j=0;j<n;j++)
            if(isValid(i,j))
            {
                mat[i][j]=1;
                int r=nqueen(q-1,c+1);
                if(r==-1)
                    mat[i][j]=0;
            }
        return -1;
}

int main()
{
    int i=0,j=0;
    cout<<"\nEnter value of n : ";
    cin>>n;
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mat[i][j]=0;
    cout<<"Possible solutions :\n ";
    nqueen(n,0);

}
