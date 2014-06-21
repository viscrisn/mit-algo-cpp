#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    int test,a,b,j,l,flag,t,q,w;
    register int i,i1,k;
    register int n[20000];
    int count=0;


    scanf("%d",test);
    while(test!=0)
    {
        scanf("%d","%d",a,b);
        if(a%2==0)
        {
            a=a+1;
        }
        else if(b%2==0)
        {
            b=b-1;

        }
        {
            t=sqrt(b);
            for(i=3; i<=t; i+=2)
            {
                flag=0;
                k=sqrt(i);
                for(i1=3; i1<=k; i1+=2)
                {
                    if((i%i1)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    count+=1;
                    n[count]=i;
                    if(n[count]>=t)
                    {
                        break;
                    }

                }


            }
        }
        for(i=a; i<=b; i+=2)
        {
            if(i>3)
            {
                q=(i+1)%6;
                w=(i-1)%6;
                flag=0;
                if (q==0||w==0)
                {

                    for(i1=1; i1<=count; i1+=1)
                    {

                        if (i%n[i1]==0)
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
