#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int testno = 0; testno < test ; testno++ )
    {
        char a[5000];
        cin>>a;
        int len = strlen(a);
        reverse(a,a+len);
        //strrev(a);

        for (int i=0; i<len; i++ )
        {
            if(a[i]!='?')
            {
                continue;
            }
            for (int j=0;j<4;j++ )
            {
            	if(i<3) j++;
            	if(i<2) j++;
            	if(i<1) j++;

            	if(i+j>len)
            	{
            	    break;
            	}

            	if((a[i-3+j]=='F'||a[i-3+j]=='?')&&
                (a[i-2+j]=='E'||a[i-2+j]=='?')&&
                (a[i-1+j]=='H'||a[i-1+j]=='?')&&
                (a[i-0+j]=='C'||a[i-0+j]=='?'))
                {
                    a[i-3+j] = 'F';
                    a[i-2+j] = 'E';
                    a[i-1+j] = 'H';
                    a[i-0+j] = 'C';
                }
            }
        }
        for (int i=0;i<len;i++ )
        {
        	if(a[i]=='?')
            {
                a[i] = 'A';
            }
        }

        reverse(a,a+len);
        //a[len]="\n";
        //strrev(a);
        cout<<a<<"\n";

    }
}
