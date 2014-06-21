#include<iostream>

using namespace std;

int fact(int);
int main()
{
    int t,n,k;
    cout<<"Enter The Number\n";
    cin>>t;
    n=fact(t);
    cout<<n;
}

int fact(int n)
{
    int x,y,res,t=-1;
    if(n==0) return 1;
    else
    {
        x=n-1;
        t++;
        y=fact(x);
        res=n*(y+t);

        return res;
    }

}











