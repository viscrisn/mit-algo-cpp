#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int i=1;
    int j;

    for(j=0;j<=10;j++)
    {
        printf("%d: %d\n",j,i<<j);
    }

}
