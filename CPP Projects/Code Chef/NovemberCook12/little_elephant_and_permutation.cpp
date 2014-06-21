#include<iostream>

//Working properly

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,in=0,lin=0;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
                if(a[i]>a[j])
                    in++;
        }
        for (int i=0;i<n-1;i++ )
        {
        	if(a[i]>a[i+1])
                lin++;
        }

        if(lin==in)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

