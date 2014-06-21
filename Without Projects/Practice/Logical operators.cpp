#include<iostream>
using namespace std;
int count=0;

int check(int num)
{
while(num>0)
{
if(num%100==11)
return 0;
num/=10;
}
return 1;
}

int dTb(int num)
{
if (num > 0)
return (num % 2) +10* dTb(num/2); //Recursion
else return 0;
}

void r(int &i,int &num)
{
if(i<=num)
{
if((check(dTb(i))))
{cout<< dTb(i)<<"\n";count++;}
i=i+1;
r(i,num); //Recursion
return;
}
else return;
}

int main()
{int Startvalue,Endvalue;
cin>>Startvalue>>Endvalue;
cout<<"\n";
r(Startvalue,Endvalue);
cout<<"\nTotal Numbers :"<<count;
return 0;
}
