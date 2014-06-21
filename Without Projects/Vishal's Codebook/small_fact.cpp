#include<iostream>

using namespace std;

int fact(int n)
{
    int fac=1;
    for(int i=1;i<=n;i++)
    {
        fac*=i;
    }
    return fac;
}


int main()
{
    int t;
    cin>>t;
    int cse=0;
    int fac[t];

    for(int i=0;i<t;i++)
    {
        int num;
        cin>>num;


        fac[cse]=fact(num);

        cse++;

    }

    for(int i=0;i<cse;i++)
    {
        cout<<fac[i]<<"\n";
    }
}
