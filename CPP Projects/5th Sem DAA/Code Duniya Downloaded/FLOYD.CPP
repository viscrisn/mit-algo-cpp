#include<iostream>
#define MAX 999
int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
int main()
{
    clrscr();
    int n,j,k,l,c;
    int m[10][10];

    cin>>n;
    for(int i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(i==j)
                m[i][j]=0;
            else
                m[i][j]=MAX;
    cin>>j;
    for(i=0; i<j; i++)
    {
        cin>>k>>l>>c;
        if(k<n && l<n)
            m[k][l]=c;

    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)

            cout<<m[i][j]<<"\t";

        cout<<endl;
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                m[i][j]=min(m[i][j],m[i][k]+m[k][j]);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<m[i][j]<<"\t";
        cout<<endl;
    }
    getch();
}


