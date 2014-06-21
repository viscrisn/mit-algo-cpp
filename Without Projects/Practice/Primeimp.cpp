#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int test,a,b,i,j,flag,k,i1,h1,h2;
int r=0;
double g1,g2;
cin>>test;
while(test!=0)
    {
    cin>>a>>b;
    if(a%2==0)
        {
            a=a+1;
        }
    else if(b%2==0)
    {
        b=b-1;

    }
    for(i=a;i<=b;i+=2)
        {
            if(i>3)
                {
                    flag=0;
                {
                g1=(i+1)/6.0;
                h1=(i+1)/6;
                g2=(i-1)/6.0;
                h2=(i-1)/6;
                }
                    if (g1==h1||g2==h2)
                    {
                    k=sqrt(i);
                    for(i1=3;i1<=k;i1+=2)
                        {

                            if((i%i1)==0)
                                {
                                    flag=1;
                                    break;
                                }
                        }
                    if(flag==0)
                    cout<<i<<"\t";
                    }
                }
        }

    cout<<endl;
    test--;
}

}
