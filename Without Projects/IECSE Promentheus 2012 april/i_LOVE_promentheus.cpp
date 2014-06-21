#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;
int main()
{

    int final[100];

    int cases;
    cin>>cases;
    int n=cases;
    int test=0;
    int count=0;

    char qwe[1];
    gets(qwe);

    while(cases)
    {
        count=0;
        cases--;
        char ch[10000];

        int i=0, l=0,o=0,v=0,e=0, p=0,r=0,m=0,n=0,t=0,h=0,u=0,s=0;
        int z=0;

        gets(ch);
        int abc=0;
        z=-1;

        while(1)
        {
            z++;

            if(ch[z]=='I')
            {
                i++;
            }
            if(ch[z]=='L')
            {
                l++;
            }
            if(ch[z]=='O')
            {
                o++;
            }
            if(ch[z]=='V')
            {
                v++;
            }
            if(ch[z]=='E')
            {
                e++;
            }
            if(ch[z]=='P')
            {
                p++;
            }
            if(ch[z]=='R')
            {
                r++;
            }
            if(ch[z]=='M')
            {
                m++;
            }
            if(ch[z]=='T')
            {
                t++;
            }
            if(ch[z]=='H')
            {
                h++;
            }
            if(ch[z]=='U')
            {
                u++;
            }
            if(ch[z]=='S')
            {
                s++;
            }
            if(ch[z]=='\r')
            {
                break;
            }
        }
     while(1)
    {
        if(e>2)
            if(i>0)
                if(l>0)
                    if(o>1)
                        if(v>0)
                            if(p>0)
                                if(r>0)
                                    if(m>0)
                                            if(t>0)
                                                if(h>0)
                                                    if(u>0)
                                                        if(s>0)
                                                        {
                                                            count++;
                                                            i--;

                                                            l--;
                                                            o--;
                                                            v--;
                                                            e--;

                                                            p--;
                                                            r--;
                                                            o--;
                                                            m--;
                                                            e--;
                                                            //n--;
                                                            t--;
                                                            h--;
                                                            e--;
                                                            u--;
                                                            s--;

                                                        }
                                                        else break;
                                                    else break;
                                                else break;
                                            else break;

                                    else break;
                                else break;
                            else break;
                        else break;
                    else break;
                else break;
            else break;
        else break;
    }

    /*for(int j=0;j<1000;j++)
    {
         ch[j]='\n';
    }*/
    i=0, l=0,o=0,v=0,e=0, p=0,r=0,m=0,n=0,t=0,h=0,u=0,s=0;

    final[test++]=count;
}

for(int test1=0;test1<n;test1++)
{
    cout<<final[test1]<<endl;
}

}
