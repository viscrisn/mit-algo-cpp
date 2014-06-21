#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int row,clmn;
    cout<<"Enter no. of rows in the array";
    cin>>row;
    int **table=(int **)calloc(row+1,sizeof(int *));

    for(int i=0;i<row;i++)
    {
        cout<<"Enter no. of integers in row"<<i+1<<"\n";
        cin>>clmn;
        table[i]=(int *)calloc(clmn+1,sizeof(int));
        table[i][0]=clmn;
    }
//    table[r]=NULL;
    int r=0;
    while(table[r]!=NULL)
    {
        cout<<"Enter row"<<r+1<<"("<<table[r][0]<<"integers )";
        for(int c=1;c<=*table[r];c++)
            cin>>*(table[r]+c);
        r++;
    }

    cout<<"The ragged array: \n";
    for(int x=0;x<row;x++)
    {
        for(int y=1;y<=*(table[x]);y++)
            cout<<table[x][y]<<" ";
            cout<<"\n";
    }

}

