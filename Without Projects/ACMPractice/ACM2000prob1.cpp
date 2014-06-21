#include<iostream>

using namespace std;

int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return n/2;
    }
    else
    return (f(n/2) + f(n/2+1));
}

int main()
{
    int n;
    cin>>n;
    cout<<f(n);
}


