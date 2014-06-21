//Name1:						Name2:
//Del1:							Del2:
//Team ID:
//the following is a program to calculate the exact result of 2^n where n<1600. debug the program.

#include <iostream>
//#include <iostream.h>
using namespace std;

int main()
{
    int n,a[500],i=0;
//semicolon not needed
    for(i=0; i<500; i++)
        a[i]=0;
    a[498]=1;
    cin>>n;
    int ctr=1,flag=1;
    i=500;
    while(ctr<n)
    {

        flag=1;
        for(int k=0; k<=i; k++)
        {
            //arrray a is uninitialized
            a[499-k]=(a[k]*2)+flag;
            flag=1;

            if(a[k]>10)
            {
                a[499-k]/=10;
                flag=1;
                i++;
            }

        }
        ctr++;
    }

    for(int j=0; j<500; j++)
        cout<<a[j]<<" ";

}

