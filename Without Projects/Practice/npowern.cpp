#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main()
{
    int *p;
    size_t i=900000000;

    p=(int *)malloc(sizeof(int));
    cout<<"Enter the element\n";
        cin>>*p;

    int *npn=(int *)malloc(i);

    *npn=1;

    for(int i=0;i<(*p);i++)
    {
        *npn=(*npn)*(*p);
    }

    cout<<"The answer is\n"<<*npn;

}

