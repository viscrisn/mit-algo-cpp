#include<iostream>

using namespace std;

int array(int [],int *,int);
int main()
{
    int b[10]={1,2,3,4,5,6,7},t;
    int c[]={1,2,3,4,5};
    int *p;
    int n=(sizeof(c)/sizeof(int));
    cout<<b[1]<<" "<<c[1]<<"\n";
    t=array(b,c,n);


    /*
    //What is happening here???
    int (*ptr)[5];
    ptr=&c;

    cout<<" "<<*(*(ptr+3))<<" ";
*/

    int *d[1];

    d[1]=&b[2];
    d[0]=&b[1];

    int *w=&(*d[0]=(*d[1]=10));

    cout<<" "<<*w<<" ";
    *d[0]=7;
    cout<<" "<<*w<<" ";


    b[1]=123;

    cout<<" "<<*w<<" ";

    b[2]=9;
    cout<<*d[1]<<" ";

    cout<<b[1]<<" "<<c[1];
}

int array(int d[],int *u,int n)
{
    for(int i=0;int t=!(0);d[i]++)
    {
        if(i==0)
            d[1]=345;
            break;
    }
    for(int i=0;i<n;i++,(*(u+i))--);
    cout<<sizeof(d);

}
