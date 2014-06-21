#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int a[11][11];
int big1[32][32];
int big2[32][32];

int kadane(int* arr, int* start, int* finish, int n)
{
    int sum = 0, maxSum = -9999, i;
    *finish = -1;
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if (*finish != -1)
        return maxSum;
    maxSum = arr[0];
    *start = *finish = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

int findMaxSum(int M[32][32],int ROW, int COL)
{
    int maxSum = 0;
    int left, right, i;
    int temp[ROW], sum, start, finish;

    for (left = 0; left < COL; ++left)
    {
        memset(temp, 0, sizeof(temp));

        for (right = left; right < COL; ++right)
        {
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
            sum = kadane(temp,&start,&finish, ROW);

            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        int n,m;
        cin>>n>>m;
        char buf[11];
        for (int i=0; i<n; i++ )
        {
            cin>>buf;
            for (int j=0; j<m; j++ )
            {
                a[i][j] = buf[j] - 'a' + 10;
            }
        }
        for (int i=10; i<10+n; i++ )
        {
            for (int j=10; j<10+m; j++ )
            {
                big1[i][j] = a[i-10][j-10];
            }
        }
        int total_max =-1;
        for (int i=0; i<32-n; i++ )
        {
            for (int j=0; j<32-m; j++ )
            {

                int total_max_int = -1;
                for (int k=0; k<n; k++ )
                {
                    for (int o=0; o<m; o++ )
                    {
                        big2[k][o] = -100000;
                    }
                }
                int total = 0;
                for (int k=0; k<n; k++ )
                {
                    for (int o=0; o<m; o++ )
                    {
                        if(big1[k+i][o+j] == a[k][o])
                        {
                            big2[k][o] = 1;
                            total++;
                        }
                    }
                }

                if(total == n*m)
                    continue;
                total_max_int = findMaxSum(big2,n,m);
                if((total_max < total_max_int) && (total_max_int!=n*m))
                {
                    total_max = total_max_int;

                }
            }
        }
        cout<<total_max<<"\n";



    }
}

