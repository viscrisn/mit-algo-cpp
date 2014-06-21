#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{


    register int cases;
    scanf("%d",&cases);

    int n1;
    int test=0;
    n1=cases;
    int final[cases];

    while(cases)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int sum=0;


        for(int i=a;i<=b;i++)
        {
            register int c=0;
            register unsigned int n=i;
            unsigned int abc =n;
            int no1s=0;

            int inc=31;

            if((n < 2))
            {
                inc = 2;
            }
            else if((n < 8))
            {
                inc = 4;
            }
            else if((n < 32))
            {
                inc = 6;
            }
            else if((n < 64))
            {
                inc = 8;
            }
            else if((n < 256))
            {
                inc = 10;
            }
            else if((n < 1024))
            {
                inc = 12;
            }
            else if((n < 4096))
            {
                inc = 14;
            }
            else if((n < 16384))
            {
                inc = 16;
            }
            else if((n < 65536))
            {
                inc = 18;
            }
            else if((n < 262144))
            {
                inc = 20;
            }
            else if((n < 1048576))
            {
                inc = 22;
            }
            else if((n < 4194304))
            {
                inc = 24;
            }
            else if((n < 16777216))
            {
                inc = 26;
            }
            else if((n < 67108864))
            {
                inc = 28;
            }
            else if((n < 268435456))
            {
                inc = 30;
            }


            for(int k=1;k<inc;k++)
            {
                n=n/2;
                abc= abc - (n);
            }

            no1s=+abc;
            if(i<0)
            {
                no1s=no1s-1;
            }
            sum+=no1s;

        }

        final[test++]=sum;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        printf("%d\n",final[i]);
    }
}
