#include<iostream>
#include<stdio.h>

using namespace std;
int gcd(int, int);
int main()
{
    int a,b,t;
    cin>>a>>b;
    t=gcd(a,b);
    cout<<"\n"<<t;
}
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    return gcd(b,a%b);
}
