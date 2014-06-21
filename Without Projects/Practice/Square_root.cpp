#include <iostream>
#include <math.h>

using namespace std;


float sqroot(float m)
{
    float i=0;
    float x1,x2;

    while( (i*i) <= m-0.1 )
          i+=0.1;
    x1=i;

    cout<<"\n"<<x1<<"\n";
    for(int j=0;j<10;j++)
    {
        x2=m;       /*  x(N+1)=(xN+m/xN)*1/2;   */
        x2/=x1;
        x2+=x1;
        x2/=2;
        x1=x2;
    }
    return x1;
}

int main()
{
   cout<<"Enter a Number:";
   int no;
   cin>>no;
     cout<<"Square Root using sqroot()= "<<sqroot(no)<<endl
       <<"Square Root using sqrt()  = "<<sqrt(no);

   return 0;
}
