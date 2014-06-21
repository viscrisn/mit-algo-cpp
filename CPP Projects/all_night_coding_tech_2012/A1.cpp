#include<iostream>

using namespace std;



int main()
{

        int min_x =9999,min_y =9999,min_index_x=0,min_index_y=0;
        int max_x = -9999,max_y = -9999,max_index_x=0,max_index_y=0;

        int n;
        cin>>n;
        int answer=0;

        int mat[n][3];
        for (int i=0; i<n; i++ )
        {
            mat[i][2]=0;
        }

        for (int i=0; i<n; i++ )
        {
            for (int j=0; j<2; j++ )
            {
                cin>>mat[i][j];
            }
        }

        for (int i=0; i<n; i++ )
        {
            if(mat[i][0]>max_x)
            {
                max_x = mat[i][0];
                max_index_x = i;
            }
            if(mat[i][0]<min_x)
            {
                min_x = mat[i][0];
                min_index_x = i;
            }
            if(mat[i][0]>max_y)
            {
                max_y = mat[i][1];
                max_index_y = i;
            }
            if(mat[i][0]<min_y)
            {
                min_y = mat[i][1];
                min_index_y = i;
            }
        }


        cout<<mat[min_index_x][0]<<" "<<mat[min_index_x][1];
        cout<<endl;
        cout<<mat[max_index_x][0]<<" "<<mat[max_index_x][1];
        cout<<endl;
        cout<<mat[min_index_y][0]<<" "<<mat[min_index_y][1];
        cout<<endl;
        cout<<mat[max_index_y][0]<<" "<<mat[max_index_y][1];
        cout<<endl;


}

