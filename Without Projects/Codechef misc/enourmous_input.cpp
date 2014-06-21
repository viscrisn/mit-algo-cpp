#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int n;
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    int count=0;


    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);

        if(num%k==0)
        {
            count++;
        }

    }

    printf("%d\n",count);


}
