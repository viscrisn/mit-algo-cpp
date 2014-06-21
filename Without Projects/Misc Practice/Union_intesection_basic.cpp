#include<iostream>

using  namespace std;

void un(int *,int *,int *);
void in(int *,int *,int *);

int main()
{
    int a[30],b[30],c[30],d[30];
    int n=0;
    int i=0;

    cout<<"List 1\n";
    while(n!=-1)
    {
        cin>>a[i];
        n=a[i];
        i++;
    }

    i=0;
    n=0;
    cout<<"List 2\n";
    while(n!=-1)
    {
        cin>>b[i];
        n=b[i];
        i++;
    }

    un(a,b,c);
    in(a,b,d);
    cout<<"Union\n";
    while(c[i]!=-1)
    {
        cout<<" "<<c[i];
    }

    cout<<"Intersection\n";
    while(d[i]!=-1)
    {
        cout<<" "<<d[i];
    }
}

void un(int *a,int *b,int *c)
{
    int i=0;
    while(a[i]!=-1)
    {
        c[i]=a[i];
    }

    i=0;
    for(int j=0;b[i]!=-1;j++)
    {
        if(b[j]!=a[])
    }
}
