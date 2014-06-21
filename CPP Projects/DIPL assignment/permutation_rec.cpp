#include<stdio.h>
#include<string.h>

void perm(char * , int , int );
char temp,str[20];
int l;

int main()
{
    printf("Enter the string : ");
    scanf("%s",str);
    printf("The permutations are\n");
    l=strlen(str);
    perm(str,0,l);
}

void perm(char *str,const int strt, int len)
{
    int i,j;
    for(i=strt; i<len-1; ++i)
        for(j=i+1; j<len; ++j)
        {
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            perm(str , i+1 ,len);
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
        }
    printf("%s\n",str);
    return;
}
