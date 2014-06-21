#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int t=0;
    cin>>t;
    while(t)
    {
        t--;
        int k;

        cin>>k;
        for(int i=0;i<k;i++)
        {
            int h;
            int w;

            int size_h=floor(45/sqrt(k))+1;
            int size_w=floor(70/sqrt(k))+1;
            char maze[size_h][size_w];

            cout<<size_h<<" "<<size_w<<" ";

            cin>>h;
            cin>>w;

            int pos_S_i;
            int pos_S_j;

            int pos_E_i;
            int pos_E_j;

            int robot[h][w];
            int robot_i;
            int robot_j;

            for(int i=0;i<h;i++)
            {
                for(int j=0;j<w;j++)
                {
                   cin>>maze[i][j];
                   if(maze[i][j]=='S')
                   {
                       pos_S_i=i;
                       pos_S_j=j;
                   }
                   if(maze[i][j]=='E')
                   {
                       pos_E_i=i;
                       pos_E_j=j;
                   }
                }
            }

            robot_i=pos_S_i;
            robot_j=pos_S_j;

            if(maze[robot_i+1][robot_j]=='.')
            {

            }



            for(int i=0;i<h;i++)
            {
                for(int j=0;j<w;j++)
                {
                    cout<<maze[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }

}
