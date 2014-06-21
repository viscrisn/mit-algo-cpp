#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void rotate_matrix(int matrix[100][100],int n)
{

    for (int layer = 0; layer <= n / 2; ++layer)
    {
        int first = layer;
        int last = n - 1 - layer;
        for(int i = first; i <= last; ++i)
        {
            int offset = i - first;
            int top = matrix[first][i]; // save top
// left -> top
            matrix[first][i] = matrix[last-offset][first];
// bottom -> left
            matrix[last-offset][first] = matrix[last][last - offset];

// right -> bottom
            matrix[last][last - offset] = matrix[i][last];

// top -> right
            matrix[i][last] = top; // right <- saved top
        }
    }
    for(int i =0; i<n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
}

        int main()
        {
            int N;
            cin>>N;
            int mat[100][100];
            for(int i =0; i<N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    cin>>mat[i][j];
                }
            }
            rotate_matrix(mat,N);
            for(int i =0; i<N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

