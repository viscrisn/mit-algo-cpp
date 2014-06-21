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

            if((n>0) && (n<2048))
            {


                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));


                no1s=abc;
            }
            else if((n>0) && n<4096)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));



                no1s=abc;
            }
            else if((n>0) &&  n<8192)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));



                no1s=abc;
            }
            else if((n>0) && n<16384)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));



                no1s=abc;
            }
            else if((n>0) && n<32768)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));


                no1s=abc;
            }
            else if((n>0) && n<32768)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));


                no1s=abc;
            }
            else if((n>0) && n<65536)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));



                no1s=abc;
            }
            else if((n>0) && n<131072)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));



                no1s=abc;
            }
            else if((n>0) && n<262144)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));



                no1s=abc;
            }
            else if((n>0) && n<524288)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));



                no1s=abc;
            }
            else if((n>0) && n<1048576)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));



                no1s=abc;
            }
            else if((n>0) && n<2097152)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));



                no1s=abc;
            }
            else if((n>0) && n<4194304)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));



                no1s=abc;
            }
            else if((n>0) && n<8388608)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));



                no1s=abc;
            }
            else if((n>0) && n<16777216)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));


                no1s=abc;
            }
            else if((n>0) && n<33554432)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));



                no1s=abc;
            }
            else if((n>0) && n<67108864)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));



                no1s=abc;
            }
            else if((n>0) && n<134217728)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));


                no1s=abc;
            }
            else if((n>0) && n<268435456)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));


                no1s=abc;
            }
            else if((n>0) && n<536870912)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));
                abc = abc + not(not(n & 536870912));


                no1s=abc;
            }

            else if(n<0 && n>-16384)
            {

                n=~n;
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));

                abc=32-abc;

                no1s=abc;
            }

            else if(n>-4096)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));



                no1s=abc;
            }
            else if(n>-8192)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));



                no1s=abc;
            }
            else if(n>-16384)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));



                no1s=abc;
            }
            else if(n>-32768)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));


                no1s=abc;
            }
            else if(n>-32768)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));


                no1s=abc;
            }
            else if(n>-65536)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));



                no1s=abc;
            }
            else if(n>-131072)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));



                no1s=abc;
            }
            else if(n>-262144)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));



                no1s=abc;
            }
            else if(n>-524288)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));



                no1s=abc;
            }
            else if(n>-1048576)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));



                no1s=abc;
            }
            else if(n>-2097152)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));



                no1s=abc;
            }
            else if(n>-4194304)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));



                no1s=abc;
            }
            else if(n>-8388608)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));



                no1s=abc;
            }
            else if(n>-16777216)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));


                no1s=abc;
            }
            else if(n>-33554432)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));



                no1s=abc;
            }
            else if(n>-67108864)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));



                no1s=abc;
            }
            else if(n>-134217728)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));


                no1s=abc;
            }
            else if(n>-268435456)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));


                no1s=abc;
            }
            else if(n>-536870912)
            {
                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864));
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));
                abc = abc + not(not(n & 536870912));


                no1s=abc;
            }
            else if(n <0)
            {

                n=~n;

                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864)) ;
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));
                abc = abc + not(not(n & 536870912));

                abc=32-abc;

                no1s=abc;
            }
            else
            {


                abc = abc + not(not(n & 1));
                abc = abc + not(not(n & 2));
                abc = abc + not(not(n & 4));
                abc = abc + not(not(n & 8));
                abc = abc + not(not(n & 16));
                abc = abc + not(not(n & 32));
                abc = abc + not(not(n & 64));
                abc = abc + not(not(n & 128));
                abc = abc + not(not(n & 256));
                abc = abc + not(not(n & 512));
                abc = abc + not(not(n & 1024));
                abc = abc + not(not(n & 2048));
                abc = abc + not(not(n & 4096));
                abc = abc + not(not(n & 8192));
                abc = abc + not(not(n & 16384));
                abc = abc + not(not(n & 32768));
                abc = abc + not(not(n & 65536));
                abc = abc + not(not(n & 131072));
                abc = abc + not(not(n & 262144));
                abc = abc + not(not(n & 524288));
                abc = abc + not(not(n & 1048576));
                abc = abc + not(not(n & 2097152));
                abc = abc + not(not(n & 4194304));
                abc = abc + not(not(n & 8388608));
                abc = abc + not(not(n & 16777216));
                abc = abc + not(not(n & 33554432));
                abc = abc + not(not(n & 67108864)) ;
                abc = abc + not(not(n & 134217728));
                abc = abc + not(not(n & 268435456));
                abc = abc + not(not(n & 536870912));

                no1s=abc;
            }



            sum += no1s;

        }

        final[test++]=sum;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        printf("%d\n",final[i]);
    }
}


