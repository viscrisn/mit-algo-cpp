#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int gcd(int m,int n)
{
    if(n==0)
    {
        return m;
    }
    return gcd(n,m%n);
}

int main()
{
	cout<<gcd(12,8);
}
