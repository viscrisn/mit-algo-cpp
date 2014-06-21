#include<iostream>
#include<cstring>
using namespace std;

char p[10][100];
char s[]={"XZ"};
char* pand(int n)
{
    p[0][0]='X';
    p[1][0]='Y';
    p[2][0]='Z';
    strcat(p[n],p[n-2]);
    strcat(p[n],p[n-3]);
}
int main()
{
    int j,y=0;
    int k;
    int count;
    for(int i=3;i<=8;i++)
    {
        pand(i);
    }
    for(int i=8;i<=8;i++)
    {
        count=0;
        j=0;
        for(k=y;k<strlen(p[i]);k++)
        {
            while(j<strlen(s) && s[j]==p[i][k])
                j++;
        }
        if(j==strlen(s))
           count++;
        y=k;
    }
     cout<<count;
    return 0;
}
