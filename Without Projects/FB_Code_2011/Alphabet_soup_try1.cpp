#include<iostream>
#include<cstring>
#include<conio.h>

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
        int h=0,a=0,c=0,k=0,e=0,r=0,u=0,p=0;
        int i=0;



        while(1)
        {
            i++;

        ch[i]=getche();

        if(ch[i]=='H')
        {
            h++;
        }
        if(ch[i]=='A')
        {
            a++;
        }
        if(ch[i]=='C')
        {
            c++;
        }
        if(ch[i]=='K')
        {
            k++;
        }
        if(ch[i]=='E')
        {
            e++;
        }
        if(ch[i]=='R')
        {
            r++;
        }
        if(ch[i]=='U')
        {
            u++;
        }
        if(ch[i]=='P')
        {
            p++;
        }
        if(ch[i]=='\r')
        {
            break;
        }
    }
     while(1)
    {
        if(c>1)
            if(h>0)
                if(a>0)
                    if(k>0)
                        if(e>0)
                            if(r>0)
                                if(u>0)
                                    if(p>0)
                                    {
                                        count++;
                                        h--;
                                        a--;
                                        c--;
                                        k--;
                                        e--;
                                        r--;
                                        u--;
                                        p--;
                                        c--;
                                    }
                                    else break;
                                else break;
                            else break;
                        else break;
                    else break;
                else break;
            else break;
        else break;
    }

    for(int j=0;j<1000;j++)
    {
         ch[j]='\n';
    }
    h=a=c=k=e=r=u=p=0;
    final[test++]=count;
}
//cout<<endl;
for(int test1=0;test1<n;test1++)
{
    cout<<"Case #"<<test1+1<<": "<<final[test1]<<endl;
}

}
