#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    start:
    cout<<"Enter number:\n";
    int num;
    cin>>num;
    if(num<0)
    {
        goto start;
        cout<<"Please insert positive number\n";
    }

    int temp_num = num;

    int no_digits=0;

    no_digits = floor(log10(num)+1);

    /*while(temp_num!=0)
    {
        no_digits++;
        temp_num/=10;
    }*/

    int n;
    float x_0 = 0;
    if(no_digits%2==0)
    {
        n=(no_digits-2)/2;
        x_0 = 2*pow(10,n);
    }
    else
    {
        n = (no_digits-1)/2;
        x_0 = 6*pow(10,n);
    }

    float x_loop = x_0;
    for(int i=0;i<15;i++)
    {
        x_loop = (x_loop + num/x_loop)/2;
    }
    cout<<"Square root is:\n"<<x_loop<<endl;
    goto start;
}
