#include<iostream>

using namespace std;

int gcd(int m,int n)
{
    if(n==0)
        return m;
    else
        return gcd(n,m%n);
}
int main()
{
	cout<<gcd(18,12);
}
