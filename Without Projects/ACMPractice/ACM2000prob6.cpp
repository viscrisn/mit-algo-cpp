#include<iostream>
#include<math.h>

using namespace std;

int prime(int []);
int main()
{
    int a[40][40],t[1229],x=0,j=0;
    int coor1[10],coor2[10],g=0;
    int i=1;
    t[0]=2;
    //t is sorted now after this step:
    prime(t);

    a[20][20]=2;
    /*Algo is x+1 right, x+1 up, then x+2 left and x+2 down*/

    int fb=0,ud=0,basefblimit=1,baseudlimit=1,basebflimit=-1,basedulimit=-1;
    for(;i<1229;)
    {
        //<<base 1>>

        while(fb<basefblimit)
        {
            fb++;
            a[20+fb][20+ud]=t[i];
            i++;
        }
        basefblimit++;

        //base 2

        while(ud<baseudlimit)
        {
            ud++;
            a[20+fb][20+ud]=t[i];
            i++;
        }
        baseudlimit++;

        //base 3

        while(fb>basebflimit)
        {
            fb--;
            a[20+fb][20+ud]=t[i];
            i++;
        }
        basebflimit--;

        //base 4

        while(ud>basedulimit)
        {
            ud--;
            a[20+fb][20+ud]=t[i];
            i++;
        }
        basedulimit--;

    }

    while(1)
    {

        cin>>coor1[g];
        if(coor1[g]==-999)
            break;
        cin>>coor2[g];
        g++;
    }


    for(int p=0;p<g;p++)
    {
        cout<<"Case "<<p+1<<": "<<"The prime at location "
        <<"("<<(coor1[p])<<","<<(coor2[p])<<") "<<"is "
        <<a[20+coor1[p]][20+coor2[p]]<<".\n\n";

    }
}


int prime(int t[])
{
int k,i1,flag,j=1;
int count = 0;
for(int i=2;i<10000;i++)
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
                    {
                        t[j]=i;
                        j++;
                    }

    }

}
