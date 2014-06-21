#include<stdio.h>
#include<cstring>

int main()
{
    int t=0;
    scanf("%d",&t);
    int inc=0;
    int cases=t;
    int count[t];

    while(t)
    {
        long number;
        short no_part;
        scanf("%d",&number);
        count[inc]=0;
        while(number)
        {
            no_part=number%10;
            number=number/10;
            if(no_part!=4 && no_part!=7)
            {
                count[inc]++;
            }
        }
        inc++;
        t--;
    }
    for(int i=0;i<cases;i++)
    {
        printf("%d",count[i]);
        printf("\n");
    }

}
