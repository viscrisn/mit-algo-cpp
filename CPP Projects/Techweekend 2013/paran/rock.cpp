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
#include<queue>

using namespace std;

int main()
{

    while(1)
    {
        int b[1000];
        b[0] = 0;
        b[1] = 1;
        b[2] = 2;

        b[3] = 1;
        b[4] = 2;
        b[5] = 0;

        b[6] = 2;
        b[7] = 0;
        b[8] = 1;

        b[9] = 1;
        b[10] = 2;
        b[11] = 0;
        b[12] = 2;
        b[13] = 0;
        b[14] = 1;
        b[15] = 0;
        b[16] = 1;
        b[17] = 2;

        int line  =3;
        int k =9;
        for (int i=0; i<5; i++ )
        {
            for (int j=0; j<line*3; j++ )
            {
                b[k] = (b[j]+1)%3;
                k++;
            }
            for (int j=0; j<line*3; j++ )
            {
                b[k] = (b[j]+2)%3;
                k++;
            }
            line += 3;
            /*          for (int f=0; f<k; f++ )
                      {
                          if(b[f]==0)
                          {
                              cout<<"R";
                          }
                          if(b[f]==1)
                          {
                              cout<<"P";
                          }
                          if(b[f]==2)
                          {
                              cout<<"S";
                          }
                      }
                      cout<<"\n";
            */
        }

        int n;
        cin>>n;
        if(n==0)
        {
            return 0;
        }
        if(n<81)
        {
            int array[]= {1,2,3};       //R, P ,S
            int inv[]= {2,3,1};
            int big_mod=0;

            big_mod=n%81;
            //  int x=0,y;
            //x=big_mod%27;

            int comb[]= {1,2,3,  2,3,1 ,  3,1,2,
                         2,3,1,  3,1,2,   1,2,3,
                         3,1,2,  1,2,3,   2,3,1,

                         2,3,1,  3,1,2,   1,2,3,
                         3,1,2,  1,2,3,   2,3,1,
                         1,2,3,  2,3,1 ,  3,1,2,

                         3,1,2,  1,2,3,   2,3,1,
                         1,2,3,  2,3,1 ,  3,1,2,
                         2,3,1,  3,1,2,   1,2,3
                        };
            int init;
            if(big_mod==0)
            {
                init=comb[0];
            }
            else
            {
                init=comb[big_mod-1];
            }

            if(init==1)
            {
                cout<<'P'<<'\n';

            }

            if(init==2)
            {
                cout<<'S'<<'\n';

            }

            if(init==3)
            {
                cout<<'R'<<'\n';

            }
        }
        else
        {
            n--;
            if(b[n]==0)
            {
                cout<<"P\n";
            }
            if(b[n]==1)
            {
                cout<<"S\n";
            }
            if(b[n]==2)
            {
                cout<<"R\n";
            }
        }
    }



}


