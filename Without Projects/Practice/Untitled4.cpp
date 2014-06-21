#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int test,a,b,i,j,flag,k,i1;
cin>>test;
while(test!=0)
{cin>>a>>b;
for(i=a;i<=b;i++)
{ if(i>3)
{
flag=0;
k=sqrt(i);
for(i1=2;i1<=k;i1++)
{
if(i%i1==0)
{flag++;
break;}
}
if(flag==0)
cout<<i<<endl;}
else if(i!=1)
cout<<i<<endl;
}cout<<endl;
test--;}
}
