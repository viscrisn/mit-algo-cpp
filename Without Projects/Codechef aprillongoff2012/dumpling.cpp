#include<stdio.h>


int main()
{


    register int cases;
    scanf("%d",&cases);

    int n1=cases;
    int test=0;
    int final[cases];

    while(cases)
    {

        int inputs[5];
        int answer=0;

        for(int i=0;i<5;i++)
        {
            scanf("%d",&inputs[i]);
        }


        final[test++]=answer;
        cases--;
    }

    for(int i=0;i<n1;i++)
    {
        if(final[i]>0)
            printf("%d\n",final[i]);
        else
            printf("UNFIT\n");
    }
}



