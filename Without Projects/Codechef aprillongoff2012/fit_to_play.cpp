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
        unsigned long no_matches;
        scanf("%d", &no_matches);

        unsigned long goals[no_matches];

        for(int i=0;i<no_matches;i++)
        {
            scanf("%d",&goals[i]);
        }


        unsigned long difference=0;
        unsigned long temp=0;

        for(unsigned long i=1;i<no_matches;i++)
        {
            temp = goals[i] - goals[i-1];

            if(temp>difference)
            {
                difference = temp;
            }
        }

        final[test++]=difference;
        cases--;
    }

    for(unsigned long i=0;i<n1;i++)
    {
        if(final[i]>0)
            printf("%d\n",final[i]);
        else
            printf("UNFIT\n");
    }
}
