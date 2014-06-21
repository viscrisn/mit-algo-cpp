#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    long long fact = 1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        fact*=a[i];
    }

    for (int i=0;i<n;i++ )
    {
        if(a[i]==0)
        {
            long long fact2 = 1;
            for (int j=0;j<n;j++ )
            {
            	if(j!=i)
            	{
            	    fact2*=a[j];
            	}
            }
            cout<<fact2<<"\n";
        }
        else
        {
            cout<<fact/a[i]<<"\n";
        }

    }


}
