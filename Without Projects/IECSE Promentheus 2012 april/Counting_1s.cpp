

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
            register int n=i;


            int inc=0;

            if((n % 127) == n)
            {
                inc = 8;
            }
            else if((n % 32768) == n)
            {
                inc = 16;
            }
            else if((n % 8388607) == n)
            {
                inc = 24;
            }

            int counter =0;

            if(n<0)
            {
                n=~n;

                while(n>=1)
                {
                    counter++;
                    if(counter == inc)
                        break;
                    c=c + (n %2);
                    n=n/2;
                }
                c=32-c;
            }
            else
            {
                while(n>=1)
                {
                    counter++;
                    if(counter == inc)
                        break;
                    c=c + (n%2);
                    n=n/2;
                }
            }

            sum=sum + c;
        }

        final[test++]=sum;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        printf("%d\n",final[i]);
    }
}
