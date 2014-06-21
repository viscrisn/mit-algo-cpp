# include "minimumshelf.h"
#include<string.h>
#include<stdio.h>

int shelfCount(char* str)
{
    int i=0;
    int a[26] = {0};
    for(i=0;i<strlen(str);i++)
    {
        if((str[i]>91)||(str[i]<64))
            return -1;

        a[str[i]-65] = 1;
    }
    int count =0;
    for(i=0;i<26;i++)
    {
        count += a[i];
    }

    return count;
}

