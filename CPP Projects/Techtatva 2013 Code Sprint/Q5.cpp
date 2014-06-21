#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<set>
#include<queue>
#include<fstream>

using namespace std;

int fibo(int n)
{
    if(n==0||n==1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
}
