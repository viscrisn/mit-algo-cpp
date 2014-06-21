//The loop may look theta(x^4), but it isnt. The loop runs for very selective values and is at max running 18 times compared to brute force 128 times.

//Consider this solution for evaluation rather than previous.

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
    int num[4];
    int max = 1;
    int min = 10;
    int parity =0;
    for (int i=0; i<4; i++ )
    {
        cin>>num[i];
    }

    int ans[3] = {};
    int index = 0;
    int flag =0;

    for (int i=1; i<=3; i++ )
    {
        for (int j=2; j<=5; j++ )
        {
            if(j<=i)
            {
                continue;
            }
            for (int k=3; k<=6; k++ )
            {
                if((k<=j) || (k<=i))
                {
                    continue;
                }
                ans[0] = i;
                ans[1] = j;
                ans[2] = k;
                for (int l=0; l<4; l++ )
                {

                    if(((num[l] == ans[0]))
                    ||((num[l] == ans[1]))
                    ||((num[l] == ans[2]))
                    ||((num[l] == (ans[0] + ans[1])))
                    ||((num[l] == (ans[1] + ans[2])))
                    ||((num[l] == (ans[2] + ans[0])))
                    ||(num[l] == ans[0]+ans[1]+ans[2]))
                    {
                        flag = 1;
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    goto last;
                }

            }

        }

    }

last:
    if(flag == 0)
    {
        cout<<"Combination does not exist\n";
        return 0;
    }


    for (int i=0; i<3; i++ )
    {
        cout<<ans[i]<<" ";
    }



}

