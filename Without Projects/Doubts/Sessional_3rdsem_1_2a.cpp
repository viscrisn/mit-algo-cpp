#include<iostream>

using namespace std;

    int f(int);
 int main()
 {
     int a[3]={11,12,13};
     int *ptr,**q,***r;
     ptr=a;
     q=&ptr;
     r=&q;

     *(ptr+1)=**q * ***r;
     ptr++;
     *(ptr+1)=**q+ ***r;
     *(*q+2)=(ptr +2) - *q;

     cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];

     cout<<"\nNext Question \n"<<f(9);

 }

 int f(int n)
 {
     int k,m;
     if (n<=1) return 1;
     else
     {
         k=n/2;
         m=f(k)+1;
         return (m);
     }

 }
