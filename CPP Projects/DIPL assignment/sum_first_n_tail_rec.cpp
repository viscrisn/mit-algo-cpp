#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int sum(int n,int s)
{
    if(n==0)
    {
        return s;
    }
    return sum(n-1,n+s);
}
int sum_help(int n)
{
    return sum(n,0);
}


int main()
{
    cout<<sum_help(5);
}


