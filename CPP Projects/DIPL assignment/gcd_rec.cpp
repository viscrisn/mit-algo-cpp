#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int gcd(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
        {
            return gcd(x-y,y);
        }
        else
        {
            return gcd(x,y-x);
        }
    }
    return x;
}

int main()
{
    cout<<gcd(12,8);
}

