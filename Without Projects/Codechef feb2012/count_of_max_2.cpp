#include<stdio.h>


int main()
{
    int t;
    scanf("%d",&t);

    int count[t];
    int pos[t];
    for(int i=0;i<t;i++)
    {
        count[i]=0;
        pos[i]=0;
    }
    int test1=0;

    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int array[n];

        int numbers[10001]={0};


        for(int i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
            numbers[array[i]]++;
        }




        for(int i=0;i<n;i++)
        {
            if(count[test1]<numbers[array[i]])
            {
                count[test1]=numbers[array[i]];
                pos[test1]=array[i];
            }

            if(count[test1]==numbers[array[i]] && pos[test1]>array[i])
            {
                count[test1]=numbers[array[i]];
                pos[test1]=array[i];
            }
        }
        test1++;


    }
    for(int i=0;i<t;i++)
    {
        printf("%d %d",pos[i],count[i]);
        printf("\n");
    }
}
