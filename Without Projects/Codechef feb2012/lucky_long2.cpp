#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t=0;
    scanf("%d",&t);
    int inc=-1;
    int cases=t;
    double count[t];
    t++;
    while(t)
    {
        char number='0';
        short no_part;

        count[inc]=0;
        //int dummy=0;

        while((number=getchar())!='\n')
        {

            no_part=int(number-'0');

            if(no_part!=4 && no_part!=7)
            {
                count[inc]++;
            }
            //dummy++;

        }
        //printf("Dummy: %d\n",dummy);
        inc++;
        t--;
    }
    for(int i=0;i<cases;i++)
    {
        printf("%d\n",count[i]);
    }

}
