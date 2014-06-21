#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int sum(int i,int j,int s)
{
    if(j<i)
    {
        return s;
    }
    return sum(i,j-1,j+s);
}
int sum_help(int i,int j)
{
    return sum(i,j,0);
}


int main()
{
    cout<<sum_help(1,10);
}



