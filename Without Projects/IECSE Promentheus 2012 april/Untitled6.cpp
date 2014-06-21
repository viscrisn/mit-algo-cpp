#include<stdio.h>

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
            /*register int i1=1;

            while(i1<32)
            {
                c=c + (n & ((i1*2)-1))&1;
                i1++;
            }*/
            while(n>=1)
            {
                c=c + (n & 1);
                n=n>>1;
            }
            sum+=c;
        }

        final[test++]=sum;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        printf("%d\n",final[i]);
    }
}
