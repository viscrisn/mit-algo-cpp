#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return fact(n-1)*n;
}

int main()
{
    cout<<fact(5);
}
