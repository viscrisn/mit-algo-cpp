#include<iostream>

using namespace std;

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    cout<<"Enter a number\n";
    int n;
    cin>>n;
    cout<<n<<"th fibonacci number is:\n"<<fibo(n);

}
