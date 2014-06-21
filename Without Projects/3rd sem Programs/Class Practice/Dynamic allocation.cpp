#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int *p;
    int t=0;

    p=(int *)malloc(4);

    cout<<"Enter the element\n";
        cin>>*p;

        cout<<*p;

}
