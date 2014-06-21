#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int input, gate, a[10][2],temp;
    //input 1st statement.
    cin>>input>>gate;
    //input the data.
    for(int i=0;i<gate;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a[i][j];
        }
    }
    //making a[i][0] always > a[i][1]
    for(int i=0;i<gate;i++)
    {
        if(a[i][0]>a[i][1])
        {
            temp=a[i][0];
            a[i][0]=a[i][1];
            a[i][1]=temp;
        }
    }


}















