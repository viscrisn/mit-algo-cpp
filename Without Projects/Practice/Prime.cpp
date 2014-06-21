#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
int i,k,i1,flag,abc=0;
int count = 0;
for(int i=0;i<10000;i++)
 {
                        flag=0;
                        if((i%2)==0)
                                {
                                    flag=1;
                                }
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
                        abc+=1;
 }
 cout<<abc;
}



