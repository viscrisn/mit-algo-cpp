#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

char *replace_space(char *str)
{
    int len = strlen(str);
    int spaces = 0;
    for(int i= 0;i<len;i++)
    {
        if(str[i]==' ')
            spaces++;
    }
    spaces = spaces * 2;
    for(int i = len-1,j = len+spaces-1;i>=0;i--)
    {
        if(str[i]!=' ')
            str[j--] = str[i];
        else
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }
    str[len+spaces] = '\0';
    return str;
}

int main()
{
    char buf[100];
    char *str = buf;
    gets(str);
    str = replace_space(str);
    cout<<str<<"\n";
    return 0;
}
