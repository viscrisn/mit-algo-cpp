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

            register int n=i;
            int no1s=0;

            int inc=31;


            if((n<0) && (n>-16384))
            {
                n=~n;
                register int abc=n;

                for(int k=1;k<inc;k++)
                {
                    n=n/2;
                    abc= abc - (n);
                }
                abc=32-abc;

                no1s=+abc;
            }
            else if(n>=16384)
            {
                cout<<"ENtered\t";
                n=~n;

                register int abc =0;
                register unsigned int hi =n;


                for(int k=1;k<inc;k++)
                {
                    abc=abc + (hi%2);
                    hi=hi/2;
                }
                //abc=32-abc;

                n=~n;

                while(n>=1)
                {
                    c=c + (n %2);
                    n=n/2;
                }
                c=32-c;

                no1s=+abc;
            }
            else
            {
                cout<<"eihfio\t";

                register unsigned int abc =n;


                for(int k=1;k<inc;k++)
                {
                    n=n/2;
                    abc= abc - (n);
                }

                no1s=+abc;
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
