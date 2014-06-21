#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int sum(int i,int j)
{
    if(j==i)
    {
        return i;
    }
    return sum(i,j-1) + j;
}



int main()
{
    cout<<sum(1,10);
}
