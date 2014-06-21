#include<iostream>
#include<stdio.h>

using namespace std;

int sum(int &, int &);
int reverse(int &);
int main()
{
    int p,q,sum1;


    reverse(&p);
    reverse(&q);

    (t)=sum(&p,&q);
    reverse(&t);
    cout<<"the sum is\n"<<t;
}
int reverse(int &a)
{
    int i=0,b;
    while(a)
    {
        b+=((a)%10)*(10*i);
        i++;
        a/=10;
        if(a==0)
        {
            return 0;
            break;
        }
        return b;
    }
}

int sum(int *p,int *q)
{
    int temp;
    temp=(*p)+(*q);
    return temp;
}
