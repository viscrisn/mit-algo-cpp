#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return sum(n-1) + n;
}



int main()
{
    cout<<sum(10);
}


