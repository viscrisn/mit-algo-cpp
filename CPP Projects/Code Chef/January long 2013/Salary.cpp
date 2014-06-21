#include<iostream>

using namespace std;

int a[200];

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        test--;
        int n;
        cin>>n;
        int min = 999999;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]<min) min = a[i];
        }
        int diff =0;
        for(int i=0; i<n; i++)
        {
            diff += a[i] - min;
        }
        cout<<diff<<"\n";
    }
}
