#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int final[20];

    int cases;
    cin>>cases;
    int n=cases;
    int test=0;
    int count=0;

    while(cases)
    {
        cases--;
        char ch[1000];

        while(1)
        {
            i++;

        ch[i]=getche();

        if(ch[i]=='a')
        {
            h++;
        }
        if(ch[i]=='b')
        {
            a++;
        }
        if(ch[i]=='c')
        {
            c++;
        }
        if(ch[i]=='d')
        {
            k++;
        }
        if(ch[i]=='e')
        {
            e++;
        }
        if(ch[i]=='f')
        {
            r++;
        }
        if(ch[i]=='g')
        {
            u++;
        }
        if(ch[i]=='h')
        {
            p++;
        }
        if(ch[i]=='i')
        {
            h++;
        }
        if(ch[i]=='j')
        {
            a++;
        }
        if(ch[i]=='k')
        {
            c++;
        }
        if(ch[i]=='l')
        {
            k++;
        }
        if(ch[i]=='m')
        {
            e++;
        }
        if(ch[i]=='n')
        {
            r++;
        }
        if(ch[i]=='o')
        {
            u++;
        }
        if(ch[i]=='p')
        {
            p++;
        }
        if(ch[i]=='q')
        {
            p++;
        }
        if(ch[i]=='r')
        {
            h++;
        }
        if(ch[i]=='s')
        {
            a++;
        }
        if(ch[i]=='t')
        {
            c++;
        }
        if(ch[i]=='u')
        {
            k++;
        }
        if(ch[i]=='v')
        {
            e++;
        }
        if(ch[i]=='w')
        {
            r++;
        }
        if(ch[i]=='x')
        {
            u++;
        }
        if(ch[i]=='y')
        {
            p++;
        }
        if(ch[i]=='z')
        {
            p++;
        }
        if(ch[i]=='\r')
        {
            break;
        }
    }

        final[test++]=count;
    }
//cout<<endl;
    for(int test1=0;test1<n;test1++)
    {
        cout<<"Case #"<<test1+1<<": "<<final[test1]<<endl;
    }

}
