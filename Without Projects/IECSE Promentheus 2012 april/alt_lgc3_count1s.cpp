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
        int no1s=0;


        for(int i=a;i<=b;i++)
        {

            register int n=i;
            register int abc=0;
            no1s=0;

            if((n>0) && (n<16384))
            {


                if((n & 1))
                {
                    abc = abc + 1;
                }
                if((n & 2))
                {
                    abc = abc + 1;
                }
                if((n & 4))
                {
                    abc = abc + 1;
                }
                if((n & 8))
                {
                    abc = abc + 1;
                }
                if((n & 16))
                {
                    abc = abc + 1;
                }
                if((n & 32))
                {
                    abc = abc + 1;
                }
                if((n & 64))
                {
                    abc = abc + 1;
                }
                if((n & 128))
                {
                    abc = abc + 1;
                }
                if((n & 256))
                {
                    abc = abc + 1;
                }
                if((n & 512))
                {
                    abc = abc + 1;
                }
                if((n & 1024))
                {
                    abc = abc + 1;
                }
                if((n & 2048))
                {
                    abc = abc + 1;
                }
                if((n & 4096))
                {
                    abc = abc + 1;
                }
                if((n & 8192))
                {
                    abc = abc + 1;
                }
                if((n & 16384))
                {
                    abc = abc + 1;
                }

                no1s=abc;
            }
            else if(n>=16384)
            {

                if((n & 1))
                {
                    abc = abc + 1;
                }
                if((n & 2))
                {
                    abc = abc + 1;
                }
                if((n & 4))
                {
                    abc = abc + 1;
                }
                if((n & 8))
                {
                    abc = abc + 1;
                }
                if((n & 16))
                {
                    abc = abc + 1;
                }
                if((n & 32))
                {
                    abc = abc + 1;
                }
                if((n & 64))
                {
                    abc = abc + 1;
                }
                if((n & 128))
                {
                    abc = abc + 1;
                }
                if((n & 256))
                {
                    abc = abc + 1;
                }
                if((n & 512))
                {
                    abc = abc + 1;
                }
                if((n & 1024))
                {
                    abc = abc + 1;
                }
                if((n & 2048))
                {
                    abc = abc + 1;
                }
                if((n & 4096))
                {
                    abc = abc + 1;
                }
                if((n & 8192))
                {
                    abc = abc + 1;
                }
                if((n & 16384))
                {
                    abc = abc + 1;
                }
                if((n & 32768))
                {
                    abc = abc + 1;
                }
                if((n & 65536))
                {
                    abc = abc + 1;
                }
                if((n & 131072))
                {
                    abc = abc + 1;
                }
                if((n & 262144))
                {
                    abc = abc + 1;
                }
                if((n & 524288))
                {
                    abc = abc + 1;
                }
                if((n & 1048576))
                {
                    abc = abc + 1;
                }
                if((n & 2097152))
                {
                    abc = abc + 1;
                }
                if((n & 4194304))
                {
                    abc = abc + 1;
                }
                if((n & 8388608))
                {
                    abc = abc + 1;
                }
                if((n & 16777216))
                {
                    abc = abc + 1;
                }
                if((n & 33554432))
                {
                    abc = abc + 1;
                }
                if((n & 67108864))
                {
                    abc = abc + 1;
                }
                if((n & 134217728))
                {
                    abc = abc + 1;
                }
                if((n & 268435456))
                {
                    abc = abc + 1;
                }
                if((n & 536870912))
                {
                    abc = abc + 1;
                }

                no1s=abc;
            }

            else if(n<0 && n>-16384)
            {

                n=~n;

                if((n & 1))
                {
                    abc = abc + 1;
                }
                if((n & 2))
                {
                    abc = abc + 1;
                }
                if((n & 4))
                {
                    abc = abc + 1;
                }
                if((n & 8))
                {
                    abc = abc + 1;
                }
                if((n & 16))
                {
                    abc = abc + 1;
                }
                if((n & 32))
                {
                    abc = abc + 1;
                }
                if((n & 64))
                {
                    abc = abc + 1;
                }
                if((n & 128))
                {
                    abc = abc + 1;
                }
                if((n & 256))
                {
                    abc = abc + 1;
                }
                if((n & 512))
                {
                    abc = abc + 1;
                }
                if((n & 1024))
                {
                    abc = abc + 1;
                }
                if((n & 2048))
                {
                    abc = abc + 1;
                }
                if((n & 4096))
                {
                    abc = abc + 1;
                }
                if((n & 8192))
                {
                    abc = abc + 1;
                }
                if((n & 16384))
                {
                    abc = abc + 1;
                }
                abc=32-abc;

                no1s=abc;
            }
            else if(n <= -16384)
            {

                n=~n;

                if((n & 1))
                {
                    abc = abc + 1;
                }
                if((n & 2))
                {
                    abc = abc + 1;
                }
                if((n & 4))
                {
                    abc = abc + 1;
                }
                if((n & 8))
                {
                    abc = abc + 1;
                }
                if((n & 16))
                {
                    abc = abc + 1;
                }
                if((n & 32))
                {
                    abc = abc + 1;
                }
                if((n & 64))
                {
                    abc = abc + 1;
                }
                if((n & 128))
                {
                    abc = abc + 1;
                }
                if((n & 256))
                {
                    abc = abc + 1;
                }
                if((n & 512))
                {
                    abc = abc + 1;
                }
                if((n & 1024))
                {
                    abc = abc + 1;
                }
                if((n & 2048))
                {
                    abc = abc + 1;
                }
                if((n & 4096))
                {
                    abc = abc + 1;
                }
                if((n & 8192))
                {
                    abc = abc + 1;
                }
                if((n & 16384))
                {
                    abc = abc + 1;
                }
                if((n & 32768))
                {
                    abc = abc + 1;
                }
                if((n & 65536))
                {
                    abc = abc + 1;
                }
                if((n & 131072))
                {
                    abc = abc + 1;
                }
                if((n & 262144))
                {
                    abc = abc + 1;
                }
                if((n & 524288))
                {
                    abc = abc + 1;
                }
                if((n & 1048576))
                {
                    abc = abc + 1;
                }
                if((n & 2097152))
                {
                    abc = abc + 1;
                }
                if((n & 4194304))
                {
                    abc = abc + 1;
                }
                if((n & 8388608))
                {
                    abc = abc + 1;
                }
                if((n & 16777216))
                {
                    abc = abc + 1;
                }
                if((n & 33554432))
                {
                    abc = abc + 1;
                }
                if((n & 67108864))
                {
                    abc = abc + 1;
                }
                if((n & 134217728))
                {
                    abc = abc + 1;
                }
                if((n & 268435456))
                {
                    abc = abc + 1;
                }
                if((n & 536870912))
                {
                    abc = abc + 1;
                }
                abc=32-abc;

                no1s=abc;
            }

            sum += no1s;

        }

        //cout<<not(not(234))<<"\t";

        final[test++]=sum;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        printf("%d\n",final[i]);
    }
}

