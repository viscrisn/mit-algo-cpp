#include<iostream>

using namespace std;

int main()
{
    int grid[10][10]={{0}};
    int no_of_sticks=0;

    cin>>no_of_sticks;
    int pos_stk[no_of_sticks][4];

    for (int i=0;i<no_of_sticks;i++ )
    {
        for (int j=0;j<4;j++ )
        {
            cin>>pos_stk[i][j];
        }
    }

    for (int i=0;i<no_of_sticks;i++ )
    {
        grid[pos_stk[i][0]][pos_stk[i][1]]=1;
        grid[pos_stk[i][2]][pos_stk[i][3]]=1;
    }

    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++ )
        {
        	cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }

   /* for (int i=0;i<no_of_sticks;i++ )
    {
        for (int j=0;j<4;j++ )
        {
            cout<<pos_stk[i][j]<<" ";
        }
        cout<<"\n";
    }*/

}
