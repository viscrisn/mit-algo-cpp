#include<iostream>
#include<stdio.h>

using namespace std;

class time1
{
    int hr,min,sec;
    public:
        void display();
        void check();
        void input();
        int compare(time1);
        time1 add(time1);
        time1 substract(time1);
};

time1 time1::add(time1 d)
{
    time1 sum;
    sum.sec=sec+d.sec;
    sum.hr=hr+d.hr;
    sum.min=min+d.min;
    sum.check();
    return sum;
}

time1 time1::substract(time1 d)
{
    time1 diff;
    int temp;

    int t1,t2;
    t1=((hr*3600)+min*60)+sec;
    t2=((d.hr*3600)+d.min*60)+d.sec;
    temp=t1-t2;
    diff.sec=temp;

    diff.check();
    return diff;

}

void time1::input()
{
    int a,b,c;
    cout<<"Enter Hour::Minute::Second";
    cin>>a>>b>>c;
    hr=a;
    min=b;
    sec=c;
}

void time1::display()
{
    cout<<"Hour::Minute::Second\n"<<hr<<"::"<<min<<"::"<<sec<<"\n";
}

void time1::check()
{
    if(sec>=60)
    {
        min+=sec/60;
        sec%=60;
    }
    if(min>=60)
    {
        hr+=min/60;
        min%=60;
    }
    if(hr>=24)
    {
        hr=hr%24;
    }
}

int time1::compare(time1 d)
{
    int temp;

    int t1,t2;
    t1=((hr*3600)+min*60)+sec;
    t2=((d.hr*3600)+d.min*60)+d.sec;

    if(t1>t2)
    {
        return 1;
    }
    else if(t1<t2)
    {
        return -1;
    }
    else
        return 0;
}

int main()
{
    time1 A,B,result;
    int cmpre;
    A.input();
    B.input();

    A.check();
    B.check();

    A.display();
    B.display();

    cout<<"the sum is:\n";
    result=A.add(B);
    result.display();

    cmpre=A.compare(B);

    if(cmpre==1)
    {
        result=A.substract(B);
        cout<<"\nA is larger than B\n";
    }
    else if(cmpre==-1)
    {
        result=B.substract(A);
        cout<<"\nB is larger than A\n";
    }
    else
    {
        cout<<"Both times are equal\n";
    }

    cout<<"\nThe difference is: \n";
    result.display();

}























