#include<iostream>

using namespace std;

union abc
{
    int f;
    struct asd
    {
        char q,w,e,r;
    }ST;
}UN;

int main()
{
    int a[4]={1,2,3,4};
    a[0]=a[0]>>4;
    cout<<a[0]<<" "<<a[1];

    cout<<"\n";

    UN.f=10;
    /*UN.ST.q=1;
    UN.f=UN.f<<9;
    cout<<(char)(UN.ST.q+'0')<<" "<<UN.f;
*/
    UN.ST.q=1;
    UN.ST.q=UN.ST.q<<6;
    cout<<endl<<(char)(UN.ST.q+'0')<<" "<<UN.f;
}





