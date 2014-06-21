#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
        int ch[100];
        int i1=0;
        int no_char[30];

        for(int i=0;i<30;i++)
        {
            no_char[i]=0;
        }

        while(1)
        {
            i1++;

        ch[i1]=getche();

        if(ch[i1]=='a')
        {
            no_char[0]++;
        }
        if(ch[i1]=='b')
        {
            no_char[1]++;
        }
        if(ch[i1]=='c')
        {
            no_char[2]++;
        }
        if(ch[i1]=='d')
        {
            no_char[3]++;
        }
        if(ch[i1]=='e')
        {
            e++;
        }
        if(ch[i1]=='f')
        {
            r++;
        }
        if(ch[i1]=='g')
        {
            u++;
        }
        if(ch[i1]=='h')
        {
            p++;
        }
        if(ch[i1]=='i')
        {
            h++;
        }
        if(ch[i1]=='j')
        {
            a++;
        }
        if(ch[i1]=='k')
        {
            c++;
        }
        if(ch[i1]=='l')
        {
            k++;
        }
        if(ch[i1]=='m')
        {
            e++;
        }
        if(ch[i1]=='n')
        {
            r++;
        }
        if(ch[i1]=='o')
        {
            u++;
        }
        if(ch[i1]=='p')
        {
            p++;
        }
        if(ch[i1]=='q')
        {
            p++;
        }
        if(ch[i1]=='r')
        {
            h++;
        }
        if(ch[i1]=='s')
        {
            a++;
        }
        if(ch[i1]=='t')
        {
            c++;
        }
        if(ch[i1]=='u')
        {
            k++;
        }
        if(ch[i1]=='v')
        {
            e++;
        }
        if(ch[i1]=='w')
        {
            r++;
        }
        if(ch[i1]=='x')
        {
            u++;
        }
        if(ch[i1]=='y')
        {
            p++;
        }
        if(ch[i1]=='z')
        {
            p++;
        }
        if(ch[i1]=='\r')
        {
            break;
        }
    }

    for(int i=0;ch[i]!='\r';i++)
    {
        cout<<ch[i]<<" ";
    }


}

