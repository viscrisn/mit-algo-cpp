#include<iostream>

using namespace std;

class spiral
{
private:
    int n;
    long long n_2;
    int digits;
    char temp[50];
public:
    spiral(int a)
    {
        n = a;
        n_2 = n*n;
    }
    void prnt(int , int);
    void cal_digits(int);
    void number(int);
    void run();
};

void spiral::cal_digits(int n)
{
    digits = 0;
    while(n!=0)
    {
        n/=10;
        digits++;
    }
}


void spiral::run()
{
    cal_digits(n_2);
    for (int r=0; r < n; r++)
    {
        prnt(n, r);
        cout<<"\n";
    }
}
void spiral::number(int num)
{
    for(int i =digits-1; i>= 0; i--)
    {
        if(num == 0)
        {
            temp[i] = '0';
            continue;
        }
        temp[i] = (num%10) + 48;
        num /= 10;
    }
    temp[digits]='\0';

}

void spiral::prnt(int n, int r)
{
    long long nsq = n_2 - n*n;

    if(r+1 == n)
    {
        for (int i=0; i<n; i++)
        {
            number(nsq-i+1+(n-1)*3);
            cout<<temp;
        }
    }
    else if(!r)
    {
        for (int i=0; i<n; i++)
        {
            number(nsq+i+1);
            cout<<temp;
        }
    }
    else
    {
        number(nsq-r+1+(n-1)*4);
        cout<<temp;
        prnt(n-2, r-1);
        number(nsq+(n-1)+r+1);
        cout<<temp;
    }
}

int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
        return 0;
    }
    spiral matrix(n);
    matrix.run();
}
