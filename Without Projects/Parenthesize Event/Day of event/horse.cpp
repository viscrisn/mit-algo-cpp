#include<iostream>
#include<cstdio>
using namespace std;

int checkhorse(char **arr,int m, int n, int x,int y)
{
        int x1=x,y1=y;
        x1-=2;
        y1--;
        int count=0;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;
        x1=x;
        y1=y;
        x1--;
        y1-=2;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;

        x1=x;
        y1=y;
        x1--;
        y1+=2;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;

        x1=x;
        y1=y;
        x1-=2;
        y1++;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;

        x1=x;
        y1=y;
        x1++;
        y1+=2;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;
        x1=x;
        y1=y;
        x1++;
        y1-=2;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;
        x1=x;
        y1=y;
        x1+=2;
        y1++;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;
        x1=x;
        y1=y;
        x1+=2;
        y1--;
        if(check(x1,y1,m,n)&&arr[x1][y1]!='E')
            count++;

    return count;
}
int check(int x,int y,int m,int n)
{
    if(x>m-1||x>n-1)
        return 0;
    if(x<0||y<0)
        return 0;
    return 1;
}
