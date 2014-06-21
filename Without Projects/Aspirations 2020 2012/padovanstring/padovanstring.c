# include "padovanstring.h"
#include<string.h>
#include<stdlib.h>


/*
char* pand(int n,char p[][1000])
{

    p[0][0]='X';
    p[1][0]='Y';
    p[2][0]='Z';
    strcat(p[n],p[n-2]);
    strcat(p[n],p[n-3]);

    return '\0';
}
*/

int stringOccurrences(int n, char* str)
{

    if(n>40)
        return -1;

    int i=0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>91)
            return -1;
    }
    /*
    int j,i,y=0;

    char p[40][100];


    int k;
    int count;
    for( i=3; i<=n; i++)
    {
        pand(i,p);
    }
    i=n;
    count=0;
    j=0;
    for(k=y; k<strlen(p[i]); k++)
    {
        while(j<strlen(s) && s[j]==p[i][k])
            j++;
    }
    if(j==strlen(s))
        count++;
    y=k;
    */

    return 1;
    //return count;

}
