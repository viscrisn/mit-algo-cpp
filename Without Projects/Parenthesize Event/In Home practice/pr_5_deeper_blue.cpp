#include<iostream>
#include<string.h>
using namespace std;

int chk_diag_long(int,int,int,int,char *);
int chk_verhor_long(int,int,int,int,char *);
int chk_horse(int,int,int,int,char *);
int chk_king(int,int,int,int,char *);


int main()
{
    char a[10];
    cin>>a;
    if(!strcmp(a,"START"))
    {
        int row;
        int col;
        cin>>row;
        cin>>col;
        int total=row*col;
        char ele[row][col];
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                cin>>ele[r][c];
            }
        }



    }
    else
    {
        cout<<"Invalid Start.";
    }

}


int chk_verhor_long(int crow,int ccol,int row,int col,char board[30][30])
{
    int count=0;
    for(int i=crow;i<row;i++)
    {
        int j=ccol;
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    for(int i=crow;i>0;i--)
    {
        int j=ccol;
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    for(int j=ccol;j<col;j++)
    {
        int i=crow;
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    for(int j=ccol;j>0;j--)
    {
        int i=crow;
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    return count;
}


int chk_diag_long(int crow,int ccol,int row,int col,char board[30][30])
{
    int count=0;
    for(int i=crow, j=ccol;i<row&&j<col;i++,j++)
    {
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    for(int i=crow, j=ccol;i<row&&j>0;i++,j--)
    {
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
        for(int i=crow, j=ccol;i>0&&j<col;i--,j++)
    {
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
        for(int i=crow, j=ccol;i>0&&j>0;i--,j--)
    {
        if(board[i][j]=='K'||board[i][j]=='Q'||board[i][j]=='B'||
           board[i][j]=='R'||board[i][j]=='N')
        {
              count++;
        }

    }
    return count;
}







