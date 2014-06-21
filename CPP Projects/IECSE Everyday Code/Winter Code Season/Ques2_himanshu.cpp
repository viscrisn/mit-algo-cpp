#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    int a[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin>>a[i][j];

        }
    }
    cout<<"\nInput smaller matrix size:";
    cin>>k;
    int **b;
    b=(int**)calloc(k,sizeof(int));
    for(int i=0; i<k; i++)
    {
        b[i]=(int *)calloc(k,sizeof(int));
    }
    int row=0,col=0;
    while(row!=n-k+1)
    {
        col=0;
        while(col!=n-k+1)
        {
            for (int i=row,l=0; i<row+k; i++,l++)
            {
                for (int j=col,p=0; j<col+k; j++,p++)
                {

                    b[l][p]+=a[i][j];

                }

            }
            col++;
        }
        row++;
    }


    for (int i=0; i<k; i++)
    {
        for (int j=0; j<k; j++)
        {
            cout<<b[i][j]<< " ";
        }
        cout<<"\n";

    }

}
