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
    char a[100];
    char b[100];
    cin>>a;
    cin>>b;

    int len1 = strlen(a);
    int len2 = strlen(b);

    int del =0;
    int add= 0;
    if(len1>len2)
        del = len1-len2;
    else
        add = len2 - len1;

    int start = 0;
    int flag =0;
    for (int i=0; i<len1; i++ )
    {
        for (int j=0; j<len2; j++ )
        {
            if(a[i]==b[j])
            {
                start = j;
                flag =1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
    int ao =0;
    for (int i=0; i<start; i++ )
    {

        cout<<"a "<<b[i]<<"\n";
        add--;
    }

    for (int i=start;i<len2-add;i++ )
    {

        if(a[ao]==b[i])
        {
            cout<<"c "<<b[i]<<"\n";
        }
        else
        {
            cout<<"m "<<b[i]<<"\n";
        }

    	ao++;


    	if(a[i]=='\n')
    	{
    	    break;
    	}
    }
    for (int i=0;i<add;i++ )
    {
    	cout<<"a "<<b[len2-add+i]<<"\n";
    }


}
