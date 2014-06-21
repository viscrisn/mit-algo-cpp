#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int a[10];
    int b[10];
    int n=0;
    int i=0;

    while(n!=-1)
    {

        cin>>a[i];
        i++;
        n=a[i];
    }
    a[i]=-999;

    i=0;
    while(n!=-1)
    {

        cin>>b[i];
        i++;
        n=b[i];
    }
    b[i]=-999;

    int startx=a[0];
    int starty=b[0];

    int endx=a[1];
    int endy=b[1];

    if((startx-endx)<(starty-endy))
    {
        cout<<(starty-endy);
    }
    else
        cout<<(starty-endx);


}


