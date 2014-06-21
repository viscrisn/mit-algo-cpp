#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int fact(int n,int f)
{
    if(n==0)
    {
        return f;
    }
    return fact(n-1,n*f);
}
int fact_help(int n)
{
    return fact(n,1);
}


int main()
{
    cout<<fact_help(5);
}

