#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char ca;
    int a[10][10];
    int value=0;
    int p_pos_i[10];
    int p_pos_j[10];

    int k_pos_i[10];
    int k_pos_j[10];

    int no_of_k=0;
    int no_of_p=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cin>>ca;
            if(ca=='.')
            {
                value=3;
            }
            if(ca=='K')
            {
                value=9;
                k_pos_i[no_of_k]=i;
                k_pos_j[no_of_k]=j;
                no_of_k++;
            }
            if(ca=='P')
            {
                value=7;
                p_pos_i[no_of_p]=i;
                p_pos_j[no_of_p]=j;
                no_of_p++;
            }
            a[i][j]=value;
        }
    }

    for(int i=0;i<no_of_p;i++)
    {
        for(int j=0;j<no_of_k;j++)
        {
            if(p_pos_i[i]==k_pos_i[j]+1||p_pos_i[i]==k_pos_i[j]-1)
            {
                if()
            }
        }

    }
   /* for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/


}
