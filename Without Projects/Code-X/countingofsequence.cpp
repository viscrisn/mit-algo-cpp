#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char d[30];
    char e[30];
    char f[30];
    char *a=d;
    char *b=e;
    char *c=f;


    int i=0;

    for(int i=0;i<strlen(a);i++)
        {
        for(int j=0;j<strlen(b);j++)
        {
            for(int k=0;j<strlen(c);k++)
            {

                if(!(strcmp(a,b)&&strcmp(b,c)))
                {
                    i++;
                }

            }
        }
    }
}



