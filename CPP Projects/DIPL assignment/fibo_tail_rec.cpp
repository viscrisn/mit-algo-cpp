#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<cmath>

using namespace std;

int fibo(int n,int f_prev,int f,int i,int fib)
{
    if(i==n)
    {
        return fib;
    }
    return fibo(n,f,f_prev + f,i+1,f_prev + f);


}

int fibo_help(int n)
{
    return fibo(n,0,1,1,1);
}

int main()
{
    cout<<fibo_help(6);
}




