#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++ )
    {
    	cin>>a[i];
    }

    int k = rand()%n;
    cout<<a[k];

}
