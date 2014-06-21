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
        if(num[i]>max)
        {
            max = num[i];
        }
        else if(num[i]<min)
        {
            min = num[i];
        }
        if(num[i]%2==1)
        {
            parity = 1;
        }
    }

    for (int i=0; i<4; i++ )
    {
        for (int j=i; j<4; j++ )
        {
            if(num[i]>num[j])
            {
                swap(num[i],num[j]);
            }
        }

    }

    int ans[3] = {};
    int index = 0;
    if(parity == 1)
    {
        if(num[0] < 5)
        {
            ans[index++] = 1;
        }
        else
        {
            ans[0] = 2;
            ans[1] = 3;
            ans[2] = 4;
            goto check;
        }

    }
    else
    {
        ans[0] = 2;
        ans[1] = 4;
        ans[2] = 6;
        goto check;
    }
    if(num[3] < 8)
    {
        ans[0] = 1;
        ans[1] = 2;
        ans[2] = 4;
        goto check;
    }
    else if(num[3] == 8)
    {
        if(num[0]==4 || num[1]==4 || num[1]==4)
        {
            ans[index++] = 3;
        }
        else
        {
            ans[index++] = 2;
        }
    }
    else if(num[3] == 9)
    {
        if((num[0]==4) || (num[1]==4) || (num[1]==4))
        {
            ans[index++] = 3;
        }
        else
        {
            ans[index++] = 2;
        }
    }
    ans[index] = num[3] - (ans[0] + ans[1]);

    check:
    int flag =0;
    for (int i=0; i<3; i++ )
    {
        if((num[i] == ans[0]) || (num[i] == ans[1]) || (num[i] == ans[2]) || (num[i] == (ans[0] + ans[1])) || (num[i] == (ans[1] + ans[2])) || (num[i] == (ans[2] + ans[0])))
        {
            continue;
        }
        flag = 1;
    }
    if(flag == 1)
    {
        cout<<"Combination does not exist\n";
        return 0;
    }


    for (int i=0; i<3; i++ )
    {
        cout<<ans[i]<<" ";
    }



}
