//Started 7:10pm 26/08/2012
//Break for 1 hr for eating
//got logic at 9:42pm 26/08/2012 - used paper and pen
//Completed at 11:45pm
//Working


#include<iostream>
#include<math.h>

#define correct_it numbers[0] = numbers[N]; numbers[N+1] = numbers[1]

#define correct_final final[i][0] = final[i][N]; final[i][N+1] = final[i][1]

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int M,N;
        cin>>N>>M;
        int numbers[N+2];
        int total_sum =0;
        int turns = M/N;
        int leftover = M%N;


        for (int i=1; i<N+1; i++ )
        {
            cin>>numbers[i];
            total_sum+=numbers[i];
        }

        numbers[0] = numbers[N];
        numbers[N+1] = numbers[1];

        long long pre_final[N];


        for (int i=0; i<N+2; i++ )
        {
            if(turns>1)
            {
                pre_final[i]= pow(total_sum*3,(turns-1));
            }
            else
            {
                pre_final[i] = 0;
            }
        }
        correct_it;

        long long final[N][N+2];

        for (int i=0; i<N; i++ )
        {
            for (int j=0; j<N+2; j++ )
            {
                final[i][j] = numbers[j] + pre_final[j];
            }

        }

        if(turns>0)
        {
            leftover += N;
        }

        for (int i=0; i<N; i++ )
        {
            int leftover_temp = leftover;
            while(leftover_temp!=0)
            {
                for (int j=i+1; j<N+1; j++ )
                {
                    correct_final;
                    if(leftover_temp==0)
                    {
                        break;
                    }
                    leftover_temp--;
                    final[i][j] = final[i][j-1] + final[i][j] + final[i][j+1];
                }
                for (int j=1; j<i+1; j++ )
                {
                    correct_final;
                    if(leftover_temp==0)
                    {
                        break;
                    }
                    leftover_temp--;

                    final[i][j] = final[i][j-1] + final[i][j] + final[i][j+1];
                }
            }


        }
        for (int i=0; i<N; i++ )
        {
            for (int j=1; j<N+1; j++ )
            {
                cout<<final[i][j]<<" ";
            }
            cout<<"\n";
        }


        cout<<"\n";
    }
}
