#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
  //a ^ a = 0
  //a ^ 0 = a
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}
