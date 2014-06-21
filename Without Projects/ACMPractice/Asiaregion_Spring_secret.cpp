/*10 mins, working*/
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=n;
    int x=1;
    int d[n];
    while(n)
    {
        int w;
        cin>>w;
        int flag=0;
        for(int i=0;i<w;i++)
        {
            char a[15];
            cin>>a;
            if(!strcmp(a,"hilsha"))
            {
                flag++;
            }
        }
        d[n]=flag;
        n--;
    }
    while(t)
    {
        cout<<"Case "<<x++<<": "<<d[t]<<endl;
        t--;
    }
}
